#include <iostream>
#include "ListaSEncad.h"
using namespace std;
int main()
{
    ListaSEncad lista;
    lista.insere_ordenado(20);
    lista.insere_ordenado(10);
    lista.insere_ordenado(40);
    lista.insere_ordenado(30);
    lista.insere_ordenado(20);
    lista.imprime();
    cout << "Total: " << lista.totalNos() << '\n';
}