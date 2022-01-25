#include <iostream>
#include <fstream> // TIENE FUNCIONES DE LECTURA Y ESCRITURA DENTRO DEL ARCHIVO
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* cin>> // lectura de numeros
   cin.getline(cadena, longitud) // para leer tipos de datos char
   getline(cin, cadena) // para leer tipos de datos string
*/

using namespace std;

class Peliculas
{
public:
    char Pelicula_Nombre[10], Menu_Lista[10]; //ARREGLOS UNIDIMENSIONALES
    void Agregar(); //METODOS
    void Imprimir();
    void Buscar();
    void Modificar();
    void Eliminar();
}p;



/////METODO AGREGAR ///
void Peliculas::Agregar() // DE LA CLASE ALUMNO PERTENECE CAPTURAR ESO SIGNIFICAN LOS DOS PUNTOS
{
    cout<<"Introduce el nombre de la pelicula que deceas agregar:";
    cin.getline(Pelicula_Nombre, 10);
    cin.getline(Pelicula_Nombre, 10); //EN LUGAR DE FFLUSH X QUE NO SIRVE CON GETLINE PARA LEER CADENAS


    cout<<"¿En que lista deceas agregar la pelicula?: ";
    cin.getline(Menu_Lista, 10);

    ofstream Archivo("Peliculas.txt",ios::app); // ofstream crea un objeto para escritura en el archivo llamado "Archivo", ios::app = entrada y salida de datos
    Archivo<<Pelicula_Nombre<<'|'<<Menu_Lista<<'|'; // se escribiendo en el archivo creado campo por campo separado por el delimitador '|'
    Archivo.close(); // cerrar el archivo
}


//////METODO IMPRIMIR
void Peliculas::Imprimir()
{
    int i;
    ifstream Lectura("Peliculas.txt"); // abrir archivo en formato de lectura, "Lectura" que es un objeto
    if(!Lectura.good()) // good ( libreria fstream) nos verifica si hubo problema al abrir el archivo a traves de true o false
    {
        cout<<"No existe el archivo\n";
        system("pause");
    }
    else
    {
        while(!Lectura.eof()) // eof = end of file
        {
            //Lectura de la variable user
            i=0;
            do
            {
                Lectura.read((char *)&Pelicula_Nombre[i],1); //leo el objeto de tipo char, lo asigno a la variable user en la posicion que tenga el subindice, y se lee de caracter en carácter
                if(Lectura.eof())
                    break;
                    i++;
            }while(Pelicula_Nombre[i-1]!='|'); // mientras user en la posicion del subindice menos 1 sea diferente al delimitador, sigues escribiendo en el arreglo "user"
            Pelicula_Nombre[i-1]='\0'; // si no se cumple el while anterior, entonces escribe en la posicion del delimitador '\0' que significa final de la cadena para saber que se termino ese campo "user"
            //Lectura de la variable pass
            i=0;
            do
            {
                Lectura.read((char *)&Menu_Lista[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(Menu_Lista[i-1]!='|');
            Menu_Lista[i-1]='\0';
            //Lectura de la variable nom
            i=0;

            if(Lectura.eof())
                break;

            //Imprimes valores
            cout<<endl<<"\nNombre de la pelicula: "<<Pelicula_Nombre<<endl<<endl<<"\n"; // endl=salto de linea
            if(Lectura.eof())
                break;
        }
        system("pause");
    }
    Lectura.close(); // cierras el archivo a traves del objeto "Lectura"
}


int main(){
    int opc;
    do{
        cout<<"\n 1.- AGREGAR \n 2.- IMPRIMIR \n 3.- BUSCAR \n 4.- MODIFICAR \n 5.- ELIMINAR \n 6-SALIR \n\n Selecciona una opcion: ";
        cin>>opc;
        switch(opc){
            case 1: p.Agregar();
                break;

            case 2: p.Imprimir();
                break;

            case 3: p.Buscar();
                break;

            case 4: p.Modificar();
                break;

            case 5: p.Eliminar();
            break;
        }

    }while(opc!=6);
}
