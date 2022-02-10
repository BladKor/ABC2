//------------------------------------------------------------------------------
// train.cpp - содержит функции обработки поезда
//------------------------------------------------------------------------------

#include "train.h"

void Train::In(ifstream &ifst) {
    ifst >> speed >> distance >> carriage_counter;
}

void Train::InRnd() {
    speed = Transport::rnd20.Get();
    distance = Transport::rnd20.Get();
    carriage_counter = Transport::rnd20.Get();
}

void Train::Out(ofstream &ofst) {
    ofst << "Train: speed = "
         << speed << ", distance = " << distance
         << ", carriage counter = " << carriage_counter
         << ". Optimal time = " << OptimalTime() << "\n";
}

double Train::OptimalTime() {
    return static_cast<double>(distance) / static_cast<double>(speed);
}