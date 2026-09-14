#ifndef CONT_H_INCLUDED
#define CONT_H_INCLUDED

 class Cont
 {
    public:
    Cont(int tam);
    ~Cont();
    int get(int k);
    bool troca(int pos1,int pos2);
    void set(int k,int val);
    bool aumentaCapacidade(int novoMax); 
    int insereFinal(int k);
    void removeFinal();
    void insereK(int k, int val);
    void removeK(int k);
    int busca(int chave);
    int tam() const {return n;}
    private:
    int n;
    void realoca();
    int max;
    int *vet;
    
 };

 #endif