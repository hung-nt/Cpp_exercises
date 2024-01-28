# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall

# Executable name
EXEC := main

# Source files
SRCS := main.cpp Khoa.cpp SinhVien.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(EXEC)
	./$(EXEC)

# Clean
clean:
	rm -f $(OBJS) $(EXEC)