# Makefile for the TVC standalone test harness

# Compiler and flags
CXX := g++
CXXFLAGS := -I. -Wall -Werror -std=c++11

# Source files
SRCS := main_test.cpp custom_main.cpp PID.cpp filters.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Target executable
TARGET := tvc_test

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	@./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
