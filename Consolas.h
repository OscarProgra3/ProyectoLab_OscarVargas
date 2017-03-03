#ifndef CONSOLAS_H
#define CONSOLAS_H

class Consolas
{
	protected:
		int añosalida;
		string modelo;
		string estado;
		int numeroserie;
		double precio;


	public:
		Consolas(int, string, string, int, double);
		Consolas();
		
		//mutadores
		int getAñosalida();
		void setAñosalida(int);

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