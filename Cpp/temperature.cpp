#include <iostream>
#include <string>
using namespace std;

const int G=7;

class giorno{
	private:
		float tmax;
		float tmin;
	public:
		float getmin(){
			return tmin;
		}
		float getmax(){
			return tmax;
		}
		float getdiff(){
			return (tmax-tmin);
		}
		void inserimento(float tmin2, float tmax2){
			tmin=tmin2;
			tmax=tmax2;
		}
		void costante(float TSCELTA){
			
		}
		
};
int main(){
	giorno sett[G];
	float unatemp;
	int scelta;
	
	do{
		cout<<"0.esci 1.inserimento 2.ricerce temp piu' basse"<<endl;
		cin>>scelta;
		switch(scelta){
			case 1:
			for(int i=0;i<G;i++){
			float tempmin,tempmax;
			cout<<"Inserisci la temperatura minima del giorno "<<i+1<<endl;
			cin>>tempmin;
			cout<<"Inserisci la temperatura massima del giorno "<<i+1<<endl;
			cin>>tempmax;
			sett[i].inserimento(tempmin, tempmax);
			}
			break;
			case 2:
			cout<<"Inserisci una temperatura: ";
			cin>>unatemp;
			for(int i=0;i<G;i++){
				if(unatemp>sett[i].getmax()){
					cout<<"temperatura: "<<sett[i].getmin()<<"il giorno: "<<i+1<<endl;
				}
				if(unatemp>sett[i].getmin()){
					cout<<"temperatura: "<<sett[i].getmax()<<"il giorno: "<<i+1<<endl;
				}
			}		
			break;
	
		}
	}while(scelta!=0);
}
	
	




	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	






