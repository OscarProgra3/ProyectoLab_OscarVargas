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

Venta* funcionvender(vector <Videojuegos*> ListaVideojuegosT,vector <Consolas*> listaconsolasT);
void funcionAgregar(vector<Consolas*> Listaconsolas, vector<Videojuegos*> ListaVideojuegos);
void funciondibujo();
void imprimirVenta(Venta* venta);

string hora();

void escribirbinario(vector<Consolas*> Listaconsolas, vector<Videojuegos*> ListaVideojuegos);
void leerbinario(vector <Consolas*> consola, vector <Videojuegos*> videojuego);
void funcionListarJuego(vector<Videojuegos*>);
void funcionListarConsola(vector<Consolas*>);

int main()
{
	
	vector<Consolas*> Listaconsolas;
	vector<Videojuegos*> ListaVideojuegos;
	


    cout<<endl<<endl;

	Administrador* admin = new Administrador(); //Administrador predefinido
	int respuesta1 = 0;

	vector<Microsoft*> consolasMicrosoft;
	vector<Nintendo*> consolasNintendo;
	vector<Sony*> consolasSony;
	while(respuesta1!=1){



		cout << "Bienvenido a GAMEHUB\n";
		cout << "Como desea entrar?\n";
		cout << "1) Entrar como Administrador\n";
		cout << "2) Entrar como Vendedor\n";
		int respuesta2;
		cin >> respuesta2;


		while(respuesta2 < 1 || respuesta2 > 2)
		{
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
		} else
		{//Se hace false si una de las dos es diferente
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
				while(respuesta4 < 1 || respuesta4 > 3) {
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
						} else
						{//Agregar consola de sony

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

					} else
					{ //Agregar Videojuegos

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
						cout << "Cual videojuego desea modificar?\n";
						for (int i = 0; i < ListaVideojuegos.size(); ++i)
						{
							cout << i << ") " << (ListaVideojuegos.at(i) -> getNombre()) << endl;
						}
						int juegomodificar;
						cin >> juegomodificar;
						while (juegomodificar < 0 || juegomodificar > ListaVideojuegos.size()) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> juegomodificar;
						}
						cout << "Que desea modificar!\n";
						cout << "1) Nombre\n";
						cout << "2) Año de salida\n";
						cout << "3) Consola\n";
						cout << "4) Numero de jugadores\n";
						cout << "5) Genero del juego\n";
						cout << "6) Estado del juego\n";
						cout << "7) Numero de serie\n";
						cout << "8) Precio del juego\n";
						int respuestamodificar3;
						cin >> respuestamodificar3;
						while(respuestamodificar3 < 1 || respuestamodificar3 > 8) {
							cout << "Numero invalido, ingrese su numero de nuevo!\n";
							cin >> respuestamodificar3;
						}

						if (respuestamodificar3 == 1)
						{//Modificar el nombre
							string nombreTemp2;
							cout << "Ingrese el nuevo nombre del juego: " << endl;
							cin >> nombreTemp2;
							ListaVideojuegos.at(juegomodificar) -> setNombre(nombreTemp2);
							cout << "Nombre modificado exitosamente!" << endl;
						} else if (respuestamodificar3 == 2)
						{//Modificar el año de salida
							int aniodesalida3;
							cout << "Ingrese el nuevo año de salida: " << endl;
							cin >> aniodesalida3;
							ListaVideojuegos.at(juegomodificar) -> setAnio(aniodesalida3);
							cout << "Año de salida modificado exitosamente!" << endl;
						} else if (respuestamodificar3 == 3)
						{//Modificar la consola
							string consolaTemp;
							cout << "Ingrese la consola nueva: " << endl;
							cin >> consolaTemp;
							ListaVideojuegos.at(juegomodificar) -> setConsola(consolaTemp);
							cout << "Consola modificada exitosamente!" << endl;
						} else if (respuestamodificar3 == 4)
						{//Modificar el numero de jugadores
							int numdejug;
							cout << "Ingrese el nuevo numero de jugadores: " << endl;
							cin >> numdejug;
							ListaVideojuegos.at(juegomodificar) -> setNumjugadores(numdejug);
							cout << "Numero de jugadores modificado exitosamente!" << endl;
						} else if (respuestamodificar3 == 5)
						{//Modificar el genero del juego
							string generoTemp;
							cout << "Ingrese el nuevo genero: " << endl;
							cin >> generoTemp;
							ListaVideojuegos.at(juegomodificar) -> setGenero(generoTemp);
							cout << "Genero modificado exitosamente!" << endl;
						} else if (respuestamodificar3 == 6)
						{//Modificar el estado del juego
							string estadojuegoT;
							cout << "Ingrese el nuevo estado: " << endl;
							cin >> estadojuegoT;
							ListaVideojuegos.at(juegomodificar) -> setEstado(estadojuegoT);
							cout << "Estado modificado exitosamente!" << endl;
						} else if (respuestamodificar3 == 7)
						{//Modificar el numero de serie
							bool norepetido3 = false;
							int numdeserieT;
							cout << "Ingrese el numero de serie: " << endl;
							cin >> numdeserieT;
							for (int i = 0; i < ListaVideojuegos.size(); ++i)
							{
								if (norepetido3 == ListaVideojuegos.at(i) -> getNumSerie())
								{
									norepetido3 = false;
								}
							}
							while(norepetido3 == false) {
								cout << "Numero de serie repetido, ingrese el numero de serie de nuevo!\n";
								cin >> numdeserieT;
								norepetido3 = true;
								for (int i = 0; i < ListaVideojuegos.size(); ++i)
								{
									if (norepetido3 == ListaVideojuegos.at(i) -> getNumSerie())
									{
										norepetido3 = false;
									}
								}
							}
							ListaVideojuegos.at(juegomodificar) -> setNumSerie(numdeserieT);
							cout << "Numero de serie modificado exitosamente!" << endl;
						} else {//Modificar el precio
							int precioT;
							cout << "Ingrese el nuevo precio: " << endl;
							cin >> precioT;
							ListaVideojuegos.at(juegomodificar) -> setPrecio(precioT);
							cout << "Precio modificado exitosamente!" << endl;
						}
					}

					cout << endl;

				} else if(respuesta3 == 3) { //Eliminar

				} else {//Listar
					cout << "Consolas: \n";
					funcionListarConsola(Listaconsolas);
					cout << "Videojuegos: \n";
					funcionListarJuego(ListaVideojuegos);
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
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
		
		} else
		{// Si es Vendedor
			cout<<endl;
			string horaentrada=hora();
			cout<<"hora de ingreso"<< horaentrada;
			string nombrevendedor;
			cout<<"Me podria escribir su nombre vendedor: ";
			cin>>nombrevendedor;

			Vendedor* vendedor;

			
			int online2 = 0;
			while(online2 == 0)
			{
				int cantartvend=0;//cantidad de articulos vendidos
				double dinerogenerado=0.0;
				

				int opcvendedor=0;
				while(opcvendedor!=3)
				{
					
					cout<<"Bienvenido vendedor\n ¿Que es lo que desea realizar?\n1.-Agregar a el inventario\n2.-Vender\n3.-Sair\nIngrese su opcion: ";
					cin>>opcvendedor;
					if (opcvendedor==1)
					{//AGREGAR A EL INVENTARIO	
						//funcionAgregar(Listaconsolas, ListaVideojuegos);
						//Agregar
						cout << "Que desea agregar?\n";
						cout << "1) Consola\n";
						cout << "2) Videojuego\n";
						int respuesta4;
						cin >> respuesta4;
						while(respuesta4 < 1 || respuesta4 > 3) {
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
							while(norepetido == false)
							{
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
						} else
						{//Agregar consola de sony

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

					} else
					{ //Agregar Videojuegos

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
					//-----------------------------------------------------------------	vender
					}//vender
					if (opcvendedor==2)
					{		
						cout << endl;
						//Venta* venta;
						//venta=funcionvender(ListaVideojuegos,Listaconsolas);
						//venta->setNombreusuario(nombrevendedor);

						//-------------------------------------------------------------------------
						Videojuegos* juegot;
						vector <Consolas*> consolasvendidas;
						vector <Videojuegos*> juegosvendidos;
						int cantartvend=0;
						double subtotal=0;
						cout<<"    ___\n   |[_]|\n   |+ ;| GAMEHUB\n   `---'\n";
						cout<<"\n      Bienvenido vendedor\n";
						cout<<endl;

						Venta* venta;

						int respv=5;
						while(respv!=3)
						{	 
							cout<<endl;
							cout<<"¿Que es lo que desea vender?\n";
							cout<<"1.-Consolas\n2.-Videojuegos\nOpcion: "<<endl;
							cin>>respv;//respuesta venta
							cout<<endl<<endl;

							if (respv==1)
							{//vender consolas
								
								cout<<"----------*LISTA DE CONSOLAS*-----------"<<endl;
								for (int i = 0; i < Listaconsolas.size(); ++i)
								{
									cout << "consola numero: "<<i<<endl;
									cout << "Consola numero: " << (i+1) << endl;
									cout << "El precio es de: " << Listaconsolas.at(i) -> getPrecio() << endl;
									cout << "----------------------------------------------" << endl;
								}
								int opcconsola;
									Consolas*  consolat;
									cout<< "¿Cual numero de consola desea?"<<endl;
									cin>>opcconsola;
									
									for (int i = 0; i < Listaconsolas.size(); ++i)
									{
										if (i==opcconsola)
										{
											consolat=Listaconsolas.at(i);
											consolasvendidas.push_back(consolat);
											cantartvend++;
											cout<<"Agregado a el carrito"<<endl;
											cout<<"-------------------"<<cantartvend<<endl;
										}else{
											cout<<"ese numero no existe (-.-')"<<endl;
										}
									}
					 		}
						 	if (respv==2)
						 	{//VENDER VIDEOJUEGOS
						 		cout<<"----------*LISTA DE VIDEOJUEGOS*-----------"<<endl;

					 			for (int i = 0; i < ListaVideojuegos.size(); ++i)
								{
									cout << "Videojuego numero: "<<i<<endl;
									cout << "El nombre del videojuego es: " << ListaVideojuegos.at(i) -> getNombre() << endl;
									cout << "El precio es de: " << ListaVideojuegos.at(i) -> getPrecio() << endl;					
									cout << "----------------------------------------------------" << endl;
								}
								Videojuegos* juegost;
								int opcjuego;
								cout<< "¿Cual numero de videojuego desea?"<<endl;
								cin>>opcjuego;
						 			
								for (int i = 0; i < ListaVideojuegos.size(); ++i)
								{
									if (i==opcjuego)
										{
											juegost=ListaVideojuegos.at(i);
											juegosvendidos.push_back(juegost);
											cantartvend++;
											cout<<"Agregado a el carrito"<<endl;
											cout<<"-------------------"<<cantartvend<<endl;
										}else
										{
											cout<<"ese numero no existe (-.-')"<<endl;
										}
									}
									//cout<<consolasvendidas.at(0)->getEstado();
							
								cantartvend++;
						 	}
						 	char respventa;
						 	cout<<"¿desea vender algo mas?(s/n)";
						 	cin>>respventa;
						 	if (respventa=='s' || respventa=='S')
						 	{
						 		respv=5;
						 	}else
						 	{
						 		string nomcli;//nombre del cliente
						 		cout<<"A nombre de quien sera la factura: ";
						 		cin>>nomcli;
						 		string horafinalizacion=hora();

						 		for (int i = 0; i < consolasvendidas.size(); ++i)
						 		{
						 			subtotal+=consolasvendidas.at(i)->getPrecio();
						 		}
						 		for (int i = 0; i < juegosvendidos.size(); ++i)
						 		{
						 			subtotal+=juegosvendidos.at(i)->getPrecio();
						 		}

						 		cout<<"subtotal: "<<subtotal<<endl;

						 		//venta=new Venta(nomcli,consolasvendidas,juegosvendidos,horafinalizacion,nombrevendedor,subtotal);
								
						 		venta->setNombrecliente(nomcli);
						 		venta->setListaconsolas(consolasvendidas);
						 		venta->setListavideojuegos(juegosvendidos);
						 		venta->setHorafinalizacion(horafinalizacion);
								venta->setNombreusuario(nombrevendedor);
								venta->setSubtotal(subtotal);
								

						 		respv=3;
						 	}		
						}



						//---------------------------------------------------------------------------------------------------




						//cout << venta->getListavideojuegos(0)->getNombre() <<endl;

						imprimirVenta(venta);

						string horasalida=hora();
					}
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
			escribirbinario(Listaconsolas, ListaVideojuegos);

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

		}else{
			respuesta1=0;
		}
		cout << endl;
	}
}
	/*Nintendo* nin=new Nintendo(2017,"Sega","bueno",111,15.30);
	
	//nin->{};
	cout<< "\nYOLOYOLOYOLOYOLOYOLO"<<endl;
	cout<<nin->getModelo()<<"ESOOOOOO"<<endl;
		return 0;*/
	//}

Venta* funcionvender(vector <Videojuegos*> ListaVideojuegosT,vector <Consolas*> ListaconsolasT)
{

	Videojuegos* juegot;
	vector <Consolas*> consolasvendidas;
	vector <Videojuegos*> juegosvendidos;
	int cantartvend=0;
	double subtotal=0;

	cout<<"    ___\n   |[_]|\n   |+ ;| GAMEHUB\n   `---'\n";
	cout<<"\n      Bienvenido vendedor\n";
	cout<<endl;

	int respv=5;
	while(respv!=3)
	{	 
		cout<<endl;
		cout<<"¿Que es lo que desea vender?\n";
		cout<<"1.-Consolas\n2.-Videojuegos\nOpcion: "<<endl;
		cin>>respv;//respuesta venta
		cout<<endl<<endl;

		if (respv==1)
		{//vender consolas
			
			cout<<"----------*LISTA DE CONSOLAS*-----------"<<endl;
			for (int i = 0; i < ListaconsolasT.size(); ++i)
			{
				cout << "consola numero: "<<i<<endl;
				cout << "Consola numero: " << (i+1) << endl;
				cout << "El precio es de: " << ListaconsolasT.at(i) -> getPrecio() << endl;
				cout << "----------------------------------------------" << endl;
			}
			int opcconsola;
				Consolas*  consolat;
				cout<< "¿Cual numero de consola desea?"<<endl;
				cin>>opcconsola;
				
				for (int i = 0; i < ListaconsolasT.size(); ++i)
				{
					if (i==opcconsola)
					{
						consolat=ListaconsolasT.at(i);
						consolasvendidas.push_back(consolat);
						cantartvend++;
						cout<<"Agregado a el carrito"<<endl;
						cout<<"-------------------"<<cantartvend<<endl;
					}else{
						cout<<"ese numero no existe (-.-')"<<endl;
					}
				}
 		}
	 	if (respv==2)
	 	{//VENDER VIDEOJUEGOS
	 		cout<<"----------*LISTA DE VIDEOJUEGOS*-----------"<<endl;

 			for (int i = 0; i < ListaVideojuegosT.size(); ++i)
			{
				cout << "Videojuego numero: "<<i<<endl;
				cout << "El nombre del videojuego es: " << ListaVideojuegosT.at(i) -> getNombre() << endl;
				cout << "El precio es de: " << ListaVideojuegosT.at(i) -> getPrecio() << endl;					
				cout << "----------------------------------------------------" << endl;
			}
			Videojuegos* juegost;
			int opcjuego;
			cout<< "¿Cual numero de videojuego desea?"<<endl;
			cin>>opcjuego;
	 			
			for (int i = 0; i < ListaVideojuegosT.size(); ++i)
			{
				if (i==opcjuego)
					{
						juegost=ListaVideojuegosT.at(i);
						juegosvendidos.push_back(juegost);
						cantartvend++;
						cout<<"Agregado a el carrito"<<endl;
						cout<<"-------------------"<<cantartvend<<endl;
					}else
					{
						cout<<"ese numero no existe (-.-')"<<endl;
					}
				}
				//cout<<consolasvendidas.at(0)->getEstado();
		
			cantartvend++;
	 	}
	 	char respventa;
	 	cout<<"¿desea vender algo mas?(s/n)";
	 	cin>>respventa;
	 	if (respventa=='s' || respventa=='S')
	 	{
	 		respv=5;
	 	}else
	 	{
	 		string nomcli;//nombre del cliente
	 		cout<<"A nombre de quien sera la factura: ";
	 		cin>>nomcli;
	 		string horafinalizacion=hora();

	 		for (int i = 0; i < consolasvendidas.size(); ++i)
	 		{
	 			subtotal+=consolasvendidas.at(i)->getPrecio();
	 		}
	 		for (int i = 0; i < juegosvendidos.size(); ++i)
	 		{
	 			subtotal+=juegosvendidos.at(i)->getPrecio();
	 		}

	 		cout<<"subtotal: "<<subtotal<<endl;

	 		Venta* venta=new Venta(nomcli,consolasvendidas,juegosvendidos,horafinalizacion,"temporal",subtotal);
	
	 		return venta;
	 		respv=3;
	 	}		
	}


}







string hora()
{
	time_t tAct = time(0);
	string horaaentrada=asctime(localtime(&tAct));
	return horaaentrada;
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

void funcionListarConsola(vector<Consolas*> ListaconsolasT) {
	for (int i = 0; i < ListaconsolasT.size(); ++i)
	{
		cout << "Consola numero: " << (i+1) << endl;
		cout << "El año de salida es: " << ListaconsolasT.at(i) -> getAniosalida() << endl;
		cout << "El modelo es: " << ListaconsolasT.at(i) -> getModelo() << endl;
		cout << "El estado en el que esta es: " << ListaconsolasT.at(i) -> getEstado() << endl;
		cout << "El numero de serie es: " << ListaconsolasT.at(i) -> getNumeroSerie() << endl;
		cout << "El precio es de: " << ListaconsolasT.at(i) -> getPrecio() << endl;
		cout << "----------------------------------------------" << endl;
	}
}

void funcionListarJuego(vector<Videojuegos*> ListaVideojuegosT) {
	for (int i = 0; i < ListaVideojuegosT.size(); ++i)
	{
		cout << "Videojuego numero: " << (i+1) << endl;
		cout << "El nombre del videojuego es: " << ListaVideojuegosT.at(i) -> getNombre() << endl;
		cout << "El año en el que salio es: " << ListaVideojuegosT.at(i) -> getAnio() << endl;
		cout << "La consola del videojuego es: " << ListaVideojuegosT.at(i) -> getConsola() << endl;
		cout << "El numero de jugadores es de: " << ListaVideojuegosT.at(i) -> getNumjugadores() << endl;
		cout << "El genero del juego es: " << ListaVideojuegosT.at(i) -> getGenero() << endl;
		cout << "El estado del juego es: " << ListaVideojuegosT.at(i) -> getEstado() << endl;
		cout << "El numero de serie: " << ListaVideojuegosT.at(i) -> getNumSerie() << endl;
		cout << "El precio es de: " << ListaVideojuegosT.at(i) -> getPrecio() << endl;
		cout << "----------------------------------------------------" << endl;
	}
}


void imprimirVenta(Venta* venta)
{
	int contarticulos=0;
	ofstream  salida;
	stringstream stm;
	string fichero;

	string horafinalizacion=hora();
	stm << "./log_ventas/" << horafinalizacion << ".log";
	fichero = stm.str();
	salida.open(fichero.c_str());
	salida << "-----------GAMEHUB---------" << endl;
	salida << "---------------------------" << endl;
	salida << venta->getHorafinalizacion()<<"yolo" << endl;
	salida << "Vendedor: " << venta->getNombreusuario()<< endl;
	salida << "Cliente: " << venta->getNombrecliente() << endl;
	int contador = venta->getTamConsola() + venta->getTamJuegos();

	salida << "Cantidad de articulos " << contador  << endl;

	for (int i=0; i < venta->getTamConsola(); i++)
	{
		salida << venta->getListaconsolas.at(i)->getModelo() << "    L." << venta->getListaconsolas.at(i)->getPrecio() << endl;
	}
	for (int i=0; i < venta->getTamJuegos(); i++)
	{
 		salida << venta->getListavideojuegos.at(i)->getNombre() << "     L." << venta->getListavideojuegos.at(i)->getPrecio() << endl;
	}

	salida << "Subtotal: " << venta->getSubtotal() << endl;
	double impuesto = venta->getSubtotal()*0.15;
	salida << "Impuesto: " << impuesto << endl;
	double total = venta->getSubtotal() + impuesto;
	salida << "Total: " << total << endl;
	salida.close();
}