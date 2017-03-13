#include "Consolas.h"
#include <iostream>
#include <string>


using namespace std;


Consolas::Consolas(int paniosalida, string pmodelo,
		string pestado, int pnumeroserie, double pprecio)
{
	this -> aniosalida=paniosalida;
	this -> modelo=pmodelo;
	this -> estado=pestado;
	this -> numeroserie=pnumeroserie;
	this -> precio=pprecio;
}

Consolas::Consolas(Consolas* consola)
{
	consola=consola;
}

int Consolas::getAniosalida()
{
	return aniosalida;
}
void Consolas::setAniosalida(int taniosalida)
{
	aniosalida=taniosalida;
}

string Consolas::getModelo()
{
	return modelo;
}
void Consolas::setModelo(string tmodelo)
{
	modelo=tmodelo;
}

string Consolas::getEstado()
{
	return estado;
}
void Consolas::setEstado(string testado)
{
	estado=testado;
}

int Consolas::getNumeroSerie()
{
	return numeroserie;
}
void Consolas::setNumeroSerie(int tnumeroserie)
{
	numeroserie=tnumeroserie;
}

double Consolas::getPrecio()
{
	return precio;
}
void Consolas::setPrecio(double tprecio)
{
	precio=tprecio;
}









