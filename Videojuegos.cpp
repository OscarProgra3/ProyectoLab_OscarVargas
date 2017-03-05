#include "Videojuegos.h"


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

Videojuegos::getNombre()
{
	return nombre;
}
Videojuegos::setNombre(string tnombre)//tnombre=temporal nombre
{
	this->nombre=tnombre;
}


Videojuegos::getAnio()
{
	return anio;
}
Videojuegos::setAnio(int tanio)
{
	this->anio=tanio;
}


Videojuegos::getConsola()
{
	return consola;
}
Videojuegos::setConsola(string tconsola)
{
	this->consola=tconsola;
}


Videojuegos::getNumjugadores()
{
	return numjugadores;
}
Videojuegos::setNumjugadores(int tnumjugadores)
{
	this->numjugadores=tnumjugadores;
}

Videojuegos::getGenero()
{
	return genero;
}
Videojuegos::setGenero(string tgenero)
{
	this->genero=tgenero;
}


Videojuegos::getEstado()
{
	return estado;
}
Videojuegos::setNombre(string tnombre)//tnombre=temporal nombre
{
	this->nombre=tnombre;
}


Videojuegos::getNumSerie()
{
	return numserie;
}
Videojuegos::setNumSerie(int tnumserie)
{
	this->numserie=tnumserie;
}

Videojuegos::getPrecio()
{
	return precio;
}
Videojuegos::setPrecio(double tprecio)
{
	this->precio=tprecio;
}

