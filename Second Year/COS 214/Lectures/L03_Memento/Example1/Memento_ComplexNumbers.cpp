#include <iostream>

class ComplexNumber;  // Originator


class State {
	public:
		State(double val1, double val2) {
			value[0] = val1;
			value[1] = val2;
		}
		double getFirst() {
	  		return value[0];
  		}
		double getSecond() {
	  		return value[1];
		}
	
	private:
		double value[2];
};

class Memento {
	public:
		virtual ~Memento() {
			delete _state;
			_state = 0;
		}
	private:
		friend class ComplexNumber;

		Memento(double val1, double val2) {
			_state = new State(val1,val2);
  		}
	
		State* _state;
};

class ComplexNumber {  // Originator
	public:
		ComplexNumber() {
			_real = 0;
			_imaginary = 0;
		}
	
		ComplexNumber(double real, double imaginary) {
			_real = real;
			_imaginary = imaginary;
		}
	
		void add(ComplexNumber c) {
			_real = _real + c._real;
			_imaginary = _imaginary + c._imaginary;
		}
	
		void multiply(ComplexNumber c) {
			_real = (_real * c._real) - (_imaginary * c._imaginary);
			_imaginary = (_real * c._imaginary) + (_imaginary * c._real);
	
		}
		double getReal() {
			return _real;
		}
	
		double getImaginary() {
			return _imaginary;
		}
	
		void print(){
			std::cout<<_real<<" + "<<_imaginary<<"i"<<std::endl;
		}
	
		Memento *createMemento() {
			return new Memento(_real,_imaginary);
		}
	
		void reinstateMemento(Memento *mem) {
			State* s = mem->_state;
		
			_real = s->getFirst();
			_imaginary = s->getSecond();
		}

	private:
		double _real;
		double _imaginary;
};

class Store { // Caretaker
	public:
  		void storeMemento(Memento* mem) {
    		_mem = mem;
		}

  		Memento* retreiveMemento(){
    		return _mem;
		}

		~Store() {
    		delete _mem;
  		}
	private:
  	Memento* _mem;
};



int main() {
	Store temp;
	ComplexNumber* one;
	ComplexNumber* two;
	
	one = new ComplexNumber(1.0,2.0); // 1 + 2i
	temp.storeMemento(one->createMemento());
	
	one = new ComplexNumber(3.0,4.0); // 3 + 4i

	
	
	Memento* mem = temp.retreiveMemento();
	two = new ComplexNumber(); // 1 + 2i
	
	two->reinstateMemento(mem); // 1 + 2i
	
	
	one->print();
	two->print();

	one->add(*two);
	
	one->print();
	two->print();

	delete two;
	delete one;

	
	return 0;
}
