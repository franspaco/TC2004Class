

class Base {

};

class SubClase : public Base {
public:
  Base* clone(){
    return this;
  }
};

int main(){
  
  return 0;
}
