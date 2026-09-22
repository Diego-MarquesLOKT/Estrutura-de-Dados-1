#include "No.h"
#include <iostream>
using namespace std;

No::No(int val)
{
    info = val;
    prox = nullptr;
}
int No::getInfo()
{
    return info;
}
No *No::getProx()
{
    return prox;
}
void No::setProx(No *p)
{
    prox = p;
}