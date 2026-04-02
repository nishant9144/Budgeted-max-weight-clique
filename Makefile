CXX      = mpic++
CXXFLAGS = -O3 -std=c++17

TARGET = main
SRCS   = main.cpp
HDRS   = graph.hpp bounds.hpp bnb.hpp

# Overridable via: make run NP=8  INPUT=mygraph.txt  OUTPUT=out.txt
NP     ?= 4
INPUT  ?= input.txt
OUTPUT ?= output.txt

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	mpirun -np $(NP) ./$(TARGET) $(INPUT) $(OUTPUT)

clean:
	rm -f $(TARGET)

.PHONY: run clean
