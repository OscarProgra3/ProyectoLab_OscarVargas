#include "Vendedor.h"

Vendedor::Vendedor(string pnombre,string horaentrada, string horasalida) : Usuario(pnombre) 
{
}

string Vendedor::getHoraentrada()
{
	return horaentrada;
}
void Vendedor::setHoraentrada(string thoraentrada)
{
	horaentrada=thoraentrada;
}


string Vendedor::getHorasalida()
{
	return horasalida;
}
void Vendedor::setHorasalida(string thorasalida)
{
	horaentrada=thorasalida;
}