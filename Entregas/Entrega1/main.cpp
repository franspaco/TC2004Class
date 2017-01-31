#include <iostream>

using namespace std;


class Personaje {
private:
    void operator=(Personaje const&);
public:
    virtual void correr() = 0;

    template <class T>
    static Personaje * factoryMethod() {
        T * t =  new T();
        return t;
    }
};

class PersonajeEstatico : public Personaje {
private:
    PersonajeEstatico() {};
    PersonajeEstatico(PersonajeEstatico const&);
public:
    void correr() {}
    static PersonajeEstatico& getInstance() {
        static PersonajeEstatico instance;
        return instance;
    }
};

template <class SubClase>
class ClonPersonaje : public Personaje {
private:
public:
    /*static ClonPersonaje& getInstance() {
        static ClonPersonaje instance;
        return instance;
    }*/

    virtual Personaje* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};

class Principe : public ClonPersonaje<Principe>
{
public:
    void seleccionarArma();
    void atacar();
    void correr()
    {
        cout << "El principe corre rápido" << endl;
    }
};

class Princesa : public ClonPersonaje<Princesa>
{
public:
    void gritar();
    void correr()
    {
        cout << "La princesa corre medio lento" << endl;
    }
};

class Villano : public ClonPersonaje<Villano>
{
public:
    void atacar();
    void atraparPricnesa();
    void correr()
    {
        cout << "El villano no necesita correr" << endl;
    }
};

class VillanoVolador : public ClonPersonaje<VillanoVolador>
{
public:
    void correr()
    {
        cout << "También puede volar" << endl;
    }
};

int main()
{
    Villano v;
    Princesa p;
    Principe pri;

    Personaje* pe = v.clonar();
    pe->correr();

    Personaje * lol = Personaje::factoryMethod<Princesa>();
    lol->correr();

    return 1;
}