/*NOTAS:
    Hay que hacer una funcion para cada opcion.
    Hay que usar vectores <> (arrays dinamicos) en lugar de 
    arrays estaticos, porque no sabemos cuantos elementos van a haber.
    
    Al usar la funcion AgregarPaciente se recolectan los datos y se deben pasar al
    constructor paciente dentro del vector pacientes. */


#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
//Para estilizar textos en CMD:
#include <iomanip>
#include <ios> 

using namespace std;

//variables globales
int opcion, id = 0;

//prototipos
void menu();
void AgregarPaciente();


typedef struct paciente{
    string nombre;
    string apellido;
    int edad;
    string enfermedad;
    int id;

    //constructor del paciente
    paciente(string _nombre, string _apellido, int _edad, string _enfermedad, int _id) 
        : nombre(_nombre), apellido(_apellido), edad(_edad), enfermedad(_enfermedad), id(_id) {}
}paciente;

vector<paciente> pacientes;

void AgregarPaciente(){
    string nombrePaciente;
    string apellidoPaciente;
    int edadPaciente;
    string enfermedadPaciente;

    cout << "Ingresa el nombre del paciente: ";
    getline(cin, nombrePaciente);
    fflush(stdin);

    cout << "Ingresa el apellido del paciente: ";
    getline(cin, apellidoPaciente);
    fflush(stdin);

    cout << "Ingresa la edad del paciente: ";
    cin >> edadPaciente;
    fflush(stdin);

    cout << "Ingresa la enfermedad del paciente: ";
    getline(cin, enfermedadPaciente);
    fflush(stdin);

    //se pasan los datos al vector con la info para el constructor
    pacientes.push_back(paciente(nombrePaciente, apellidoPaciente, edadPaciente, enfermedadPaciente, id));
    
    system("CLS");
    cout << "Paciente Registrado" << endl;
    cout << "Nombre: " << nombrePaciente << endl;
    cout << "Apellido: " << apellidoPaciente << endl;
    cout << "Edad: " << edadPaciente << endl;
    cout << "Enfermedad: " << enfermedadPaciente << endl;
    cout << "ID: " << id << endl << endl;
    id++;
    cout << "Pulsa enter para continuar...";
    getch();
    fflush(stdin);
    system("CLS");
    menu();
}

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
        //agregar paciente
        AgregarPaciente();
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