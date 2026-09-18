#include <iostream>
#include "Cont.h"

using namespace std;

Cont::Cont(int tam)
{
    n = 0;
    max = tam;
    vet = new int[max];
}

Cont::~Cont()
{
    delete[] vet;
}

int Cont::get(int k)
{
    if (k < 0 || k >= n)
    {
        cout << "Posicao invalida! Erro: -1" << endl;
        return -1;
    }
    return vet[k];
}

void Cont::set(int k, int val)
{
    if (k < 0 || k >= n)
    {
        cout << "Posicao invalida! Erro: -1" << endl;
        exit(-1);
    }
    vet[k] = val;
}

bool Cont::troca(int posicao1, int posicao2)
{
    if (n == 0)
    {
        cout << "Lista vazia!" << endl;
        return false;
    }
    else if (posicao1 >= n || posicao2 >= n || posicao1 < n || posicao2 < n)
    {
        cout << "Fora da lista!" << endl;
        return false;
    }
    int tmp = vet[posicao1];
    vet[posicao1] = vet[posicao2];
    vet[posicao2] = tmp;

    return true;
}

bool Cont::aumentaCapacidade(int novoMax)
{
    if (novoMax <= max)
    {
        cout << "Capacidade inferior ou igual a capacidade anterior" << endl;
        return false;
    }
    int *novo_vet = new int[novoMax];
    for (int i = 0; i < n; i++)
    {
        novo_vet[i] = vet[i];
    }
    delete[] vet;
    max = novoMax;
    vet = novo_vet;
    return true;
}

int Cont::insereFinal(int k)
{
    if (n == max)
    {
        realoca();
    }
    vet[n] = k;
    n++;
}

void Cont::removeFinal()
{
    if (n == 0)
    {
        cout << "Lista vazia! erro 0" << endl;
        exit(0);
    }
    n--;
}
void Cont::insereK(int k, int val)
{
    if (k < 0 || k > n)
    {
        cout << "Indice invalido! Erro -3" << endl;
        exit(-3);
    }
    if (n == max)
    {
        cout << "Lista cheia!" << endl;
        return;
    }

    for (int i = n; i > k; i--)
    {
        vet[i] = vet[i - 1];
    }
    vet[k] = val;
    n++;
}

void Cont::removeTodos(int val)
{
    if (n == 0)
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == val)
        {
            for (int j = i; j < n - 1; j++)
            {
                vet[j] = vet[j + 1];
            }
            cont++;
            n--;
            i--;
        }
    }

    /*
    int j = 0;
        for (int i = 0; i < n; i ++) {
            if ( vet [i ] != val )
            vet [j ++] = vet [i ];
            }
            int removidos = n - j;
            n = j;
            return removidos ;
*/
}

void Cont::rotacionaEsquerda(int p)
{
    if (n == 0)
    {
        return;
    }

    if (p == 0 || p == n)
    {
        return;
    }
    if (p > n)
    {
        p = p % n;
    }

    for (int i = 0; i < p; i++)
    {
        int tmp = vet[0];
        for (int j = 0; j < n - 1; j++)
        {
            vet[j] = vet[j + 1];
        }
        vet[n - 1] = tmp;
    }

    /*
    if (n == 0) return ;
p = p % n ;
if (p == 0) return ;
int * aux = new int[ n ];
for (int i = 0; i < n; i ++)
aux [i ] = vet [( i + p ) % n ];
for (int i = 0; i < n; i ++)
vet [i ] = aux [i ];
delete [] aux ;*/
}

void Cont::removeK(int k)
{
    if (k < 0 || k >= n)
    {
        cout << "Indice invalido! Erro -4" << endl;
        exit(-4);
    }
    for (int i = k; i < n; i++)
    {
        vet[i] = vet[i + 1];
    }
    n--;
}

int Cont::busca(int val)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == val)
        {
            return i;
        }
    }
    return -1;
}

void Cont::concatena(const Cont &outra)
{
    if(n == 0 && outra.n == 0)
    {
        return;
    }
    if(outra.n + n > max )
    {
        realoca();
    }
    int qtd = outra.n;
    for(int i = 0 ; i < qtd;i++)
    {
        vet[n++] = outra.vet[i];
    }
}

void Cont::realoca()
{
    int *novo_vet = new int[2 * max];

    for (int i = 0; i < n; i++)
    {
        novo_vet[i] = vet[i];
    }
    vet = novo_vet;
    max *= 2;
}

void Cont::inverte()
{
    for (int i = 0; i < n / 2; i++)
    {
        int tmp = vet[i];
        vet[i] = vet[n - 1 - i];
        vet[n - 1 - i] = tmp;
    }
}

void Cont::imprime()
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << vet[i];
    }
    cout << endl;
}

int Cont::tamanho()
{
    return n;
}

void Cont::limpa()
{
    n = 0;
}

int Cont::buscaMaior(int val)
{
    for (int i = 0; i < n; i++)
    {
        if (val < vet[i])
        {
            return i;
        }
    }
    return -1;
}
