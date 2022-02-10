#ifndef __train__
#define __train__

//------------------------------------------------------------------------------
// train.h - содержит описание поезда
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "transport.h"

class Train: public Transport {
public:
    virtual ~Train() {}
    // Ввод параметров из файла
    virtual void In(ifstream &ifst);
    // Рандомный ввод
    virtual void InRnd();
    // Вывод
    virtual void Out(ofstream &ofst);
    // Вычисление оптимального времени
    virtual double OptimalTime();
private:
    int carriage_counter;
};

#endif //__train__