#include <iostream>
#include <cmath>
#include <fstream>
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

double binomial(int k, int s){
 
    double result = factorial(k)/(factorial(s)*factorial(k-s)); 
    return result;
    
}
double calculateProduct(double r, int s){
    
    double result = 1;
    
    for (int i = 0; i <= s - 1; i++)
        result *= (r - i);
    
    
    return result;
}

double gramPolyNomial(int k, int n, double q){
 
    double coefficient = 1;
    double result = 0;
    for(int s = 0; s <= k; s++){
        
        
        result += coefficient * binomial(k,s) * binomial(k + s, s)
            * (calculateProduct(q,s)/calculateProduct(n,s));
            
        coefficient *= -1;
    }
    
    return result;   
}

double calculateS(int j, int n){
    
    double sum = 0;
    for(int q = 0; q <= n; q++){
        sum += pow(gramPolyNomial(j, n, q), 2);
    }
    
    return sum;
}

double calculateC(int j, int n, double*& f){
    
    
    double sum = 0;
    for(int q = 0; q <= n; q++){
    
        sum += f[q] * gramPolyNomial(j, n, q);
    }
    
    return sum;
}

double calculate_q(double x, double x_0, double h){
    return (x-x_0)/h;
}

double approx(double x, double x_0, int m, int n, double h, double*& f, double*& a ){
    

    double sum = 0;
    
    for(int j = 0; j <= m; j++){
        
        a[j] = calculateC(j,n,f)/calculateS(j,n);
        sum += a[j] * gramPolyNomial(j, n, calculate_q(x, x_0, h));
    }
   
    return sum;
}

void writeToFile(const std::string& path, double*& x, double*& f ,double*& results, int n){
    
    std::ofstream oFile(path);
    
    if(!oFile)
        throw -1;
    
    oFile << "x," << "f(x)," << "Q(x)" << endl;
        
    for(int i = 0; i < n; i++){
        oFile << x[i] << "," << f[i] << "," << results[i] << endl;
    }
    
    oFile.close();
}

int main(int argc, char* argv[]){
    
   
    
    int n = stoi(argv[1]);
    int degree = stoi(argv[2]);
    int lowerBoundry = stoi(argv[3]);
    int upperBoundry = stoi(argv[4]);
    std::string outputPath = argv[5];
    
    double interval = (double)(upperBoundry - lowerBoundry)/n;
    
    double* x = new double[n+1];
    double* f = new double[n+1];
    double* a = new double[degree + 1];
    double* results = new double[n+1];

   
 
    x[0] = lowerBoundry;
    
    for(int i = 1; i < n + 1; i++){
        
        x[i] = x[i-1] + interval;
    }
    
    
    for(int i = 0; i < n + 1; i++){
        f[i] = cos(x[i])*sin(3*x[i]);
        //*(f+i) = sin(*(x+i))*sin(2*(*(x+i)));
    }
    
    for(int i = 0; i < n + 1; i++){
        results[i] = approx(x[i],lowerBoundry, degree, n + 1, interval, f, a);
    }
    
    
    writeToFile(outputPath, x, f, results, n + 1);

    return 0;
}