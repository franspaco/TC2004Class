#include<iostream>

using namespace std;

class ArrayNatPerfect;

class Proxy
{
    ArrayNatPerfect& arr;
    int idx;
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
    Proxy(ArrayNatPerfect& arr, int idx) : arr(arr), idx(idx){}
    Proxy& operator = (int value);
    friend ostream& operator<<(ostream&, Proxy&&);
};

class ArrayNatPerfect
{
private:
    int * arr;
    int size;

public:
    friend class Proxy;
    ArrayNatPerfect(int size) : size(size)
    {
        arr = new int[size+1]; //EL MAS 1 ES PARA REDIRIGIR ERRORES
    }
    Proxy operator[](int index)
    {
        if(index < 0 || index >= size)
        {
            cout << "Error: No hay índices negativos" << endl;
            return Proxy(*this, size);
        }
        return Proxy(*this, index);
    }
    friend ostream& operator<<(ostream& os, Proxy&& p);
};

Proxy& Proxy::operator = (int value)
{
        if(is_perfect(value)) //natural perfecto
        {
            arr.arr[idx] = value;
        }
        else
        {
            cout << "Eror no es natural perfecto" << endl;
        }
        return *this;
}

ostream& operator<<(ostream& os, Proxy&& p)
{
    os << p.arr.arr[p.idx];
    return os;
}

int main()
{
    ArrayNatPerfect a(5);
    a[0]=1;
    a[5]= 2;
    a[-1] = -1;
    cout << a[1];

}
