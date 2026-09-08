#include "no_d.h"
using namespace std;

NoDuplo::NoDuplo(int val) : ant(nullptr), info(val), prox(nullptr) {}
 NoDuplo::~NoDuplo() {}
 void NoDuplo::setAnt(NoDuplo *p) { ant = p; }
 void NoDuplo::setProx(NoDuplo *p) { prox = p; }
 void NoDuplo::setInfo(int val) { info = val; }
 NoDuplo *NoDuplo::getAnt() { return ant; }
 NoDuplo *NoDuplo::getProx() { return prox; }
int NoDuplo::getInfo() { return info; }