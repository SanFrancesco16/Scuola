#include <iostream>
#include <fstream>
#include <string>
using namespace std;

fstream f1;
const int N=20;

class dipendente{
	private:
		string nome;
		string cognome;
		float stipendio;
	public:
		void inserimento_dati(string name,string surname,float salary){
			nome=name;
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
		void SetStipendio(float support){
			stipendio=support;//"support" sta per il nuovo stipendio inserito nel main "nuovo_stipendio"
//			support=nuovo_stipendio;
//			stipendio=support;
		}	
			
//			
//			
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
//			
};



int main(){
	int scelta;
	dipendente num_dip[N];
	int main_cont=0;
	
	cout<<"PROGRAMMA SUI DIPENDENTI DI UNA AZIENDA\n";
	do{
	cout<<"\n\nPER TESTARE PREMERE 9\n0.uscita\n1.inserire dati\n2.dato un file con cognome e nome cambiare lo stipendio ai nominativi contenuti nel file\n3.dato uno stipendio in input salvare su file nomi, cognomi e stipendi dei dipendenti con stipendio maggiore dello stipendio fornito in input\n4.Salvataggio su file\n\nfai una scelta: ";
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
		case 2:
			{
			float appo;
			float nuovo_stipendio;
			string name1;
			string surname1;
			float stipendio_corrente;
			int ast=0;//contatore
			
			cout<<"inserisci nome dip: ";
			cin>>name1;
			cout<<"inser cognome dip: ";
			cin>>surname1;
			cout<<"inser stipendio corrente: ";
			cin>>stipendio_corrente;
			for(int i=0;i<main_cont;i++){
				if(num_dip[i].GetNome() == name1 and num_dip[i].GetCognome() == surname1 and num_dip[i].GetStipendio() == stipendio_corrente){
					cout<<"dipendente trovato!\n";
					ast++;
					cout<<"inserisci nuovo stipendio: ";
					cin>>nuovo_stipendio;
					num_dip[i].SetStipendio(nuovo_stipendio);
					f1.open("/*da modificare*/file_dipendente.txt",ios::out);
					for(int i=0;i<main_cont;i++){
						f1<<"nome dipendente: "<<num_dip[i].GetNome()<<"    cognome dipendente: "<<num_dip[i].GetCognome()<<"    stipendio dipendente: "<<num_dip[i].GetStipendio()<<endl;
						f1<<endl;
					}
					f1.close();
					cout<<"\n\nfile salvato\n";
			}
//					appo=num_dip[i].GetStipendio();
//					SetStipendio(name1,surname1,nuovo_stipendio,appo);
				
			
			}
					if(ast==0){
						cout<<"\n\ndipendente non trovato\n";
					}
				}
		break;
		case 3:
			{
			float stipendio_base;
			int contatore_di_supporto=0;
			
			cout<<"Inserisci lo stipendio da utilizzare come base per trovare i dipendenti con stipendio maggiore di quello inserito: ";
			cin>>stipendio_base;
			f1.open("/*da modificare*/file_dipendente.txt",ios::out);
			for(int i=0;i<main_cont;i++){
				if(stipendio_base<num_dip[i].GetStipendio()){
					contatore_di_supporto++;
					cout<<"\n\n";
					cout<<i+1<<") "<<"nome dipendente: "<<num_dip[i].GetNome()<<"    cognome dipendente: "<<num_dip[i].GetCognome()<<"    stipendio dipendente: "<<num_dip[i].GetStipendio()<<endl<<"salvato\n\n";
					f1<<"nome dipendente: "<<num_dip[i].GetNome()<<"    cognome dipendente: "<<num_dip[i].GetCognome()<<"    stipendio dipendente: "<<num_dip[i].GetStipendio()<<endl;
					f1<<endl;
				}
			}
			if(contatore_di_supporto==0){
				cout<<"nesssun dipendente trovato con stipendio superiore a quello inserito\n";
			}
			f1.close();
		}
		break;
		case 4:
			f1.open("/*da modificare*/file_dipendente.txt",ios::out);
			for(int i=0;i<main_cont;i++){
				f1<<"nome dipendente: "<<num_dip[i].GetNome()<<"    cognome dipendente: "<<num_dip[i].GetCognome()<<"    stipendio dipendente: "<<num_dip[i].GetStipendio()<<endl;
				f1<<endl;
			}
			f1.close();
			cout<<"\n\nfile salvato\n";
		break;
		case 9:
			for(int i=0;i<main_cont;i++){
				cout<<"nome dip: "<<num_dip[i].GetNome()<<"   cognome: "<<num_dip[i].GetCognome()<<"   stipendio: "<<num_dip[i].GetStipendio()<<endl;
			}
		break;
		
		}
	
		
	}while(scelta!=0);
}
