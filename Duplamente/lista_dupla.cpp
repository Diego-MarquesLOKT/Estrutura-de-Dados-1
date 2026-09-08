#include "no_d.h"
#include "lista_dupla.h"
using namespace std;

ListaDupla::ListaDupla()
{
    inicio =nullptr;
    fim = nullptr;
    n=0;


}

ListaDupla::~ListaDupla()
{

}

bool ListaDupla::vazia()
{
    return n==0;
}

void ListaDupla::insere_inicio(int valor)
{
    NoDuplo* novo_no = new NoDuplo(valor);
    if(vazia())
    {
        inicio = novo_no;
        fim = novo_no;
        n++;
        return;
    }
    
}

