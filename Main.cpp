#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <typeinfo>

//para la hora
#include <time.h>       /* time_t, struct tm, time, localtime, asctime */
#include <stdio.h>

#include <sstream>

#include <fstream> //PARA FICHEROS

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
void funcionAgregar(vector<Consolas*> Listaconsolas, vector<Videojuegos*> ListaVideojuegos);
void funciondibujo();

string hora();

void escribirbinario(vector<Consolas*> Listaconsolas, vector<Videojuegos*> ListaVideojuegos);
void leerbinario(vector <Consolas*> consola, vector <Videojuegos*> videojuego);

int main()
{
	vector<Consolas*> Listaconsolas;
	vector<Videojuegos*> ListaVideojuegos;

	leerbinario(Listaconsolas,ListaVideojuegos);




    cout<<endl<<endl;

	Administrador* admin = new Administrador(); //Administrador predefinido
	int respuesta1 = 0;

		vector<Microsoft*> consolasMicrosoft;
		vector<Nintendo*> consolasNintendo;
		vector<Sony*> consolasSony;

		cout << "Bienvenido a GAMEHUB\n";
		cout << "Como desea entrar?\n";
		cout << "1) Entrar como Administrador\n";
		cout << "2) Entrar como Vendedor\n";
		int respuesta2;
		cin >> respuesta2;
		while(respuesta2 < 1 || respuesta2 > 2) {
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
				cout << "Bienvenido Administrador!\n";
				cout << "Que desea hacer?\n";
				cout << "1) Agregar\n";
				cout << "2) Modificar\n";
				cout << "3) Eliminar\n";
				cout << "4) Listar\n";
				int respuesta3;
				cin >> respuesta3;
				while(respuesta3 < 1 || respuesta3 > 4) {
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
					while(respuesta4 < 1 || respuesta4 > 2) {
						cout << "Numero invalido, ingrese su numero de nuevo!\n";
						cin >> respuesta4;
					}

					if (respuesta4 == 1) //Agregar Consola
					{
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
							cout << "Numero de serie repetido, ingrese el numero de serie de nuevo!\n";
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

						cout << "De que compañia es la consola?\n";
						cout << "1) Microsoft\n";
						cout << "2) Nintendo\n";
						cout << "3) Sony\n";
						int respuesta5;
						cin >> respuesta5;
						while(respuesta5 < 1 || respuesta5 > 3) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> respuesta5;
						}
						if (respuesta5 == 1)
						{//Agregando consola de microsoft
							cout << "Escoga el modelo de la consola: \n";
							cout << "1) Xbox\n";
							cout << "2) Xbox 360\n";
							cout << "3) Xbox One\n";
							int respuestamodelo;
							cin >> respuestamodelo;
							while(respuestamodelo < 1 || respuestamodelo > 3) {
								cout << "Numero invalido, ingrese su numero de nuevo!\n";
								cin >> respuestamodelo;
							}
							if (respuestamodelo == 1) //Mira el modelo de la consola
							{
								modelodeconsola = "Xbox";
							} else if (respuestamodelo == 2)
							{
								modelodeconsola = "Xbox 360";
							} else {
								modelodeconsola = "Xbox One";
							}
							Listaconsolas.push_back(new Microsoft(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola));
							cout << "Consola agregada exitosamente!\n";
						} else if (respuesta5 == 2)
						{//Agregar consola de nintendo

							cout << "Escoga el modelo de la consola: \n";
							cout << "1) Nintendo Entertainment System\n";
							cout << "2) Super Nintendo Entertainment System\n";
							cout << "3) Nintendo 64\n";
							cout << "4) Nintendo Gamecube\n";
							cout << "5) Nintendo Wii\n";
							cout << "6) Nintendo Wii U\n";
							cout << "7) Nintendo Switch\n";
							cout << "8) Gameboy\n";
							cout << "9) Gameboy Colors\n";
							cout << "10) Gameboy Advance\n";
							cout << "11) Nintendo DS\n";
							cout << "12) Nintendo DSi\n";
							cout << "13) Nintendo 3DS\n";
							cout << "14) Nintendo New 3DS\n";
							int respuestamodelo;
							cin >> respuestamodelo;
							while(respuestamodelo < 1 || respuestamodelo > 14) {
								cout << "Numero invalido, ingrese su numero de nuevo!\n";
								cin >> respuestamodelo;
							}

							if (respuestamodelo == 1) //Mira el modelo de la consola
							{
								modelodeconsola = "Nintendo Entertainment System";
							} else if (respuestamodelo == 2)
							{
								modelodeconsola = "Super Nintendo Entertainment System";
							} else if (respuestamodelo == 3)
							{
								modelodeconsola = "Nintendo 64";
							} else if (respuestamodelo == 4)
							{
								modelodeconsola = "Nintendo Gamecube";
							} else if (respuestamodelo == 5)
							{
								modelodeconsola = "Nintendo Wii";
							} else if (respuestamodelo == 6)
							{
								modelodeconsola = "Nintendo Wii U";
							} else if (respuestamodelo == 7)
							{
								modelodeconsola = "Nintendo Switch";
							} else if (respuestamodelo == 8)
							{
								modelodeconsola = "Gameboy";
							} else if (respuestamodelo == 9)
							{
								modelodeconsola = "Gameboy Colors";
							} else if (respuestamodelo == 10)
							{
								modelodeconsola = "Gameboy Advance";
							} else if (respuestamodelo == 11)
							{
								modelodeconsola = "Nintendo DS";
							} else if (respuestamodelo == 12)
							{
								modelodeconsola = "Nintendo DSi";
							} else if (respuestamodelo == 13)
							{
								modelodeconsola = "Nintendo 3DS";
							} else {
								modelodeconsola = "Nintendo New 3DS";
							}

							Listaconsolas.push_back(new Nintendo(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola));
							cout << "Consola agregada exitosamente!\n";
						} else {//Agregar consola de sony

							cout << "Escoga el modelo de la consola: \n";
							cout << "1) Play Station 1\n";
							cout << "2) Play Station 2\n";
							cout << "3) Play Station 3\n";
							cout << "4) Play Station 4\n";
							cout << "5) PSP\n";
							cout << "6) PSP Vita\n";
							int respuestamodelo;
							cin >> respuestamodelo;
							while(respuestamodelo < 1 || respuestamodelo > 6) {
								cout << "Numero invalido, ingrese su numero de nuevo!\n";
								cin >> respuestamodelo;
							}
							if (respuestamodelo == 1) //Mira el modelo de la consola
							{
								modelodeconsola = "Play Station 1";
							} else if (respuestamodelo == 2)
							{
								modelodeconsola = "Play Station 2";
							} else if (respuestamodelo == 3) 
							{
								modelodeconsola = "Play Station 3";
							} else if (respuestamodelo == 4)
							{
								modelodeconsola = "Play Station 4";
							} else if (respuestamodelo == 5)
							{
								modelodeconsola = "PSP";
							} else {
								modelodeconsola = "PSP Vita";
							}

							Listaconsolas.push_back(new Sony(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola));
							cout << "Consola agregada exitosamente!\n";
						}
						cout << endl;

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
						while(respuesta5 < 1 || respuesta5 > 9) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> respuesta5;
						}
						if (respuesta5 == 1)
						{//Agregar juego de microsoft
							ListaVideojuegos.push_back(new JuegosMicrosoft(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 2)
						{//Agregar juego de nintendo
							ListaVideojuegos.push_back(new juegosNintendo(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 3)
						{//Agregar juego de sony
							ListaVideojuegos.push_back(new juegosSony(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 4)
						{//Agregar juego de Sega
							ListaVideojuegos.push_back(new juegosSega(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 5)
						{//Agregar juego de bandai
							ListaVideojuegos.push_back(new juegosBandai(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 6)
						{//Agregar juego de electronic arts
							ListaVideojuegos.push_back(new juegosElectronicArts(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 7)
						{//Agregar juego de konami
							ListaVideojuegos.push_back(new juegosKonami(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 8)
						{//Agregar juego de square enix
							ListaVideojuegos.push_back(new juegosSquareEnix(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else { //Agregar juego de ubisoft
							ListaVideojuegos.push_back(new juegosUbisoft(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						}
						cout << endl;
					} //Fin if agregar consola o videojuego

				} else if (respuesta3 == 2)
				{ //Modificar
					cout << "Que desea modificar?\n";
					cout << "1) Consola\n";
					cout << "2) Videojuego\n";
					int respuestamodificar;
					cin >> respuestamodificar;
					while(respuestamodificar < 1 || respuestamodificar > 2) {
						cout << "Numero invalido, ingrese su numero de nuevo!\n";
						cin >> respuestamodificar;
					}
					if (respuestamodificar == 1)
					{//Modificar Consola
						cout << "Cual consola desea modificar?\n";
						for (int i = 0; i < Listaconsolas.size(); ++i)
						{
							cout << i << ") " << (Listaconsolas.at(i) -> getModelo()) << endl;
						}
						int consolamodificar;
						cin >> consolamodificar;
						while (consolamodificar < 0 || consolamodificar > Listaconsolas.size()) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> consolamodificar;
						}

						cout << "Que desea modificar?\n";
						cout << "1) Año de salida\n";
						cout << "2) Modelo\n";
						cout << "3) Estado\n";
						cout << "4) Numero de Serie\n";
						cout << "5) Precio\n";
						int respuestamodificar2;
						cin >> respuestamodificar2;
						while (respuestamodificar2 < 1 || respuestamodificar2 > 5) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> respuestamodificar2;
						}

						if (respuestamodificar2 == 1)
						{
							cout << "Ingrese el nuevo año de salida.\n";
							int aniodesalida;
							cin >> aniodesalida;
							Listaconsolas.at(consolamodificar) -> setAniosalida(aniodesalida);
							cout << "Año de salida cambiado exitosamente!\n";
						} else if (respuestamodificar2 == 2)
						{
							Consolas* temp = Listaconsolas.at(consolamodificar);
							string modelodeconsola;
              				if (typeid(*temp)==typeid(Microsoft)) {//Verifica si la consola a modificar es de microsoft
                				
              					cout << "Escoga el nuevo modelo de la consola: \n";
								cout << "1) Xbox\n";
								cout << "2) Xbox 360\n";
								cout << "3) Xbox One\n";
								int respuestamodelo2;
								cin >> respuestamodelo2;
								while(respuestamodelo2 < 1 || respuestamodelo2 > 3) {
									cout << "Numero invalido, ingrese su numero de nuevo!\n";
									cin >> respuestamodelo2;
								}
								if (respuestamodelo2 == 1) //Mira el modelo de la consola
								{
									modelodeconsola = "Xbox";
								} else if (respuestamodelo2 == 2)
								{
									modelodeconsola = "Xbox 360";
								} else {
									modelodeconsola = "Xbox One";
								}
								Listaconsolas.at(consolamodificar) -> setModelo(modelodeconsola);
								cout << "Modelo cambiado exitosamente!\n";

							} else if (typeid(*temp)==typeid(Nintendo))
							{//Verifica si la consola a modificar es de nintendo
								
								cout << "Escoga el nuevo modelo de la consola: \n";
								cout << "1) Nintendo Entertainment System\n";
								cout << "2) Super Nintendo Entertainment System\n";
								cout << "3) Nintendo 64\n";
								cout << "4) Nintendo Gamecube\n";
								cout << "5) Nintendo Wii\n";
								cout << "6) Nintendo Wii U\n";
								cout << "7) Nintendo Switch\n";
								cout << "8) Gameboy\n";
								cout << "9) Gameboy Colors\n";
								cout << "10) Gameboy Advance\n";
								cout << "11) Nintendo DS\n";
								cout << "12) Nintendo DSi\n";
								cout << "13) Nintendo 3DS\n";
								cout << "14) Nintendo New 3DS\n";
								int respuestamodelo2;
								cin >> respuestamodelo2;
								while(respuestamodelo2 < 1 || respuestamodelo2 > 14) {
									cout << "Numero invalido, ingrese su numero de nuevo!\n";
									cin >> respuestamodelo2;
								}

								if (respuestamodelo2 == 1) //Mira el modelo de la consola
								{
									modelodeconsola = "Nintendo Entertainment System";
								} else if (respuestamodelo2 == 2)
								{
									modelodeconsola = "Super Nintendo Entertainment System";
								} else if (respuestamodelo2 == 3)
								{
									modelodeconsola = "Nintendo 64";
								} else if (respuestamodelo2 == 4)
								{
									modelodeconsola = "Nintendo Gamecube";
								} else if (respuestamodelo2 == 5)
								{
									modelodeconsola = "Nintendo Wii";
								} else if (respuestamodelo2 == 6)
								{
									modelodeconsola = "Nintendo Wii U";
								} else if (respuestamodelo2 == 7)
								{
									modelodeconsola = "Nintendo Switch";
								} else if (respuestamodelo2 == 8)
								{
									modelodeconsola = "Gameboy";
								} else if (respuestamodelo2 == 9)
								{
									modelodeconsola = "Gameboy Colors";
								} else if (respuestamodelo2 == 10)
								{
									modelodeconsola = "Gameboy Advance";
								} else if (respuestamodelo2 == 11)
								{
									modelodeconsola = "Nintendo DS";
								} else if (respuestamodelo2 == 12)
								{
									modelodeconsola = "Nintendo DSi";
								} else if (respuestamodelo2 == 13)
								{
									modelodeconsola = "Nintendo 3DS";
								} else {
									modelodeconsola = "Nintendo New 3DS";
								}
								Listaconsolas.at(consolamodificar) -> setModelo(modelodeconsola);
								cout << "Modelo cambiado exitosamente!\n";

							} else {//Verifica si la consola a modificar es de sony

								cout << "Escoga el nuevo modelo de la consola: \n";
								cout << "1) Play Station 1\n";
								cout << "2) Play Station 2\n";
								cout << "3) Play Station 3\n";
								cout << "4) Play Station 4\n";
								cout << "5) PSP\n";
								cout << "6) PSP Vita\n";
								int respuestamodelo2;
								cin >> respuestamodelo2;
								while(respuestamodelo2 < 1 || respuestamodelo2 > 6) {
									cout << "Numero invalido, ingrese su numero de nuevo!\n";
									cin >> respuestamodelo2;
								}
								if (respuestamodelo2 == 1) //Mira el modelo de la consola
								{
									modelodeconsola = "Play Station 1";
								} else if (respuestamodelo2 == 2)
								{
									modelodeconsola = "Play Station 2";
								} else if (respuestamodelo2 == 3) 
								{
									modelodeconsola = "Play Station 3";
								} else if (respuestamodelo2 == 4)
								{
									modelodeconsola = "Play Station 4";
								} else if (respuestamodelo2 == 5)
								{
									modelodeconsola = "PSP";
								} else {
									modelodeconsola = "PSP Vita";
								}
								Listaconsolas.at(consolamodificar) -> setModelo(modelodeconsola);
								cout << "Modelo cambiado exitosamente!\n";

							}
							delete temp;

						} else if (respuestamodificar2 == 3)
						{
							cout << "Ingrese el nuevo estado de la consola.\n";
							string newestado;
							cin >> newestado;
							Listaconsolas.at(consolamodificar) -> setEstado(newestado);
							cout << "Estado modificado exitosamente!\n";

						} else if (respuestamodificar2 == 4)
						{
							bool norepetido = true;
							cout << "Ingrese el nuevo numero de serie de la consola.\n";
							int numerodeserie2;
							cin >> numerodeserie2;
							for (int i = 0; i < Listaconsolas.size(); ++i)
							{
								if (numerodeserie2 == Listaconsolas.at(i) -> getNumeroSerie())
								{
									norepetido = false;
								}
							}
							while(norepetido == false) {
								cout << "Numero de serie repetido, ingrese el numero de serie de nuevo!\n";
								cin >> numerodeserie2;
								norepetido = true;
								for (int i = 0; i < Listaconsolas.size(); ++i)
								{
									if (numerodeserie2 == Listaconsolas[i] -> getNumeroSerie())
									{
										norepetido = false;
									}
								}
							}
							Listaconsolas.at(consolamodificar) -> setNumeroSerie(numerodeserie2);
							cout << "Numero de serie cambiado exitosamente!\n";

						} else {
							cout << "Ingrese el nuevo precio.\n";
							int nuevoprecio;
							cin >> nuevoprecio;
							Listaconsolas.at(consolamodificar) -> setPrecio(nuevoprecio);
							cout << "Precio cambiado exitosamente!";
						}

					} else {//Modificar Videojuego

					}

					cout << endl;

				} else if(respuesta3 == 3) { //Eliminar

				} else {
					cout << "Consolas: \n";
					for (int i = 0; i < Listaconsolas.size(); ++i)
					{
						cout << i << ") " << (Listaconsolas.at(i) -> getModelo()) << endl;
					}
					cout << "Videojuegos: \n";
					for (int i = 0; i < ListaVideojuegos.size(); ++i)
					{
						cout << i << ") " << (ListaVideojuegos.at(i) -> getNombre()) << endl;
					}
					cout << endl;
				}
				cout << "Desea salir de su cuenta administrador? 1 = Salir 0 = No salir\n";
				cin >> online1;
				while(online1 < 0 || online1 > 1) {
					cout << "Numero invalido, ingrese su numero de nuevo!\n";
					cin >> online1;
				}
				cout << endl;

			}




		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
		} else {// Si es Vendedor
			cout<<endl;
			string nombrevendedor;
			cout<<"Me podria escribir su nombre: ";
			cin>>nombrevendedor;



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
					{//AGREGAR A EL INVENTARIO	
						funcionAgregar(Listaconsolas, ListaVideojuegos);
					}//
					if (opcv==2)
					{
						escribirbinario(Listaconsolas, ListaVideojuegos);
						//funcionvender();
					}
					cout<<"Bienvenido vendedor\n ¿Que es lo que desea realizar?\n1.-Agregar a el inventario\n2.-Vender\n3.-Sair\nIngrese su opcion: ";
					cin>>opcvendedor;
				}
				cout << "Desea salir? 1 = Salir 0 = No salir\n";
				cin >> online2;
				while(online2 < 0 || online2 > 1) {
					cout << "Numero invalido, ingrese su numero de nuevo!\n";
					cin >> online2;
				}
				cout << endl;
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
		cout << endl;
		
	}
	
	cout << "Nos vemos luego!\n";

	/*Nintendo* nin=new Nintendo(2017,"Sega","bueno",111,15.30);

	//nin->{};
	cout<< "\nYOLOYOLOYOLOYOLOYOLO"<<endl;
	cout<<nin->getModelo()<<"ESOOOOOO"<<endl;
		return 0;*/
}


void funcionAgregar(vector<Consolas*> Listaconsolas, vector<Videojuegos*> ListaVideojuegos){
	cout << endl<<endl;
	cout << "Que desea agregar?\n";
	cout << "1) Consola\n";
	cout << "2) Videojuego\n";
	int respuesta4;
	cin >> respuesta4;
	while(respuesta4==3)
	{
		cout << "Numero invalido, ingrese su numero de nuevo!\n";
		cin >> respuesta4;
	}

	if (respuesta4 == 1) //Agregar Consola al inventario
	{
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
		while(norepetido == false)
		{
			cout<<endl;
			cout << "Numero de serie repetido, ingrese el numero de serie de nuevo!\n";
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

		cout << "De que compañia es la consola?\n";
		cout << "1) Microsoft\n";
		cout << "2) Nintendo\n";
		cout << "3) Sony\n";

		int respuesta5;
		cin >> respuesta5;
		while(respuesta5 < 1 || respuesta5 > 3)
		{
			cout << "Numero invalido, ingrese su numero de nuevo!\n";
			cin >> respuesta5;
		}
		if (respuesta5 == 1)
		{//Agregando consola de microsoft
			cout << "Escoga el modelo de la consola: \n";
			cout << "1) Xbox\n";
			cout << "2) Xbox 360\n";
			cout << "3) Xbox One\n";
			int respuestamodelo;
			cin >> respuestamodelo;
			while(respuestamodelo < 1 || respuestamodelo > 3) {
								cout << "Numero invalido, ingrese su numero de nuevo!\n";
								cin >> respuestamodelo;
							}
							if (respuestamodelo == 1) //Mira el modelo de la consola
							{
								modelodeconsola = "Xbox";
							} else if (respuestamodelo == 2)
							{
								modelodeconsola = "Xbox 360";
							} else {
								modelodeconsola = "Xbox One";
							}
							Listaconsolas.push_back(new Microsoft(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola));
							cout << "Consola agregada exitosamente!\n";
						} else if (respuesta5 == 2)
						{//Agregar consola de nintendo

							cout << "Escoga el modelo de la consola: \n";
							cout << "1) Nintendo Entertainment System\n";
							cout << "2) Super Nintendo Entertainment System\n";
							cout << "3) Nintendo 64\n";
							cout << "4) Nintendo Gamecube\n";
							cout << "5) Nintendo Wii\n";
							cout << "6) Nintendo Wii U\n";
							cout << "7) Nintendo Switch\n";
							cout << "8) Gameboy\n";
							cout << "9) Gameboy Colors\n";
							cout << "10) Gameboy Advance\n";
							cout << "11) Nintendo DS\n";
							cout << "12) Nintendo DSi\n";
							cout << "13) Nintendo 3DS\n";
							cout << "14) Nintendo New 3DS\n";
							int respuestamodelo;
							cin >> respuestamodelo;
							while(respuestamodelo < 1 || respuestamodelo > 14) {
								cout << "Numero invalido, ingrese su numero de nuevo!\n";
								cin >> respuestamodelo;
							}

							if (respuestamodelo == 1) //Mira el modelo de la consola
							{
								modelodeconsola = "Nintendo Entertainment System";
							} else if (respuestamodelo == 2)
							{
								modelodeconsola = "Super Nintendo Entertainment System";
							} else if (respuestamodelo == 3)
							{
								modelodeconsola = "Nintendo 64";
							} else if (respuestamodelo == 4)
							{
								modelodeconsola = "Nintendo Gamecube";
							} else if (respuestamodelo == 5)
							{
								modelodeconsola = "Nintendo Wii";
							} else if (respuestamodelo == 6)
							{
								modelodeconsola = "Nintendo Wii U";
							} else if (respuestamodelo == 7)
							{
								modelodeconsola = "Nintendo Switch";
							} else if (respuestamodelo == 8)
							{
								modelodeconsola = "Gameboy";
							} else if (respuestamodelo == 9)
							{
								modelodeconsola = "Gameboy Colors";
							} else if (respuestamodelo == 10)
							{
								modelodeconsola = "Gameboy Advance";
							} else if (respuestamodelo == 11)
							{
								modelodeconsola = "Nintendo DS";
							} else if (respuestamodelo == 12)
							{
								modelodeconsola = "Nintendo DSi";
							} else if (respuestamodelo == 13)
							{
								modelodeconsola = "Nintendo 3DS";
							} else {
								modelodeconsola = "Nintendo New 3DS";
							}

							Listaconsolas.push_back(new Nintendo(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola));
							cout << "Consola agregada exitosamente!\n";
						} else {//Agregar consola de sony

							cout << "Escoga el modelo de la consola: \n";
							cout << "1) Play Station 1\n";
							cout << "2) Play Station 2\n";
							cout << "3) Play Station 3\n";
							cout << "4) Play Station 4\n";
							cout << "5) PSP\n";
							cout << "6) PSP Vita\n";
							int respuestamodelo;
							cin >> respuestamodelo;
							while(respuestamodelo < 1 || respuestamodelo > 6) {
								cout << "Numero invalido, ingrese su numero de nuevo!\n";
								cin >> respuestamodelo;
							}
							if (respuestamodelo == 1) //Mira el modelo de la consola
							{
								modelodeconsola = "Play Station 1";
							} else if (respuestamodelo == 2)
							{
								modelodeconsola = "Play Station 2";
							} else if (respuestamodelo == 3) 
							{
								modelodeconsola = "Play Station 3";
							} else if (respuestamodelo == 4)
							{
								modelodeconsola = "Play Station 4";
							} else if (respuestamodelo == 5)
							{
								modelodeconsola = "PSP";
							} else {
								modelodeconsola = "PSP Vita";
							}

							Listaconsolas.push_back(new Sony(aniodesalida, modelodeconsola, estadodeconsola, numerodeserie, preciodeconsola));
							cout << "Consola agregada exitosamente!\n";
						}
						cout << endl;

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
						while(respuesta5 < 1 || respuesta5 > 9) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> respuesta5;
						}
						if (respuesta5 == 1)
						{//Agregar juego de microsoft
							ListaVideojuegos.push_back(new JuegosMicrosoft(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 2)
						{//Agregar juego de nintendo
							ListaVideojuegos.push_back(new juegosNintendo(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 3)
						{//Agregar juego de sony
							ListaVideojuegos.push_back(new juegosSony(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 4)
						{//Agregar juego de Sega
							ListaVideojuegos.push_back(new juegosSega(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 5)
						{//Agregar juego de bandai
							ListaVideojuegos.push_back(new juegosBandai(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 6)
						{//Agregar juego de electronic arts
							ListaVideojuegos.push_back(new juegosElectronicArts(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 7)
						{//Agregar juego de konami
							ListaVideojuegos.push_back(new juegosKonami(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
						} else if (respuesta5 == 8)
						{//Agregar juego de square enix
							ListaVideojuegos.push_back(new juegosSquareEnix(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
							cout << "Juego agregado exitosamente!\n";
		} else { //Agregar juego de ubisoft
			ListaVideojuegos.push_back(new juegosUbisoft(nombrejuego, aniodesalida2, consoladeljuego, numjugadores, genero, estadojuego, numserie, preciojuego));
			cout << "Juego agregado exitosamente!\n";
		}
		cout << endl;
	} //Fin if agregar consola o videojuego

}


/*
string hora()
{

string horaactual;
/*
//para solo imprimir la hora en void 
time_t tiempo = time(0);
struct tm *hora = localtime(&tiempo);
char output[50];
strftime(output,50,"%H:%M:%S",hora);
strftime(output,50,"%H:%M:%S",hora);
printf("%s\n",output);
*/
//return horaactual;
//}

string hora()
{
	time_t tAct = time(0);
	string horaaentrada=asctime(localtime(&tAct));


	return horaaentrada;
}

void funcionvender()
{
	
	cout<<"    ___\n   |[_]|\n   |+ ;| GAMEHUB\n   `---'\n";

	 
	cout<<"\n      Bienvenido vendedor\n";

	cout<<"";

	string respv="z";
	while(respv!="s" || respv!="S")
	{	 
		cout<<endl;
		cout<<"¿Que es lo que desea vender?\n";
		cout<<"a.-Consolas\nb.-Videojuegos\n"<<endl;
		cin>>respv;
		if (respv=="a" || respv=="A")
		{
 			


			//vender consolas
 		}
	 	if (respv=="b" || respv=="B")//si VENDER VIDEOJUEGOS
	 	{
	 		


	 		/*
	 		string nomvijuego;
	 		cout<<"Nombre del videojuego: ";
	 		cin>>nomvijuego;

	 		int aniojuego;
	 		cout<<"\nAño del videojuego";
	 		cin>>aniojuego;

	 		string consolavideojuego;
	 		cout<<"Nombre del videojuego: ";
	 		cin>>nomvijuego;





	 		string respventavideo="o";
	 		while(respventavideo!="s"||respventavideo!="S")
	 		{
	 			cout<<endl;
	 			cout<<" De cual compañia desea el videojuego"<<endl;
	 			cout<<"1.-Microsoft\n2.-Sony\n3.-Nintendo\n4.-Bandai\n5.-Konami\n6.-Square Enix\n7.-Electronic Arts\n8.-SEGA\n9.-Ubisoft\n ";
			*/	


	 			cout<<"¿Desea aregar otro videojuego?";
	 			cin>>respv;
	 		}	
	 	}

	 	cout<<"¿Desea vender algo mas?(s/n)\n";
	 	cin>>respv;
	}


void funciondibujo()
{
	cout<<"**************BIENVENIDO******************\n";
}



void escribirbinario(	vector <Consolas*> consola, vector <Videojuegos*> videojuego){
 //,vector <Videojuegos*> tlistavideojuegos

	ofstream escritura;
 
	

	Videojuegos* tlistavideojuegos;
	Consolas* tlistaconsolas;


	escritura.open("binario.bin", ios::binary|ios::app);	
	escritura.write((char*)(&tlistaconsolas),sizeof(consola));
	escritura.write((char*)(&tlistavideojuegos),sizeof(Videojuegos));
	escritura.close();

	cout<< "DATOS GUARDADOS CON EXCITO"<<endl;
}


void leerbinario(vector <Consolas*> consola, vector <Videojuegos*> videojuego){
	

	ifstream lectura;
	Consolas* listaconsolas;
	Videojuegos* listavideojuegos;

//	vector <Consolas*> listaconsolas;
//	vector <Videojuegos*> listavideojuegos;

	lectura.open("binario.bin", ios::binary|ios::app);
	lectura.seekg(0,ios::end);//ir a el final del fichero
	long longitudFichero=lectura.tellg();//Ver posicion para saber el tamaño
	lectura.seekg(0, ios::beg);//volver a el principio
 
	if(!lectura.good()) return;
 
	for (int i = 0; i < (longitudFichero/sizeof(consola)); i++) {
		lectura.read((char*)(&listaconsolas),sizeof(consola));
		lectura.read((char*)(&listaconsolas),sizeof(videojuego));
		//cout<<lectura.tellg();
		//	cout<<cliente<<endl;
	}

	cout<<"lectura realizada exitosamente"<<endl;
	lectura.close();
}