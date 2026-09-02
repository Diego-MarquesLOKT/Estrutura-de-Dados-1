#ifndef NO_H
#define NO_H

class No{
    public:
    No(int val);
    int getInfo();
    No* getProx();
    void setInfo(int val);
    void setProx(No* p);
    private:
    int info;
    No* prox;
};
#endif