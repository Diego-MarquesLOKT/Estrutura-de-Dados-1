#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class No {
    public:
    No(int val);
    int getInfo();
    No* getProx();
    void setProx(No* p);

    private:
    int info;
    No *prox;
}