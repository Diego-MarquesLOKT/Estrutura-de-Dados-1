#include "No.h"
#include "PilhaEncad.h"
#include <iostream>
using namespace std;

PilhaEncad::PilhaEncad()
{
    topo = nullptr;
}

PilhaEncad::~PilhaEncad()
{
    No *p = topo;
    while (topo != nullptr)
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

bool PilhaEncad::vazia()
{
    return (topo == nullptr);
}