#ifndef CHOCOLATE_H
#define CHOCOLATE_H



class Chocolate {
  public:
    Chocolate();
    void wrap();
  protected:
    virtual void print() = 0;  
    int id_;
    static int total_;
};


class Barone : public Chocolate {
  protected:
    void print();
};

class Tex : public Chocolate {
  protected:
    void print();
};

class Creator {
  public:
    Chocolate* produce();
  protected:
    virtual Chocolate* produceProduct() = 0;
};

class BaroneCreator : public Creator {
  protected:
    Chocolate* produceProduct();
};


class TexCreator : public Creator {
  protected:
    Chocolate* produceProduct();
};

#endif

// Remember to add the virtual destructors
