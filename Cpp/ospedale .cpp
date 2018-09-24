/*
Scrivi un programma che esegua le seguenti operazioni: 
a)stampa dell'elenco di tutti i pazienti dimessi in una determinata data fornita in input 
b)registrazione di una dimissione avendo in input il cognome del paziente da dimettere e la data attuale 
c)registrazione di un'accettazione di un paziente con immissione dei dati relativi nella prima posizione
*/

/*/- librerie -/*/
#include<iostream>
#include<string>
using namespace std;

struct Pazienti{
	string Cognome;
	string Nome;
	string Data_Acc;/*/- data accettazione -/*/
	string Data_Dim;/*/- data dimissione -/*/
};

int p,non_uscito=0;
Pazienti Max[250];

void Riempimento(){
	cout<<"Inserisci il numero di pazienti presenti nell'ospedale: ";
	cin>>p;
	for(int i=0;i<p;i++){
		cout<<"Inserisci il cognome del "<<i+1<<" paziente: ";
		cin>>Max[i].Cognome;
		cout<<"Inserisci il nome del "<<i+1<<" paziente: ";
		cin>>Max[i].Nome;
		cout<<"Inserisci la data di accettazione del "<<i+1<<" paziente: ";
		cin>>Max[i].Data_Acc;
		cout<<"Inserisci la data di dimissione del "<<i+1<<" paziente\n[0 per dichiarare che il paziente non e' stato dimesso altromenti la data di dimissione]: ";
		cin>>Max[i].Data_Dim;
		if('Max[i].Data_Dim'==0){
			non_uscito++;
		}
	}
}

string data_dimesso_cin;
void OutDeiDimessi(){
	char scelta;
	cout<<"Se vuoi vedere tutti i enti dimessi premere Y,\naltrimenti premere N per vedere i pazienti dimessi in una determinata data\noppure qualsiasi altro tasto per saltare l'operazione: ";
	cin>>scelta;
	if(scelta=='Y' or 'y'){
		cout<<"I parenti dimessi sono:\n";
		for(int j=0;j<p;j++){
			if('Max[j].Data_Dim'==0){
			}
			else{
				cout<<"Il paziente "<<Max[j].Cognome<<" "<<Max[j].Nome<<" e' stato dimesso il giorno "<<Max[j].Data_Dim<<endl;
			}
		}
	}
	else if(scelta=='N' or 'n'){
		cout<<"Inserisci la data della quale vuoi vedere i pazienti dimessi: ";
		cin>>data_dimesso_cin;
		cout<<"I pazienti dimessi nel giorno scelto sono:\n";
		for(int cont=0;cont<p;cont++){
			if(data_dimesso_cin==Max[cont].Data_Dim){
				cout<<"Il paziente "<<Max[cont].Cognome<<" "<<Max[cont].Nome<<" e' stato dimessio nel giorno scelto";
			}
		}
	}
	else{
		cout<<"La verifica della dimissione e' stata saltata!\n";
	}
}
void DimettereUnPaziente(){
	char decisione01,decisione02;
	string today;
	string co_paz_da_dim /*/- cognome del paziente da dimettere -/*/,no_paz_da_dim /*/- nome del paziente da dimettere -/*/,ac_paz_da_dim/*/- data di accettazione del paziente -/*/;
	cout<<"Vuoi dimettere un paziente? [Y/N]\n";
	cin>>decisione01;
	if(decisione01=='Y' or 'y'){
		peat;
		cout<<"Inserisci il cognome del paziente da dimettere: ";
		cin>>co_paz_da_dim;
		cout<<"Inserisci il nome del paziente da dimettere: ";
		cin>>no_paz_da_dim;
		cout<<"Inserisci la data del paziente di ammissione: ";
		cin>>ac_paz_da_dim;
		for(int cont=0;cont<p;cont++){
			if(co_paz_da_dim==Max[cont].Cognome and no_paz_da_dim==Max[cont].Nome and ac_paz_da_dim==Max[cont].Data_Acc){
				cout<<"Inserisci la data di oggi: ";
				cin>>today;
				Max[cont].Data_Dim=today;
			}
		}
	}
	cout<<"Vuoi dimettere un'altro paziente? [Y/N]\n";
	cin>>decisione02;
	if(decisione02=='Y' or 'y'){
		goto peat;
	}
	else{
		cout<<"Ok, passiamo ad altro!\n";
	}
}


int main(){
	Riempimento();
	OutDeiDimessi();
	DimettereUnPaziente();
	return 0;
}
