Main: Main.o Administrador.o Consolas.o juegosBandai.o juegosElectronicArts.o juegosKonami.o JuegosMicrosoft.o juegosNintendo.o juegosSega.o juegosSony.o juegosSquareEnix.o juegosUbisoft.o Microsoft.o Nintendo.o Sony.o Usuario.o Vendedor.o Videojuegos.o
	g++ Main.o Administrador.o Consolas.o juegosBandai.o juegosElectronicArts.o juegosKonami.o JuegosMicrosoft.o juegosNintendo.o juegosSega.o juegosSony.o juegosSquareEnix.o juegosUbisoft.o Microsoft.o Nintendo.o Sony.o Usuario.o Vendedor.o Videojuegos.o -o Main

Main.o: Main.cpp Administrador.h Consolas.h juegosBandai.h juegosElectronicArts.h juegosKonami.h JuegosMicrosoft.h juegosNintendo.h juegosSega.h juegosSony.h juegosSquareEnix.h juegosUbisoft.h Microsoft.h Nintendo.h Sony.h Usuario.h Vendedor.h Videojuegos.h
	g++ -c Main.cpp

Administrador.o: Administrador.cpp Administrador.h Usuario.h
	g++ -c Administrador.cpp

Consolas.o: Consolas.cpp Consolas.h
	g++ -c Consolas.cpp

juegosBandai.o: juegosBandai.cpp juegosBandai.h Videojuegos.h
	g++ -c juegosBandai.cpp

juegosElectronicArts.o: juegosElectronicArts.cpp juegosElectronicArts.h Videojuegos.h
	g++ -c juegosElectronicArts.cpp

juegosKonami.o: juegosKonami.cpp juegosKonami.h Videojuegos.h
	g++ -c juegosKonami.cpp

JuegosMicrosoft.o: JuegosMicrosoft.cpp JuegosMicrosoft.h Videojuegos.h
	g++ -c JuegosMicrosoft.cpp

juegosNintendo.o: juegosNintendo.cpp juegosNintendo.h Videojuegos.h
	g++ -c juegosNintendo.cpp

juegosSega.o: juegosSega.cpp juegosSega.h Videojuegos.h
	g++ -c juegosSega.cpp

juegosSony.o: juegosSony.cpp juegosSony.h Videojuegos.h
	g++ -c juegosSony.cpp

juegosSquareEnix.o: juegosSquareEnix.cpp juegosSquareEnix.h Videojuegos.h
	g++ -c juegosSquareEnix.cpp

juegosUbisoft.o: juegosUbisoft.cpp juegosUbisoft.h Videojuegos.h
	g++ -c juegosUbisoft.cpp

Microsoft.o: Microsoft.cpp Microsoft.h Consolas.h
	g++ -c Microsoft.cpp

Nintendo.o: Nintendo.cpp Nintendo.h Consolas.h
	g++ -c Nintendo.cpp

Sony.o: Sony.cpp Sony.h Consolas.h
	g++ -c Sony.cpp

Usuario.o: Usuario.cpp Usuario.h
	g++ -c Usuario.cpp

Vendedor.o: Vendedor.cpp Vendedor.h Usuario.h
	g++ -c Vendedor.cpp

Videojuegos.o: Videojuegos.cpp Videojuegos.h
	g++ -c Videojuegos.cpp

clean:
	rm -f *.o Main
