#include <iostream>
#include <string>
using namespace std;
struct studente{
	string cognome;
	string nome;
	float voto;
};
studente classe[40];
int n;
void carica(){
	int i;
	cout<<"Inserisci numero studenti"<<endl;
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"inserisci cognome in posizione"<<i+1<<endl;
		cin>>classe[i].cognome;
		cout<<"inserisci nome in posizione"<<i+1<<endl;
		cin>>classe[i].nome;
		cout<<"inserisci voto in posizione"<<i+1<<endl;
		cin>>classe[i].voto;
	}
}
void voto_max(){
	int i,pos=0;
	float voto_max=classe[0].voto;
	for(i=1;i<n;i++){
		if(voto_max<classe[i].voto)
		{
			voto_max=classe[i].voto;
			pos=i;
		}
			
	}
	cout<<"cognome studente con voto max: "<<classe[pos].cognome<<endl;
}
void stud_insuff(){
	int con_insuff=0;
	for(int cont=0;cont<n;cont++){
		if(classe[cont].voto<6){
			con_insuff++;
			cout<<"Lo studente "<<classe[cont].cognome<<" "<<classe[cont].nome<<" "<<classe[cont].voto<<" e' insufficiente\n";
		}
	}
	cout<<"Il totale degli alunni insufficienti e': "<<con_insuff<<endl;
}
void perc_aaa(){
	int t=1,v_perc[t];
	for(int k=0;k<n;k++){
		if(k>n){
			t+1;
			v_perc[k]=classe[k].voto;
		}
		else{
			v_perc[k]=classe[k].voto;
		}	
	}
	int min_del_v /* numero minore del vettore */=v_perc[0];                              //      deposito(var) = primo numero                                
	int mass_del_v /* numero massimo del vettore */=v_perc[0];                            //      primo numero = secondo numero                               
	int deposito;                                                                         //      secondo numero = deposito                                     
	for(int p=0;p<n-1;p++){
		for(int q=p+1;q<n;q++){
			if(v_perc[p]>v_perc[q]){
				deposito=v_perc[p];
				v_perc[p]=v_perc[q];
				v_perc[q]=deposito;
			}
		}
	}
	for(int j=0;j<t;j++){
		if(min_del_v>v_perc[j]){
			min_del_v=v_perc[j];
			if(mass_del_v<v_perc[j]){
				mass_del_v=v_perc[j];
			}
		}
	}
	int sot;/* sottrazione tra il massimo e il minimo dei numeri contenuti nell'array */
	sot=mass_del_v-min_del_v;
	cout<<"-->"<<sot<<"<-- Rappresenta il range di questo insieme numerico \n";
}
int main(){
	carica();
	voto_max();
	stud_insuff();
	perc_aaa();
	
	return 0;
}
