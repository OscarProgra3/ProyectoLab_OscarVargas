#include "Usuario.h"

using namespace std;

Usuario::Usuario(string pnombre)
{
	this-> nombre=pnombre;
}

Usuario::getNombre()
{
	return nombre;
}
Usuario::setNombre(string tnombre)
{
	this-> nombre=tnombre;
}