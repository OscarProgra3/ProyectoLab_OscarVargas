#include "Sony.h"
#include "Consolas.h"

Sony::Sony() : Consolas( pañosalida,  pmodelo,
		 pestado,  pnumeroserie,  pprecio) 
{
	this -> añosalida=pañosalida;
	this -> modelo=pmodelo;
	this -> estado=pestado;
	this -> numeroserie=pnumeroserie;
	this -> precio=pprecio;    
}

