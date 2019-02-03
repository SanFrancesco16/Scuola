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
	int scelta;
	int presente=0;
	
	do{
		cout<<"PROGRAMMA TEMPERATURE\n\n0.esci\n1.inserimento\n2.ricerce temp piu' basse\n3.Salvataggio su file temp min e temp max\n4.calcola escusione termica per ogni giorno\n5.Salvataggio su file completo\n6.ricerca temp piu' alte\n7.calcola media giornaliera\n8.calcola media settmanale\n\nFai una scelta: ";
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
				float tempinser;
				presente=0;
				cout<<"Inserisci una temperatura: ";
				cin>>tempinser;
				for(int i=0;i<G;i++){
					if(sett[i].getmin()<tempinser){
						cout<<"temperatura: "<<sett[i].getmin()<<"	il giorno: "<<i+1<<endl;
						presente++;
					}
					if(sett[i].getmax()<tempinser){
						cout<<"temperatura: "<<sett[i].getmax()<<"	il giorno: "<<i+1<<endl;
						presente++;
					}
				}
				if(presente==0){
					cout<<"\nno temp min di quella scelta\n"<<endl;
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
				float m_s;//media_settimanale
				float a;//appo
				float mg[G];//media_giorno[G]
				for(int i=0;i<G;i++){
					mg[i]=(sett[i].getmax()+sett[i].getmin())/2;
					a=a+mg[i];
				}
				m_s=a/G;
				f1.open("C:\\Users\\loren\\Desktop\\Temperature_settimanali.txt",ios::out);
				for(int i=0;i<G;i++){
					f1<<"giorno: "<<i+1<<"      temp min: "<<sett[i].getmin()<<"      temp max: "<<sett[i].getmax()<<"      escursione termica: "<<sett[i].getdiff()<<"		media del giorno: "<<mg[i]<<endl;
				}
				f1<<"\n\nMEDIA SETTIMANALE: "<<m_s<<endl;
				f1.close();
				cout<<"File savato"<<endl;
			break;
			case 6:
				float temp_per_max;
				cout<<"Inserisci una temperatura: ";
				cin>>temp_per_max;
				for(int i=0;i<G;i++){
					if(temp_per_max<sett[i].getmax()){
						cout<<"temperatura: "<<sett[i].getmax()<<"	il giorno: "<<i+1<<endl;
					}
					if(temp_per_max<sett[i].getmin()){
						cout<<"temperatura: "<<sett[i].getmin()<<"	il giorno: "<<i+1<<endl;
					}
				}
			break;
			case 7:
				float media_giornaliera[G];
				for(int i=0;i<G;i++){
					media_giornaliera[i]=(sett[i].getmax()+sett[i].getmin())/2;
					cout<<"temp media: "<<media_giornaliera[i]<<"	giorno: "<<i+1<<endl;
				}
			break;
			case 8:
				float media_settimanale;
				float appo;
				float media_giorno[G];
				for(int i=0;i<G;i++){
					media_giorno[i]=(sett[i].getmax()+sett[i].getmin())/2;
					appo=appo+media_giorno[i];
				}
				media_settimanale=appo/G;
				cout<<"media settimanale: "<<media_settimanale<<endl;
			break;
		}
	}while(scelta!=0);
}
