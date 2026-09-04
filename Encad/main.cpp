#include <iostream>
#include "ListaSEncad.h"
using namespace std;
int main()
{
    ListaSEncad lista;
    lista.insere_final(10);
    lista.insere_final(20);
    lista.insere_final(30);
    lista.insere_final(40);
    lista.imprime();
    lista.remove_inicio();
    lista.imprime();
    lista.remove_final();
    lista.imprime();
    lista.remove_posicao(1);
    lista.imprime();
    lista.remove_posicao(8);
    lista.imprime();
    lista.remove_final();
    lista.imprime();
    lista.remove_inicio();
}