#ifndef FILACIRC_H
#define FILACIRC_H

class FilaCirc{
    public:
    FilaCirc(int tam);
    ~FilaCirc();
    int getInicio();
    void enfileira(int val);
    int desenfileira();
    bool vazia();
    bool cheia();
    private:
    int max;
    int inicio;
    int fim;
    int n;
    int *vet;
    int inc(int ind);
};

#endif