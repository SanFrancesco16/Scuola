#include<iostream>
#include<fstream>
#include<string>

using namespace std;
struct Studente{
		string cognome;
		float eta;
		float voto;
	};

	Studente Classe[40];
	
int main(){
	string cog;
	float eta_stud, voto_stud;
	
	fstream f1;
	
	f1.open("C:\\Users\\N8_4A\\Desktop\\test.txt",ios::in);
	f1>>cog>>eta_stud>>voto_stud;
	
	

	int i=0;
		Classe[i].cognome=cog;
		Classe[i].eta=eta_stud;
		Classe[i].voto=voto_stud;

	while(!f1.eof()){
		i++;
		f1>>cog>>eta_stud>>voto_stud;
		Classe[i].cognome=cog;
		Classe[i].eta=eta_stud;
		Classe[i].voto=voto_stud;
	}

	f1.close();
	
	
	string array[40];
    
	for(int j=0;j<i+1;j++){
		if(Classe[j].voto>=7){
			array[j]=Classe[j].cognome;
			cout<<array[j];
		}
	}


	return 0;
}
