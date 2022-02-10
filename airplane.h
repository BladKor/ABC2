#ifndef __airplane__
#define __airplane__

//------------------------------------------------------------------------------
// airplane.h - содержит описание самолёта
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "transport.h"

class Airplane: public Transport {
public:
    virtual ~Airplane() {}

    virtual void In(ifstream &ifst);

    virtual void InRnd();

    virtual void Out(ofstream &ofst);

    virtual double OptimalTime();
private:
    int fly_distance, load_capacity;
};

#endif //__Airplane__