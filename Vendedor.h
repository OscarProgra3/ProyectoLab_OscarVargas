#include "Usuario.h"
#include <string>

#ifndef VENDEDOR_H
#define VENDEDOR_H

using namespace std;

class Vendedor : public Usuario
{
	private:
		string horaentrada;
		string horasalida;

	public:
//		Vendedor();
		Vendedor(string,string,string);
		
		string getHoraentrada();
		void setHoraentrada(string);

		string getHorasalida();
		void setHorasalida(string);



};

#endif