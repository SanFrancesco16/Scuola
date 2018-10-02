#include <iostream>
#include <string>
using namespace std;
string Cog,data_in,data_out;
float eta_paz;
struct paziente{
	string 	Cognome;
	string	data_in;
	string	data_out;
	float eta;
};
paziente Ospedale[1000];
int Num_paz;

int Paz_data(string data);
void Inserimento_Ini_Paz()
{
	for(int i=0;i<Num_paz;i++)
	{
		cout<<"inserisci cognome"<<endl;
		cin>>Ospedale[i].Cognome;
		cout<<"inserisci data_in"<<Ospedale[i].data_in<<endl;
		cin>>Ospedale[i].data_in;
		cout<<"inserisci eta"<<endl;
		cin>>Ospedale[i].eta;
		Ospedale[i].data_out="0";
	}
}
void Inserimento_Paz(string Cog,string data_in, float eta_paz)
{	cout<<"dammi cognome: \n";
	cin>>Cog;
	cout<<"dammi data: \n";
	cin>>data_in;
	cout<<"dammi eta: ";
	cin>>eta_paz;
	Ospedale[Num_paz].Cognome=Cog;
	Ospedale[Num_paz].data_in=data_in;
	Ospedale[Num_paz].eta=eta_paz;
	Ospedale[Num_paz].data_out="0";
	//Incremento contatore
	Num_paz++;	
}
void Dimissioni_Paz(string Cog,string data_in)
{	cout<<"dammi cognome: \n";
	cin>>Cog;
	cout<<"dammi data: \n";
	cin>>data_in;
	for(int i=0;i<Num_paz;i++)
	{
		//Ospedale[Num_paz].data_out=data_in;
		if(Ospedale[i].Cognome==Cog)
			Ospedale[i].data_out=data_in;	
	}
}
void Ordinamento()
{	paziente appo;
int i,j;
	for(i=0;i<Num_paz-1;i++)
	{
		for(j=i+1;j<Num_paz;j++)
		{
			if(Ospedale[j].eta<Ospedale[i].eta)
			{
			appo=Ospedale[i];
			Ospedale[i]=Ospedale[j];
			Ospedale[j]=appo;
			}
		}
	}
	
}

int main()
{	int Num_paz_in,scelta=1;
	string data_usc,cog,data_ins;
	cout<<"numero pazienti: "<<endl;
	cin>>Num_paz_in;
	Num_paz=Num_paz_in;
	Inserimento_Ini_Paz();
	while(scelta!=0)
	{
		cout<<"1:inserimento paz. -2:dimissioni paziente -3: paz. alla data -4 stampa pazienti -5 Ordinamento 0:uscita \n";
		cin>>scelta;
		switch(scelta)
		{
		case 1:
					
			Inserimento_Paz(cog,data_ins,eta_paz);
			
		break;
		
		case 2:
			cout<<"dimetto pazienti \n";
			Dimissioni_Paz(cog,data_ins);
		break;
		case 3:
			cout<<" dammi la data di uscita dei pazienti: "<<endl;
			cin>>data_usc;
			cout<<"Num pazienti dimessi in questa data="<<Paz_data(data_usc)<<endl;
		break;
		
		case 4:
			//stampa pazienti dopo inserimento
			for(int i=0;i<Num_paz;i++)
			{
				cout<<" cognome:"<<Ospedale[i].Cognome<<endl;
				cout<<" data_in:"<<Ospedale[i].data_in<<endl;
				cout<<" data_out:"<<Ospedale[i].data_out<<endl;
				cout<<"eta: "<<Ospedale[i].eta<<endl;
			};
		break;
		
		case 5:
			cout<<"Ordinamento \n";
			Ordinamento();
		break;
		
		default:
			cout<<"uscita \n";
		break;
		}
	}
	return 0;
}
int Paz_data(string data3)
{int cont=0;
	for(int i=0;i<Num_paz;i++)
	{
		if(Ospedale[i].data_out==data3)
		{
			cout<<"Cognome paz usciti in data:"<<data3<<" pari a "<<Ospedale[i].Cognome<<endl;
			cont++;
		}
	}
	return cont;
}

