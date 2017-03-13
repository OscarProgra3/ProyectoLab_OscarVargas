#include "Venta.h"
#include "Consolas.h"



Venta::Venta(string pnomcliente, vector<Consolas*> plistaconsola, vector<Videojuegos*> plistavideojuegos, 
	string phorafinalizacion, string pnombreusuario, double psubtotal)
{
	nomcliente=pnomcliente;
	listaconsolas=plistaconsola;
	listavideojuegos=plistavideojuegos;
	horafinalizacion=phorafinalizacion;
	nombreusuario=pnombreusuario;
	subtotal=psubtotal;
}

string Venta::getNombrecliente()
{
	return nomcliente;
}
void Venta::setNombrecliente(string tnombrecliente)
{
	nomcliente=tnombrecliente;
}


vector <Consolas*> Venta::getListaconsolas()
{				
	return listaconsolas;
}
void Venta::setListaconsolas(vector <Consolas*> e)
{
	listaconsolas = e;
}

int Venta::getTamConsola()
{
	return listaconsolas.size();
}
int Venta::getTamJuegos()
{
	return listavideojuegos.size();
}

vector <Videojuegos*>  Venta::getListavideojuegos()
{
	return listavideojuegos;
}

void Venta::setListavideojuegos(vector <Videojuegos*>  e)
{
	listavideojuegos = e;
}

string Venta::getHorafinalizacion()
{
	return horafinalizacion;
}
void Venta::setHorafinalizacion(string thorafinalizacion)
{
	horafinalizacion=thorafinalizacion;
}

string Venta::getNombreusuario()
{
	return nombreusuario;
}
void Venta::setNombreusuario(string tnomusu)
{
	nombreusuario=tnomusu;
}

double Venta::getSubtotal()
{
	return subtotal;
}
void Venta::setSubtotal(double tsubtotal)
{
	subtotal=tsubtotal;
}

