#include<iostream>
using namespace std;
const int Ctc = 100;
struct contactoEmail{
	string Nom;
	string Sx;
	int Eda;
	string Tel;
	string Mail;
	string Nac;
};
contactoEmail Ag[Ctc];
int Tctc = 0;
void Agregarcontacto(){
	if(Tctc<Ctc){
		contactoEmail nuevo;
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
void Eliminarcontacto(){
	if(Tctc==0){
		cout<<"No hay contactos registrados"<<endl;
	}else{
		string BuContc;
		cout<<"Ingrese el email del contacto a eliminar: ";
		getline(cin, BuContc);
		int ContcEli = -1;
		for(int i= 0; i < Tctc; i++){
			if(Ag[i].Mail == BuContc){
				ContcEli=i;
			}
		}
		if(ContcEli != -1){
			for(int j = ContcEli; j<Tctc-1; j++){
				Ag[j]=Ag[j+1];
			}
			Tctc--;
			cout<<"Contacto eliminado"<<endl;
		}else{
			cout<<"Contacto no encontrado"<<endl;
		}
	}
}
void Mostrarcontactos(){
	if(Tctc==0){
		cout<<"No hay contactos registrados"<<endl;
	}
	for(int i= 0; i<Tctc; i++){
		contactoEmail c = Ag[i];
		cout<<"Contacto #"<<i+1<<": "<<endl;
		cout<<"Nombre completo: "<< c.Nom<<endl;
		cout<<"Sexo: "<<c.Sx<<endl;
		cout<<"Edad: "<<c.Eda<<endl;
		cout<<"Numero de telefono: "<<c.Tel<<endl;
		cout<<"Email: "<<c.Mail<<endl;
		cout<<"Nacionalidad: "<<c.Nac<<endl;
	}
}
string Obtenerservidor(const string& Mail){
	string serv = "";
	bool Arb = false;
	for(int i=0; Mail[i]!='\0'; i++){
		if(Arb){
			serv += Mail[i];
		}
		if(Mail[i]=='@'){
			Arb = true;
		}
	}
	return serv;
}
void Mostrarcontactosporservidor(){
	if(Tctc==0){
		cout<<"No hay contactos registrados"<<endl;
	}else{
		contactoEmail aux[Ctc];
		for(int i=0; i<Tctc; i++){
			aux[i]=Ag[i];
		}
		for(int i=0; i<Tctc; i++){
			for(int j=0; j<Tctc-i-1; j++){
				string serv1 = Obtenerservidor(aux[i].Mail);
				string serv2 = Obtenerservidor(aux[j].Mail);
				if(serv1>serv2){
					contactoEmail aux1 = aux[i];
					aux[i] = aux[j];
					aux[j] = aux1;
				}
			}
		}
		string sev = "";
		for(int i=0; i<Tctc; i++){
			string sv = Obtenerservidor(aux[i].Mail);
			if(sv != sev){
				cout<<"\nServidor: "<<sv<<endl;
				sev=sv;
			}
			cout<<" - "<< aux[i].Nom << " ("<<aux[i].Mail<<") "<<endl;
			cout<<"Sexo: "<<aux[i].Sx<<endl;
			cout<<"Edad: "<<aux[i].Eda<<endl;
			cout<<"Telefono: "<<aux[i].Tel<<endl;
			cout<<"Nacionalidad: "<<aux[i].Nac<<endl;
		}
	}
}
void menu(){
	char op;
	while(op!='5'){
		cout<<"Menu"<<endl;
		cout<<"1) Agregar contacto"<<endl;
		cout<<"2) Eliminar contacto"<<endl;
		cout<<"3) Mostrar listado general de contactos"<<endl;
		cout<<"4) Mostrar listado de contactos por servidor de correo"<<endl;
		cout<<"Seleccione una opcion"<<endl;
		cin>>op;
		cin.ignore();
		if(op=='1'){
			Agregarcontacto();
		}else if(op=='2'){
			Eliminarcontacto();
		}else if(op=='3'){
			Mostrarcontactos();
		}else if(op=='4'){
			Mostrarcontactosporservidor();
		}
	}
}
int main(){
	menu();
	return 0;
}