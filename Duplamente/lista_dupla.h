#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#include "no_d.h"
class ListaDupla
{
public:
     ListaDupla();
    ~ListaDupla();
    bool vazia();
    bool busca(int val);
    void insere_inicio(int val);
    void remove_inicio();
    void insere_final(int val);
    void remove_final();
    void imprime();
    void imprime_reverso();
    void insere_posicao(int pos,int valor);
    void insere(int val);
    void inverte();
    void insere_ordenado(int val);
    int removeTodos(int val);
    void inverte();
private:
     NoDuplo *inicio;
    NoDuplo *fim;
    int n;
};

#endif;