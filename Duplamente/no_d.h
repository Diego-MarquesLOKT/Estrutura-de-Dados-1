#ifndef NO_D_H
#define NO_D_H

class NoDuplo
{
public:
    NoDuplo(int val);
    ~NoDuplo();
    void setAnt(NoDuplo *p);
    void setProx(NoDuplo *p);
    void setInfo(int val);
    NoDuplo *getAnt();
    NoDuplo *getProx();
    int getInfo();

private:
    NoDuplo *ant;  // ponteiro para o anterior
    int info;      // informacao
    NoDuplo *prox; // ponteiro para o proximo
};

#endif;