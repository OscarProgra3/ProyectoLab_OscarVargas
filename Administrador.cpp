#include "Administrador.h"
#include <string>

Administrador::Administrador() : Usuario("admin") {
	contrasenia = "123";
}

Administrador::Administrador(string pnombre, string pcontrasenia) : Usuario(pnombre)
{
	contrasenia=pcontrasenia;
}

string Administrador::getContrasenia()
{
	return contrasenia;
}
void Administrador::setContrasenia(string tcontra)
{
	contrasenia=tcontra;
}