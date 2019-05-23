#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


//funkcja wyznaczajaca wspol. Newtona "k po s"
double binomial(int k, int s){
     
    double result = 1.0;
    
    if(s > k -s)
        s = k - s;
    
    for(int i = 0; i < s; i++){
        result *= (k-i);
        result /= (i+1.0);
    }
    
    return result;
}

//funkcja wyznaczajaca pomocniczy iloczyn r^[s]
double calculateProduct(double r, int s){
    
    double result = 1;
    
    for (int i = 0; i <= s - 1; i++)
        result *= (r - i);
    
    return result;
}

//funkcja wyznaczajaca wartosc wiel. Grama
//k - stopien
//n - liczba punktow
//q - argument
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

//funkcja wyznaczajaca wartosc wspol. s
//j - indeks wspolczynnika
//n - indeks ostatniego wezla
double calculateS(int j, int n){
    
    double sum = 0;
    for(int q = 0; q <= n; q++){
        sum += pow(gramPolyNomial(j, n, q), 2);
    }
    
    return sum;
}

//funkcja wyznaczajaca wartosc wspol. c
//j - indeks wspolczynnika
//n - indeks ostatniego wezla
//f - tablica wartosci funkcji aproksymowanej
double calculateC(int j, int n, double*& f){
    
    
    double sum = 0;
    for(int q = 0; q <= n; q++){
    
        sum += f[q] * gramPolyNomial(j, n, q);
    }
    
    return sum;
}

//funkcja wyznaczajaca przeksztalcenie liniowe x->q
//x - argument,
//x_0 - ograniczenie dolne zbioru argumentow
//h - odleglosc miedzy wezlami
double calculate_q(double x, double x_0, double h){
    return (x-x_0)/h;
}

//funkcja wyznaczajaca wartosc funkcji aproksymujacej
//x - argument
//x_0 - ograniczenie dolne zbioru argumentow
//m - stopien wielomianu aproksymujacego
//n - indeks ostatniego wezla
//h - odleglosc miedzy wezlami
//f - tablica wartosci funkcji aproksymowanej
//a - tablica wspolczynnikow a funkcji aproksymujacej
double approx(double x, double x_0, int m, int n, double h, double*& f, double*& a ){
    
    double sum = 0;
    for(int j = 0; j <= m; j++){
        a[j] = calculateC(j,n,f)/calculateS(j,n);
        sum += a[j] * gramPolyNomial(j, n, calculate_q(x, x_0, h));
    }
    return sum;
}

//funkcja wyznaczajaca wartosc bledu
//f - tablica wartosci funkcji aproksymowanej
//Q - tablica wartosci funkcji aproksymujacej
//n - indeks ostatniego wezla
double absoluteError(double*& f ,double*& Q, int n){

    double absError = 0;
    for(int i = 0; i <= n; i++)
        absError += pow(f[i] - Q[i], 2);
        
    return absError;
    
}

//funkcja zapisujaca wynik do pliku
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

//funkcja zapisujaca tablice wspolczynnikow a i wartosc bledu do pliku
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
    
    //liczba wezlow
    int n = stoi(argv[1]);
    
    //stopien wielomianu
    int degree = stoi(argv[2]);
    
    //dolne i gorne ograniczenie przedzialu
    int lowerBoundry = stoi(argv[3]);
    int upperBoundry = stoi(argv[4]);
    
    //sciezki do plikow
    string outputPathResult = argv[5];//wyniki
    string outputPathCoeffError = argv[6];//wspolczynniki i blad
    
    //odleglosc miedzy pojedynczymi wezlami
    double interval = (double)(upperBoundry - lowerBoundry)/n;

    //tablica przechowujaca wartosci wezlow
    double* x = new double[n+1];
    
    //tablica przechowujaca wartosci funkcji aproksymowanej
    double* f = new double[n+1];
    
    //tablica przechowujaca wspolczynniki a
    double* a = new double[degree + 1];
    
    //tablica przechowujaca wartosci funkci aproksymujacej
    double* Q = new double[n+1];
    
    //wartosc bledu
    double absError;

    //wyznaczenie wartosci wezlow
    x[0] = lowerBoundry;
    for(int i = 1; i < n + 1; i++){
        x[i] = x[i-1] + interval;
    }
    
    //wyznaczenie wartosci zadanej funkcji aproksymowanej
    for(int i = 0; i < n + 1; i++){
        f[i] = cos(x[i])*sin(3*x[i]);
    }
    
    //wyznaczenie wartosci funkcji aproksymujacej
    for(int i = 0; i < n + 1; i++){
        Q[i] = approx(x[i],lowerBoundry, degree, n + 1, interval, f, a);
    }
    
    //wyznaczenie bledu
    absError = absoluteError(f, Q, n);
    
    //zapis wynikow do pliku
    try{
        writeFileResult(outputPathResult, x, f, Q, n + 1);
        writeFileCoeffError(outputPathCoeffError, a, degree, absError);
        
    }catch(int &e){
        cout << "Blad odczytu plikow!" << endl;
    }
    
    return 0;
}