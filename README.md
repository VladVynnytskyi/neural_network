# Neural Network from Scratch in C++

A neural network implementation built from scratch in C++ without any external ML libraries.
Course project for **Programowanie 2**, Jagiellonian University, 2025/2026.

## Goal

Build a fully functional feedforward neural network capable of learning from data using backpropagation and gradient descent — implemented entirely in C++ using only the standard library.

## Features

### Stage 1 — Matrix & Vector Math ✅
- `Matrix` class with addition, multiplication, transpose
- Element-wise operations, dot product
- Unit tests for correctness

### Stage 2 — Network Architecture ✅
- `Layer` class (fully connected / dense layer)
- Configurable number of neurons per layer
- Weight and bias initialization (random)
- Forward pass through a single layer

### Stage 3 — Activation Functions ✅
- Sigmoid
- ReLU / Leaky ReLU
- Tanh
- Softmax (for output layer)

### Stage 4 — Loss Functions & Forward Pass ✅
- Mean Squared Error (MSE)
- Binary Cross-Entropy
- Categorical Cross-Entropy
- Full forward pass through the entire network

### Stage 5 — Backpropagation ✅
- Gradient computation via chain rule
- Backprop through each layer
- Gradient clipping to prevent explosion

### Stage 6 — Training & Evaluation ✅
- Stochastic Gradient Descent (SGD) optimizer
- Per-sample training loop with epoch shuffling
- Train/validation split (80/20)
- Accuracy and loss tracking per epoch
- CSV data loader
- Demo: Iris classification (~97% train accuracy, ~93% val accuracy)

## Project Structure

```
neural_network/
├── src/
│   ├── matrix.cpp        # Matrix operations
│   ├── layer.cpp         # Dense layer with activation and backprop
│   ├── network.cpp       # Full network (forward + backward)
│   ├── activations.cpp   # Activation functions
│   ├── loss.cpp          # Loss functions
│   └── data_loader.cpp   # CSV reader / data utils
├── include/
│   ├── matrix.h
│   ├── layer.h
│   ├── network.h
│   ├── activations.h
│   ├── loss.h
│   └── data_loader.h
├── tests/
│   ├── tests.h             # Test helper (check, approx, summary)
│   ├── test_matrix.cpp
│   ├── test_activations.cpp
│   ├── test_loss.cpp
│   └── test_layer.cpp
├── data/
│   └── iris.csv            # UCI Iris dataset (150 samples)
├── main.cpp
├── Makefile
└── README.md
```

## Build & Run

```bash
make          # build
./neural_net  # run training on Iris dataset
make test     # build and run all unit tests
make clean    # remove build artifacts
```

## Constraints

- Language: **C++17**
- No external ML libraries (no TensorFlow, PyTorch, Eigen, etc.)
- Standard library only (`<vector>`, `<cmath>`, `<fstream>`, etc.)

## References

- [3Blue1Brown — Neural Networks series](https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi)
- [Build Your Own Neural Network — codecrafters](https://github.com/codecrafters-io/build-your-own-x?tab=readme-ov-file#build-your-own-neural-network)
- Nielsen, M. — *Neural Networks and Deep Learning* (free online book)
