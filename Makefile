CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = neural_net

TEST_BINS = tests/test_matrix tests/test_activations tests/test_loss tests/test_layer

all: $(TARGET)

$(TARGET): main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/%: tests/%.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -Itests -o $@ $^

test: $(TEST_BINS)
	@for t in $(TEST_BINS); do echo "--- $$t ---"; ./$$t; done

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_BINS)

.PHONY: all test clean
