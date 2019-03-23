#include <iostream>
#include <stdlib.h>
#include <time.h>   
#include "Sort.h"

//#include "Util.h"
using namespace std;

int main(){
    
        srand(time(NULL));
        Sort sorter;
        int size = 5;   
        
        double* tab = new double[size];
        Util::generateRandomArray(tab, size, -30, 30);
        
        
        
        sorter.quickSort(tab, size);
        
        for (int i = 0; i < size; i++){
            cout << tab[i] << endl;
        }
        
        delete[] tab;
        return 0;
}