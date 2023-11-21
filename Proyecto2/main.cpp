#include <iostream>
#include <fstream>
#include<string.h>
#include <sstream>
#include <string>
#include "Risk.h"
#include "arbolhuffman.h"
#include "grafo.h"
#include <map>
#include <bitset>




using namespace std;
struct  infodos
{
  int cantidadjug;
  vector<string> color;
  int fichas;
  vector<string> territorios;
  vector<string> nombrejug;
  string jugadort;
  vector<string>cartas;
  vector<int>fichasd;
  vector<int>ejercito;

};


struct InformacionJugador {
    string jugadort;
    string nombre;
    string jugadores;
    string color;
    string nombrejug;
    vector<string> territorios;
    string cantidadPaises;
    vector<string> codigosPaises;
    vector<string> cantidadEjercito;
    string cantidadTarjetas;
    vector<string> identificadoresTarjetas;
};

string ingresarComando();
void mensajeBienvenida();
int identificarComando(char comadno[20][100],string cadena);
string separarEspacio(string cadena, bool parametro);
bool qParametros(string respuesta);
void crearArchivo(const string& nombreArchivo);
void leerArchivo(const string& nombreArchivo);
void mostrarAyudaComando(const string& comando);
void infoInicializar(void);
void infoTurno(void);
void infoSalir(void);
void infoGuardar(void);
void infoGuardarComprimido(void);
void infoCostoConquista(void);
void infoConquistaMasBarata(void);

//entrega 1
void inicializarJuego(Risk* risk);
void UbicarTropas(Risk* risk, bool inicializar);
void fortificar(Risk* risk);
void turno (Risk* risk);
void atacar(Risk* risk);

//entrega 2
void crearArchivoBinario(const string& nombreArchivo,const   InformacionJugador& jugadorInfo);
void crearArchivo(const string& nombreArchivo, const string& contenidoGuardar);



//entrega 3
void costo_conquista(Risk* risk,std::string NTerritorio);
void conquista_mas_barata(Risk* risk);

string nombreArchivo;
string identificante="";
infodos inf;
 InformacionJugador jugadorInfo;
 ArbolHuffman<char> arbolHuffman;
 Risk risk;
 Grafo grafo;
  char comand[100];
  char palabra[20][100];
int main() {
  
  //instancia para la clase risk
  
  risk.crearContinente();
 risk.InicializarTerritoriosColindantes(&risk);
grafo.inicializarGrafo(&risk);
 
    //guarda la cadena ingresada por el usuario
    string respuesta;
    //mensaje de bienvenida
    mensajeBienvenida();
    
    //bandera para terminar el programa
    bool salir = false;
    //valor= variable usada en el switch case
    //qJugadores= cantidad de jugadores en la partida
    int valor, qJugadores;
    //turno= turno ingresado por el usuario
    //turnoPrueba= variable de turno para pruebas
    string turnoAux;
    //indica si hay algún ganador
    int ganador = -1;
     string Nombrevar;
    

    do {
      
      //std::cout<<"\t\tTURNO DEL JUGADOR "<<risk.getNameJugadorEnTurno()<<std::endl;
      std::cout<<"Quieres ver como va la informacion de los jugadores\nsi\nno"<<std::endl;
      std::string elecinfojug=ingresarComando();
      if(elecinfojug=="si"){
        system("cls");
          std::cout<<risk.imprimirJugadoresInformacion()<<std::endl;
          
      }

      
      std::cout<<"Introduce un comando Risk:"<<std::endl;

        //respuesta = ingresarComando();
        
      char palabras[20][100]; // Donde se van a guardar las palabras
		for (int i = 0; i < 20; i++)
		{
			strcpy(palabras[i], " "); // limpia arreglo
		}
		cout << endl
			 << "$";
		cin.getline(comand, sizeof(comand));
		char *p;
		int contador = 0;
		p = strtok(comand, " ");
		while (p != NULL)
		{ // Realiza separacion del comando por espacios
			strcpy(palabras[contador], p);
			contador++;
			p = strtok(NULL, " ");
		}

    //para guardar el valor complementario del comando
    if((strcmp(palabras[3], " ") != 0)){
      identificante=palabras[1];
    identificante+=" ";
    identificante+=palabras[2];
    identificante+=" ";
    identificante+=palabras[3];
    }else if(strcmp(palabras[2], " ") != 0){
    identificante=palabras[1];
    identificante+=" ";
    identificante+=palabras[2];
    }else if(strcmp(palabras[1], " ") != 0){
      identificante=palabras[1];
    }
    
    
    respuesta=palabras[0];
    
    
        valor = identificarComando(palabras,respuesta);
        grafo.actualizarMatrizAdyacencia();
        system("cls");
        switch (valor) {
            //inicializar con archivo
            case 1:
                {
                    string nombreArchivo = identificante;
        
                    leerArchivo(nombreArchivo);
                }
                break;
            //inicializar
            case 2:
                if(!risk.estadoPartida()){
                  inicializarJuego(&risk);
                  UbicarTropas(&risk, true);
                  risk.turnosEnCero();
                  std::cout<<"\n-** El juego se ha inicializado correctamente. **-\n"<<endl;
                }else
                  std::cout<<"Esta partida ya ha sido inicializada"<<endl;

                break;
              //turno id_jugador
            case 3:
            risk.turnosEnCero();
                turnoAux = identificante;

                if(!risk.estadoPartida()){
                    std::cout<<"-** Esta partida no ha sido inicializada correctamente **-\n";
                }else if (risk.estadoGanador()){
                    std::cout<<"-** Esta partida ya tuvo un ganador **-\n";
                }else if(risk.esTurnoJugador(turnoAux)){

                    turno (&risk);

                }else if (risk.jugadorExiste(turnoAux)){
                    std::cout<<"-** No es el turno del jugador <"<< turnoAux<<"> **-\n"; 
                }else
                    std::cout<<"-** El jugador <"<< turnoAux<<"> no forma parte de esta partida. **-\n";
                                   

                std::cout << "id_jugador " << turnoAux << endl;
                
                break;
              //salir
            case 4:
                salir = true;
                break;
                // guardar <nombre_archivo>
                 
            case 5: 
                {
                string nombreArchivo = identificante;
                crearArchivo(nombreArchivo );
                   
                }
                break;
                // guardar_comprimido <nombre_archivo>
            case 6: 
                {
                  
                  nombreArchivo = identificante;
                  crearArchivoBinario(nombreArchivo, jugadorInfo);
                }
                break;
              //costo_conquista <territorio>
            case 7:
              Nombrevar=identificante;
              if(risk.estadoPartida()){
              if(!risk.estadoGanador()){
                    std::cout << "comando exitoso\n" << "costo_conquista <territorio>\n";
                    std::cout<<identificante<<std::endl;
                    costo_conquista(& risk,Nombrevar);

                }else if (risk.estadoGanador()){
                    std::cout<<"-** Esta partida ya tuvo un ganador **-\n";
                }}else{
                  std::cout<<"Esta partida todavia no se ha inicializado \n"<<std::endl;
                }
                break;
              //conquista_mas_barata
            case 8:
                
              if(risk.estadoPartida()){
              if(!risk.estadoGanador()){
                    std::cout << "comando exitoso\n" << "conquista_mas_barata\n";
                    
                    conquista_mas_barata(& risk);

                }else if (risk.estadoGanador()){
                    std::cout<<"-** Esta partida ya tuvo un ganador **-\n";
                }}else{
                  std::cout<<"Esta partida todavia no se ha inicializado \n"<<std::endl;
                }
                break;
              //conquista_mas_barata

            case 9:
                std::cout << "comando exitoso" << endl;
                std::cout << "help <comando>: Proporciona información de ayuda para los comandos de Risk.\n\nComandos disponibles:\n";

                break;

            
            case 10:
                std::cout << "help <comando>: Proporciona información de ayuda para los comandos de Risk.\n\nComandos disponibles:\n";

              std::cout << "inicializar - Inicializa un nuevo juego" << endl;
  std::cout << "turno - Muestra el turno" << endl; 
  std::cout << "salir - Salir del programa" << endl;
  std::cout << "guardar -  Guarda el progreso" << endl;
  std::cout << "guardar_comprimido - Guarda el progreso en un formato .zip" << endl;
  std::cout << "costo_conquista - Muestra el costo de conquista de un territorio" << endl;
  std::cout << "conquista_mas_barata - Muestra costo de conquista mas barato" << endl;        
                break;

          case 11:
            mostrarAyudaComando(identificante);
            break;

            default:
                std::cout << "\"" << respuesta << "\"" << " no se reconoce como un comando interno o parametros incorrectos.\n\n";
                break;
        }

    } while (salir == false);

    return 0;
}

void crearArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo ); 
    if (archivo.is_open()) {
        archivo<<"cantidad de jugadores"<< " "<<inf.cantidadjug;
        archivo << "\n";
        for ( std::string& cantnombre : inf.nombrejug){
        archivo<<"nombre jugadores"<< " "<<cantnombre<< '\n';
        }
        archivo << "\n";
        for ( std::string& cantcoloir : inf.color)
        archivo<<"color"<<cantcoloir<< " " << '\n';
        archivo << "\n";
        for ( std::string& cantipaices : inf.territorios) {
                  archivo <<"territorios"<< " " <<cantipaices  << '\n';
         }
         archivo << "\n";
         for ( int fichas : inf.fichasd) {
                  archivo <<"fichas vovidas al territorio"<< " " <<fichas  << '\n';
         }
         archivo << "\n";
         for ( int ejercito: inf.ejercito) {
                  archivo <<"fichas vovidas al territorio"<< " " <<ejercito  << '\n';
         }


        archivo.close();
        std::cout << "La partida ha sido guardada correctamente en " << nombreArchivo  << endl;
    } else {
        std::cout << "La partida no ha sido guardada correctamente." << endl;
    }
}






//permite crear un archivo



void crearArchivoBinario(const std::string& nombreArchivo, const InformacionJugador& jugadorInfo) {
    try {
        std::ofstream archivo(nombreArchivo, std::ios::binary | std::ios::app);
        if (archivo.is_open()) {
            archivo.write(jugadorInfo.nombre.c_str(), jugadorInfo.nombre.size());
            archivo.write(jugadorInfo.jugadores.c_str(), jugadorInfo.jugadores.size());
            archivo.write("\n", 1); // Cambio de línea después de cada cadena

            archivo.write(jugadorInfo.nombrejug.c_str(), jugadorInfo.nombrejug.size());
            archivo.write("\n", 1);

            archivo.write(jugadorInfo.color.c_str(), jugadorInfo.color.size());
            archivo.write("\n", 1);

            archivo.write(jugadorInfo.cantidadPaises.c_str(), jugadorInfo.cantidadPaises.size());
            archivo.write("\n", 1);

            archivo.write(jugadorInfo.jugadort.c_str(), jugadorInfo.jugadort.size());
            archivo.write("\n", 1);

            // Función auxiliar para escribir las líneas con cambio de línea cada 8 bits
            auto escribirConSeparador = [&archivo](const std::string& linea) {
                int contadorBits = 0;
                for (char bit : linea) {
                    archivo.write(&bit, 1);
                    contadorBits++;
                    if (contadorBits % 8 == 0) {
                        archivo.write("\n", 1); // Cambio de línea cada 8 bits
                    }
                }
            };

            // Escribe las líneas de territorios y cantidades de ejército
            for (const std::string& codigoCantidadPaises : jugadorInfo.territorios) {
                escribirConSeparador(codigoCantidadPaises);
            }

            for (const std::string& codigoCantidadeje : jugadorInfo.cantidadEjercito) {
                escribirConSeparador(codigoCantidadeje);
            }

            archivo.write("\n", 1); // Agrega una línea para separar las entradas de diferentes jugadores

            archivo.close();
            std::cout << "La partida ha sido guardada correctamente en " << nombreArchivo << "_codificado.bin." << std::endl;
        } else {
            std::cout << "No se pudo abrir el archivo para escritura." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error al escribir en el archivo: " << e.what() << std::endl;
    }
}

//permite leer la información de un archivo
void leerArchivo(const std::string &nombreArchivo) {
    std::cout << "Ingrese qué tipo de archivo desea leer: \n"
              << "1. Archivo de texto\n"
              << "2. Archivo binario\n";

    int opcion;
    std::cin >> opcion;

    if (opcion != 1 && opcion != 2) {
        std::cerr << "Opción no válida." << std::endl;
        return;
    }

    std::ifstream archivo(nombreArchivo, std::ios::binary);

    if (archivo) {
        std::string linea;

        while (std::getline(archivo, linea)) {
            if (opcion == 2) {
                // Convierte cada grupo de 8 bits a un carácter
                std::string binaryContent;
                for (size_t i = 0; i < linea.length(); i += 32) {
                    std::string bits = linea.substr(i, 32);
                    char c = static_cast<char>(std::bitset<32>(bits).to_ulong());
                    binaryContent += c;
                }

                // Decodifica la cadena de caracteres y muestra la palabra decodificada
                std::string decoded = arbolHuffman.decodificar(binaryContent);
                std::cout << "Decodificado: " << decoded << std::endl;
            } else if (opcion == 1) {
                // Si es un archivo de texto, simplemente imprime el contenido de la línea
                std::cout << linea << std::endl;
            }
        }

        archivo.close();
    } else {
        std::cerr << "Error: no se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
}



string separarEspacio(string cadena, bool parametro) {

    string comando = cadena;
    size_t separar = cadena.find(' ');

    if (separar != string::npos) {
        if (parametro == false) {
            comando = cadena.substr(0, separar);
        } else {
            comando = cadena.substr(separar + 1);
            identificante=comando;
        }
    }
    return comando;
}

void mostrarAyudaComando(const string& com) {
  
  std::cout << endl;
    if (com == "inicializar") {
        std::cout << "inicializar <nombre_archivo>\n\n";
      infoInicializar();     
    } else if (com == "turno") {
        std::cout << "turno <id_jugador>\n\n";
      infoTurno();
    } else if (com == "salir") {
        std::cout << "salir <>\n\n";
      infoSalir();
    } else if (com == "guardar") {
        std::cout << "guardar <nombre_archivo>\n\n";
      infoGuardar();
    } else if (com == "guardar_comprimido") {
        std::cout << "guardar_comprimido <nombre_archivo>\n\n";
      infoGuardarComprimido();
    } else if (com == "costo_conquista") {
        std::cout << "costo_conquista <territorio>\n\n";
      infoCostoConquista();
    } else if (com == "conquista_mas_barata") {
        std::cout << "conquista_mas_barata <>\n\n";
      infoConquistaMasBarata();
    } else if (com == "help") {
        std::cout << "help <comando>\n\n";
    }  else {
        std::cout << "El comando \"" << com << "\" no tiene una descripción de ayuda.\n";
    }
}

void mensajeBienvenida() {
  system("cls");
    std::cout << "!Bienvenido a RISK?\nanimate a jugar :)\n";
}

string ingresarComando() {
    string cadena;
    std::cout << "\n$";
    getline(cin, cadena);
    return cadena;
}

//permite identificar si solo se ingréso un comando con un solo parametro 
bool qParametros(string respuesta) {
    int espacios = 0;
    string p2 = separarEspacio(separarEspacio(respuesta, true), 0);

    for (int i = 0; i < respuesta.length(); i++) {
        if (respuesta[i] == ' ') {
            espacios++;
            
        }
    }
  
 
    if (espacios == 1 && p2 != "") {
        return true;
    }

    return false;
}


//recibe la primera parte del comando ingresado por el usuario y identificar a cual tipo corresponde
int identificarComando(char palabras[20][100],std::string cadena){
    //guarda lo que ingresa el usuario
    string respuesta = separarEspacio(cadena, false);
    int valor=0;

    if (respuesta == "inicializar" && strcmp(palabras[1], " ") != 0) { 
        valor=1;
        
    } else if(respuesta == "inicializar"){
        valor=2;

    } else if (respuesta == "turno" && strcmp(palabras[1], " ") != 0) {   
        valor=3;   
        
    } else if (respuesta == "salir") { 
        valor=4;
    } else if (respuesta == "guardar" && strcmp(palabras[1], " ") != 0) {
        valor=5;
       
    } else if (respuesta == "guardar_comprimido" && strcmp(palabras[1], " ") != 0) {
        valor=6;
       
    } else if (respuesta == "costo_conquista" && strcmp(palabras[1], " ") != 0) {
        valor=7;
       

    } else if (respuesta == "conquista_mas_barata") {
        valor=8;
    } else if (respuesta == "comandohelp"){
        valor=9;
    } else if (respuesta == "help" && strcmp(palabras[1], " ") == 0){
        valor = 10;
    } else if (respuesta == "help" && strcmp(palabras[1], " ") != 0) {
      valor = 11;
    }
    return valor;
}

void infoInicializar(void){
  std::cout << "Realiza las operaciones necesarias para inicializar el juego.\n\n El comando pregunta la cantidad de jugadores, para cada jugador su nombre o identificador, y luego, por turnos, pregunta a cada jugador en qué territorio desea ubicar sus unidades de ejército. \n\nEn cada turno, el jugador sólo puede indicar un único territorio a ocupar.\n" << endl;
}

void infoTurno(void){
  std::cout<<"Realiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades, atacar y fortificar).\n\n El comando informa al jugador cuántas unidades adicionales puede reclamar luego pregunta en cuáles de sus territorios las quiere asignar y en qué cantidad.\n\n A continuación pregunta la configuración del ataque, desde cuál territorio y hacia cuál territorio, verificando las condiciones ya descritas.\n\n Luego informa los valores obtenidos con los dados, y la cantidad de unidades que se ganan o pierden. \n\nEste proceso se repite hasta que alguno de los dos territorios se quede sin unidades, o hasta que el atacante decida detenerse. \n\nFinalmente, el comando pregunta al jugador los territorios vecinos que desea seleccionar para la fortificación, así como la cantidad de unidades que se trasladarán de uno al otro.\n" << endl;
}

void infoSalir(void){
  std::cout<<"Termina la ejecución de la aplicación \n" << endl; 
}

void infoGuardar(void){ 
  std::cout<<"El estado actual del juego es guardado en un archivo de texto. \n\nEl archivo contiene la cantidad de jugadores, y para cada jugador almacena su nombre, su color de jugador, la cantidad de países que ocupa, el identificador de cada país junto con la cantidad de unidades de ejército en él, la cantidad de tarjetas que posee y el identificador de cada tarjeta.\n" << endl;

}

void infoGuardarComprimido(void){
  std::cout<< "El estado actual del juego es guardado en un archivo binario (con extensión .bin) con la información (nombre del jugador, cantidad de países que ocupa, identificador de cada país, cantidad de unidades de ejército en paises, tarjetas que posee, identificador de cada tarjeta) comprimida.\n" << endl;
}

void infoCostoConquista(void){
  std::cout<<"Calcula el costo y la secuencia de territorios a ser conquistados para lograr controlar el territorio dado por el usuario. \n\nEl territorio desde donde debe atacar debe ser aquel que el jugador tenga controlado más cerca al dado por el jugador. \n\nEsta información se analiza desde el punto de vista del jugador que tiene el turno de juego.\n" << endl;

}

void infoConquistaMasBarata(void){
  std::cout<<"En todos los territorios posibles, revisa cual puede implicar un menor número de unidades de ejército perdidas.\n\n Esta información se analiza desde el punto de vista del jugador que tiene el turno de juego." << endl;
}

void inicializarJuego(Risk* risk){
  int cantidadJugadores=0;
  string nombreJug="", continente="", territorio = "", auxTerritorios= "";
  bool continenteValido=true, territorioValido = true;
  //cambio el estado de la partida a true
  risk->iniciarPartida();
  risk->CrearCartasJuego();
  
  //pide la cantidad de jugadores
  //hasta que esté entre 3 y 6
  do{
    std::cout<<"ingrese la cantidad de jugadores (3-6)"<<endl;
    cantidadJugadores = stoi(ingresarComando());
    vector<pair<char, int>> frecuencias = arbolHuffman.calcularFrecuencias(to_string(cantidadJugadores));
   arbolHuffman.construirArbol(frecuencias);
   jugadorInfo.jugadores=arbolHuffman.codificar(to_string(cantidadJugadores));
  

 
    inf.cantidadjug=cantidadJugadores;

  }while(cantidadJugadores<3 || cantidadJugadores>6);

   ;

system("cls");
  for(int i=0; i<cantidadJugadores; i++){
    std::cout<<"Ingrese el nombre del jugador "<< i+1<<" : \n";
    nombreJug = ingresarComando();
  inf.nombrejug.push_back(nombreJug);
   vector<pair<char, int>> frecuenciaNombre = arbolHuffman.calcularFrecuencias(nombreJug);
    arbolHuffman.construirArbol(frecuenciaNombre);
    jugadorInfo.nombrejug = arbolHuffman.codificar(nombreJug);
    risk->CrearJugador(nombreJug, cantidadJugadores);
    
  }
 
  std::cout<<risk->infoJug()<<endl;

  system ("cls");


  std::cout<<"\t -** Reclamar territorio **-"<<endl;
  do{

    std::cout<<"\n  Turno de: "<<risk->getNameJugadorEnTurno()<<"\n  Color: "<<risk->getColorJugadorEnTurno()<<"\n  FichasDisponibles: "<<risk->getFichasJugadorEnTurno()<<endl;
  //iniciarlizar tablero 

    std::cout<<"\tContinentes disponibles:"<<endl;
    
    std::cout<<risk->infoContinentes()<<endl;
    
  
    do{
      std::cout<<"\tNombre del continente:"<<endl;
      continente = ingresarComando();
    
      auxTerritorios=risk->infoTerritorios(continente);
          
        if(auxTerritorios!=""){
            std::cout<<auxTerritorios;
            continenteValido=true;
        }else{
          std::cout<<"\tNo se reconoce el continente ingresado"<<endl;
          continenteValido=false;
        }
      
    }while(!continenteValido);
  
    do{
      std::cout<<"\tNombre del Territorio:"<<endl;
      territorio = ingresarComando();
    
      if(risk->estadoTerritorioLibre(continente , territorio)){
          territorioValido=true;
      }else{
        std::cout<<"\tNo se reconoce el territorio ingresado"<<endl;
        territorioValido=false;
      }
      
    }while(!territorioValido);

    //mueve una ficha de un jugador al territorio del continente ingresado
    std::cout<<risk->infoJug()<<endl;

    //guardar el puntero hacia el territorio dentro del jugador para poder acceder a la informacion mas facil 
    Territorio* Nterritorio = risk->getTerritorio(continente,territorio);
    risk->setTerritorioaJugador(risk->getNameJugadorEnTurno(),Nterritorio);

    risk->moverFichasDisponiblesNuevoTerritorio(1, continente, territorio);

    std::cout<<risk->infoJug()<<endl;
    risk->turnoJugado(); 
    system("cls");
    inf.color.push_back(risk->getColorJugadorEnTurno());
    inf.fichas=risk->getFichasJugadorEnTurno();
    inf.territorios.push_back(territorio);
    vector<pair<char, int>> frecuenciasTerritorio = arbolHuffman.calcularFrecuencias(territorio);
   vector<pair<char, int>> frecuenciasColor = arbolHuffman.calcularFrecuencias(risk->getColorJugadorEnTurno());
   vector<pair<char, int>> frecuenciasNombreJugador = arbolHuffman.calcularFrecuencias(risk->getColorJugadorEnTurno());
  vector<pair<char, int>> frecuenciasFichas = arbolHuffman.calcularFrecuencias(to_string (risk->getFichasJugadorEnTurno()));

   arbolHuffman.construirArbol(frecuenciasTerritorio);
arbolHuffman.construirArbol(frecuenciasColor);
arbolHuffman.construirArbol(frecuenciasNombreJugador);
arbolHuffman.construirArbol(frecuenciasFichas);

    jugadorInfo;
    jugadorInfo.territorios .push_back(arbolHuffman.codificar(territorio));
   
    jugadorInfo.jugadort = arbolHuffman.codificar(risk->getNameJugadorEnTurno());
    
    jugadorInfo.color = arbolHuffman.codificar(risk->getColorJugadorEnTurno());
  
    jugadorInfo.cantidadPaises = arbolHuffman.codificar(to_string (risk->getFichasJugadorEnTurno()));
    
  }while(risk->ExistenterritoriosLibres());
}

void UbicarTropas(Risk* risk, bool inicializar){

    string territorio = "", continente= "";
    int qFichas =0;

    std::cout<<"\n\t--**Ubicar Fichas disponibles**--"<<endl;

  do{
    std::cout<<"\n  Turno de Jugador: "<<risk->getNameJugadorEnTurno()
        <<"\n  Color: "<<risk->getColorJugadorEnTurno()
        <<"\n  Fichas disponibles: "<<risk->getFichasJugadorEnTurno()
        <<"\nTerritorios disponibles: \n"<<endl;

    std::cout<<risk->buscarterritoriosJugador();


    do{
        std::cout<<"Nombre territorio:\n";
        territorio = ingresarComando();
        continente = risk->buscarContinenteTerritorio(territorio);

        std::cout<<"continente: "<<continente<<endl;
        
        if(continente=="" || !risk->EsterritorioJugador(continente, territorio)){
            std::cout<<"\n-** Nombre de territorio no valido **-\n\n";
        }

    }while(continente=="" || !risk->EsterritorioJugador(continente, territorio));
    
    do{
        std::cout<<"Numero de fichas a mover: "<<endl;
        qFichas = stoi(ingresarComando());
    }while(qFichas>risk->getFichasJugadorEnTurno());
    

    risk->moverFichasDisponiblesNuevoTerritorio(qFichas, continente, territorio);

    if(inicializar && risk->getFichasJugadorEnTurno()==0){
      risk->turnoJugado();


    }
        
        system("cls");


  }while(risk->getFichasJugadorEnTurno()!=0);

}


void turno (Risk* risk){
  
  //std::vector<Territorio*> territoriosJ =risk->getJugador(risk->getNameJugadorEnTurno())->getTerritorios();
       bool Ganador = false;
       std::string elegirNuevasTropas= "", elegirFortificar= "",elegiratacar= "",jugar = "";
       do{
        system("cls");
        
       grafo.imprimirInformacionGrafo();
       int qtropas=risk->CantidadNuevasFICHASTropasxTurno(risk->getJugador(risk->getNameJugadorEnTurno())) ;
      std::cout<<"Nuevas Tropas Disponibles: "<<qtropas<<std::endl;
      std::cout<<"Deseas ubicar tus Nuevas tropas?\nSI\nNO\n--|Si no ubicas tus Nuevas Tropas se perderan|--"<<std::endl;
      elegirNuevasTropas = ingresarComando();
      if(elegirNuevasTropas=="SI"){
     //std::cout<<"jugador "<<risk->getNameJugadorEnTurno()<<"\n cantidad de tropas disponibles : "<<qtropas<<std::endl;
     risk->AgregarFichasTropas(risk->getJugador(risk->getNameJugadorEnTurno()),qtropas) ;
      
      //se colocan las nuevas tropas
      UbicarTropas(risk, false);
      }



//PROCESO DE ATACAR

std::cout<<"Deseas Realizar un ataque\n SI \n NO"<<std::endl;
        elegiratacar = ingresarComando();

        if(elegiratacar == "SI"){
        atacar(risk);
        }else{
          std::cout<<"NO se realizo ningun ataque"<<std::endl;
        }

      
      //risk->ubicarNuevasTropas(int qtropas );
      
      
//HUFFMAN, MODIFICAR
      inf.ejercito.push_back(qtropas);
        vector<pair<char, int>> frecuen = arbolHuffman.calcularFrecuencias(to_string(qtropas));
   arbolHuffman.construirArbol(frecuen);
   jugadorInfo.cantidadEjercito.push_back(arbolHuffman.codificar(to_string(qtropas)));
   




//PROCESO DE FORTIFICAR
     //if(risk->getFichasJugadorEnTurno()>0){
      std::cout<<"Deseas Fortificar un territorio \n SI \n NO"<<std::endl;
        elegirFortificar = ingresarComando();
        if(elegirFortificar == "SI"){
        fortificar(risk);
        }else{
          std::cout<<"SIGUIENTE TURNO"<<std::endl;
        }
    

    risk->evaluarexistenciaGanador();
    
    //VERIFICAR SI EXISTE UN GANADOR
    Ganador=risk->estadoGanador();
    std::cout<<"se reviso existencia ganador"<<std::endl;
    risk->turnoJugado();
  std::cout<<"se reviso existencia ganador"<<std::endl;

    std::cout<<"Quieres seguir jugando?\n"<<"continuar-pasar al siguiente turno\n"<<"salir-salir del juego\n"<<std::endl;
    jugar = ingresarComando();

     }while(Ganador!=true && jugar =="continuar" );

      std::cout<<"SE ACABO EL JUEGO"<<std::endl;




    
}


void atacar(Risk* risk){
    bool conquistado = false;
 string territorio = "", continente= "", colindante = "",combatir = " ",Fase= " ";
    int qFichas =0;
    bool Colindante= true;
    std::string elegir= "";

 do{
  do{
    
    std::cout<<" \t RONDA DE ATAQUES \n"<<std::endl;
    std::cout<<"  Turno de Jugador: "<<risk->getNameJugadorEnTurno()
        <<"\n  Color: "<<risk->getColorJugadorEnTurno()
        <<"\n\nTUS TERRITORIOS: \n"<<endl;

    std::cout<<risk->buscarterritoriosJugador();
    std::cout<<"salir - para salir de la fase de ataque"<<std::endl;
    //evalua si el territorio seleccionado te pertenece
    

      do{
        std::cout<<"\nElige el territorio con el que quieres atacar:\n";
        territorio = ingresarComando();
        continente = risk->buscarContinenteTerritorio(territorio);
        if(territorio =="salir"){
          break;
        }
        //cout<<"continente: "<<continente<<endl;
        
        if(continente=="" || !risk->EsterritorioJugador(continente, territorio)){
            std::cout<<"\n-** Nombre de territorio no valido **-\n\n";
        }

    }while(continente=="" || !risk->EsterritorioJugador(continente, territorio));
system("cls");
if(territorio =="salir"){
          break;
        }
  //evalua si el territorio a atacar es colindante
        do{
          std::cout<<"\t \n\n TERRITORIOS DISPONIBLES PARA ATACAR \n "<<endl;
          std::cout<<risk->buscarterritoriosColindantes(territorio);

           std::cout<<"retroceder = si quieres escoger otro pais con el que atacar\n"<<endl;
           std::cout<<"Escoge el territorio que quieres atacar:\n";   
           colindante = ingresarComando();
           if(colindante =="retroceder"){
            break;
           }
           
           if( !risk->getTerritorio(continente,territorio)->esColindante(risk->getTerritorio(continente,colindante))){
            std::cout<<"\n-** Nombre de territorio Colindate no valido **-\n\n";
            Colindante= false;
        }
          //revisa que el territorio seleciionado no pertenesca al mismo jugador
          if(risk->territorioPerteneceAJugador(risk->getTerritorio(continente,colindante))->GetNombreJugador()==risk->getNameJugadorEnTurno()){
            std::cout<<"\n-** Este territorio te pertenece **-\n\n";
            Colindante= false;
          }
           
        }while(Colindante==false|| !risk->getTerritorio(continente,territorio)->esColindante(risk->getTerritorio(continente,colindante)));
        
if(colindante !="retroceder"){
  system("cls");
        //realiza el lanzamiento de dados y perdida de fichas
        do{
        
        std::cout<<"\t \n HORA DE LA BATALLA \n "<<endl;
        if(continente=="" || !risk->EsterritorioJugador(continente, territorio)){
            std::cout<<"\n-** Nombre de territorio no valido **-\n\n";
        }

        
          std::string dados=risk->OperacionesDADOSAtaque(territorio,colindante);
          std::cout<<dados<<std::endl;

          risk->EvaluarConquistaTerritorio(territorio, colindante);
          //system("cls");
          std::cout<<"Quieres seguir combatiendo con este pais:"<<std::endl;
          std::cout<<"SI \nNO"<<std::endl;
          combatir = ingresarComando();
          
        }while(combatir == "SI");
       
    }

    }while(continente=="" || !risk->EsterritorioJugador(continente, territorio)||colindante=="retroceder");
    //evalua si el territorio seleccionado para atacar es colindante
    
    std::cout<<"Quieres pasar de la fase atacar:"<<std::endl;
          std::cout<<"SI \nNO"<<std::endl;
        Fase=ingresarComando();
  system("cls");

  }while(Fase =="NO");




}


void fortificar(Risk* risk){
system("cls");
  std::cout<<"FORTIFICAR"<<std::endl;

 // Obtener el jugador en turno risk->getNameJugadorEnTurno()
    Jugador* jugadorEnTurno = risk->getJugador(risk->getNameJugadorEnTurno());
    string nombreTerritorioOrigen = "", continenteOrigen= "",nombreTerritorioDestino= "",continenteDestino= "";

     std::cout<<risk->buscarterritoriosJugador();
      std::cout<<"\nsalir - para salir de la fase de fortificar\n"<<std::endl;
// Solicitar el nombre del territorio de origen y destino
  
    do{
        std::cout<<"Ingrese el nombre del territorio de origen:\n";
         nombreTerritorioOrigen = ingresarComando();
         if(nombreTerritorioOrigen=="salir"){
          break;
         }
        continenteOrigen = risk->buscarContinenteTerritorio(nombreTerritorioOrigen);

       
        
        if(continenteOrigen=="" || !risk->EsterritorioJugador(continenteOrigen, nombreTerritorioOrigen)){
            std::cout<<"\n-** Nombre de territorio no valido **-\n\n";
        }

    }while(continenteOrigen=="" || !risk->EsterritorioJugador(continenteOrigen, nombreTerritorioOrigen));

    do{
      if(nombreTerritorioOrigen=="salir"){
          break;
         }
        std::cout<<"\nIngrese el nombre del territorio de Destino:\n";
        nombreTerritorioDestino = ingresarComando();
        continenteDestino = risk->buscarContinenteTerritorio(nombreTerritorioDestino);

      
        
        if(continenteDestino=="" || !risk->EsterritorioJugador(continenteDestino, nombreTerritorioDestino)){
            std::cout<<"\n-** Nombre de territorio no valido **-\n\n";
        }

    }while(continenteDestino=="" || !risk->EsterritorioJugador(continenteDestino, nombreTerritorioDestino));

    
   
if(nombreTerritorioOrigen!="salir"){
    // Buscar los territorios de origen y destino
    Territorio* territorioOrigen = risk->getTerritorio(continenteOrigen,nombreTerritorioOrigen);
    Territorio* territorioDestino = risk->getTerritorio(continenteDestino,nombreTerritorioDestino);

    // Verificar si los territorios pertenecen al mismo jugador
    if ( risk->territorioPerteneceAJugador(territorioOrigen)->GetNombreJugador() == risk->territorioPerteneceAJugador(territorioDestino)->GetNombreJugador()) {
        // Solicitar la cantidad de fichas a mover
        int cantidadFichas;
        std::cout << "Ingrese la cantidad de fichas a mover: ";
        cantidadFichas=stoi(ingresarComando());

        // Verificar si el territorio de origen tiene suficientes fichas
        if (territorioOrigen->GetQFichas() >= cantidadFichas) {
            
            // Mover las fichas del territorio de origen al territorio de destino
            for (int i = 0; i < cantidadFichas; i++) {
                Ficha ficha = territorioOrigen->GetFicha(jugadorEnTurno->GetNombreJugador());
                std::cout<<ficha.GetColor()<<std::endl;
                
                territorioDestino->addFicha(ficha);
                
                
                
            }
            territorioOrigen->restarFichas(cantidadFichas);

            // Mostrar mensaje de exito
            std::cout << "Se han movido " << cantidadFichas << " fichas del territorio " << nombreTerritorioOrigen << " al territorio " << nombreTerritorioDestino << "." << std::endl;
            std::cout<<risk->buscarterritoriosJugador();
        } else {
            std::cout << "El territorio de origen no tiene suficientes fichas." << std::endl;
        }
    } else {
        std::cout << "Los territorios no pertenecen al mismo jugador." << std::endl;
    }

}




}

void costo_conquista(Risk* risk, std::string NTerritorio) {
  system("cls");
 std::cout<<"\n  Turno de Jugador: "<<risk->getNameJugadorEnTurno()
        <<"\n  Color: "<<risk->getColorJugadorEnTurno()
        <<"\n  Fichas disponibles: "<<risk->getFichasJugadorEnTurno()<<"\n\n"<<std::endl;
       

   // std::cout<<risk->buscarterritoriosJugador();
  
/*
  std::string prueba;
  std::cout<<NTerritorio<<std::endl;
  cin>>prueba;
*/
    if(!(risk->getContinentedelPais(NTerritorio)) ||  !(risk->getTerritorio((risk->getContinentedelPais(NTerritorio))->GetNombreContinente(), NTerritorio) )){
        std::cout<<"ESTE CONTINENTE NO EXISTE\n"<<std::endl;
    }else{
    Jugador* jugador = risk->getJugador(risk->getNameJugadorEnTurno());
    std::vector<Territorio*> territorios_jugador = jugador->GetTerritorios();
    
    Continente* cont = risk->getContinentedelPais(NTerritorio);
    Territorio* territoriodestino = risk->getTerritorio(cont->GetNombreContinente(), NTerritorio);
    if(risk->territorioPerteneceAJugador( territoriodestino)->GetNombreJugador()!=jugador->GetNombreJugador()){
    if (NTerritorio != territoriodestino->getNombre()) {
        std::cout << "Este territorio no está disponible." << std::endl;
        return;
    } else {
        // Inicializar información del camino con el costo mínimo
        int costoMinimo = 1000000;  // Puedes ajustar este valor según tus necesidades
        std::vector<Territorio*> caminoMinimo;

        for (int i = 0; i < territorios_jugador.size(); i++) {
            std::vector<Territorio*> caminoActual = grafo.buscarCaminoDijkstra(territorios_jugador[i], territoriodestino);

            // Calcular el costo total en base a las fichas del territorio
            int costoTotal = 0;
            for (int j = 0; j < caminoActual.size(); ++j) {
                costoTotal += caminoActual[j]->GetQFichas();
            }

            // Comparar con el mínimo actual
            if (costoTotal < costoMinimo) {
                costoMinimo = costoTotal;
                caminoMinimo = caminoActual;
            }
        }

        // Imprimir la información del camino con el costo mínimo
        std::cout << "Para consquistar el territorio <" << territoriodestino->getNombre() << "> debes: ";
        for (int j = 0; j < caminoMinimo.size(); ++j) {
            std::cout << caminoMinimo[j]->getNombre();
            if (j < caminoMinimo.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << " (Costo total: " << costoMinimo << ")" << std::endl;
    }
    }else {
      std::cout<<"\neste territorio ya pertenece al jugador\n"<<std::endl;
    }
    }
}

void conquista_mas_barata(Risk* risk) {
    system("cls");
   
    
    Jugador* jugador = risk->getJugador(risk->getNameJugadorEnTurno());
    std::vector<Territorio*> territorios_jugador = jugador->GetTerritorios();
    
    // Inicializar información del camino con el costo mínimo
    int costoMinimo = 1000000;  // Puedes ajustar este valor según tus necesidades
    std::vector<Territorio*> caminoMinimo;
    std::vector<Continente*> conti =risk->getContinentes();
    
    for (int i = 0; i < territorios_jugador.size(); i++) {
      
        for (int j = 0; j < risk->getContinentes().size(); j++) {
          
              std::vector<Territorio*> territorio_Destino = conti[j]->GetPTerritorios();
            for (int k = 0; k < territorio_Destino.size(); k++) {
                
                if (territorios_jugador[i]->getNombre()!=territorio_Destino[k]->getNombre()) {
                    std::vector<Territorio*> caminoActual = grafo.buscarCaminoDijkstra(territorios_jugador[i], territorio_Destino[k]);
                    
  

                    // Calcular el costo total en base a las fichas del territorio
                    int costoTotal = 0;
                    for (int l = 0; l < caminoActual.size(); ++l) {
                        costoTotal += caminoActual[l]->GetQFichas();
                    }
                    
                    // Comparar con el mínimo actual
                    if (costoTotal < costoMinimo) {
                        costoMinimo = costoTotal;
                        caminoMinimo = caminoActual;
                    }
                }
            }
        }


    }
    
    // Imprimir la información del camino con el costo mínimo
    
    std::cout << "La conquista más barata disponible es avanzar sobre el territorio <" << caminoMinimo[caminoMinimo.size()-1]->getNombre() << ">"
              << " desde el territorio <" << caminoMinimo[0]->getNombre() << ">. Para conquistar el territorio <"
              << caminoMinimo[caminoMinimo.size()-1]->getNombre() << ">, debe atacar desde <" << caminoMinimo[0]->getNombre() << ">,"
              << " pasando por los territorios: \n";
    
    for (int j = 0; j < caminoMinimo.size(); ++j) {
        std::cout << "<" << caminoMinimo[j]->getNombre() << ">";
        
            std::cout << "-> ";
        
    }
  
    std::cout << ".\n Debe conquistar " << costoMinimo << " unidades de ejército." << std::endl;
std::string prueba;
  //std::cout<<territorios_jugador[i]->getNombre()<<territorio_Destino[k]->getNombre()<<std::endl;
 // cin>>prueba;

}
