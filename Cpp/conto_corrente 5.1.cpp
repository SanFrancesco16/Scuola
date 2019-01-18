#include<iostream>
#include<string>
#include<fstream>
using namespace std;

fstream f1;

struct op{
	string VDATA;	//**Data**//
	float A;	//**Cifra Da Prelevare**//
	string TIPO;	//**Tipo dell'azione eseguita: prelievo o versamento**//
};
op Lista[1000];

class CC{ //conto corrente
	string correntista;
	string nc; //numero conto
	float saldo;
	string data;
	
	public:
		CC(float a){	//il costruttore inizializza il saldo
			saldo=a;	//alla quantità minima necessariaad aprire un conto
		}
		
	void prelievo(float a,string vdata,int cont, string tipo){
		if(saldo>a){
			saldo=saldo-a;
			cout<<"Il saldo attuale e' di euro: "<<saldo<<endl;
			data=vdata;
			Lista[cont].A=a;
			cout<<"inserisci la data di oggi\n";
			cin>>vdata;
			Lista[cont].VDATA=vdata;
			tipo="prelievo";
			Lista[cont].TIPO=tipo;
			cont++;
		}
		else{
			cout<<"Non e' possibile effettuare il prelievo di una cifra\n";
			cout<<"Superiore al saldo attuale che ammonta euro: "<<saldo<<endl;
		}
	}
	void versamento(float a,string vdata){
		saldo=saldo+a;
		cout<<"Il saldo attuale e' di euro: "<<saldo<<endl;
		data=vdata;
		
	}
	void stampa(){
		cout<<"Numero conto: "<<nc<<endl;
		cout<<"correntista: "<<correntista<<endl;
		cout<<"saldo: "<<saldo<<endl;
	//	cout<<"data: "<<data<<endl;
	}
	void crea(){
		cout<<"inserire numero conto: "<<endl;
		cin>>nc;
		cout<<"Inserire cognome correntista: "<<endl;
		cin>>correntista;
	}
	void Salvataggio(int cont){
		f1.open("C:\\Users\\N8_4A\\Desktop\\CCSalvataggio.txt",ios::out);
		for(int i=0;i<cont;i++){
			f1<<Lista[i].A<<"    "<<Lista[i].VDATA<<"    "<<Lista[i].TIPO<<"\n";
		}
		f1.close();
	}
};

int main(){
	int scelta;
	int cont=0;
	float a;
	float SALDO;
//	float A[1000];
	string vdata;
//	string VDATA[1000];
	string tipo;
//	string TIPO[1000];
	CC conto(0);
	conto.crea();
	do{
		cout<<"\n1.prelievo\n";
		cout<<"2.versamento\n";
		cout<<"3.stampa i dati del conto\n";
		cout<<"4.tracciare le azioni\n";
		cout<<"5.salvataggio\n";
		cout<<"0.esci\n";
		cout<<"Fai una scelta\n";
		cin>>scelta;
		switch(scelta){
			case 1:
				cout<<"inserire la cifra da prelevare \n";
				cin>>a;
			//	cout<<"primo cin superato\n";
				conto.prelievo(a,vdata, cont, tipo);
			break;
			
			case 2:
				cout<<"inserire la cifra da versare\n";
				cin>>a;
				Lista[cont].A=a;
				cout<<"inserisci la data di oggi\n";
				cin>>vdata;
				Lista[cont].VDATA=vdata;
				tipo="versamento";
				Lista[cont].TIPO=tipo;
				conto.versamento(a,vdata);
				cont++;
			break;
			
			case 3:
				conto.stampa();
			break;		
			
			case 4:
				for(int sup=0;sup<cont;sup++){
					cout<<"soldi "<<Lista[sup].A<<endl<<"data "<<Lista[sup].VDATA<<endl<<"tipo "<<Lista[sup].TIPO<<endl;
					cout<<"---------------------\n";
				}
			break;	
			
			case 5:
				conto.Salvataggio(cont);
				cout<<"Salvataggio\n";
			break;
		}
	}
	while(scelta!=0);
	
	return 0;
}
