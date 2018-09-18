/*/- librerie -/*/
#include <iostream>
#include <string>
using namespace std;

/*/- inizializzazione della struttura 'struct' -/*/
struct studente{
	string cognome;
	string nome;
	float voto;
};

/*/- inizializzazione variabili globali -/*/
studente classe[40];
int n;

/*/- funzione per riempire la struttura 'struct' -/*/
void carica(){
	int i;
	cout<<"Inserisci il numero dei studenti: ";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"Inserisci il cognome in posizione "<<i+1<<endl;
		cin>>classe[i].cognome;
		cout<<"Inserisci il nome in posizione "<<i+1<<endl;
		cin>>classe[i].nome;
		cout<<"Inserisci il voto in posizione "<<i+1<<endl;
		cin>>classe[i].voto;
	}
}

/*/- calcolo del voto massimo con output del cognome dello studente con il voto più alto -/*/void voto_max(){
	int i,pos=0;
	float voto_max=classe[0].voto;
	for(i=1;i<n;i++){
		if(voto_max<classe[i].voto)
		{
			voto_max=classe[i].voto;
			pos=i;
		}
			
	}
	cout<<"Il cognome dello studente con il voto piu' alto e': "<<classe[pos].cognome<<endl;
}

/*/- calcolo del totale degli alunni insufficienti con output del cognome,cognome,voto dell'alunno insufficiente 
e l'output della quantità di alunni insufficienti -/*/ 
void stud_insuff(){
	int con_insuff=0;
	for(int cont=0;cont<n;cont++){
		if(classe[cont].voto<6){
			con_insuff++;
			cout<<"Lo studente "<<classe[cont].cognome<<" "<<classe[cont].nome<<" "<<classe[cont].voto<<" e' insufficiente\n";
		}
	}
	cout<<"Il totale degli alunni insufficienti e': "<<con_insuff<<endl;
}

/*/- calcolo della percentuale  -/*/
void perc_aaa(){
	int t=1,v_perc[t];
	for(int k=0;k<n;k++){
		if(k>n){
			t+1;
			v_perc[k]=classe[k].voto;
		}
		else{
			v_perc[k]=classe[k].voto;
		}	
	}	
	
	//n = totale dei voti nela classe (neg e pos)
	int tot_v_insuff=0;
	for(int cont=0;cont<n;cont++){
		if(classe[cont].voto<6){
			tot_v_insuff++;
		}
	}
	float incognita;
	incognita=(tot_v_insuff*100)/n;
	cout<<"La percentuale dei voti insufficienti e' del "<<incognita<<"%\n";
}

int main(){/*/- inizio main -/*/
	carica();
	voto_max();
	stud_insuff();
	perc_aaa();
	
	return 0;
}/*/- fine main -/*/
