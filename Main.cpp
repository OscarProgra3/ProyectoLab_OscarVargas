#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <direct> //mkdir

#include "Consolas.h"
#include "Microsoft.h"
#include "Sony.h"
#include "Nintendo.h"
#include "Videojuegos.h"
#include "JuegosMicrosoft.h"
#include "juegosSony.h"
#include "juegosNintendo.h"
#include "juegosSega.h"
#include "juegosBandai.h"
#include "juegosKonami.h"
#include "juegosUbisoft.h"
#include "juegosSquareEnix.h"
#include "juegosElectronicArts.h"
#include "Usuario.h"
#include "Administrador.h"
#include "Vendedor.h"
#include "Venta.h"

using namespace std;

void funcionvender();
void funciondibujo();


int main()
{

	//creando carpeta para el archivo binnario
	
	




	Administrador* admin = new Administrador(); //Administrador predefinido
	int respuesta1 = 0;
	while (respuesta1 == 0) {

		vector<Consolas*> Listaconsolas;
		vector<Videojuegos*> ListaVideojuegos;
	

		vector<Microsoft*> consolasMicrosoft;
		vector<Nintendo*> consolasNintendo;
		vector<Sony*> consolasSony;

		cout << "Bienvenido a GAMEHUB\n";
		cout << "Como desea entrar?\n";
		cout << "1) Entrar como Administrador\n";
		cout << "2) Entrar como Vendedor\n";
		int respuesta2;
		cin >> respuesta2;
		while(respuesta2 <= 0 || respuesta2 > 2) {
			cout << "Numero invalido, ingrese su numero de nuevo!\n";
			cin >> respuesta2;
		}

		if (respuesta2 == 1)
		{//Si es administrador
			//Identificar si es el admin
			bool identificar;
			cout << "Ingrese el nombre de usuario: \n";
			string nombreTemp;
			cin >> nombreTemp;
			cout << "Ingrese la contraseña: \n";
			string contraseniaTemp;
			cin >> contraseniaTemp;
			if (nombreTemp == admin -> getNombre() && contraseniaTemp == admin -> getContrasenia())
			{//Se hace true si el nombre y la contrseña son iguales a las del admin
				identificar = true;
			} else {//Se hace false si una de las dos es diferente
				identificar = false;
				cout << "Nombre o Contraseña incorrecta!\n";
			}

			int online1 = 0;
			while(online1 == 0 && identificar == true) {
				cout << "Que desea hacer?\n";
				cout << "1) Agregar\n";
				cout << "2) Modificar\n";
				cout << "3) Eliminar\n";
				int respuesta3;
				cin >> respuesta3;
				while(respuesta3 <= 0 || respuesta3 > 3) {
					cout << "Numero invalido, ingrese su numero de nuevo!\n";
					cin >> respuesta3;
				}
				if (respuesta3 == 1)
				{ //Agregar
					cout << "Que desea agregar?\n";
					cout << "1) Consola\n";
					cout << "2) Videojuego\n";
					int respuesta4;
					cin >> respuesta4;
					while(respuesta4 <= 0 || respuesta4 > 2) {
						cout << "Numero invalido, ingrese su numero de nuevo!\n";
						cin >> respuesta4;
					}

					if (respuesta4 == 1) //Agregar Consola
					{
						/*cout << "Que tipo de consola desea agregar?\n";
						cout << "1) Microsoft\n";
						cout << "2) Nintendo\n";
						cout << "3) Sony\n";
						int respuesta5;
						cin >> respuesta5;
						while(respuesta5 <= 0 || respuesta5 > 3) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> respuesta5;
						}
						if (respuesta5 == 1)
						{*///Agregar consola de microsoft
						bool norepetido = true;

						int aniodesalida;
						string modelodeconsola;
						string estadodeconsola;
						int numerodeserie;
						double preciodeconsola;

						cout << "Ingrese el año de salida de la consola.\n";
						cin >> aniodesalida;
						cout << "Ingrese el estado de la consola.\n";
						cin >> estadodeconsola;
						cout << "Ingrese el numero de serie de la consola.\n";
						cin >> numerodeserie;
						for (int i = 0; i < Listaconsolas.size(); ++i)
						{
							if (numerodeserie == Listaconsolas.at(i) -> getNumeroSerie())
							{
								norepetido = false;
							}
						}
						while(norepetido == false) {
							cout << "Numerio de serie repetido, ingrese el numero de serie de nuevo!\n";
							cin >> numerodeserie;
							norepetido = true;
							for (int i = 0; i < Listaconsolas.size(); ++i)
							{
								if (numerodeserie == Listaconsolas[i] -> getNumeroSerie())
								{
									norepetido = false;
								}
							}
						}
						cout << "Ingrese el precio de la Consola: \n";
						cin >> preciodeconsola;
						cout << "Escoga el modelo de la consola: \n";
						cout << "1) Xbox\n";
						cout << "2) Xbox 360\n";
						cout << "3) Xbox One\n";
						int respuestamodelo;
						cin >> respuestamodelo;
						if (respuestamodelo == 1)
						{
							modelodeconsola = "Xbox";
						} else if (respuestamodelo == 2)
						{
							modelodeconsola = "Xbox 360";
						} else {
							modelodeconsola = "Xbox One";
						}

						Consolas* consolaM;
						cout << "Que tipo de consola desea agregar?\n";
						cout << "1) Microsoft\n";
						cout << "2) Nintendo\n";
						cout << "3) Sony\n";
						int respuesta5;
						cin >> respuesta5;
						while(respuesta5 <= 0 || respuesta5 > 3) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> respuesta5;
						}
						if (respuesta5 == 1)
						{//Agregando consola de microsoft
							consolaM = new Microsoft(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola);
							Listaconsolas.push_back(consolaM);
							cout << "Consola agregada exitosamente!\n";
						} else if (respuesta5 == 2)
						{//Agregar consola de nintendo
							consolaM = new Nintendo(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola);
							Listaconsolas.push_back(consolaM);
							cout << "Consola agregada exitosamente!\n";
						} else {//Agregar consola de sony
							consolaM = new Sony(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola);
							Listaconsolas.push_back(consolaM);
							cout << "Consola agregada exitosamente!\n";
						}
						//Borrar punteros
						delete consolaM;

					} else { //Agregar Videojuegos

						bool norepetido2 = true;

						string nombrejuego;
						int aniodesalida2;
						string consoladeljuego;	
						int numjugadores;
						string genero;
						string estadojuego;
						int numserie;
						double preciojuego;

						cout << "Ingrese el nombre del juego.\n";
						cin >> nombrejuego;
						cout << "Ingrese el año de salida del juego.\n";
						cin >> aniodesalida2;
						cout << "Para que consola es el videojuego?\n";
						cin >> consoladeljuego;
						cout << "Ingrese el estado del juego.\n";
						cin >> estadojuego;
						cout << "Ingrese el numero de jugadores.\n";
						cin >> numjugadores;
						cout << "Ingrese el numero de serie del juego.\n";
						cin >> numserie;
						cout << "Ingrese el genero del juego.\n";
						cin >> genero;
						cout << "Ingrese el precio del juego.\n";
						cin >> preciojuego;
						for (int i = 0; i < ListaVideojuegos.size(); ++i)
						{
							if (numserie == ListaVideojuegos.at(i) -> getNumSerie())
							{
								norepetido2 = false;
							}
						}
						while(norepetido2 == false) {
							cout << "Numerio de serie repetido, ingrese el numero de serie de nuevo!\n";
							cin >> numserie;
							norepetido2 = true;
							for (int i = 0; i < ListaVideojuegos.size(); ++i)
							{
								if (numserie == ListaVideojuegos.at(i) -> getNumSerie())
								{
									norepetido2 = false;
								}
							}
						}

						Videojuegos* juego;
						cout << "Que tipo de juego desea agregar?\n";
						cout << "1) Juego de Microsoft\n";
						cout << "2) Juego de Nintendo\n";
						cout << "3) Juego de Sony\n";
						cout << "4) Juego de Sega\n";
						cout << "5) Juego de Bandai\n";
						cout << "6) Juego de Electrocic Arts\n";
						cout << "7) Juego de Konami\n";
						cout << "8) Juego de Square Enix\n";
						cout << "9) Juego de Ubisoft\n";
						int respuesta5;
						cin >> respuesta5;
						while(respuesta5 <= 0 || respuesta5 > 9) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> respuesta5;
						}
						if (respuesta5 == 1)
						{//Agregar juego de microsoft
							juego = new JuegosMicrosoft(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 2)
						{//Agregar juego de nintendo
							juego = new juegosNintendo(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 3)
						{//Agregar juego de sony
							juego = new juegosSony(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 4)
						{//Agregar juego de Sega
							juego = new juegosSega(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 5)
						{//Agregar juego de bandai
							juego = new juegosBandai(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 6)
						{//Agregar juego de electronic arts
							juego = new juegosElectronicArts(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 7)
						{//Agregar juego de konami
							juego = new juegosKonami(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 8)
						{//Agregar juego de square enix
							juego = new juegosSquareEnix(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						} else { //Agregar juego de ubisoft
							juego = new juegosUbisoft(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego);
							ListaVideojuegos.push_back(juego);
							cout << "Juego agregado exitosamente!\n";
						}

					}

				} else if (respuesta3 == 2)
				{ //Modificar
					

				} else { //Eliminar

				}
				cout << "Desea salir? 1 = Salir 0 = No salir\n";
				cin >> online1;
				while(online1 < 0 || online1 > 1) {
					cout << "Numero invalido, ingrese su numero de nuevo!\n";
					cin >> online1;
				}

			}
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
		} else {// Si es Vendedor
			int online2 = 0;
			while(online2 == 0)
			{
				int opcvendedor=0;
				while(opcvendedor!=3)
				{
					int opcv=0;
					cout<<"Bienvenido vendedor\n ¿Que es lo que desea realizar?\n1.-Agregar a el inventario\n2.-Vender\n3.-Sair\nIngrese su opcion: ";
					cin>>opcv;

					if (opcv==1)
					{
						void funciondibujo();
					}
					if (opcv==2)
					{
						funcionvender();
					}
				}
				cout << "Desea salir? 1 = Salir 0 = No salir\n";
				cin >> online2;
				while(online2 < 0 || online2 > 1) {
					cout << "Numero invalido, ingrese su numero de nuevo!\n";
					cin >> online2;
				}
			}
		}

		cout << "Desea salir de GAMEHUB? (S/N)\n";
		char respuestaFinal;
		cin >> respuestaFinal;
		if (respuestaFinal == 'S' || respuestaFinal == 's')
		{
			respuesta1 = 1;

			//Borrar vector de consolasMicrosoft
			for (int i=0; i< Listaconsolas.size(); i++){
		    	delete Listaconsolas[i];
		  	}
			Listaconsolas.clear();

			//Borrar vector de consolasNintendo
			for (int i=0; i< ListaVideojuegos.size(); i++){
		    	delete ListaVideojuegos[i];
		  	}
			ListaVideojuegos.clear();

		}
	}
	
	cout << "Nos vemos luego!\n";

	/*Nintendo* nin=new Nintendo(2017,"Sega","bueno",111,15.30);

	//nin->{};
	cout<< "\nYOLOYOLOYOLOYOLOYOLO"<<endl;
	cout<<nin->getModelo()<<"ESOOOOOO"<<endl;
		return 0;*/
}

void funcionvender()
{
	cout<<"    ___\n   |[_]|\n   |+ ;| GAMEHUB\n   `---'\n";
	 
	cout<<"\n      Bienvenido vendedor\n";

	cout<<"";

	int respv=0;
	while(respv!=3)
	{	 
		cout<<"¿Que es lo que desea vender?\n";
		cout<<"1.-Consolas\n2.-Videojuegos\n3.-Salir"<<endl;
		cin>>respv;
		if (respv==1)
		{
 	

 		}
	 	if (respv==2)
	 	{
	 		string respventavideo="o";
	 		while(respventavideo=="s"||respventavideo=="S")
	 		{

	 			cout<<" De cual compañia desea el videojuego"<<endl;
	 			cout<<"1.-Microsoft\n2.-Sony\n3.-Nintendo\n4.-Bandai\n5.-Konami\n6.-Square Enix\n7.-Electronic Arts\n8.-SEGA\n9.-Ubisoft\n ";



	 			cout<<"¿Desea aregar otro videojuego?";
	 			cin>>respventavideo;
	 		}	
	 	}
	}
}

void funciondibujo()
{
	cout<<"**************BIENVENIDO******************\n";
}