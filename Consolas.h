#ifndef CONSOLAS_H
#define CONSOLAS_H
#include <string>

using namespace std;

class Consolas
{
	protected:
		int aniosalida;
		string modelo;
		string estado;
		int numeroserie;
		double precio;


	public:
		Consolas(int, string, string, int, double);
		Consolas();
		
		//mutadores
		int getAniosalida();
		void setAniosalida(int);

		string getModelo();
		void setModelo(string);

		string getEstado();
		void setEstado(string);

		int getNumeroSerie();
		void setNumeroSerie(int);

		double getPrecio();
		void setPrecio(double);


};
#endif