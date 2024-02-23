/*NOTAS:
    Hay que hacer una funcion para cada opcion.
    Hay que usar vectores <> (arrays dinamicos) en lugar de 
    arrays estaticos, porque no sabemos cuantos elementos van a haber.*/


#include <iostream>
#include <string>
#include <vector>
//Para estilizar textos en CMD:
#include <iomanip>
#include <ios> 

using namespace std;

//variables globales
int opcion;
vector<int> pacientes;
int nextId = 0;

typedef struct paciente{
    string nombre;
    string apellido;
    string enfermedad;
    int id;
    paciente(string nombre, string apellido, string enfermedad, int id){}//constructor del paciente
}paciente;


void menu(){

    cout << "*******************" << endl;
    cout << "*Base de Pacientes*" << endl;
    cout << "*******************" << endl;
    cout << endl << endl;
    cout << "1. Mostrar Pacientes." << endl;
    cout << "2. Añadir Paciente." << endl;
    cout << "3. Modificar Paciente." << endl;
    cout << "4. Quitar Paciente." << endl;
    cout << "5. Salir." << endl << endl;
    cout << "Ingresa el número correspondiente a la opción: ";
    cin >> opcion;
    fflush(stdin);
    system("CLS");
}

int main(){

    menu();
    switch (opcion)
    {
    case 1:
        /* Mostrar Pacientes*/
        break;
    case 2:
        //add paciente
        break;
    case 3:
        //Modificar paciente
        break;
    case 4:
        //Quitar paciente
        break;
    case 5:
        //salir
        break;
    }
    
}