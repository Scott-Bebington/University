# Define the compiler to use
CXX = g++

# Define the flags to use when compiling .cpp files
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Define the command to use when compiling .cpp files
COMPILE = $(CXX) $(CXXFLAGS) -c

# Define the command to use when linking object files
LINK = $(CXX) $(CXXFLAGS)

# Define the source files to compile
SRCS = $(wildcard *.cpp)

# Define the object files to create
OBJS = $(SRCS:.cpp=.o)

# Define the name of the executable to create
EXEC = my_program

# Define the default target
all: $(EXEC) run clean

# Define the rule to create the executable
$(EXEC): $(OBJS)
	$(LINK) $(OBJS) -o $(EXEC)

# Define the rule to compile .cpp files into object files
%.o: %.cpp %.h
	$(COMPILE) $< -o $@

# Define a clean target to remove object files and the executable
clean:
	rm -f $(OBJS)

# Define a run target to execute the program
run:
	./$(EXEC)
