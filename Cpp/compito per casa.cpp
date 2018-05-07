/* 
Fare un programma in C++ ch inserisca in un array 5 numeri casuali compresi tra -9 e 50.
Quindi dopo aver riempito un array con tali numeri stampare tutti i numeri 
dell'array compresi tra 5 e 25.
Usare funzioni o procedure strutturate in modo corretto e semplice...
si suggerisce di lavorare prima nel main() e poi trasferire l'algoritmo in procedure o funzioni.
*/
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void g_n_r (int cont, float array [5]); /* generzione di numeri casuali*/
void c_a (int cont, float array [5]); /* controllo dell'array */

int main()
{
	float min = -9, max = 50;	
	float array [5];
	int cont;
	srand(time(NULL));
	
	g_n_r (cont, array);
	c_a (cont, array);
	
}
void g_n_r (int cont, float array [5])
{
	for (cont = 0; cont < 5; cont ++)
	{
		array [cont] = -900 + rand() % 5000;
		array [cont] /= 100;
	}
}
void c_a (int cont, float array [5])
{
	for (cont = 0; cont < 5; cont++)
	{
		if (array [cont] >= 5 && array [cont] <= 25)
		{
			cout << array [cont] << "\n";
		}
		else 
		{
		}
	}
}




