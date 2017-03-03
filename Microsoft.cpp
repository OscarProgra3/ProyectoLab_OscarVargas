#include "Microsoft.h"
#include "JuegosMicrosoft.h"
#include "Consolas.h"

Microsoft::Microsoft() : Consolas( pañosalida,  pmodelo,
		 pestado,  pnumeroserie,  pprecio) 
{
	this -> añosalida=pañosalida;
	this -> modelo=pmodelo;
	this -> estado=pestado;
	this -> numeroserie=pnumeroserie;
	this -> precio=pprecio;    
}

