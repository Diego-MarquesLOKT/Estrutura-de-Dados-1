#include <iostream>
#include "Cont.h"

using namespace std;

 Cont::Cont(int tam){
    n = 0;
    max = tam;
    vet = new int [max];
 }

 Cont::~Cont()
 {
    delete [] vet;
 }

 int Cont::get(int k)
 {
    if(k < 0 || k >= n)
    {
        cout << "Posicao invalida! Erro: -1" << endl;
        return -1;
    }
    return vet[k];
 }

 void Cont::set(int k,int val)
 {
if(k < 0 || k >= n)
    {
        cout << "Posicao invalida! Erro: -1" << endl;
        exit(-1);
    }
    vet[k] = val;
 }

 int Cont::insereFinal(int k)
 {
    if(n == max)
    {
        cout << "Vetor cheio! Erro -2" << endl;
        return -2;
    }
    vet[n] = val;
    n++;
 }

 void Cont::removeFinal()
 {
    if(n==0)
    {
        cout << "Lista vazia! erro 0" << endl;
        exit(0);
    }
    n--;
 }
void Cont::insereK(int k,int val)
{
    if(k < 0|| k > n)
    {
        cout << "Indice invalido! Erro -3" << endl;
        exit(-3);
    }
if(n == max)
{
    cout << "Lista cheia!" << endl;
    return;
}


    for(int i = n; i > k; i--)
    {
        vet[i] = vet[i -1];
    }
    vet[k]= val;
    n++;
}

void Cont::removeK(int k)
{
     if(k < 0|| k >= n)
    {
        cout << "Indice invalido! Erro -4" << endl;
        exit(-4);
    }
    for(int i = k;i < n;i++)
    {
        vet [i] = vet[i+1];
    }
    n--;
}

int Cont::busca(int val)
{
    for(int i = 0; i < n;i++)
    {
        if(vet[i] == val)
        {
            return i;
        }
    }
    else return -1;
}