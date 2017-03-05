#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

class Usuario
{
	protected:	
		string nombre;

	public:
		Usuario();
		Usuario(string);
		string getNombre();
		void setnombre(string);

		
};
#endif