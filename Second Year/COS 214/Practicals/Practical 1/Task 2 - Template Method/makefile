CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: client run clean

client: client.o consumer.o odataConsumer.o jsonConsumer.o consumerCreator.o
	$(CXX) $(CXXFLAGS) -o client client.o consumer.o odataConsumer.o jsonConsumer.o consumerCreator.o

client.o: client.cpp consumer.h consumerCreator.h odataConsumer.h jsonConsumer.h
	$(CXX) $(CXXFLAGS) -c client.cpp

consumer.o: consumer.cpp consumer.h
	$(CXX) $(CXXFLAGS) -c consumer.cpp

odataConsumer.o: odataConsumer.cpp odataConsumer.h consumer.h
	$(CXX) $(CXXFLAGS) -c odataConsumer.cpp

jsonConsumer.o: jsonConsumer.cpp jsonConsumer.h consumer.h
	$(CXX) $(CXXFLAGS) -c jsonConsumer.cpp

consumerCreator.o: consumerCreator.cpp consumerCreator.h consumer.h
	$(CXX) $(CXXFLAGS) -c consumerCreator.cpp

run:
	./client

clean: 
	rm -f *.o client
