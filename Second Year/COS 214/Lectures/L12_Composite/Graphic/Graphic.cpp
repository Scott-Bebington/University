#include <iostream>
#include <list>

// Component
class Graphic {
public:
	/// Print out the Graphic
	virtual void print() = 0;
    
    // Will ensure well-behaved deletion if no anonymous objects.
    virtual ~Graphic(){
        std::cout << "Deleting" << std::endl;
    };
};

// Composite
class CompositeGraphic: public Graphic {
public:
	CompositeGraphic() : Graphic(), _l() {}
	
	/// Add a child
	void addGraphic(Graphic* g) {
		_l.push_back(g);
	}
	
	/// Remove a child
	void removeGraphic(Graphic* g);
	
	void print(){
		// for each child ...
		for (std::list<Graphic*>::iterator it =
				 _l.begin();
				 it != _l.end();
				 ++it)
			(*it)->print(); // ... print it
	}
    
private:
	/// children
	std::list<Graphic*> _l;
};

// Leaf
class Ellipse: public Graphic {
public:
	/// Build an ellipse with the specified
	// coordinates and radius
	Ellipse(int x, int y, unsigned radius)
	: Graphic(), _x(x), _y(y), _r(radius) {}
	
	virtual void print() {
		std::cout << "Ellipse("
		<< _x << ", "
		<< _y << ", "
		<< _r << ")"
		<< std::endl;
	}
	
private:
	int _x;
	int _y;
	unsigned _r;
};

int main(){
  Ellipse* e1 = new Ellipse(42, 51, 69);
  Ellipse* e2 = new Ellipse(16, 64, 86);
  Ellipse* e3 = new Ellipse(1, 33, 7);
  CompositeGraphic* g1 = new CompositeGraphic();
  CompositeGraphic g2;
  g1->addGraphic(e1);
  g1->addGraphic(e2);
  g2.addGraphic(e3);
  g2.addGraphic(g1);
  std::cout<<"g1 = "<<std::endl; 
  g1->print();
  std::cout<<"g2 = "<<std::endl; 
  g2.print();
  
  delete g1;
  delete e3;
  delete e2;
  delete e1;
  
    
	// other memory??  Will not delete anonymous alloctions
    // delete g1;
	// g2 is on the stack.
	return 0;
}
