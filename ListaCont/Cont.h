#ifndef CONT_H_INCLUDED
#define CONT_H_INCLUDED

 class Cont
 {
    public:
    Cont(int tam);
    ~Cont();
    int get(int k);
    void set(int k,int val);
    int insereFinal(int k);
    void removeFinal();
    void insereK(int k, int val);
    void removeK(int k);
    int busca(int chave) const;
    int tam() const {return n;}
    private:
    int n;
    void realoca();
    int max;
    int *vet;
    
 };

 #endif