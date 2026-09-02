#include <iostream>
#include "ListaSEncad.h"
using namespace std;
int main() {
ListaSEncad lista;
lista.imprime();
lista.insere_inicio(20);
lista.imprime();
lista.insere_inicio(10);
lista.imprime();
lista.insere_final(40);
lista.imprime();
lista.insere_posicao(2, 30);
lista.imprime();
lista.insere_posicao(8, 99);
lista.imprime();
cout << "Total: " << lista.totalNos() << '\n';
}