/*
Gestione e prenotazione visite mediche.
1) Inserisci nome ed età in due array diversi
2) Chiamata visita: stampa nome - stampa età - shift array
3) Salvataggio su file degli array
4) Stampa
5) Ripristino = trasferimento dati da F_PAZ ad array
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
	struct Paziente{
		string nome_paz;
		int eta_paz;
	};
	Paziente Ospedale[100];
	fstream f1;
	int i=0;
	string Nomi[100];
	int Eta[100];

void Inserimento(){
	cout<<"Inserisci nome paziente: ";
	cin>>Ospedale[i].nome_paz;
	cout<<"Inserisci eta' paziente: ";
	cin>>Ospedale[i].eta_paz;
	i++;	
}


void Chiamata_v(){
	string p;
	int t1;
	
	cout<<"Entra il paziente: "<<Ospedale[0].nome_paz<<endl;
	for(int h=0;h<i-1;h++){
		Ospedale[h].nome_paz=Ospedale[h+1].nome_paz;
		Ospedale[h].eta_paz=Ospedale[h+1].eta_paz;
	}
	i--;
	
} 


void Salvataggio(){
	f1.open("C:\\Users\\N8_4A\\Desktop\\Pazienti.txt",ios::out);
	for(int g=0;g<i;g++){
		f1<<Ospedale[g].nome_paz<<" "<<Ospedale[g].eta_paz<<endl;
	}
	f1.close();
	cout<<"File salvato\n";
}


void Stampa(){
	
//	cout<<i;
	
	for(int y=0;y<i;y++){
		cout<<"Nome: "<<Ospedale[y].nome_paz<<" Eta': "<<Ospedale[y].eta_paz<<" in posizione: "<<y+1<<endl;
	}
}


void Ripristino(){
	i=0;
	string NOME;
	int ETA;
	f1.open("C:\\Users\\N8_4A\\Desktop\\Pazienti.txt",ios::in);
	f1>>NOME>>ETA;
	while(!f1.eof()){
		
	//	cout<<" indice: "<<l<<endl;
		Ospedale[i].nome_paz=NOME;
		Ospedale[i].eta_paz=ETA;

	//cout<<Ospedale[l].nome_paz<<" "<< Ospedale[l].eta_paz<<endl;
	
		i++;
		f1>>NOME>>ETA;
	}
	f1.close();
	cout<<"Ripristino completato\n";
}


void Precedenza(){
	string Paz_Prec;
	int Eta_Prec;
	cout<<"Inserisci paziente con precedenza: ";
	cin>>Paz_Prec;
	cout<<"Inserisci eta': ";
	cin>>Eta_Prec;
	for(int c=i;c>0;c--){
		Ospedale[c].nome_paz=Ospedale[c-1].nome_paz;
		Ospedale[c].eta_paz=Ospedale[c-1].eta_paz;
	}
		Ospedale[0].nome_paz=Paz_Prec;
		Ospedale[0].eta_paz=Eta_Prec;
	i++;
}

int main(){
	int scelta=1;
	while(scelta!=0){
	cout<<"[1]Inserisci nome eta'  [2]Chiamata visita   [3]Salvataggio   [4]Stampa   [5]Ripristino  [6]Precedenza  [0]Uscita"<<endl;
	cin>>scelta;
	switch(scelta){
			case 1:
				Inserimento();
			break;
			
			case 2:
				Chiamata_v();
			break;
			
			case 3:
				Salvataggio();
			break;
			
			case 4:
				Stampa();
			break;
			
			case 5:
				Ripristino();
			break;
			
			case 6:
				Precedenza();
			break;
			
			case 0:
				cout<<"Uscita"<<endl;
			break;
		}
	}
	
	return 0;
}
