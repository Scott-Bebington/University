#include <iostream>

using namespace std;

class Shape {
  public:
    Shape() {
      id_ = total_++;
    }
    //virtual double perimeter() = 0; // To be implemented
	//virtual double area() = 0; // To be implemented
    virtual void draw() = 0;
    virtual ~Shape() {};
  protected:
    int id_;
    static int total_;
};

int Shape::total_ = 0;

class AngularShape : public Shape {
  public:
    void draw() {
      cout << "Angular Shape " << id_ << ": draw" << endl;
    }
    virtual ~AngularShape() {};
};

class RoundedShape : public Shape {
  public:
    void draw() {
      cout << "Rounded Shape " << id_ << ": draw" << endl;
    }
    virtual ~RoundedShape() {};
};

class Circle : public RoundedShape {
  public:
    void draw() {
      RoundedShape::draw();
      cout << "circle " << id_ << ": draw" << endl;
    }
};
class Square : public AngularShape {
  public:
    void draw() {
      AngularShape::draw();
      cout << "square " << id_ << ": draw" << endl;
    }
};
class Ellipse : public RoundedShape {
  public:
    void draw() {
      RoundedShape::draw();
      cout << "ellipse " << id_ << ": draw" << endl;
    }
};
class Rectangle : public AngularShape {
  public:
    void draw() {
      AngularShape::draw();
      cout << "rectangle " << id_ << ": draw" << endl;
    }
};

class Factory {
  public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
    virtual ~Factory() {};
};

class BoxShapeFactory : public Factory {
  public:
    Shape* createCurvedInstance() {
      return new Circle;
    }
    Shape* createStraightInstance() {
      return new Square;
    }
};

class ElongatedShapeFactory : public Factory {
  public:
    Shape* createCurvedInstance()   {
      return new Ellipse;
    }
    Shape* createStraightInstance() {
      return new Rectangle;
    }
};

int main() {
  Factory** factory  = new Factory*[2];
  factory[0] = new BoxShapeFactory;
  factory[1] = new ElongatedShapeFactory;

  Shape* shapes[4];

  shapes[0] = factory[0]->createCurvedInstance();   
  shapes[1] = factory[0]->createStraightInstance();
  shapes[2] = factory[1]->createCurvedInstance();   
  shapes[3] = factory[1]->createStraightInstance();

  for (int i=0; i < 4; i++) {
    shapes[i]->draw();
  }

  for (int i=0; i < 4; i++) {
    delete shapes[i];
  }

  for (int i=0; i < 2; i++) {
    delete factory[i];
  }
  delete [] factory;

  return 0;

}
