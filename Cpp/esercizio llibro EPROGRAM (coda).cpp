#include <iostream>
#include <string>
using namespace std;

struct paziente{
	string nome;//nome del pazioente
	int num;//numero assegnato all'ingresso
	struct paziente *next;//puntatore al paziente successivo
};

class coda_classe{
	private:
		int cont=1;
		paziente *testa;
		paziente *coda;
	public:
		coda_classe(){
			testa=NULL;
			coda=NULL;
		}
		void arrivo(){
			paziente *p;
			p=new(paziente);
			cout<<"inserisci nome paziente: ";
			cin>>p->nome;
			p->num=cont;
			cout<<"al paziente "<<p->nome<<" e' stato asegnato il numero "<<cont<<endl;
			if(testa==NULL){
			p->next=coda;
			testa=p;
			coda=p;
			}
			else{
				coda->next=p;
				coda=p;
				coda->next=NULL;
			}
			cont++;
		}
		void stampa(){
			if(testa==NULL){
				cout<<"non ci sono pazienti\n";
			}
			else{
			paziente *p;
			cout<<"pazienti in lista di attesa:\n";
				for(p=testa;p!=NULL;p=p->next){
					cout<<"il paziente "<<p->nome<<" e' in lista di attesa e ha il numero "<<p->num<<endl;
				}
			}
		}
		void estrazione(){			//estrazione ultimo paziente dalla coda 
			if(testa==NULL){
				cout<<"non ci sono pazienti\n";
			}
			else{
			paziente *p;
			p=testa;
			cout<<"il paziente "<<p->nome<<" con il numero "<<p->num<<"e' uscito\n";
			testa=p->next;
			delete p;
			}
		}
};
int main(){
	coda_classe CODA;
	int scelta;
	
	do{
		cout<<"0.esci\n1.arrivo paziente\n2.stampa pazienti in lista d'attesa\n3.estrazione ultimo paziente\n";
		cin>>scelta;
		switch(scelta){
			case 1:
				CODA.arrivo();
			break;
			case 2:
				CODA.stampa();
			break;
			case 3:
				CODA.estrazione();
			break;
		}
	}while(scelta!=0);
}
