#include "Util.h"

void Util::swap(double &arg1, double &arg2){
    
    int tmp = arg1;
    arg1 = arg2;
    arg2 = tmp;
}

void Util::generateRandomArray(double*& tab, int len, double min, double max){
    
    for(int i = 0; i < len; i++){
        *(tab + i) = rand() % (int)(max - min) + min;
    }
}
