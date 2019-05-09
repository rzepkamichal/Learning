#include <iostream>
#include <cmath>
using namespace std;
int factorial(int arg){

    if(arg == 0 || arg == 1)
        return 1;
    
    int result = arg;
    for(int i = arg - 1; i > 1; i--){
        result *= i;
    }
    
    return result;
}

int binomial(int k, int s){
   
    return factorial(k)/(factorial(s)*factorial(k-s));
    
}
int calculateProduct(int r, int s){
    
    int result = 1;
    
    for(int i = 1; i <= s; i++){
        result *= r-i + 1;
    }
    
    return result;
}

double gramPolyNomial(int degree, int n, int q){
 
    int coefficient = 1;
    double sum = 0;
    for(int i = 0; i <= degree; i++){
        
        
        sum += coefficient * binomial(degree,i) * binomial(degree + i, i)
            * (calculateProduct(q,i)/calculateProduct(n,i));
            
        //std::cout << "Iteracja: " << i <<std::endl;
        //std::cout << coefficient * binomial(degree,i) * binomial(degree + i, i) << std::endl;
        coefficient *= -1;
    }
    
    
    return sum;   
}

double calculateS(int j, int n){
    
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum+= gramPolyNomial(j, n, i) * gramPolyNomial(j, n, i);
    }
    
    return sum;
}

double calculateC(int j, int n, double*& f){
    
    
    int sum = 0;
    for(int i = 0; i <= n; i++){
    
        sum+= *(f+i) * gramPolyNomial(j, n, i);
    }
    
    return sum;
}

double calculate_q(double x, double x_0, double h){
    return (x-x_0)/h;
}

double approx(double x, double x_0, int degree, int n, double h, double*& f, double*& a ){
    

    double sum = 0;
    
    for(int j = 0; j <= degree; j++){
        
        *(a + i) = (double)(calculateC(j,n, f)/calculateS(j,n));
        sum += (*(a+i)) * gramPolyNomial(degree, n, calculate_q(x, x_0, h));
    }
   
    return sum;
}

int main(){
    
    int n = 49;
    int degree = 5;
    double* x = new double[n+1];
    double* f = new double[n+1];
    double* a = new double[degree + 1];
    
    for(int i = 0; i < n + 1; i++){
        
        //std::cout << (double) 4/(n-1) << std :: endl;

        *(x+i) = -2 + (i * (double)4/n);
    }
    
    
    for(int i = 0; i < n + 1; i++){
        *(f+i) = cos(*(x+i))*sin(3*(*(x+i)));
    }
    
    
    double result;
    result = approx(2, -2, degree, n, (double)4/(n-1), f);
    
    std::cout << result << std::endl;
    
    /*
    for(int i = 0; i < n; i++){
        std::cout << *(x+i) << ", " << *(f+i) << std ::endl;
    }
    */
    //std::cout << calculateProduct(3,1) << std::endl;
    //std::cout << gramPolyNomial(0, 10, 20) << std::endl;
    
    return 0;
}