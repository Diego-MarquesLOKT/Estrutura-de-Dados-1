#include "FilaCirc.h"
#include <iostream>;
using namespace std;

int FilaCirc::inc(int ind){
    return (ind + 1) % max;
}

FilaCirc::FilaCirc(int tam)
{
    max = tam;
    n = 0;
    inicio = fim = 0;
    vet = new int[max];
}

FilaCirc::~FilaCirc()
{
    delete [] vet;
}

bool FilaCirc::vazia()
{
    return (n==0);
}

bool FilaCirc::cheia(){
    return (n==max);
}

void FilaCirc::enfileira(int val)
{
    if(cheia())
    {
        cout << "ERRO: Fila Cheia!" << endl;
        return;
    }
    vet[fim] = val;
    fim = inc(fim);
    n = n + 1;
}

int FilaCirc::desenfileira()
{
    if(vazia())
    {
        cout << "ERRO: Fila vazia!" << endl;
        exit(1);
    }
    int val = vet[inicio];
    inicio = inc(inicio);
    n = n -1 ;
    return val;
}

int FilaCirc::getInicio()
{
    if(vazia())
    {
        cout << "ERRO: Fila vazia!" << endl;
        exit(1);
    }
    return vet[inicio];
}