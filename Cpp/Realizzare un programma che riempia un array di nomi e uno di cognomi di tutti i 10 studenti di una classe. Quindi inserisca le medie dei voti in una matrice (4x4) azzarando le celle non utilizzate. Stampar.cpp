#include<iostream>
#include<iostream>
using namespace std;

const int N=0,Ncolonne=4,Nrighe=4;
void RiempimentoArrayDiNomi(string array[N]);
void RiempimentoArrayDiCognomi(string array[N]);
void InserimentoMedie(float Matrice[Ncolonne][Nrighe]);
void StampareMedie(float Matrice[Ncolonne][Nrighe]);

int main(){
	string Vn[N],Vc[N];
	float M[Ncolonne][Nrighe];
	
	RiempimentoArrayDiNomi(Vn);
	RiempimentoArrayDiCognomi(Vc);
	InserimentoMedie(M);
	StampareMedie(M);
	
	return 0;
}
void RiempimentoArrayDiNomi(string array[N]){
	cout<<"Inserisci 10 nomi di 10 studenti\n";
	for(int cont=0;cont<N;cont++){
		cout<<"Inserisci il "<<cont++<<"^ nome\n";
		cin>>array[cont];
	}
}
void RiempimentoArrayDiCognomi(string array[N]){
	cout<<"Inserisci 10 cognomi dei 10 studenti inseriti prima\n";
	for(int cont=0;cont<N;cont++){
		cout<<"Inserisci il "<<cont++<<"^ cognome\n";
		cin>>array[cont];
	}
}
void InserimentoMedie(float Matrice[Ncolonne][Nrighe]){
	int supporto=0;
	cout<<"Inserisci le medie dei 10 alunni\n";
	for(int cont=0;cont<Ncolonne;cont++){
		for(int i=0;i<Nrighe;i++){
			supporto++;
			if(supporto>10){
				Matrice[cont][i]=0;
			}
			else{
				cout<<"Inserisci la media del "<<supporto<<"alunno\n";
				cin>>Matrice[cont][i];
			}
		}
	}
}
void StampareMedie(float Matrice[Ncolonne][Nrighe]){
	for(int cont=0;cont<Ncolonne;cont++){
		for(int i=0;i<Nrighe;i++){
			if(Matrice[cont][i]>=7.5){
				cout<<Matrice[cont][i]<<endl;
			}
			else{}
		}
	}
}
