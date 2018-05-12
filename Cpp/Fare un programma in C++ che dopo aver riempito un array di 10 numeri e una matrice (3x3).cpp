/*
Fare un programma in C++ che dopo aver riempito un array di 10 numeri e una matrice (3x3) 
con numeri random positivi e minori di 150.5, stampi la posizione del massimo dell'array 
dopo aver verificato che il massimo della matrice è compreso tra 40 e 100, 
altrimenti stampi la posizione del numero più piccolo contenuto nell'array. 
Successivamente riempire una seconda matrice (3x3) contenente numeri compresi 
tra -12 e 121 se la media dei numeri contenuti nell'array è superiore a 100, 
altrimenti riempire una matrice da tastiera con numeri compresi tra 49 e 89. 
FARE USO OTTIMIZZATO di FUNZIONI e PROCEDURE.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int N=10,Nrighe=3,Ncolonne=3;
void RiempimentoArrayCasuale(float array[N]);
void RiempimentoMatriceRandom(float Matrice[Ncolonne][Nrighe]);
void RiempimentoMatriceNumero2Random(float Matrice[Ncolonne][Nrighe]);
void RiempimentoMatriceDaTastiera(float Matrice[Ncolonne][Nrighe]);
float VerificaMaxMatrice(float Matrice[Ncolonne][Nrighe]);
float PosizioneDelMassimoInArray(float array[N]);
float PosizioneDelMinimoInArray(float array[N]);
float MediaDeiNumeriInArray(float array[N]);

int main(){
	float v[N],M[Ncolonne][Nrighe],M2[Ncolonne][Nrighe],M3[Ncolonne][Nrighe];
	srand(time(NULL));
	
	RiempimentoArrayCasuale(v);
	RiempimentoMatriceRandom(M);
	VerificaMaxMatrice(M);
	if(VerificaMaxMatrice(M)<=100 && VerificaMaxMatrice(M)>=40){
		PosizioneDelMassimoInArray(v);
	}
	else{
		PosizioneDelMinimoInArray(v);
	}
	MediaDeiNumeriInArray(v);
	if(MediaDeiNumeriInArray(v)>100){
		RiempimentoMatriceNumero2Random(M2);
	}
	else{
		RiempimentoMatriceDaTastiera(M3);
	}
	return 0;
}
void RiempimentoArrayCausale(float array[N]){
	for(int cont=0;cont<N;cont++){
		array[cont]=rand()%15050/100;
	}
}
void RiempimentoMatriceRandom(float Matrice[Ncolonne][Nrighe]){
	for(int cont=0;cont<Ncolonne;cont++){
		for(int k=0;k<Nrighe;k++){
			Matrice[cont][k]=rand()%15050/100;
		}
	}
}
float VerificaMaxMatrice(float Matrice[Ncolonne][Nrighe]){
	float max_matrice=Matrice[0][0];
	for(int cont=0;cont<Ncolonne;cont++){
		for(int i=0;i<Nrighe;i++){
			if(max_matrice<Matrice[cont][i]){
				max_matrice=Matrice[cont][i];
			}
		}
	}
	return max_matrice;
}
float PosizioneDelMassimoInArray(float array[N]){
	float max_array=array[0];
	float supporto=array[0];
	int posizione_del_maggiore=0;
	for(int cont=0;cont<N;cont++){
		if(max_array<array[cont]){
			max_array=array[cont];
		}
	}
	while(supporto==max_array){
		posizione_del_maggiore++;
	}
	return posizione_del_maggiore;
}
float PosizioneDelMinimoInArray(float array[N]){
	float min_array=array[0];
	float supporto_per_il_minore=array[0];
	int posizione_del_minore=0;
	for(int cont=0;cont<N;cont++){
		if(min_array>array[cont]){
			min_array=array[cont];
		}
	}
	while(supporto_per_il_minore==min_array){
		posizione_del_minore++;
	}
	return posizione_del_minore;
}
void RiempimentoMatriceNumero2Random(float Matrice[Ncolonne][Nrighe]){
	for(int cont=0;cont<Ncolonne;cont++){
		for(int k=0;k<Nrighe;k++){
			Matrice[cont][k]=-12+rand()%(121-(-12)+1)-12;
		}
	}
}
float MediaDeiNumeriInArray(float array[N]){
	float media=0,somma=0;
	for(int cont=0;cont<N;cont++){
		somma+=array[cont];
	}
	media=somma/N;
	return media;
}
void RiempimentoMatriceDaTastiera(float Matrice[Ncolonne][Nrighe]){
	cout<<"Inserisci 9 numeri (compresi tra 49 e 89)\n";
	for(int cont=0;cont<Ncolonne;cont++){
		for(int k=0;k<Nrighe;k++){
			cout<<"Inserisci il numero che va nella cella--> "<<cont<<":"<<k<<"\n";
			cin>>Matrice[cont][k];
			if(Matrice[cont][k]<=89 && Matrice[cont][k]>= 49){
			}
			else{
				cout<<"Numero NON valido.\nRiprovare.\n";
				k--;
			}
		}
	}
}
