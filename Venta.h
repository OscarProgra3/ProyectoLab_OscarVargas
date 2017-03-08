#ifndef VENTA_H
#define VENTA_H
#include <vector>
#include <string>
#include "Consolas.h"
#include "Videojuegos.h"
	
using namespace std;

class Venta
{
	private:
		string nomcliente;
		vector<Consolas*> listaconsolas;
		vector<Videojuegos*> listavideojuegos;
		string horafinalizacion;
		string nombreusuario;
		double subtotal;

	public:
		Venta(string,vector <Consolas*>,vector <Videojuegos*>, string, string, double);
		~Venta();

		string getNombrecliente();
		void setNomcli(string);

		Consolas* getListaconsolas(int);
		void setConsolas(Consolas*); 
	
		Videojuegos* getListavideojuegos();
		void setListaVideojuegos(int);

		string getHorafinalizacion();
		void setHorafinalizacion(string);

		string getNombreusuario();
		void setNombreusuario(string);

		double getSubtotal();
		void setSubtotal(double);

};

#endif