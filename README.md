# Neural Network from Scratch in C++

A neural network implementation built from scratch in C++ without any external ML libraries.
Course project for **Programowanie 2**, Jagiellonian University, 2025/2026.

## Goal

Build a fully functional feedforward neural network capable of learning from data using backpropagation and gradient descent — implemented entirely in C++ using only the standard library.

## Planned Features

### Stage 1 — Matrix & Vector Math
- `Matrix` class with addition, multiplication, transpose
- Element-wise operations, dot product
- Unit tests for correctness

### Stage 2 — Network Architecture
- `Layer` class (fully connected / dense layer)
- Configurable number of neurons per layer
- Weight and bias initialization (random, Xavier)
- Forward pass through a single layer

### Stage 3 — Activation Functions
- Sigmoid
- ReLU / Leaky ReLU
- Tanh
- Softmax (for output layer)

### Stage 4 — Loss Functions & Forward Pass
- Mean Squared Error (MSE)
- Binary Cross-Entropy
- Categorical Cross-Entropy
- Full forward pass through the entire network

### Stage 5 — Backpropagation
- Gradient computation via chain rule
- Backprop through each layer
- Gradient clipping to prevent explosion

### Stage 6 — Training & Evaluation
- Stochastic Gradient Descent (SGD) optimizer
- Mini-batch training loop
- Train/validation split
- Accuracy and loss tracking per epoch
- CSV data loader
- Demo: digit classification on a dataset (e.g. MNIST subset or Iris)

## Project Structure

```
neural_network/
├── src/
│   ├── matrix.cpp        # Matrix operations
│   ├── layer.cpp         # Dense layer
│   ├── network.cpp       # Full network (forward + backward)
│   ├── activations.cpp   # Activation functions
│   ├── loss.cpp          # Loss functions
│   ├── optimizer.cpp     # SGD and variants
│   └── data_loader.cpp   # CSV reader / data utils
├── include/
│   ├── matrix.h
│   ├── layer.h
│   ├── network.h
│   ├── activations.h
│   ├── loss.h
│   ├── optimizer.h
│   └── data_loader.h
├── tests/
│   └── test_matrix.cpp   # Unit tests
├── data/
│   └── iris.csv          # Example dataset
├── main.cpp
├── Makefile
└── README.md
```

## Build & Run

```bash
make
./neural_net
```

## Constraints

- Language: **C++17**
- No external ML libraries (no TensorFlow, PyTorch, Eigen, etc.)
- Standard library only (`<vector>`, `<cmath>`, `<fstream>`, etc.)

## References

- [3Blue1Brown — Neural Networks series](https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi)
- [Build Your Own Neural Network — codecrafters](https://github.com/codecrafters-io/build-your-own-x?tab=readme-ov-file#build-your-own-neural-network)
- Nielsen, M. — *Neural Networks and Deep Learning* (free online book)
