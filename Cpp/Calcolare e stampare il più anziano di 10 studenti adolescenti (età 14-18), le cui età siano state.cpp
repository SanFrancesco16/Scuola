/* 
Calcolare e stampare il pi� anziano di 10 studenti adolescenti (et� 14-18), le cui et� siano state 
inserite in un array apposito in modo randomico. 
Se il pi� anziano � maggiorenne allora stampare l'et� del pi� giovane altrimenti
l'et� media dei 10 studenti. Meditare su quante e quali funzizoni o procedure dovete utilizzare 
nel main() e risolvere con esse.
*/
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void Riempimento_Array (int ARRAY[10]);
void Valore_Massimo (int ARRAY [10]);

int main()
{
	
	int cont, array [10];

	Riempimento_Array (array);
	Valore_Massimo (array);
}
void Riempimento_Array (int ARRAY[10])
{
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i ++)
	{
		ARRAY [i] = 14 + rand() % 18;
	}
}
void Valore_Massimo (int ARRAY [10])
{
	int i;
	int max = ARRAY [0];
	for (i = 0; i < 10; i ++)
	{
		if (max < ARRAY [i])
			max = ARRAY [i];
		else
		{
		}
	}
	
}
