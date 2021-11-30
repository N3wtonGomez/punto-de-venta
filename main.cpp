#include <iostream>
#include <fstream> // lectura de archivos
using namespace std;

void AltaTrabajador(int ID, string NOMBRE, string PATERNO, string MATERNO, long telefono, int civil, string DEPARTAMENTO, int turno){
    // variable del archivo
    ofstream arch_empleados;
    arch_empleados.open("empleados.txt", ios::out);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    arch_empleados << ID << "   " << NOMBRE << "    " << PATERNO << "  " << MATERNO << "    " << telefono << " " << civil << " " << DEPARTAMENTO << "  " << turno;
    // cerramos el archivos
    arch_empleados.close();
}

void BajaTrabajador(){

}

void BusquedaEmpleado(){

}

void TodosEmpleados(){
    // imprimimos todos los empleados
    ifstream arch_empleados;
    string info;
    
    arch_empleados.open("empleados.txt", ios::in);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    while (!arch_empleados.eof()){
        getline(arch_empleados, info);
        cout << info << endl;
    }
    
    
}

int main(){
    
    AltaTrabajador(
        12,
        "Enrique",
        "Gomez",
        "Linares",
        4491687798,
        2,
        "ventas",
        2
    );


    TodosEmpleados();
    return 0;
}