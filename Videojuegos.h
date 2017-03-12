#ifndef VIDEOJUEGOS_H
#define VIDEOJUEGOS_H
#include <string>
using namespace std;
#include <boost/serialization/base_object.hpp> 

class Videojuegos
{
	protected:
		string nombre;
		int anio;
		string consola;	
		int numjugadores;
		string genero;
		string estado;
		int numserie;
		double precio;


	public:
		Videojuegos(string, int, string,int,  string,string, int, double);
		
		string getNombre();
		void setNombre(string);

		int getAnio();
		void setAnio(int);


		string getConsola();
		void setConsola(string);

		int getNumjugadores();
		void setNumjugadores(int);

		string getGenero();
		void setGenero(string);

		string getEstado();
		void setEstado(string);
		
		int getNumSerie();
		void setNumSerie(int);


		double getPrecio();
		void setPrecio(double);
		
		
};

#endif