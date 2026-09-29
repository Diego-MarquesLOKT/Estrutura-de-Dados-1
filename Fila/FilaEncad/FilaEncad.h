#ifndef FILAENCAD_H
#define FILAENCAD_H
#include "No.h"
class FilaEncad {
    public:
    FilaEncad();
    ~FilaEncad();
    int getInicio();
    void enfileira(int val);
    int desenfileira();
    bool vazia();

    private:
    No *inicio;
    No*fim;
};

#endif