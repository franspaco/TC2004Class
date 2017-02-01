
#include <iostream>

class NNP {
private:
  int data;
  bool is_perfect(int inpt){
    if (inpt < 6)
      return false;

    int sum = 1;
    for(int i = 2; i <= (inpt/2); i++){
      if(inpt%i == 0){
        sum += i;
      }
    }
    return sum == inpt;
  }
public:
  int& operator=(int const& inpt){
    if(is_perfect(inpt)){
      data = inpt;
      std::cout << "Success!" << std::endl;
    }else{
      std::cout << "Error: Not a perfect number!" << std::endl;
    }
    return data;
  }
  void test(){
    std::cout << "Test" << std::endl;
  }

  friend std::ostream& operator<<(std::ostream& os, const NNP& thing) {
    os << thing.data;
    return os;
  }
  
};

class ArregloNNP {
private:
  NNP * array;
  NNP trash;
  int size;
public:
  ArregloNNP() {}
  ArregloNNP(int inpt){
    array = new NNP[inpt];
    size = inpt;
  }
  ~ArregloNNP(){
    delete[] array;
  }

  NNP& operator[](int index){
    if(index < 0  || index >= size){
      std::cout << "Error: Array out of bounds!" << std::endl;
      return trash;
    }else{
      return array[index];
    }
  }
};

int main(){
  ArregloNNP a(10);
  a[0] = 1;
  a[1] = 6;
  a[2] = 28;
  a[3] = 25;

  return 0;
}
