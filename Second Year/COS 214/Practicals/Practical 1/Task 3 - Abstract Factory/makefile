CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: main run clean

main: main.o factory.o openGLFactory.o openGLPrimitive.o openGLWindow.o Primitive.o vulkanWindow.o vulkanFactory.o vulkanPrimitive.o Window.o
	$(CXX) $(CXXFLAGS) -o main main.o factory.o openGLFactory.o openGLPrimitive.o openGLWindow.o Primitive.o vulkanWindow.o vulkanFactory.o vulkanPrimitive.o Window.o

main.o: main.cpp Primitive.h openGLFactory.h Window.h
	$(CXX) $(CXXFLAGS) -c main.cpp

factory.o: factory.cpp factory.h
	$(CXX) $(CXXFLAGS) -c factory.cpp

openGLFactory.o: openGLFactory.cpp openGLFactory.h
	$(CXX) $(CXXFLAGS) -c openGLFactory.cpp	

openGLPrimitive.o: openGLPrimitive.cpp openGLPrimitive.h
	$(CXX) $(CXXFLAGS) -c openGLPrimitive.cpp

openGLWindow.o: openGLWindow.cpp openGLWindow.h
	$(CXX) $(CXXFLAGS) -c openGLWindow.cpp

Primitive.o: Primitive.cpp Primitive.h
	$(CXX) $(CXXFLAGS) -c Primitive.cpp

vulkanWindow.o: vulkanWindow.cpp vulkanWindow.h
	$(CXX) $(CXXFLAGS) -c vulkanWindow.cpp

vulkanFactory.o: vulkanFactory.cpp vulkanFactory.h
	$(CXX) $(CXXFLAGS) -c vulkanFactory.cpp

vulkanPrimitive.o: vulkanPrimitive.cpp vulkanPrimitive.h
	$(CXX) $(CXXFLAGS) -c vulkanPrimitive.cpp

Window.o: Window.cpp Window.h
	$(CXX) $(CXXFLAGS) -c Window.cpp


run:
	./main

clean: 
	rm -f *.o main
