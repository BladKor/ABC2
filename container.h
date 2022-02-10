#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "transport.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    int len;
    Container();
    ~Container();

    void In(ifstream &ifst);

    void InRnd(int size);

    void Out(ofstream &ofst);

    void ShakerSort(int size);
private:
    void Clear();

    Transport* storage[10000];
};

#endif //__container__