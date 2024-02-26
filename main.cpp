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
//Para estilizar textos en CMD:
#include <iomanip>
#include <windows.h>

using namespace std;

//variables globales
int opcion, id = 0, colAncho = 23;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //de windows.h para obtener manejo de la salida estandar. Se guarda en hConsole


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

void ColorAmarillo(){ //Cambia color del texto a amarillo

    SetConsoleTextAttribute(hConsole, 14);
}
void ColorVerde(){
    SetConsoleTextAttribute(hConsole, 2);
}
void ColorRojo(){
    SetConsoleTextAttribute(hConsole, 4);
}
void ColorReset(){ //Resetea el color del texto al default
    SetConsoleTextAttribute(hConsole, 7);
}

void Menu(){

    ColorAmarillo();
    cout << "*******************" << endl;
    cout << "*Base de Pacientes*" << endl;
    cout << "*******************" << endl;
    ColorReset();
    cout << endl << endl;

    cout << "[";
    ColorAmarillo();
    cout << "1";
    ColorReset();
    cout << "] Mostrar Pacientes." << endl;

    cout << "[";
    ColorAmarillo();
    cout << "2";
    ColorReset();
    cout << "] Añadir Paciente." << endl;

    cout << "[";
    ColorAmarillo();
    cout << "3";
    ColorReset();
    cout << "] Modificar Paciente." << endl;

    cout << "[";
    ColorAmarillo();
    cout << "4";
    ColorReset();
    cout << "] Quitar Paciente." << endl;

    cout << "[";
    ColorAmarillo();
    cout << "5";
    ColorReset();
    cout << "] Salir." << endl << endl;

    cout << "Ingresa el número correspondiente a la opción: ";
    cin >> opcion;
    cin.ignore();
    system("CLS");
}

void MostrarPacientes(){

    if (pacientes.empty()) //si no hay datos registrados
    {
        ColorRojo();
        cout << "Sin datos para mostrar" << endl;
        ColorReset();
        system("pause");
        system("CLS");
        main();
    }
    else{
    ColorAmarillo();
    cout << setw(5) << "ID" << setw(colAncho) <<"NOMBRE" << setw(colAncho) << "APELLIDO" << setw(colAncho) << "EDAD" << setw(colAncho) << "ENFERMEDAD" << endl;
    ColorReset();
    for (paciente i : pacientes){
        cout << setw(5) << i.id << setw(colAncho) << i.nombre << setw(colAncho) << i.apellido << setw(colAncho) << i.edad << setw(colAncho) << i.enfermedad << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
    }
    system("pause");
    system("CLS");
    main();
    } 
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

    ColorVerde();
    cout << "Paciente Registrado" << endl;

    ColorAmarillo();
    cout << "Nombre: ";
    ColorReset();
    cout << nombrePaciente << endl;
    ColorAmarillo();
    cout << "Apellido: ";
    ColorReset();
    cout << apellidoPaciente << endl;
    ColorAmarillo();
    cout << "Edad: ";
    ColorReset();
    cout << edadPaciente << endl;
    ColorAmarillo();
    cout << "Enfermedad: ";
    ColorReset();
    cout << enfermedadPaciente << endl;
    ColorAmarillo();
    cout << "ID: ";
    ColorReset();
    cout << id << endl << endl;
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
            ColorAmarillo();
            cout << "*********************" << endl;
            cout << "*";
            ColorVerde();
            cout << "PACIENTE ENCONTRADO";
            ColorAmarillo();
            cout << "*" << endl;
            cout << "*********************" << endl << endl;
            ColorReset();

            cout<<endl<<"Usted quiere modificar a: ";ColorVerde();cout<< i.nombre; ColorReset();cout<<", el cual tiene los siguientes datos";
            cout<<endl<<"Apellido:      "<<i.apellido;
            cout<<endl<<"Edad:          "<<i.edad;
            cout<<endl<<"Enfermedad:    "<<i.enfermedad<<endl<<endl;
            cout << "[";
            ColorAmarillo();
            cout << "1";
            ColorReset();
            cout << "] Cambiar nombre." << endl;
            cout << "[";
            ColorAmarillo();
            cout << "2";
            ColorReset();
            cout << "] Cambiar apellido." << endl;
            cout << "[";
            ColorAmarillo();
            cout << "3";
            ColorReset();
            cout << "] Cambiar edad." << endl;
            cout << "[";
            ColorAmarillo();
            cout << "4";
            ColorReset();
            cout << "] Cambiar enfermedad." << endl;
            cout << "[";
            ColorAmarillo();
            cout << "5";
            ColorReset();
            cout << "] Salir" << endl << endl;

            cout << "Selecciona la opción del dato a modificar: ";
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
        ColorVerde();
        cout << "Datos Actualizados." << endl;
        ColorReset();
        system("pause");
        break;
        }
    }
    if(!encontrado)
    {
        system("CLS");
        ColorRojo();
        cout << "Paciente no encontrado." << endl;
        ColorReset();
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

            ColorAmarillo();
            cout << "*********************" << endl;
            cout << "*";
            ColorVerde();
            cout << "PACIENTE ENCONTRADO";
            ColorAmarillo();
            cout << "*" << endl;
            cout << "*********************" << endl << endl;
            ColorReset();

            ColorAmarillo();
            cout << setw(5) << "ID" << setw(colAncho) <<"NOMBRE" << setw(colAncho) << "APELLIDO" << setw(colAncho) << "EDAD" << setw(colAncho) << "ENFERMEDAD" << endl;
            ColorReset();
            cout << setw(5) << it->id << setw(colAncho) << it->nombre << setw(colAncho) << it->apellido << setw(colAncho) << it->edad << setw(colAncho) << it->enfermedad << endl << endl;

            cout << "Ingresa [";
            ColorAmarillo();
            cout << "1";
            ColorReset();
            cout << "] para eliminar el paciente. Ingresa cualquier otro numero para regresar: ";
            cin >> confirmar;
            cin.ignore();
            if(confirmar == 1){
                pacientes.erase(it);
                ColorRojo();
                cout << "Paciente eliminado." << endl;
                ColorReset();
            }
            else cout << "Cancelando..." << endl;
            break;
        }
    }
    if (!encontrado) {
        ColorRojo();
        cout << "Paciente no encontrado." << endl;
        ColorReset();
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
    }
}
