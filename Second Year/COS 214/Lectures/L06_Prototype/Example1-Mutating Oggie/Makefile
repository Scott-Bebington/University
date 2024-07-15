CXX=g++
CFLAGS=-I. -Wall
TARGET=TestOrganism
OBJS= Cell.o Organism.o TestOrganism.o  

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)
    
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
    
clean:
	rm -f $(TARGET) $(OBJS)
    