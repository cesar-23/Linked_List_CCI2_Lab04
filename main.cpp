#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
    LinkedList mylista;
    //Llenamos nuestra lista con valores desordenados
    mylista.Insert(15);
    mylista.Insert(4);
    mylista.Insert(6);
    mylista.Insert(9);
    mylista.Insert(23);
    mylista.Insert(2);
    mylista.Insert(7);
    mylista.Insert(5);
    mylista.Insert(20);
    mylista.Insert(11);
    //salida
    cout<<"Sobrecarga del operador (<<)\n";
    cout<<mylista;
    cout<<"\n";
    cout<<"Metodo remove(Por posicion) impreso mediante metodo print()\n";
    mylista.Remove(5);
    mylista.print();
    
    return 0;
}