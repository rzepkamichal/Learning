
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 * funkcja wyznacza elementy macierzy L i U za pomoca algorytmu Doolittle'a
 * @param n - rzad ukladu rownan
 * @param A - wskaznik na tablice przechowujaca elementy macierzy A
 * @param B - wskaznik na tablice przechowujaca elementy wektora B
 * @param L - wskaznik na tablice, do ktorej zostana zapisane elementy macierzy L
 * @param U - wskaznik na tablice, do ktorej zostana zapisane elementy macierzy U
 */
void functionB(int n, double **& A, double*& B, double **& L, double **& U){
    //wyznaczenie wiersza 1 macierzy U
    for (int j = 1; j <= n; j++)
        U[1][j] = A[1][j];

    //zabezpieczenie przed dzieleniem przez 0
    if (U[1][1] == 0)
        throw -1;
    else{
        
        //wyznaczenie kolumny 1 macierzy L
        for (int j = 2; j <= n; j++)
            L[j][1] = A[j][1] / U[1][1];
    }
    
    //przechowanie sum w poszczegolnych iteracjach dla U i L
    double sumU;
    double sumL;
    
    //wyznaczenie pozostalych elementow macierzy U i L
    for (int i = 2; i <= n; i++){
        
        //U
        for (int j = i; j <= n; j++){           
            sumU = 0;
            for (int k = 1; k <= i - 1; k++)
                sumU += L[i][k] * U[k][j];
            U[i][j] = A[i][j] - sumU;
        }
        
        //L
        for (int j = i + 1; j <= n; j++){       
            sumL = 0;
            for (int k = 1; k <= i - 1; k++)
                sumL += L[j][k] * U[k][i];
            
            //zabezpieczenie przed dzieleniem przez 0
            if (U[i][i] == 0)                               
                throw - 1;
            else
                L[j][i] = (A[j][i] - sumL) / U[i][i];
        }
    }
}

/**
 * funkcja rozwiazuje rownania macierzowe LY = B oraz  UX = Y
 * @param n - rzad ukladu rownan
 * @param A - wskaznik na tablice przechowujaca elementy macierzy A
 * @param B - wskaznik na tablice przechowujaca elementy wektora B
 * @param L - wskaznik na tablice przechowujaca elementy macierzy L
 * @param U - wskaznik na tablice przechowujaca elementy macierzy U
 * @param X - wskaznik na tablice przechowujaca wyznaczone elementy wektora X
 * @param Y - wskaznik na tablice przechowujaca wyznaczone elementy wektora Y
 */
void functionC(int n, double**& A, double*& B, double**& L, double**& U, double*& X, double*& Y) {

    //inicjalizacja pierwszego elementu wektora Y
    Y[1] = B[1];

    //przechowuje sumy wyliczane w kolejnych iteracjach
    double sum;

    //wyznaczenie pozostalych elementow wektora Y
    for(int i = 2; i <= n; i++){
        sum = 0;
        for(int k =1; k <= i-1; k++){
            sum += L[i][k] * Y[k];
        }
        Y[i] = B[i] - sum;
    }

    //inicjalizacja ostatniego elementu wektora X
    X[n] = Y[n] / U[n][n];

    //wyznaczenie pozostalych elementow wektora X
    for(int i = n-1; i >= 1; i--){
        sum = 0;
        for(int k = i + 1; k <= n; k++){
            sum += U[i][k] * X[k];
        }

        X[i] = (Y[i] - sum)/U[i][i];
    }
}

/**
 * odczytanie macierzy A i wektora B z pliku
 * @param n - rzad ukladu rownan
 * @param A - wskaznik na tablice przechowujaca elementy macierzy A
 * @param B - wskaznik na tablice przechowujaca elementy macierzy A
 * @param path - sciezka do pliku wejsciowego
 */
void readFileInput(int n, double**& A, double*& B, const std::string& path){
    

    ifstream iFile;

    iFile.open(path);

    if(!iFile){
        throw -1;
    }

    string tmpLine;

    int i = 1;
    while(getline(iFile,tmpLine)){

        stringstream tmpStream(tmpLine);
        string buff;


        for(int j = 1; j <=n+1; j++){
            tmpStream >> buff;
            if(j == n+1){
                B[i] = stod(buff);
            }else {
                A[i][j] = stod(buff);
            }
        }
        i++;
    }
    
    iFile.close();
}

void saveToFile(int n, double**& A, double*& B, double**& L, double**& U, double *& X, double *& Y, std::ofstream & oFile){
    
    //generowanie raportu do pliku
    int width = 20;
    
    oFile << "Macierz A:" << endl << endl;
    for(int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) {
            oFile << setw(width) << A[i][j] ;
        }
        oFile << endl;
    }
    
    oFile << endl << endl;
    oFile << "----------------------------------------------------------" << endl;

    oFile << "Wektor B:" << endl << endl;
    for(int i = 1; i <= n; i++){
        oFile << setw(width) << B[i];
    }

    oFile << endl << endl;
    oFile << "----------------------------------------------------------" << endl;

    oFile << "Macierz L:" << endl << endl;
    for(int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) {
            oFile << setw(width) << L[i][j];
        }
        oFile << endl;
    }
    oFile << endl << endl;
    oFile << "----------------------------------------------------------" << endl;
    
    oFile << "Macierz U:" << endl << endl;
    for(int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) {
            oFile << setw(width) << U[i][j];
        }
        oFile << endl;
    }
    
    oFile << endl << endl;
    oFile << "----------------------------------------------------------" << endl;

    oFile.precision(9);
    oFile << std::scientific;
    
    oFile << "Wektor Y:" << endl << endl;
    for(int i = 1; i <= n; i++){
        oFile << setw(width) << Y[i];
    }
    
    oFile << endl << endl;
    oFile << "----------------------------------------------------------" << endl;

    oFile << "Wektor X:" << endl << endl;
    for(int i = 1; i <= n; i++){
        oFile << setw(width) << X[i];
    }
}

int main(int argc, char *argv[]) {

    //rzad ukladu rownan
    int n = stoi(argv[1]);
    
    //tablice przechowujace elementy macierzy A,B,L i U.
    double **A = new double* [n+1];
    double *B = new double[n+1];
    double **L = new double*[n+1];
    double **U = new double*[n+1];

    //alokacja pamieci na tablice dwuwymiarowe oraz zerowanie wektora B
    for(int i = 0; i < n+1; i++){
        A[i] = new double[n+1];
        L[i] = new double[n+1];
        U[i] = new double[n+1];
        B[i] = 0;
    }

    //zerowanie macierzy A, U, L
    //ustawienie wartosci 1 na glownej przekatnej macierzy L
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            A[i][j] = 0;
            U[i][j] = 0;
            if(i == j)
                L[i][j] = 1;
            else
                L[i][j] = 0;
        }
    }

    //tablice przechowujace elementy wektorow X i Y
    double* X = new double[n + 1];
    double* Y = new double [n + 1];
    
    //wyzerowanie wektorow
    for (int i = 0; i < n + 1; i++) {
        Y[i] = 0 ;
        X[i] = 0;
    }
    
    
    //odczyt danych z pliku wejsciowego
    try{

        readFileInput(n, A, B, argv[2]);

    }catch(int &e){
        cout << "Blad odczytu plik wejsciowego" << endl;
        return 0;
    }
    
    //otwarcie pliku wyjsciowego do wygenerowania raportu
    
    ofstream oFile;
    //oFile.precision(10);
    oFile.open(argv[3]);
    
    if(!oFile){
        cout << "Blad otwarcia pliku wyjsciowego" << endl;
        return 0;
    }


    //wywolanie funkcji B i C dla wczytanych danych
    try {
        functionB(n, A, B, L, U);
    }catch(int &e){
        oFile << "Blad dzielenia przez 0." << endl;
        oFile << "Za pomoca implementowanej metody nie mozna rozwiazac ukladu rownan dla podanych danych wejsciowych" << endl;
        return 0;
    }

    functionC(n, A, B, L, U, X, Y);

    saveToFile(n, A, B, L, U, X, Y, oFile);

    oFile.close();
    return 0;
}