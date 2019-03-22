#include<iostream>
#include<string>

using namespace std;

struct vettura{
	string targa;
	struct vettura *next;
};

class pila{
	private:
		vettura *testa;
	public:
		pila(){
			testa=NULL;
		}
		void inserimento(){
			vettura *p;
			p=new(vettura);
			cout<<"inserisci targa: ";
			cin>>p->targa;
			p->next=testa;
			testa=p;
		}
		void stampa(){
			vettura *p;
			if(testa==NULL){
				cout<<"no vetture disponiblil\n";
			}
			else{
				cout<<"elenco vetture:\n";
				for(p=testa;p!=NULL;p=p->next){
					cout<<"la targa vettura e' "<<p->targa<<endl;
				}
			}
		}
};
int main(){
	pila garage;
	int scelta;
	do{
		cout<<"PROGRAMMA PILA PRINCIPALE\n\n1.inserisci\n2.stampa\n0.esci\nFai una scelta: ";
		cin>>scelta;
		switch(scelta){
			case 1:
				garage.inserimento();
			break;
			case 2:
				garage.stampa();
			break;
		}
	}while(scelta!=0);
}





