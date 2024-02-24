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

//prototipo para llamarlo desde otros lados.
int main();

//estructura de paciente
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

//vector de tipo paciente
vector <paciente> pacientes;

void Menu(){

    cout << "*******************" << endl;
    cout << "*Base de Pacientes*" << endl;
    cout << "*******************" << endl;
    cout << endl << endl;
    cout << "[1] Mostrar Pacientes." << endl;
    cout << "[2] Añadir Paciente." << endl;
    cout << "[3] Modificar Paciente." << endl;
    cout << "[4] Quitar Paciente." << endl;
    cout << "[5] Salir." << endl << endl;
    cout << "Ingresa el número correspondiente a la opción: ";
    cin >> opcion;
    cin.ignore();
    system("CLS");
}

void MostrarPacientes(){

    cout << "ID\tNOMBRE\tAPELLIDO\tEDAD\tENFERMEDAD" << endl;
    for (paciente i : pacientes){
        cout << i.id << "\t" << i.nombre << "\t" << i.apellido << "\t" << i.edad << "\t" << i.enfermedad << endl;
    }
    system("pause");
    system("CLS");
    main();
    
}

void AgregarPaciente(){
    string nombrePaciente;
    string apellidoPaciente;
    int edadPaciente;
    string enfermedadPaciente;

    cout << "Ingresa el nombre del paciente: ";
    getline(cin, nombrePaciente);
    cin.ignore();

    cout << "Ingresa el apellido del paciente: ";
    getline(cin, apellidoPaciente);
    cin.ignore();

    cout << "Ingresa la edad del paciente: ";
    cin >> edadPaciente;
    cin.ignore();

    cout << "Ingresa la enfermedad del paciente: ";
    getline(cin, enfermedadPaciente);
    cin.ignore();

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
    system("CLS");
    main();
}

void ModificarPaciente(){

    int target; //target = id a buscar
    bool encontrado = false;
    cout << "Ingresa el ID del paciente: ";
    cin >> target;
    cin.ignore();
    for (paciente &i : pacientes)
    {
        if (i.id == target)
        {
            encontrado = true;
            cout << "*********************" << endl;
            cout << "*PACIENTE ENCONTRADO*" << endl;
            cout << "*********************" << endl << endl;

            cout << "[1] Cambiar nombre." << endl;
            cout << "[2] Cambiar apellido." << endl;
            cout << "[3] Cambiar edad." << endl;
            cout << "[4] Cambiar enfermedad." << endl;
            cout << "[5] Salir" << endl << endl;

            cout << "Selecciona la opción del dato a modificar" << endl;
            cin >> opcion;
            cin.ignore();
            system("CLS");

            switch (opcion)
            {
            case 1: //cambiar nombre
                cout <<"Ingresa el nuevo nombre: ";
                getline(cin, i.nombre);
                cin.ignore();
                break;
            
            case 2:
                cout << "Ingresa el nuevo apellido: ";
                getline(cin, i.apellido);
                cin.ignore();
                break;
            
            case 3:
                cout << "Ingresa la nueva edad: ";
                cin >> i.edad;
                cin.ignore();
                break;

            case 4:
                cout << "Ingresa la nueva enfermedad: ";
                getline(cin, i.enfermedad);
                cin.ignore();
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

void EliminarPaciente(){

    int target; //target = id a buscar
    bool encontrado = false;
    int confirmar;
    cout << "Ingresa el ID del paciente: ";
    cin >> target;
    cin.ignore();
    
    for (auto it = pacientes.begin(); it != pacientes.end(); ++it)
    {
        if (it->id == target)
        {
            encontrado = true;
            cout << "*********************" << endl;
            cout << "*PACIENTE ENCONTRADO*" << endl;
            cout << "*********************" << endl << endl;

            cout << "ID\tNOMBRE\tAPELLIDO\tEDAD\tENFERMEDAD" << endl;
            cout << it->id << "\t" << it->nombre << "\t" << it->apellido << "\t" << it->edad << "\t" << it->enfermedad << endl << endl;

            cout << "Ingresa [1] para eliminar el paciente. Ingresa cualquier otro numero para regresar: ";
            cin >> confirmar;
            cin.ignore();
            if(confirmar == 1){
                pacientes.erase(it);
                cout << "Paciente eliminado." << endl;
            }
            else cout << "Cancelando..." << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "Paciente no encontrado." << endl;
    }
    system("pause");
    system("CLS");
    main();
}


int main(){

    Menu();
    switch (opcion)
    {
    case 1:
        MostrarPacientes();
        break;
    case 2:
        AgregarPaciente();
        break;
    case 3:
        ModificarPaciente();
        break;
    case 4:
        EliminarPaciente();
        break;
    case 5:
        //salir
        return 0;
    }   
}