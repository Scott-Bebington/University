#include <iostream>
#include <cmath>

class Number {
  public:
    virtual void print() = 0;
    virtual ~Number() {}; // If not included, modern compilers throw a warning
};

class ComplexNumber : public Number
{
public:
	ComplexNumber() : Number(){
		_real = 0;
		_imaginary = 0;
	};

	ComplexNumber(double real, double imaginary)
	{
		_real = real;
		_imaginary = imaginary;
	};	

	void add(ComplexNumber c)
	{
		_real = _real + c._real;
		_imaginary = _imaginary + c._imaginary;
	}
	
	void multiply(ComplexNumber c)
	{
		_real = (_real * c._real) - (_imaginary * c._imaginary);
		_imaginary = (_real * c._imaginary) + (_imaginary * c._real);
	
	}
	double getReal()
	{
		return _real;
	}
	
	double getImaginary()
	{
		
		return _imaginary;
	}
	
	void print(){
        std::cout<<_real<<" + "<<_imaginary<<"i"<<std::endl;
	}
    
private:
	double _real;
	double _imaginary;
};



class NumberGenerator
{
  public:

    NumberGenerator()
    {
      number = 0;
      cartesian = true;
      value = 0;
      size = 0;
    };

    void toggleCoordSystem() 
    {
      cartesian = !cartesian;
    };

    bool isCartesian() {
      return cartesian;
    };

    
    virtual void setValue(double*,int) = 0;

    Number* nextNumber() {
      number = generateNumber();
      return number;
    };    
    
    virtual ~NumberGenerator() 
    {
      if (number != 0) {
        number = 0;
      }
      if (size != 0) {
        delete [] value;
	  } else {
		  delete value;
	  }
	  value = 0;
    }
  protected:
	virtual Number* generateNumber() = 0;  // Factory Method
	
    double* value;
    int size;
  private:
    bool    cartesian;
    Number* number;
};

class ComplexNumberGenerator : public NumberGenerator 
{
  public:

    ComplexNumberGenerator() : NumberGenerator() { };

    virtual Number* generateNumber() 
    {
      if (size == 0) {
        value = new double[2];
        value[0] = 0;
        value[1] = 0;
        size = 2;
      }
      if (isCartesian())
        return new ComplexNumber(value[0],value[1]);
      else
        return new ComplexNumber(value[0]*cos(value[1]),value[0]*sin(value[1]));
    };

    virtual void setValue(double* arr,int size) {
      if (this->size != 0) {
        delete [] value;
        this->size = 0;
      }
      value = new double[size];
      value[0] = arr[0];
      value[1] = arr[1];
      this->size = size;
    };

};





int main()
{
    double* valueList;

    valueList = new double[2];
    valueList[0] = 3;
    valueList[1] = 8;

	NumberGenerator* factory = new ComplexNumberGenerator();

    Number* one = 0;
	Number* two = 0;
    

   
	factory->setValue(valueList,2);
    one = (factory->nextNumber());
	
    factory->toggleCoordSystem();
    factory->setValue(valueList,2);
    two = (factory->nextNumber());

	one->print();	
    two->print();

    delete one;
    delete two;

	delete factory;
    delete [] valueList;
  
	return 0;
}

/* Note:
 When using older versions of clang, link with clang++ to ensure linking the C++ runtime occurs
 and not the C runtime.
*/
