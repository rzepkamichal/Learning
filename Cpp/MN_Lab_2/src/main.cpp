#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double binomial(int k, int s){
     
    double result = 1;
    
    if(s > k -s)
        s = k - s;
    
    for(int i = 0; i < s; i++){
        result *= (k-i);
        result /= (i+1);
    }
    
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

double absoluteError(double*& f ,double*& Q, int n){
    
    double absError = 0;
    for(int i = 0; i <= n; i++)
        absError += pow(f[i] - Q[i], 2);
        
    return absError;
    
}

void writeFileResult(const std::string& path, double*& x, double*& f ,double*& Q, int n){
    
    std::ofstream oFile(path);
    
    if(!oFile)
        throw -1;
    
    oFile << "x," << "f(x)," << "Q(x)" << endl;
        
    for(int i = 0; i < n; i++){
        oFile << x[i] << "," << f[i] << "," << Q[i] << endl;
    }
    
    oFile.close();
}

void writeFileCoeffError(const std::string& path, double*& a, int degree, double absError){
    
    std::ofstream oFile(path);
    
    if(!oFile)
        throw -1;
    
    oFile << "i," << "a[i]," << "miara bledu aproksymacji," << endl;
    oFile << " ," << " ," << absError << "," << endl;
        
    for(int i = 0; i <= degree; i++){
        oFile << i << "," << a[i] << "," << endl;
    }
    
    oFile.close();
}

int main(int argc, char* argv[]){
    
   
    int n = stoi(argv[1]);
    int degree = stoi(argv[2]);
    int lowerBoundry = stoi(argv[3]);
    int upperBoundry = stoi(argv[4]);
    std::string outputPathResult = argv[5];
    std::string outputPathCoefficients = argv[6];
    
    double interval = (double)(upperBoundry - lowerBoundry)/n;

    double* x = new double[n+1];
    double* f = new double[n+1];
    double* a = new double[degree + 1];
    double* Q = new double[n+1];
    double absError;

    x[0] = lowerBoundry;
    
    for(int i = 1; i < n + 1; i++){
        x[i] = x[i-1] + interval;
    }
    
    for(int i = 0; i < n + 1; i++){
        f[i] = cos(x[i])*sin(3*x[i]);
    }
    
    for(int i = 0; i < n + 1; i++){
        Q[i] = approx(x[i],lowerBoundry, degree, n + 1, interval, f, a);
    }
    
    absError = absoluteError(f, Q, n);
      
    try{
        writeFileResult(outputPathResult, x, f, Q, n + 1);
        writeFileCoeffError(outputPathCoefficients, a, degree, absError);
        
    }catch(int &e){
        std::cout << "Blad odczytu plikow!" << std::endl;
    }
     
     

    return 0;
}