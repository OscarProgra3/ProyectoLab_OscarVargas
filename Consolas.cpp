#include "Consolas.h"
#include <iostream>


using namespace std;


Consolas::Consolas(int pañosalida, string pmodelo,
		string pestado, int pnumeroserie, double pprecio)
{
	this -> añosalida=pañosalida;
	this -> modelo=pmodelo;
	this -> estado=pestado;
	this -> numeroserie=pnumeroserie;
	this -> precio=pprecio;
}


Consolas::getAñosalida()
{
	return añosalida;
}
Consolas::setAñosalida(int tañosalida)
{
	añosalida=pañosalida;
}

Consolas::getModelo()
{
	return modelo;
}
Consola::setModelo(string tmodelo)
{
	modelo=pmodelo;
}

Consolas::getEstado()
{
	return estado;
}
Consolas::setEstado(string tpestado)
{
	estado=pestado;
}

Consolas::getNumeroSerie()
{
	return numeroserie;
}
Consolas::setNumeroSerie(int tnumeroserie)
{
	numeroserie=pnumeroserie;
}

Consolas::getPrecio()
{
	return precio;
}
Consolas::setPrecio(double tprecio)
{
	precio=pprecio;
}







