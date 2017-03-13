#ifndef VENTA_H
#define VENTA_H
#include <vector>
#include <string>
#include <vector>
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
		void setNombrecliente(string);

		vector <Consolas*> getListaconsolas(int);
		void setListaconsolas(vector <Consolas*>); 

		int getTamConsola();
	
		vector <Videojuegos*> getListavideojuegos(int);
		void setListavideojuegos(vector <Videojuegos*> );

		int getTamJuegos();

		string getHorafinalizacion();
		void setHorafinalizacion(string);

		string getNombreusuario();
		void setNombreusuario(string);

		double getSubtotal();
		void setSubtotal(double);

};

#endif