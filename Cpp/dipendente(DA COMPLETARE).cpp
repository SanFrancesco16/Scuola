#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N=20;

class dipendente{
	private:
		string nome;
		string cognome;
		float stipendio;
	public:
		void inserimento_dati(string name,string surname,float salary){
			name=nome;
			cognome=surname;
			stipendio=salary;
		}
		string GetNome(){
			return nome;
		}
		string GetCognome(){
			return cognome;
		}
		float GetStipendio(){
			return stipendio;
		}
//		void SetStipendio(string name1,string surname1){
//			float nuovo_stipendio;
//			cout<<"inserisci nome dip: ";
//			cin>>name1;
//			cout<<"inser cognome dip: ";
//			cin>>surname1;
//			for(int i=0;i<N;i++){
//				if(dipendente[i].nome and dipendente[i].cognome == name1 and surname1){
//					cout<<"inserisci nuovo stipendio: ";
//					cin>>nuovo_stipendio;
//					dipendente[i].stipendio=nuovo_stipendio;
//				}
//			}
//		}
};



int main(){
	int scelta;
	dipendente num_dip[N];
	int main_cont=0;
	
	cout<<"PROGRAMMA SUI DIPENDENTI DI UNA AZIENDA\n";
	do{
	cout<<"\n\n0.uscita\n1.inserire dati\n2.dato un file con cognome e nome cambiare lo stipendio ai nominativi contenuti nel file\n3.dato uno stipendio in input salvare su file i cognomi e stipendi dei dipendenti con stipendio maggiore dello stipendio fornito in input\n\nfai una scelta: ";
	cin>>scelta;
	switch(scelta){
		case 1:
			{
			string main_nome;
			string main_cognome;
			float main_stipendio;
			
			cout<<"Inserisci nome: ";
			cin>>main_nome;
			cout<<"inser cognome: ";
			cin>>main_cognome;
			cout<<"inser stipendio: ";
			cin>>main_stipendio;
			num_dip[main_cont].inserimento_dati(main_nome,main_cognome,main_stipendio);
					
			main_cont++;
			}
		break;
		case 9:
			for(int i=0;i<main_cont;i++){
				cout<<"nome dip: "<<num_dip[i].GetNome()<<"   cognome: "<<num_dip[i].GetCognome()<<"   stipendio: "<<num_dip[i].GetStipendio()<<endl;
			}
		break;
		
	}
		
	}while(scelta!=0);
}
