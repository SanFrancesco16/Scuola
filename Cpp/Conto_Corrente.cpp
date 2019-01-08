#include<iostream>
#include<string>
using namespace std;

class CC{ //conto corrente
	string correntista;
	string nc; //numero conto
	float saldo;
	
	public:
		CC(float a){	//il costruttore inizializza il saldo
			saldo=a;	//alla quantità minima necessariaad aprire un conto
		}
		
	void prelievo(float a){
		if(saldo>a){
			saldo=saldo-a;
			cout<<"Il saldo attuale e' di euro: "<<saldo<<endl;
		}
		else{
			cout<<"Non e' possibile effettuare il prelievo di una cifra\n";
			cout<<"Superiore al saldo attuale che ammonta euro: "<<saldo<<endl;
		}
	}
	void versamento(float a){
		saldo=saldo+a;
		cout<<"Il saldo attuale e' di euro: "<<saldo<<endl;
	}
	void stampa(){
		cout<<"Numero conto: "<<nc<<endl;
		cout<<"correntista: "<<correntista<<endl;
		cout<<"saldo: "<<saldo<<endl;
	}
	void crea(){
		cout<<"inerire numero conto :"<<endl;
		cin>>nc;
		cout<<"Inserire cognome correntista: "<<endl;
		cin>>correntista;
	}
};

int main(){
	int scelta;
	float a;
	CC conto(0);
	conto.crea();
	do{
		cout<<"1.prelievo\n";
		cout<<"2.versamento\n";
		cout<<"3.stampa i dati del conto\n";
		cout<<"0.esci\n";
		cout<<"Fai una scelta\n";
		cin>>scelta;
		switch(scelta){
			case 1:
				cout<<"inserire la cifra da prelevare \n";
				cin>>a;
				conto.prelievo(a);
			break;
			
			case 2:
				cout<<"inserire la cifra da versare\n";
				cin>>a;
				conto.versamento(a);
			break;
			
			case 3:
				conto.stampa();
			break;				 
		}
	}
	while(scelta!=0);
	
	return 0;
}
