#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include "matrix.h"
#include "layer.h"
#include "network.h"
#include "loss.h"
#include "data_loader.h"

static void normalize(std::vector<Matrix>& inputs) {
    int features = inputs[0].rows;
    for (int f = 0; f < features; f++) {
        double min_val = inputs[0].data[f][0];
        double max_val = inputs[0].data[f][0];
        for (auto& m : inputs) {
            min_val = std::min(min_val, m.data[f][0]);
            max_val = std::max(max_val, m.data[f][0]);
        }
        double range = max_val - min_val;
        if (range == 0.0) range = 1.0;
        for (auto& m : inputs)
            m.data[f][0] = (m.data[f][0] - min_val) / range;
    }
}

int main() {
    Dataset ds = DataLoader::loadIris("data/iris.csv");
    normalize(ds.inputs);

    std::mt19937 rng(42);
    std::vector<int> idx(ds.inputs.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::shuffle(idx.begin(), idx.end(), rng);

    int total = (int)ds.inputs.size();
    int train_size = (int)(total * 0.8);

    std::vector<Matrix> train_in, train_tgt, val_in, val_tgt;
    for (int i = 0; i < total; i++) {
        if (i < train_size) {
            train_in.push_back(ds.inputs[idx[i]]);
            train_tgt.push_back(ds.targets[idx[i]]);
        } else {
            val_in.push_back(ds.inputs[idx[i]]);
            val_tgt.push_back(ds.targets[idx[i]]);
        }
    }

    Network net;
    net.addLayer(Layer(4, 8, ActivationType::RELU));
    net.addLayer(Layer(8, 3, ActivationType::SIGMOID));

    double lr = 0.01;
    int epochs = 200;

    std::vector<int> train_order(train_size);
    std::iota(train_order.begin(), train_order.end(), 0);

    for (int epoch = 1; epoch <= epochs; epoch++) {
        std::shuffle(train_order.begin(), train_order.end(), rng);

        double train_loss = 0.0;
        int train_correct = 0;

        for (int i = 0; i < train_size; i++) {
            int s = train_order[i];
            Matrix output = net.forward(train_in[s]);

            std::vector<double> out_vec(3), tgt_vec(3);
            for (int j = 0; j < 3; j++) {
                out_vec[j] = output.data[j][0];
                tgt_vec[j] = train_tgt[s].data[j][0];
            }
            train_loss += Loss::mse(out_vec, tgt_vec);

            Matrix grad(3, 1);
            for (int j = 0; j < 3; j++)
                grad.data[j][0] = 2.0 * (out_vec[j] - tgt_vec[j]) / 3.0;
            net.backward(grad, lr);

            int pred = (int)(std::max_element(out_vec.begin(), out_vec.end()) - out_vec.begin());
            int actual = (int)(std::max_element(tgt_vec.begin(), tgt_vec.end()) - tgt_vec.begin());
            if (pred == actual) train_correct++;
        }

        double val_loss = 0.0;
        int val_correct = 0;
        for (int i = 0; i < (int)val_in.size(); i++) {
            Matrix output = net.forward(val_in[i]);

            std::vector<double> out_vec(3), tgt_vec(3);
            for (int j = 0; j < 3; j++) {
                out_vec[j] = output.data[j][0];
                tgt_vec[j] = val_tgt[i].data[j][0];
            }
            val_loss += Loss::mse(out_vec, tgt_vec);

            int pred = (int)(std::max_element(out_vec.begin(), out_vec.end()) - out_vec.begin());
            int actual = (int)(std::max_element(tgt_vec.begin(), tgt_vec.end()) - tgt_vec.begin());
            if (pred == actual) val_correct++;
        }

        if (epoch % 20 == 0) {
            double train_acc = 100.0 * train_correct / train_size;
            double val_acc = 100.0 * val_correct / (int)val_in.size();
            std::cout << "Epoch " << epoch
                      << " | train loss: " << train_loss / train_size
                      << " | train acc: " << train_acc << "%"
                      << " | val loss: " << val_loss / val_in.size()
                      << " | val acc: " << val_acc << "%\n";
        }
    }

    return 0;
}
