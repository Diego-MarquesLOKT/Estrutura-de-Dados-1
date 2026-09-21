#ifndef LISTA_CIRC_H
#define LISTA_CIRC_H
#include "no_d.h"
class ListaCirc
{
     public :  
     ListaCirc();
     ~ListaCirc();
     bool vazia();
     void insere_inicio(int val);
     void remove_inicio();
     void insere_final(int val);
     void remove_final();
     void imprime();
     void removeIntervalo(int a,int b);
     private:  
    NoDuplo *inicio;
     NoDuplo *fim;
     int n;
    
};

#endif