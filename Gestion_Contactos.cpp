#include<iostream>
using namespace std;
const int Ctc = 100;
struct Contacto {
	string Nom;
	string Sx;
	int Eda;
	string Tel;
	string Mail;
	string Nac;
};
Contacto Ag[Ctc];
int Tctc = 0;
void Agregarcontacto(){
	if(Tctc<Ctc){
		Contacto nuevo;
		cout<<"Nombre completo: ";
		getline(cin, nuevo.Nom);
		cout<<"Sexo: ";
		getline(cin, nuevo.Sx);
		cout<<"Edad: ";
		cin>>nuevo.Eda;
		while(nuevo.Eda<=0){
			cout<<"Intentelo de nuevo"<<endl;
			cin>>nuevo.Eda;
		}
		cin.ignore();
		cout<<"Numero de telefono: ";
		getline(cin, nuevo.Tel);
		cout<<"Email: ";
		getline(cin, nuevo.Mail);
		cout<<"Nacionalidad: ";
		getline(cin, nuevo.Nac);
		Ag[Tctc] =  nuevo;
		Tctc++;
		cout<<"Contacto agregado"<<endl;
	}else{
		cout<<"No se puede agregar mas contactos. Limite alcanzado"<<endl;
	}
}
void menu(){
	char op;
	while(op!='5'){
		cout<<"Menu"<<endl;
		cout<<"1) Agregar contacto"<<endl;
		cout<<"Seleccione una opcion"<<endl;
		cin>>op;
		cin.ignore();
		if(op=='1'){
			Agregarcontacto();
		}
	}
}
int main(){
	menu();
	return 0;
}