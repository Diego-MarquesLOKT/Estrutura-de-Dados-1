#include "No.h"

No::No(int val)
{
    info = val;
    prox = nullptr;
}

int No::getInfo()
{
    return info;
}

No* No::getProx()
{
    return prox;
}

void No::setInfo(int val)
{
    info = val;
}
void No::setProx(No* p)
{
    prox = p;
}