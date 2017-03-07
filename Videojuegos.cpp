#include "Videojuegos.h"
#include <string>
using namespace std;

Videojuegos::Videojuegos(string pnombre, int panio, string pconsola, int pnumjudaores, string pgenero, string pestado, int pnumserie,double pprecio)
{ 
		this-> nombre=pnombre;
		this-> anio=panio;
		this-> consola=pconsola;	
		this-> numjugadores=pnumjudaores;
		this-> genero=pgenero;
		this-> estado=pestado;
		this-> numserie=pnumserie;
		this-> precio=pprecio;
}

string Videojuegos::getNombre()
{
	return nombre;
}
void Videojuegos::setNombre(string tnombre) 		
{
	nombre=tnombre;	
}


int Videojuegos::getAnio()
{
	return anio;
}
void Videojuegos::setAnio(int tanio)
{
	this->anio=tanio;
}


string Videojuegos::getConsola()
{
	return consola;
}
void Videojuegos::setConsola(string tconsola)
{
	this->consola=tconsola;
}


int Videojuegos::getNumjugadores()
{
	return numjugadores;
}
void Videojuegos::setNumjugadores(int tnumjugadores)
{
	this->numjugadores=tnumjugadores;
}

string Videojuegos::getGenero()
{
	return genero;
}
void Videojuegos::setGenero(string tgenero)
{
	this->genero=tgenero;
}


string Videojuegos::getEstado()
{
	return estado;
}
void Videojuegos::setEstado(string testado)//tnombre=temporal nombre
{
	this->estado=testado;
}


int Videojuegos::getNumSerie()	
{
	return numserie;
}
void Videojuegos::setNumSerie(int tnumserie)
{
	this->numserie=tnumserie;
}

double Videojuegos::getPrecio()
{
	return precio;
}
void Videojuegos::setPrecio(double tprecio)
{
	this->precio=tprecio;
}

