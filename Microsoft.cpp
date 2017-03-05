#include "Microsoft.h"
#include "Consolas.h"


using namespace std;

Microsoft::Microsoft() : Consolas( pañosalida,  pmodelo,
		 pestado,  pnumeroserie,  pprecio) 
{
	this -> añosalida=pañosalida;
	this -> modelo=pmodelo;
	this -> estado=pestado;
	this -> numeroserie=pnumeroserie;
	this -> precio=pprecio;    
}

	