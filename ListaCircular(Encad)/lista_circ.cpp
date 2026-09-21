#include "lista_circ.h";
using namespace std;
#include <iostream>

ListaCirc::ListaCirc()
    : inicio(nullptr), fim(nullptr), n(0) {}

// Reaproveita remove_inicio(), que ja trata
// corretamente o religamento do ciclo
ListaCirc::~ListaCirc()
{
    while (n != 0)
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

void ListaCirc::removeIntervalo(int a, int b)
{
    if (n == 0)
    {
        return;
    }
    NoDuplo *p = inicio;
    NoDuplo *ant = nullptr;
    NoDuplo *prox = nullptr;
    int qtd = n;
    int cont = 0;
    do
    {
        prox = p->getProx();

        if (p->getInfo() >= a && p->getInfo() <= b)
        {
            // Se p é o único nó restante
            if (n == 1)
            {
                delete p;

                inicio = nullptr;
                fim = nullptr;
                n = 0;

                return;
            }
            ant = p->getAnt();
            ant->setProx(prox);
            prox->setAnt(ant);
            if (p == inicio)
            {
                inicio = prox;
            }
            if (p == fim)
            {
                fim = ant;
            }
            delete p;
            n--;
        }
        p = prox;
        cont++;
    } while (cont < qtd);
}

void ListaCirc::remove_inicio()
{
    if (n == 0)
        return;

    NoDuplo *p = inicio;
    n--;
    if (n == 0)
    {
        inicio = nullptr;
        fim = nullptr;
    }
    inicio = p->getProx();
    inicio->setAnt(fim);
    fim->setProx(inicio);

    delete p;
}

void ListaCirc::imprime()
{
    if (n == 0)
    {
        cout << "Lista vazia." << endl;
        return;
    }
    NoDuplo *p = inicio;
    do
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    } while (p != inicio);
    cout << endl;
}

void ListaCirc::remove_final()
{
    if (n == 0)
        return;
    NoDuplo *p = fim;
    fim = fim->setAnt();
    inicio->setAnt(fim);
    delete p;
    n--;
    if (n == 0)
    {
        inicio = nullptr;
        fim = nullptr;
    }
}