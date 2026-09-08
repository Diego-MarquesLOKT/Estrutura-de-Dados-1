#include "no_d.h"
#include "lista_dupla.h"
using namespace std;
#include <iostream>;

ListaDupla::ListaDupla()
{
    inicio = nullptr;
    fim = nullptr;
    n = 0;
}

ListaDupla::~ListaDupla()
{
}

bool ListaDupla::vazia()
{
    return n == 0;
}

void ListaDupla::insere_inicio(int valor)
{
    NoDuplo *novo_no = new NoDuplo(valor);
    if (vazia())
    {
        inicio = novo_no;
        fim = novo_no;
        n++;
        return;
    }
    inicio->setAnt(novo_no);
    novo_no->setProx(inicio);
    inicio = novo_no;
    n++;
}

void ListaDupla::remove_inicio()
{
    if (vazia())
    {
        cout << "Lista vazia" << endl;
        return;
    }
    NoDuplo *p = inicio;
    inicio = inicio->getProx();
    inicio->setAnt(nullptr);
    n--;
    if (n == 0)
    {
        inicio = nullptr;
        fim = nullptr;
    }
}

void ListaDupla::insere_final(int val)
{
    NoDuplo *p = new NoDuplo(val);
    if (n == 0)
    {
        inicio = p; // unico no: e tambem o inicio
    }
    else
    {
        fim->setProx(p);
        p->setAnt(fim);
    }
    fim = p;
    n = n + 1;
}

void ListaDupla::remove_final()
{
    NoDuplo *p = fim;
    fim = p->getAnt();
}

void ListaDupla::remove_final()
{
    if (n == 0)
    {
        cout << "Erro: lista vazia." << endl;
        return;
    }
    NoDuplo *p = fim;
    fim = p->getAnt();
    delete p;
    n = n - 1;
    if (n == 0)
        inicio = nullptr; // lista ficou vazia
    else
        fim->setProx(nullptr);
}

void ListaDupla::imprime()
{
    cout << "[ ";
    NoDuplo *atual = inicio;
    while (atual != nullptr)
    {
        cout << atual->getInfo() << " ";
        atual = atual->getProx();
    }
    cout << " ]";
}

void ListaDupla::imprime_reverso()
{
    cout << "[ ";
    NoDuplo *atual = fim;
    while (atual != nullptr)
    {
        cout << atual->getInfo() << " ";
        atual = atual->getAnt();
    }
    cout << " ]";
}

void ListaDupla::insere_posicao(int pos,int valor)
{
    if(n == 0)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    if (pos < 0 && pos > n)
    {
        cout << "Posicao  invalida" << endl;
        return;
    }
    if (pos == 0)
    {
        insere_inicio(valor);
        return;
    }
    NoDuplo* p = inicio;
    int i = 0;
    while(p !=nullptr && i < pos - 1 )
    {
        p = p->getProx();
        i++;
    }
     if (p == nullptr)
    {
        cout << "Posicao invalida" << endl;
        return;
    }
    NoDuplo* novo = new NoDuplo(valor);
    novo->setProx(p->getProx());
    p->setProx(novo);
    n++;
}