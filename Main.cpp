#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

int main(int argc, char const *argv[])
{
	Administrador* admin = new Administrador(); //Administrador predefinido
	int respuesta1 = 0;
	while (respuesta1 == 0) {
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
						{//Agregar consola de microsoft
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
							for (int i = 0; i < consolasMicrosoft.size(); ++i)
							{
								if (numerodeserie == consolasMicrosoft[i] -> getNumeroSerie())
								{
									norepetido = false;
								}
							}
							while(norepetido == false) {
								cout << "Numerio de serie repetido, ingrese el numero de serie de nuevo!\n";
								cin >> numerodeserie;
								norepetido = true;
								for (int i = 0; i < consolasMicrosoft.size(); ++i)
								{
									if (numerodeserie == consolasMicrosoft[i] -> getNumeroSerie())
									{
										norepetido = false;
									}
								}
							}
							cout << "Ingres el precio de la Consola: \n";
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
							
						} else if (respuesta5 == 2)
						{//Agregar consola de nintendo
							

						} else {//Agregar consola de sony

						}

					} else { //Agregar Videojuegos

					}

				} else if (respuesta3 == 2)
				{ //Modificar
					

				} else { //Eliminar

				}
			}

		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
		} else {// Si es Vendedor
			int online2 = 0;
			while(online2 == 0) {

			}
		}

		cout << "Desea salir de GAMEHUB? (S/N)\n";
		char respuestaFinal;
		cin >> respuestaFinal;
		if (respuestaFinal == 'S' || respuestaFinal == 's')
		{
			respuesta1 = 1;
		}

		//Borrar vector de consolasMicrosoft
		for (int i=0; i<consolasMicrosoft.size(); i++){
    		delete consolasMicrosoft[i];
  		}
		consolasMicrosoft.clear();

		//Borrar vector de consolasNintendo
		for (int i=0; i<consolasNintendo.size(); i++){
    		delete consolasNintendo[i];
  		}
		consolasNintendo.clear();

		//Borrar vector de consolasSony
		for (int i=0; i<consolasSony.size(); i++){
    		delete consolasSony[i];
  		}
		consolasSony.clear();

	}
	cout << "Nos vemos luego!\n";

	/*Nintendo* nin=new Nintendo(2017,"Sega","bueno",111,15.30);

	//nin->{};
	cout<< "\nYOLOYOLOYOLOYOLOYOLO"<<endl;
	cout<<nin->getModelo()<<"ESOOOOOO"<<endl;
		return 0;*/
}