// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
      ofstream out(nombre_archivo.c_str(), ios::in|ios::binary);//Abrimos el archivo
      out.seekp(posicion*24);

      out.write((char*)&mascota->edad,4);
      out.write(mascota->nombre.c_str(),20); //Se escriben los datos en el archivo

      out.close();//Cerramos el archivo*/

}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{

    ifstream in(nombre_archivo.c_str()); //Abrimos el archivo
    in.seekg(posicion*24);

    char nombre[20];
    int edad=0; //Variables para almacenar los datos

    in.read((char*)&edad,4);
    in.read(nombre,20); //extraccion de los datos

    in.close();

    Mascota *m = new Mascota(edad,nombre); //Se crea nueva mascota
    return m; //se retorna la mascota
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta; //Vector para almacenar mascotas


    ifstream in(nombre_archivo.c_str()); //Abrimos el archivo
    in.seekg(0,in.end);
    float tam = in.tellg()/24; //Se calcula la cantidad de mascotas en el archivo

    in.seekg(0); //Va al inicio del archivo

    int edad;
    char nombre [20]; //variables para almacenar datos de la mascota

    for(int i = 0; i < tam; i++)
    {
        in.read((char*)&edad,4);
        in.read(nombre,20); //extraccion de los datos y almacenaje en las variables
        respuesta.push_back(new Mascota(edad, nombre)); //Se guardan los datos en el vector
    }

    return respuesta; //retornamos el vector
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
