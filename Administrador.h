#include "Usuario.h"
#include <string>

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
using namespace std;

class Administrador : public Usuario
{

	private:
		string contrasenia;		


	public:
		Administrador();
		Administrador(string,string);
		~Administrador();

		string getContrasenia();
		void setContrasenia(string);
	
};
#endif	