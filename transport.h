#ifndef __transport__
#define __transport__

//------------------------------------------------------------------------------
// transport.h - содержит описание обобщающей транспорт
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"

class Transport {
protected:
    static Random rnd20;
    static Random rnd3;
    int speed, distance;
public:
    virtual ~Transport() {}
    // Ввод
    static Transport *StaticIn(ifstream &ifdt);
    // Ввод
    virtual void In(ifstream &ifdt) = 0;
    // Рандомный ввод
    static Transport *StaticInRnd();
    // Виртуальный метод ввода
    virtual void InRnd() = 0;
    // Вывод
    virtual void Out(ofstream &ofst) = 0;
    // Вычисление оптимального времени
    virtual double OptimalTime() = 0;

};


#endif //__transport__