#include "Nintendo.h"
#include "Consolas.h"

Nintendo::Nintendo() : Consolas( pañosalida,  pmodelo,
		 pestado,  pnumeroserie,  pprecio) 
{
	this -> añosalida=pañosalida;
	this -> modelo=pmodelo;
	this -> estado=pestado;
	this -> numeroserie=pnumeroserie;
	this -> precio=pprecio;    
}

