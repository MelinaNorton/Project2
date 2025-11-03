# ===== Simple Makefile =====
CXX       := g++
CXXFLAGS  := -Wall -std=c++17
SRC_DIR   := strategyPattern
BIN       := $(SRC_DIR)/app

# Add more .cpps here if needed
SRCS := $(SRC_DIR)/main.cpp

.PHONY: all clean run

all: $(BIN)

$(BIN): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

# Optional: quick runner (uses ARGS verbatim, but you can just run the binary yourself)
run: $(BIN)
	@$(BIN) $(ARGS)

clean:
	@$(RM) $(BIN)
