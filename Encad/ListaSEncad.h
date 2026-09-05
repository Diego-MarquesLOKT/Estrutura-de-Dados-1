#ifndef LISTASENCAD_H
#define LISTASENCAD_H
#include "No.h"

class ListaSEncad
{
public:
    ListaSEncad();
    ~ListaSEncad();
    void insere_inicio(int val);
    void insere_final(int val);
    void insere_posicao(int k, int val);
    void remove_inicio();
    void remove_final();
    void remove_posicao(int k);
    No *busca(int val);
    int totalNos();
    void imprime();
    void insere_ordenado(int val);
    int soma();

private:
    No *inicio;
    No *ultimo;
    int n;
};
#endif