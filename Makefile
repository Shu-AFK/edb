CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = edb
SRCS = main.cpp

BUILD_DIR = build
OBJS = $(BUILD_DIR)/$(SRCS:.cpp=.o)

all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

