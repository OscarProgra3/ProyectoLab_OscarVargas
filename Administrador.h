#include "Usuario.h"

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

using namespace std;

class Administrador : public Usuario
{

	private:
		string contraseña;		


	public:
		Administrador();
		~Administrador();

		string getContraseña();
		void setContraseña(string);
	
};