#include "lista_circ.h";
using namespace std;

ListaCirc::ListaCirc()
    : inicio(nullptr), fim(nullptr), n(0) {}

// Reaproveita remove_inicio(), que ja trata
// corretamente o religamento do ciclo
ListaCirc::~ListaCirc()
{
    while (n > 0)
        remove_inicio();
}

bool ListaCirc::vazia() { return n == 0; }

void ListaCirc::insere_inicio(int val)
{
    NoDuplo *p = new NoDuplo(val);
    if (n == 0)
    {
        p->setProx(p); // aponta para si mesmo
        p->setAnt(p);
        fim = p;
    }
    else
    {
        p->setProx(inicio);
        p->setAnt(fim);
        inicio->setAnt(p);
        fim->setProx(p);
    }
    inicio = p;
    n = n + 1;
}

void ListaCirc::remove_inicio()
{
    if(n==0) return;

    NoDuplo *p=inicio;
    n--;
    if(n==0)
    {
        inicio = nullptr;
        fim = nullptr;
    }
    inicio = p->getProx();
    inicio->setAnt(fim);
    fim->setProx(inicio);
    
    delete p;
}