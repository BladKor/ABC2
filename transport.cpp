//------------------------------------------------------------------------------
// Transport.cpp - содержит процедуры связанные с обработкой обобщенного
// транспорта и создания рандомного транспорта
//------------------------------------------------------------------------------

#include "transport.h"
#include "airplane.h"
#include "ship.h"
#include "train.h"

//------------------------------------------------------------------------------
Random Transport::rnd20(1, 20);
Random Transport::rnd3(1, 3);

Transport* Transport::StaticIn(ifstream &ifst) {
    std::string s;
    ifst >> s;
    Transport* t = nullptr;
    if (s == "airplane") {
        t = new Airplane();
    } else if (s == "ship") {
        ifst >> s;
        if (s == "liner") {
            t = new Liner();
        } else if (s == "tug") {
            t = new Tug();
        } else if (s == "tanker") {
            t = new Tanker();
        } else {
            return nullptr;
        }
    } else if (s == "train") {
        t = new Train();
    } else {
        return nullptr;
    }
    t->In(ifst);
    return t;
}

Transport *Transport::StaticInRnd() {
    auto k = Transport::rnd3.Get();
    Transport* t = nullptr;
    if (k == 1) {
        t = new Airplane();
    } else if (k == 2) {
        k = Transport::rnd3.Get();

        if (k == 1) {
            t = new Liner();
        } else if (k == 2) {
            t = new Tug();
        } else {
            t = new Tanker();
        }
    } else {
        t = new Train();
    }
    t->InRnd();
    return t;
}