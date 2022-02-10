#ifndef __ship__
#define __ship__

//------------------------------------------------------------------------------
// ship.h - содержит описание корабля
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "transport.h"

class Ship: public Transport {
public:
    virtual void In(ifstream &ifst);

    virtual void InRnd();

    virtual void Out(ofstream &ofst) = 0;

    virtual double OptimalTime();
protected:
    int displacement;
};

class Liner: public Ship {
    ~Liner() {}

    virtual void Out(ofstream &ofst);
};

class Tug: public Ship {
    ~Tug() {}

    virtual void Out(ofstream &ofst);
};

class Tanker: public Ship {
    ~Tanker() {}

    virtual void Out(ofstream &ofst);
};

#endif //__ship__