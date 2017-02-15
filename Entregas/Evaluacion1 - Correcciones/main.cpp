#include <iostream>
#include "Inventario.h"

template<class T>
void pln(T thing) {
    //lazy printing method
    std::cout << thing << std::endl;
}

Inventario& inv = Inventario::getInstance();

void printOptions(){
    cout << "\n\nPick an option" << endl;
    cout << " 1 - Create Game" << endl;
    cout << " 2 - Clone Game" << endl;
    cout << " 3 - Delete Game" << endl;
    cout << " 4 - Undo Delete" << endl;
    cout << " 5 - Search Games" << endl;
    cout << " 6 - Sort Games [Asc]" << endl;
    cout << " 7 - Sort Games [Des]" << endl;
    cout << " 8 - View all games" << endl;
    cout << " q - Quit" << endl;
}


void doPretest(){
    pln(0);
    Videojuego * test1 = Videojuego::factoryMethod<Aventura>();
    Videojuego * test2 = Videojuego::factoryMethod<Aventura>();
    Videojuego * test3 = Videojuego::factoryMethod<Aventura>();

    pln(1);
    test1->setName("test1");
    test2->setName("test2");
    test3->setName("test3");

    test1->setNo_serie(100);
    test2->setNo_serie(101);
    test3->setNo_serie(102);

    pln(2);
    test1->setCosto(10.0);
    test2->setCosto(5.0);
    test3->setCosto(15.0);

    Videojuego * test4 = test1->clonar(105);

    pln(3);
    inv.addGame(test1);
    inv.addGame(test2);
    inv.addGame(test3);
    inv.addGame(test4);

    pln(4);
    inv.print();

    pln(5);
    inv.sortPrice(true);

    pln(6);

    inv.deleteGame(101);

    inv.print();

    pln(7);

    inv.undoDelete();

    inv.print();
}

void create(){
    int tipo = -1;
    pln("Type:\n 1 - Strategy\n 2 - Adventure\n 3 - Learning");
    cin >> tipo;
    Videojuego * temp;
    switch (tipo){
        case 1:
            temp = Videojuego::factoryMethod<Estrategia>();
            break;
        case 2:
            temp = Videojuego::factoryMethod<Aventura>();
            break;
        case 3:
            temp = Videojuego::factoryMethod<Aprendizaje>();
            break;
        default:
            break;
    }
    string nombre;
    pln("Type in name:");
    cin >> nombre;

    int no_serie;
    pln("Type in serial #:");
    cin >> no_serie;

    int rating;
    pln("Type in rating [0-100]:");
    cin >> rating;

    double cost;
    pln("Type in cost:");
    cin >> cost;

    temp->setName(nombre);
    temp->setNo_serie(no_serie);
    temp->setCosto(cost);
    temp->setRating(rating);

    inv.addGame(temp);
}

void clone(){
    pln("Enter Serial # to clone:");
    int temp;
    cin >> temp;
    temp = inv.searchNS(temp);

    if(temp == -1){
        pln("Serial # not found!");
        return;
    }
    int newSN;
    pln("Enter new serial #:");
    cin >> newSN;

    Videojuego * newGame = inv.getIndex(temp)->clonar(newSN);

    inv.addGame(newGame);
}


void deleteGame(){
    pln("Enter Serial # to delete:");
    int temp;
    cin >> temp;

    inv.deleteGame(temp);
}

void seachGame(){

    Videojuego * res = nullptr;

    pln("Seach:");
    pln("  a - by serial number");
    pln("  b - by name");

    char in;
    cin >> in;

    if (in == 'a'){
        int num = 0;
        pln("Enter number to search");
        cin >> num;
        res = inv.search(num);
    } else
    if ( in == 'b') {
        string str = "";
        pln("Enter name to search");
        cin >> str;
        inv.search(str);
    }

    if(res != nullptr){
        pln("Found:");
        res->print();
    }
}

int main() {
    //doPretest();

    char input = 0;

    do{
        printOptions();
        std::cin >> input;

        switch (input){
            case '1':
                create();
                break;
            case '2':
                clone();
                break;
            case '3':
                deleteGame();
                break;
            case '4':
                inv.undoDelete();
                break;
            case '5':
                seachGame();
                break;
            case '6':
                inv.sortPrice(true);
                break;
            case '7':
                inv.sortPrice(false);
                break;
            case '8':
                inv.print();
                break;
            default:
                break;
        }
    }while(input != 'q');

    inv.free();

    return 0;
}