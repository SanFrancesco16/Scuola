#include <iostream>
#include <string>
using namespace std;

struct vettura{
	string targa; //targa dell'automobile
	int cil; //cilindrata
	struct vettura *next; //puntatore alla vettura successiva
};

class pila{
	private:
	vettura *testa;
	public:
	pila(){
		testa=NULL;
	}
	void inserimento(){		/*--PUSH--*/
		vettura *p;
		p=new(vettura);
		cout<<"inserisci la targa dell'automobile: ";
		cin>>p->targa;
		cout<<"inserisci la cilindrata: ";
		cin>>p->cil;
		p->next=testa;
		testa=p;
	}
	void /*CancellazioneUltimoValoreInserito*/CUVI(){
		vettura *p;
		p=testa;
		testa=p->next;
		cout<<"l'elemento "<<p->targa<<" "<<p->cil<<" e' stato rimosso\n";
		delete p;
	}
	void stampa(){
		vettura *p;
		if(testa==NULL){
			cout<<"non ci sono macchine\n";
		}
		else{
			int cont=0;
			for(p=testa;p!=NULL;p=p->next){
				cout<<"caratteristiche macchina "<<cont+1<<":\ntarga: "<<p->targa<<"\tcilindrata: "<<p->cil<<"\n";
				cont++;
			}
		}
	}
};
int main(){
	pila PILA;
	int scelta;
	do{
		cout<<"0.esci\n1.inserisci\n2.cancellazione ultimo valore inserito\n3.stampa vetture nel parco macchine\n";
		cin>>scelta;
		switch(scelta){
			case 1:
				PILA.inserimento();
			break;
			case 2:
				PILA.CUVI();
			break;
			case 3:
				PILA.stampa();
			break;
		}
	}while(scelta!=0);
}
