
#include "PilhaCont.h"
#include <iostream>;
using namespace std;
PilhaCont::PilhaCont(int tam)
{
    max = tam;
    topo = -1;
    vet = new int[max];
}

PilhaCont::~PilhaCont()
{
    delete[] vet;
}

bool PilhaCont::vazia()
{
    return (topo == -1);
}

void PilhaCont::empilha(int val)
{
    if (topo == (max - 1))
    {
        cout << "ERRO: Pilha cheia!" << endl;
    }
    topo = topo + 1;
    vet[topo] = val;
}

int PilhaCont::desempilha()
{
    if (vazia())
    {
        cout << "ERRO: Lista vazia!!" << endl;
        exit(1);
    }
    int val = vet[topo];
    topo = topo - 1;
    return val;
}

int PilhaCont::getTopo()
{
    if (vazia())
    {
        cout << " ERRO : Pilha vazia ! " << endl;
        exit(1);
    }
    return vet[topo];
}