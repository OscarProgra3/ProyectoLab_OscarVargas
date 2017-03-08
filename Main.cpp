#include <iostream>
#include <string>
#include <vector>

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

using namespace std;

int main(int argc, char const *argv[])
{

	Nintendo* nin=new Nintendo(2017,"Sega","bueno",111,15.30);

	//nin->{};
	cout<< "\nYOLOYOLOYOLOYOLOYOLO"<<endl;
	cout<<nin->getModelo()<<"ESOOOOOO"<<endl;
		return 0;
}