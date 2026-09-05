#include <iostream>
#include "ListaSEncad.h"
using namespace std;
ListaSEncad::ListaSEncad()
{
    inicio = nullptr;
    ultimo = nullptr;
    n = 0;
}
// Temporário: a lista ainda está sempre vazia neste checkpoint.
ListaSEncad::~ListaSEncad()
{
    No *p = inicio;
    while (p != nullptr)
    {
        No *proximo = p->getProx();
        delete p;
        p = proximo;
    }
    inicio = nullptr;
}

void ListaSEncad::insere_inicio(int val)
{
    No *novo = new No(val);
    novo->setProx(inicio);
    inicio = novo;
    n++;
    n++;

    if (n == 1)
        ultimo = novo;
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

void ListaSEncad::remove_inicio()
{
    if (inicio == nullptr)
    {
        cout << "Erro: lista vazia.\n";
        return;
    }
    No *alvo = inicio;
    inicio = inicio->getProx();
    delete alvo;
}

void ListaSEncad::remove_final()
{
    if (inicio == nullptr)
        return;
    if (inicio->getProx() == nullptr)
    {
        delete inicio;
        inicio = nullptr;
        return;
    }
    No *p = inicio;
    while (p->getProx()->getProx() != nullptr)
        p = p->getProx();
    delete p->getProx();
    p->setProx(nullptr);
}

void ListaSEncad::remove_posicao(int k)
{
    if (k < 0)
    {
        cout << "Valor invalido" << endl;
        return;
    }
    if (k == 0)
    {
        remove_inicio();
        return;
    }
    if (inicio == nullptr || inicio->getProx() == nullptr)
    {
        cout << "Lista no final/vazia" << endl;
        return;
    }
    No *p = inicio;
    No *alvo = p->getProx();
    int i = 0;
    while (p->getProx() != nullptr && i < k - 1)
    {
        p = p->getProx();
        i++;
    }
    if (p->getProx() == nullptr)
    {
        cout << "Endereço invalido" << endl;
        return;
    }
    alvo = p->getProx();
    p->setProx(alvo->getProx());
    delete alvo;
}

void ListaSEncad::insere_posicao(int k, int val)
{
    if (k < 0)
    {
        cout << "Posicao  invalida" << endl;
        return;
    }
    if (k == 0)
    {
        insere_inicio(val);
        return;
    }
    No *p = inicio;
    int i = 0;
    while (p != nullptr && i < k - 1)
    {
        p = p->getProx();
        i++;
    }
    if (p == nullptr)
    {
        cout << "Posicao invalida" << endl;
        return;
    }
    No *novo = new No(val);
    novo->setProx(p->getProx());
    p->setProx(novo);
}

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