/*NOTAS:
    Hay que hacer una funcion para cada opcion.
    Hay que usar vectores <> (arrays dinamicos) en lugar de 
    arrays estaticos, porque no sabemos cuantos elementos van a haber.
    
    Al usar la funcion AgregarPaciente se recolectan los datos y se deben pasar al
    constructor paciente dentro del vector pacientes.
    
    Falta agragar algo como "pulsa ESC para regresar al menu" */


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
void Menu();
int main();
void AgregarPaciente();
void MostrarPacientes();
void ModificarPaciente();


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
    system("pause");
    fflush(stdin);
    system("CLS");
    main();
}

void Menu(){

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

void MostrarPacientes(){

    for (paciente i : pacientes){
        cout << "ID\tNOMBRE\tAPELLIDO\tEDAD\tENFERMEDAD" << endl;
        cout << i.id << "\t" << i.nombre << "\t" << i.apellido << "\t" << i.edad << "\t" << i.enfermedad << endl;
    }
    system("pause");
    system("CLS");
    main();
    
}

void ModificarPaciente(){

    int target; //target = id a buscar
    bool encontrado = false;
    cout << "Ingresa el ID del paciente: ";
    cin >> target;
    fflush(stdin);
    for (paciente &i : pacientes)
    {
        if (i.id == target)
        {
            encontrado = true;
            cout << "*********************" << endl;
            cout << "*PACIENTE ENCONTRADO*" << endl;
            cout << "*********************" << endl << endl;

            cout << "1. Cambiar nombre." << endl;
            cout << "2. Cambiar apellido." << endl;
            cout << "3. Cambiar edad." << endl;
            cout << "4. Cambiar enfermedad." << endl;
            cout << "5. Salir" << endl << endl;

            cout << "Selecciona la opción del dato a modificar" << endl;
            cin >> opcion;
            fflush(stdin);
            system("CLS");

            switch (opcion)
            {
            case 1: //cambiar nombre
                cout <<"Ingresa el nuevo nombre: ";
                getline(cin, i.nombre);
                fflush(stdin);
                break;
            
            case 2:
                cout << "Ingresa el nuevo apellido: ";
                getline(cin, i.apellido);
                fflush(stdin);
                break;
            
            case 3:
                cout << "Ingresa la nueva edad: ";
                cin >> i.edad;
                cin.ignore();
                break;

            case 4:
                cout << "Ingresa la nueva enfermedad: ";
                getline(cin, i.enfermedad);
                fflush(stdin);
                break;
            
            case 5: break;
            }
        break;
        }
    }
    if(!encontrado)
    {
        system("CLS");
        cout << "Paciente no encontrado." << endl;
        system("pause");
    }
    system("CLS");
    main();
}

int main(){

    Menu();
    switch (opcion)
    {
    case 1:
        /* Mostrar Pacientes*/
        MostrarPacientes();
        break;
    case 2:
        //agregar paciente
        AgregarPaciente();
        break;
    case 3:
        //Modificar paciente
        ModificarPaciente();
        break;
    case 4:
        //Quitar paciente
        break;
    case 5:
        //salir
        return 0;
    }
    
}