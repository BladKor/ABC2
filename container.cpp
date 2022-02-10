//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

Container::Container(): len{0} { }

Container::~Container() {
    Clear();
}

void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

void Container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[len] = Transport::StaticIn(ifst)) != 0) {
            len++;
        }
    }
}

void Container::InRnd(int size) {
    while(len < size) {
        if((storage[len] = Transport::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

//сортировка элементов контейнера по убыванию на основании общей функции оптимального времени
void Container::ShakerSort(int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if ((storage[i] -> OptimalTime()) < (storage[i + 1] -> OptimalTime())) {
                    Transport* tmp = storage[i];
                    storage[i] = storage[i + 1];
                    storage[i + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if ((storage[i] -> OptimalTime()) < (storage[i + 1] -> OptimalTime())) {
                Transport* tmp = storage[i];
                storage[i] = storage[i + 1];
                storage[i + 1] = tmp;
                swapped = true;
            }
        }
        ++start;
    }
}