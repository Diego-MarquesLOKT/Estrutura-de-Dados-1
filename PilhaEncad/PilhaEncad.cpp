#include "No.h"
#include "PilhaEncad.h"
#include <iostream>
using namespace std;

PilhaEncad::PilhaEncad()
{
    topo = nullptr;
}

PilhaEncad::~PilhaEncad()
{
    No *p = topo;
    while (topo != nullptr)
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

bool PilhaEncad::vazia()
{
    return (topo == nullptr);
}

void PilhaEncad::empilha(int val)
{
    No *p = new No(val);
    p - > setProx(topo);
    topo = p;
}

int PilhaEncad::desempilha()
{
    if (vazia())
    {
        cout << " ERRO : Pilha vazia ! " << endl;
        exit(1);
    }
    No *p = topo;
    topo = p - > getProx();
    int val = p - > getInfo();
    delete p;
    return val;
}

int PilhaEncad::getTopo()
{
    if (vazia())
    {
        cout << " ERRO : Pilha vazia ! " << endl;
        exit(1);
    }
    return topo - > getInfo();
}