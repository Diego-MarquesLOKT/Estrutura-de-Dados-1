#ifndef PILHACONT_H_INCLUDED
#define PILHACONT_H_INCLUDED

class PilhaCont{
    public:
    PilhaCont(int tam);
    ~PilhaCont();
    int getTopo();
    void empilha(int val);
    int desempilha();
    bool vazia();

    private:
    int max;
    int topo;
    int *vet;
};

#endif