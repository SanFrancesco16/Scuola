#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int G=7;
fstream f1;

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
		
		
};
int main(){
	giorno sett[G];
	float unatemp;
	int scelta;
	
	do{
		cout<<"PROGRAMMA TEMPERATURE\n\n0.esci\n1.inserimento\n2.ricerce temp piu' basse\n3.Salvataggio su file temp min e temp max\n4.calcola escusione termica per ogni giorno\n5.Salvataggio su file completo\n\nFai una scelta: ";
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
			case 3:
				f1.open("C:\\Users\\loren\\Desktop\\Temperature_settimanali.txt",ios::out);
				for(int i=0;i<G;i++){
					f1<<"giorno: "<<i+1<<"      temp min: "<<sett[i].getmin()<<"      temp max: "<<sett[i].getmax()<<endl;
				}
				f1.close();
				cout<<"File savato"<<endl;
			break;
			case 4:
				for(int i=0;i<G;i++){
					cout<<"escuzione termica: "<<sett[i].getdiff()<<"	giorno: "<<i+1<<endl;
				}
			break;
			case 5:
				f1.open("C:\\Users\\loren\\Desktop\\Temperature_settimanali.txt",ios::out);
				for(int i=0;i<G;i++){
					f1<<"giorno: "<<i+1<<"      temp min: "<<sett[i].getmin()<<"      temp max: "<<sett[i].getmax()<<"      escursione termica: "<<sett[i].getdiff()<<endl;
				}
				
				f1.close();
				cout<<"File savato"<<endl;
			break;
		}
	}while(scelta!=0);
}
