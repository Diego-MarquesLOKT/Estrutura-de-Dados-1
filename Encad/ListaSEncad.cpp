#include <iostream>
#include "ListaSEncad.h"
using namespace std;
ListaSEncad::ListaSEncad()
{
    inicio = nullptr;
}
// Temporário: a lista ainda está sempre vazia neste checkpoint.
ListaSEncad::~ListaSEncad() {}

void ListaSEncad::insere_inicio(int val)
{
    No *novo = new No(val);
    novo->setProx(inicio);
    inicio = novo;
}

void ListaSEncad::insere_final(int val)
{
    No *novo = new No(val);
    if (inicio == nullptr)
    {
        inicio = novo;
        return;
    }
    No *p = inicio;
    while (p->getProx() != nullptr)
        p = p->getProx();
    p->setProx(novo);
}

void ListaSEncad::insere_posicao(int k,int val
{
    
})

int ListaSEncad::totalNos()
{
    int cont = 0;
    No *p = inicio;
    while (p != nullptr)
    {
        cont++;
        p = p->getProx();
    }
    return cont;
}

void ListaSEncad::imprime()
{
    No *p = inicio;
    cout << "[ ";
    while (p != nullptr)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
    cout << " ]\n";
}

No *ListaSEncad::busca(int val)
{
    No *p = inicio;
    while (p != nullptr)
    {
        if (p->getInfo() == val)
            return p;
        p = p->getProx();
    }
    return nullptr;
}

int ListaSEncad::soma()
{
    No *p = inicio;
    int soma = 0;
    while (p != nullptr)
    {
        soma += p->getInfo();
        p = p->getProx();
    }
    return soma;
}