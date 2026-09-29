#include "FilaEncad.h"
#include "No.h"
#include <iostream>
using namespace std;

FilaEncad::FilaEncad()
{
    inicio = nullptr;
    fim=nullptr;
}
FilaEncad::~FilaEncad()
{
    No *p= inicio;
    while(p != nullptr)
    {
        No *aux = p->getProx();
        delete p;
        p= aux;
    }
}

bool FilaEncad::vazia()
{
    return (inicio == nullptr);
}
void FilaEncad::enfileira(int val)
{
    No *p = new No(val);
    if(vazia())
    {
        inicio = p;
    }
    fim->setProx(p);
    fim = p;
}

int FilaEncad::desenfileira()
{
    if(vazia())
    {
        cout << "ERRO: Fila vazia!" << endl;
        exit(1);
    }
    No *p = inicio;
    inicio = p->getProx();
    if(inicio == nullptr)
        fim = nullptr;
    int val =p->getInfo();
    delete p;
    return val;
}