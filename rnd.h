#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <ctime>   // для функции time()

//------------------------------------------------------------------------------
// rnd.h - содержит генератор рандомных чисел в диапазоне от first до last
//------------------------------------------------------------------------------

class Random {
public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }
    // Генерация рандомного числа в заданном диапазоне
    int Get() {
        return rand() % (last - first + 1) + first;
    }
private:
    int first;
    int last;
};

#endif //__rnd__