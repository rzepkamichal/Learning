#include "Sort.h"

void Sort::write(){
    
        std::cout << "Hello from Sort class!" << std::endl;
}



void Sort::quickSort(double*& tab, int len){
    
    if(len < 1)
        return;
   
    double axialKey = *(tab);
    int tmpMinIndex = 0;
    
    for(int i = 0; i < len; i++){
        
        if(*(tab + i) < axialKey){
            
            tmpMinIndex++;
            Util::swap(*(tab + tmpMinIndex), *(tab + i));   
        }
        
    }
    
    Util::swap(*(tab), *(tab + tmpMinIndex));
    
    double* rightTab = tab + tmpMinIndex + 1;
    
    this->quickSort(tab, tmpMinIndex);
    this->quickSort(rightTab, len - tmpMinIndex - 1);
}