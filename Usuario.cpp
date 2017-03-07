#include "Usuario.h"
#include "string"

Usuario::Usuario(string pnombre)
{
	nombre=pnombre;
}

string Usuario::getNombre()
{
	return nombre;
}
void Usuario::setNombre(string tnombre)
{
	 nombre=tnombre;
}