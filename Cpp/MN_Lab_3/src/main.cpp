#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#define MAXN 101
// MAXN - rozmiar tablic w�z��w i warto�ci funkcji w w�z�ach interpolacji
//        zak�adamy, �e n<MAXN
	int n; // maksymalny indeks w�z�a interpolacji, (n+1) - lb. w�z��w
	int m; // wsp�czynnik m we wzorze (24)
	int mn; // lb. po�rednich punkt�w mi�dzy w�z�ami interpolacji w drugim pliku   
	int ddelta; // wsp�czynnik delta we wzorze (24)
	double a, b; // granice przedzia�u zawieraj�cego w�z�y interpolacji
	double pi2=8*atan(1.0);
	double x[MAXN]; // tablica w�z��w na osi x
	double y[MAXN]; // tablica w�z��w na osi y
	double f[MAXN]; // tablica warto�ci funkcji w w�z�ach interpolacji
	char *plkNazwaWezly, *plkNazwa; // nazwy pierwszego i drugiego pliku
	double aa[MAXN], bb[MAXN]; // tablice wsp�czynnik�w ai i bi we wzorze (24)

//	funkcja g(y) na podstawie kt�rej wyznaczane s� warto�ci w w�z�ach interpolacji
// y nale�y do przedzia�u <a, b>                     
double gfun(double y)
{
	double xp, yp, gm;
	if(y<=a +0.25*(b-a))
	{
	gm = 2;
	xp =a;
	yp = (b-a)/4.0;
	}
	else if(y<=a+0.5*(b-a))
	{
	gm = 1;
	xp =a;
	yp = (b-a)/2.0;
	}
	else if(y<=a+0.75*(b-a))
	{
	gm = 0;
	xp =a;
	yp = (b-a);
	}
	else if(y<=b)
		{
	gm = -3;
	xp =b;
	yp = (b-a)/4.0;
	}
 	return gm *( y - xp)	+ yp;
//	return cos(( ((2*M_PI)/(b-a))*(y-a) )-1)*((y-a)/(b-a)) + 1;
}

//	funkcja okresowa g(y),  y dowolne
double g(double t)
{
	double tt;
	tt=fmod(t-a, b-a);
	return gfun(tt<0?b+tt:a+tt);
}

//	funkcja dokonuj�ca konwersji zmiennej y na x
double y2x(double y)
{
	return (y-a)/(b-a)*pi2;
}

// Wyznaczenie w�z��w interpolacji i warto�ci funkcji w w�z�ach
void generWezlyTryg()
{
	double delta=(b-a)/(n+1);
	for (int i=0; i<=n; i++)
	{
		y[i]=a+delta*i;
		x[i]=y2x(y[i]);
		f[i]=gfun(y[i]);
		printf("%f     %f     %f \n", y[i], x[i], f[i]);
	}
	y[n+1]=b;
	m=n/2; //wyznaczenie wsp�czynnika m ze wzorze (24)
	ddelta=n-2*m; // wyznaczenie wsp�czynnika delta ze wzoru (24)
}

// Wyprowadzenie danych do pierwszego pliku
void generWezlyPlik()
{
	FILE *plk;
	plk = fopen( plkNazwaWezly, "w" );
// wydruk nag��wka dla pliku .rex
	fprintf(plk, "yi\t g_yi\t xi\n");
// wydruk tr�jek w�ze�  na osi y, warto�� funkcji w w�le interpolacji i w�ze� na osi x 
	for (int i=0; i<=n; i++)
	{
		fprintf(plk, "%lf\t %lf\t %lf\n", y[i], f[i], x[i]);
	}
// wydruk stopki dla pliku .rex
//	fprintf(plk, "*InfKon*\nV 0 0 0 %d",n+1 );
	fclose(plk);
}

// Generacja parametr�w ai oraz bi ze wzoru (24)
	void genAi_Bi()
{
	double sumA , sumB;
	for(int j= 0; j<=m+1; j++){
		sumA = 0;
		sumB = 0;
		
			for(int k = 0; k <= n; k++ )
			{
				sumA += f[k] * cos(j*x[k]);
				sumB += f[k] * sin(j*x[k]);
			}
		aa[j] = 2.0/(n+1) *sumA;
		bb[j] = 2.0/(n+1) *sumB;
	}
	return;
}

//funkcja interpoluj�ca
double Tryg(double t)
{
	//double pp;
	double tt;
	//int j;
	double sum = 0;
	for(int j =1; j<=m; j++)
		sum+=aa[j]*cos(j*t)+bb[j]*sin(j*t);
	
	tt = 0.5*aa[0]+sum+ddelta*0.5*aa[m+1]*cos((m+1)*t);
	
	return tt;
}

//Wyprowadzenie wiersza do drugiego pliku
void drukWiersz(double ty, FILE *plk)
{
	double eps=1.0e-20;
	double tx, wyn, gg;
	tx=y2x(ty);
	wyn=Tryg(tx);
	gg=g(ty);
	fprintf(plk, "%lf\t %lf\t %lf\t %lf\t %lf\n", ty, gg, wyn, gg-wyn, (gg-wyn)/(fabs(gg)+eps));

}

// Wyprowadzenie danych do drugiego pliku y nale�y do przedzia�u <a, b>
void generWyn()
{
	double delta;
	int i, j;
	FILE *plk;
	plk = fopen( plkNazwa, "w" );
// wydruk nag��wka dla pliku .rex
	fprintf(plk, "y\t g_y\t tt_y\t blb_y\t  blw_y\n");
	for (i=0; i<=n; i++)
	{
		delta=(y[i+1]-y[i])/mn;
		for(j=0; j<mn; j++)
		{
			drukWiersz(y[i]+delta*j, plk);
		}
	}
	drukWiersz(b, plk);
// wydruk stopki dla pliku .rex
//	fprintf(plk, "*InfKon*\nV 0 0 0 %d", (n+1)*mn+1);
	fclose(plk);
}

// Wyprowadzenie danych do drugiego pliku y nale�y do przedzia�u <a-(b-a), b+(b-a)>
void generWyn1()
{
	double ty, delta;
	int i, j;
	FILE *plk;
	plk = fopen( plkNazwa, "w" );
// wydruk nag��wka dla pliku .rex
	fprintf(plk, "y\t g_y\t tt_y\t blb_y\t  blw_y\n");
	for (i=0; i<=n; i++)
	{ //y nale�y do przedzia�u <a+(b-a), a)
		delta=(y[i+1]-y[i])/mn;
		for(j=0; j<mn; j++)
		{
			ty=-(b-a)+y[i]+delta*j;
			drukWiersz(ty, plk);
		}
	}
	for (i=0; i<=n; i++)
	{
		delta=(y[i+1]-y[i])/mn;
		for(j=0; j<mn; j++)
		{ //y nale�y do przedzia�u <a, b)
			ty=y[i]+delta*j;
			drukWiersz(ty, plk);
		}
	}
	for (i=0; i<=n; i++)
	{ //y nale�y do przedzia�u <b, b+(b-a))
		delta=(y[i+1]-y[i])/mn;
		for(j=0; j<mn; j++)
		{
			ty=(b-a)+y[i]+delta*j;
			drukWiersz(ty, plk);
		}
	}
	//y=b+(b-a)
			drukWiersz(ty, plk);
// wydruk stopki dla pliku .rex
//	fprintf(plk, "*InfKon*\nV 0 0 0 %d", 3*(n+1)*mn+1);
	fclose(plk);
}

int main(int argc, char* argv[])
{
// Odczyt danych z linii polecenia
	a=atof(argv[1]); //lewa granica przedzia�u
	b=atof(argv[2]); //prawa granica przedzia�u
	n=atoi(argv[3]); //maksymalny indeks w�z�a interpolacji
	mn=atoi(argv[4]); //liczba po�rednich punkt�w mi�dzy w�z�ami interpolacji w drugim pliku
	plkNazwa=argv[5];  //nazwa drugiego pliku (pliku z wynikami dzia�ania funkcji interpoluj�cej)
	plkNazwaWezly=argv[6]; //nazwa pierwszego pliku (pliku z w�z�ami)
// Wyprowadzenie na ekran danych z linii polecenia
	printf("a= %lf\n", a);
	printf("b= %lf\n", b);
	printf("n= %d\n", n);
	printf("mn= %d\n", mn);
// Wyznaczenie w�z��w interpolacji i warto�ci funkcji w w�z�ach
	generWezlyTryg();
// Wyprowadzenie danych do pierwszego pliku
	generWezlyPlik();
// Generacja parametr�w ai oraz bi ze wzoru (24)
	genAi_Bi();
// Wyprowadzenie danych do drugiego pliku y nale�y do przedzia�u <a, b>
	generWyn();
// Wyprowadzenie danych do drugiego pliku y nale�y do przedzia�u <a-(b-a), b+(b-a)>
//	generWyn1();
	return 0;
}
