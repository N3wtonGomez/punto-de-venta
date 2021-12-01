#include <iostream>
#include <fstream> // lectura de archivos
using namespace std;

void AltaTrabajador(int ID, string NOMBRE, string PATERNO, string MATERNO, long telefono, int civil, string DEPARTAMENTO, int turno){
    // variable del archivo
    ofstream arch_empleados;
    arch_empleados.open("empleados.txt", ios::app);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    arch_empleados <<ID<<";"<<NOMBRE<<";"<<PATERNO<<";"<<MATERNO<<";"<<telefono<<";"<<civil<<";"<<DEPARTAMENTO<<";"<<turno<<";"<<endl;
    // cerramos el archivos
    arch_empleados.close();
}

void BajaTrabajador(int ID){
    ifstream arch_empleados;
    ofstream arch_empleados_in;
    string info, datos[8];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("empleados.txt", ios::in);
    arch_empleados_in.open("temp.txt", ios::app);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    bool encontrado = false;
    while (!arch_empleados.eof()){
        while(getline(arch_empleados, info)){
            while((posicion=info.find(";"))!=string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            if(datos[0] == to_string(ID)){
                cout << "El usuario ha sido eliminado" << endl;
            }else{
                for (int i = 0; i < 8; i++){
                    arch_empleados_in << datos[i] << ";";
                }
                arch_empleados_in << endl;
            }
        }        
    }
    remove("empleados.txt");
    rename("temp.txt", "empleados.txt");
}

void BusquedaEmpleado(int ID){
    ifstream arch_empleados;
    string info, datos[8];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("empleados.txt", ios::in);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    bool encontrado = false;
    while (!arch_empleados.eof()){
        while(getline(arch_empleados, info)){
            while((posicion=info.find(";"))!=string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            if(datos[0] == to_string(ID)){
                for (int i = 0; i < 8; i++){
                    cout << datos[i] << "   ";
                }
                cout << endl;
            }  
        }        
    }
}

void TodosEmpleados(){
    ifstream arch_empleados;
    string info, datos[8];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("empleados.txt", ios::in);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    while (!arch_empleados.eof()){
        while(getline(arch_empleados, info)){
            while((posicion=info.find(";"))!=string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            for (int i = 0; i < 8; i++){
                    cout << datos[i] << "   |   ";
            }
            cout << endl;
        }        
    }
}

int main(){
    AltaTrabajador(12,"ENRIQUE","GOMEZ","LINARES",4491687798, 2, "VENTAS", 1);
    AltaTrabajador(13,"DIEGO","BIUGU","LINARES",4491687798, 2, "VENTAS", 1);
    BusquedaEmpleado(12);
    cout << "--------------" << endl;
    TodosEmpleados();
    cout << "--------------" << endl;
    BajaTrabajador(13);
    TodosEmpleados();

    return 0;
}