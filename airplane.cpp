//------------------------------------------------------------------------------
// airplane.cpp - содержит методы самолёта
//------------------------------------------------------------------------------

#include "transport.h"
#include "airplane.h"

//------------------------------------------------------------------------------
// Ввод параметров из файла
void Airplane::In(ifstream &ifst) {
    ifst >> speed >> distance >> fly_distance >> load_capacity;
}

// Рандомный ввод параметров
void Airplane::InRnd() {
    fly_distance = Transport::rnd20.Get();
    load_capacity = Transport::rnd20.Get();
}

//------------------------------------------------------------------------------
// Вывод в форматируемый поток
void Airplane::Out(ofstream &ofst) {
    ofst << "Airplane: speed = " << speed
         << ", distance = " << distance
         << ", fly distance = " << fly_distance
         << ", load capacity = " << load_capacity
         << ". Optimal time = " << OptimalTime() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Airplane::OptimalTime() {
    return static_cast<double>(fly_distance) / static_cast<double>(speed);
}