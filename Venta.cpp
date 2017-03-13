#include "Venta.h"
#include "Consolas.h"


Venta::Venta(string nomcliente, vector<Consolas*> listaconsola, vector<Videojuegos*> listavideojuegos, 
	string horafinalizacion, string nombreusuario, double subtotal)
{
	nomcliente=nomcliente;
	listaconsolas=listaconsolas;
	listavideojuegos=listavideojuegos;
	horafinalizacion=horafinalizacion;
	nombreusuario=nombreusuario;
	subtotal=subtotal;
}

string Venta::getNombrecliente()
{
	return nomcliente;
}
void Venta::setNombrecliente(string tnombrecliente)
{
	nomcliente=tnombrecliente;
}


vector <Consolas*> Venta::getListaconsolas(int num)
{				
	return listaconsolas.at(num);
}
void Venta::setListaconsolas(vector <Consolas*> e)
{
	listaconsolas.push_back(e);
}

int Venta::getTamConsola()
{
	return listaconsolas.size();
}
int Venta::getTamJuegos()
{
	return listavideojuegos.size();
}

vector <Videojuegos*>  Venta::getListavideojuegos(int num)
{
	return listavideojuegos.at(num)	;
}
void Venta::setListavideojuegos(vector <Videojuegos*>  e)
{
	listavideojuegos.push_back(e);
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

