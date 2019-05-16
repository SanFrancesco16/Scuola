#include <iostream>
using namespace std;

struct vettura{
	string nome;
	string targa;
	struct vettura *next;
};

class Pila{
	private:
	vettura *testa;
	public:
	Pila(){
		testa==NULL;
	}
	void inserimento(){
		vettura *p;
		p=new(vettura);
		cout<<"ins nome\n";
		cin>>p->nome;
		cout<<"ins targa\n";
		cin>>p->targa;
		if(testa==NULL){
			p->next=NULL;
		}
		else{
			p->next=testa;
		}
		testa=p;
	}
	void stampa(){
		vettura *p;
		for(p=testa;p!=NULL;p=p->next){
			cout<<p->nome<<p->targa<<endl;
		}
	}
	void estrazione(){
		if(testa!=NULL){
		vettura *p;
		p=testa;
		cout<<p->nome<<p->targa<<endl;
		testa=testa->next;
		delete p;
		}
	}
};
int main(){
	int scelta;
	Pila garage;
	do{
		cout<<"0.esci   1.ins    2.stampa   3.estrazione\n";
		cin>>scelta;
		switch(scelta){
			case 1:
				garage.inserimento();
			break;
			case 2:
				garage.stampa();
			break;
			case 3:
				garage.estrazione();
			break;
		}
	}while(scelta!=0);
}
