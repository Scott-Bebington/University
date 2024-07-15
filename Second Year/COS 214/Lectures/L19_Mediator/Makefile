CXX=g++
CFLAGS=-I. -Wall
TARGET=ChatExample
OBJS= Chatroom.o Chatter.o ChatExample.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)
    
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
    
clean:
	rm -f $(TARGET) $(OBJS)
    
