/*
Creare una classe "dipendente" con attributi privati (cognome, stipendio) e metodi public(inserisci 
dipendenti con gli attributi, leggi cognome, leggi stipendio.) nel menù(inserisci dipendente, stampa gli attributi dei dipendenti)
*/
#include <iostream>
#include <string>
using namespace std;

const int N=50;

class dipendente{
	private:
		string cognome;
		float stipendio;
	public:
		string getcognome(){
			return cognome;
		}
		float getstipendio(){
			return stipendio;
		}
		void inserimento(string cog, float stip){
			cognome=cog;
			stipendio=stip;
		}
};
int main(){
	dipendente A[N];
	int scelta;
	int cont=0;
	string cognome1;
	float stipendio1;
	
while(scelta!=0){
	cout<<"0.Uscita 1.inserisci dipendente 2.stampa attributi"<<endl;
	cin>>scelta;
	switch(scelta){
			case 1:
				cout<<"Inserisci cognome: ";
				cin>>cognome1;
				cout<<"Inserisci stipendio: ";
				cin>>stipendio1;
				A[cont].inserimento(cognome1,stipendio1);
				cont++;
			break;
			case 2:
				for(int i=0;i<cont;i++){
					cout<<"\nCognome: "<<A[i].getcognome()<<endl<<"Stipendio: "<<A[i].getstipendio()<<endl;	
				}
			break;

			
			case 0:
				cout<<"Uscita"<<endl;
			break;
		}
	}
		
		

//	cout<<"uscito";
	
}
