/*Fare un programma in C++ che dopo aver riempito da tastiera un array di 10 numeri interi 
del Superenalotto estragga in maniera casuale dall’array 5 numeri.*/

//librerie
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

//Programma
int main(){
	
	//Dichiarazione variabili
	int A[10],i,estrazione;
	srand(time(NULL));
	
	//Inserimento numeri
	cout<<"Inserisci 10 numeri\n";
		system("PAUSE");
	for(i=1;i<=10;i++){
		system("CLS");
		_beep(500,650);
		cout<<"\nInserisci il "<<i<<" numero\n";
		cin>>A[i];
	}
	system("CLS");
	_beep(500,950);
	//Estrazione dei numeri e verifica che non si ripetano
	cout<<"I numeri estratti sono: "<<endl;
	for(i=0;i<5;i++){
		estrazione=rand()%10;
		if(A[estrazione]==1000){
			i--;
		}
		else{
			cout<<A[estrazione]<<endl;
			A[estrazione]=1000;
		}
	}
	return 0;
}
