
#include <iostream>

class Product {
public:
    virtual void operacion1() = 0;
    virtual void operacion2() = 0;

    template <class T>
    static Product * factoryMethod() {
      T * t =  new T();
      t->operacion1();
      t->operacion2();
      return t;
    }
};

class Producto1 : public Product {
public:
  void operacion1() {
      std::cout << "Estoy en operacion 1 Prod 1" << std::endl;
  }
  void operacion2() {
      std::cout << "Estoy en operacion 2 Prod 1" << std::endl;
  }
};

class Producto2 : public Product {
public:
   void operacion1() {
      std::cout << "Estoy en operacion 1 Prod 2" << std::endl;
  }
  void operacion2() {
      std::cout << "Estoy en operacion 2 Prod 2" << std::endl;
  }
};

int main () {
  Product * p1 = Product::factoryMethod<Producto1>();
  Product * p2 = Product::factoryMethod<Producto2>();
  return 0;
}
