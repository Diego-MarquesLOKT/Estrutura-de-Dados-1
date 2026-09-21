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

void ListaDupla::insere_posicao(int pos, int valor)
{
    if (n == 0)
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
    NoDuplo *p = inicio;
    int i = 0;
    while (p != nullptr && i < pos - 1)
    {
        p = p->getProx();
        i++;
    }
    if (p == nullptr)
    {
        cout << "Posicao invalida" << endl;
        return;
    }
    NoDuplo *novo = new NoDuplo(valor);

    p->getAnt()->setProx(novo);
    novo->setAnt(p->getAnt());
    novo->setProx(p);
    p->setAnt(novo);
    n++;
}

void ListaDupla::insere_ordenado(int val)
{
    NoDuplo *novo = new NoDuplo(val);
    if (inicio == nullptr)
    {
        inicio = fim = novo;
        return;
    }

    if (val <= inicio->getInfo())
    {
        novo->setProx(inicio);
        inicio->setAnt(novo);
        inicio = novo;
        return;
    }

    NoDuplo *p = inicio;
    while (p != nullptr || p->getInfo() < val)
    {
        p = p->getProx();
    }
    if (p == nullptr)
    {
        novo->setAnt(fim);
        fim->setProx(novo);
        fim = novo;
    }
    NoDuplo *ant = p->getAnt();
    novo->setAnt(ant);
    novo->setProx(p);
    p->setAnt(novo);
    ant->setProx(novo);
}

int ListaDupla::removeTodos(int val)
{
    
    int cont = 0;
    NoDuplo *p = inicio;
    while (p != nullptr)
    {
        NoDuplo* prox = p->getProx();
      if(p->getInfo() == val)
      {
        NoDuplo * ant = p->getAnt();
        if(ant != nullptr)
        {
            ant->setProx(prox);
        }else
        {
            inicio = prox;
        }
        if(prox != nullptr)
        {
            prox->setAnt(ant);
        }else
        {
            fim = ant;
        }
        delete p;
        n--;
        cont++;
      }
      p= prox;
    }
    return cont;
}   

void ListaDupla::insere(int val)
{
    NoDuplo *novo_no = new NoDuplo(val);

    // Lista vazia
    if (n == 0)
    {
        inicio = novo_no;
        fim = novo_no;
        n++;
        return;
    }

    // Procura a primeira posição cujo valor >= val
    NoDuplo *p = inicio;

    while (p != nullptr && val > p->getInfo())
    {
        p = p->getProx();
    }

    // Inserção no início
    if (p == inicio)
    {
        novo_no->setProx(inicio);
        inicio->setAnt(novo_no);

        inicio = novo_no;

        n++;
        return;
    }

    // Inserção no final
    if (p == nullptr)
    {
        fim->setProx(novo_no);
        novo_no->setAnt(fim);

        fim = novo_no;

        n++;
        return;
    }

    // Inserção no meio
    NoDuplo *p_prev = p->getAnt();

    p_prev->setProx(novo_no);
    novo_no->setAnt(p_prev);

    novo_no->setProx(p);
    p->setAnt(novo_no);

    n++;
}

void ListaDupla::inverte()
{
    NoDuplo * p = inicio;
    if(p != nullptr)
    {
        NoDuplo* prox = p->getProx();
        prox->setAnt(p->getAnt());
        p->setAnt(prox);    
        p = prox;
    }
    NoDuplo *tmp = inicio;
    inicio = fim;
    fim = tmp;
}