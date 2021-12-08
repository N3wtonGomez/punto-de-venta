#include <iostream>
#include <cstring>
#include <fstream> 
using namespace std;

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-", &tstruct);

    return buf;
}

void ventas_hechas(int id, string cliente){
    // variable del archivo
    ofstream ventas;
    ventas.open("ventas.bin", ios::app);

    if(ventas.fail()){
        cout << "No se pudo abrir el archivo";
    }

    ifstream arch_empleados;
    string info, datos[3];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("carrito.bin", ios::in);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    ventas << currentDateTime() << ";";
    ventas << endl << id << ";" << endl << cliente << ";" << endl;

    while (!arch_empleados.eof()){
        while(getline(arch_empleados, info)){
            while((posicion=info.find(";"))!=string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            for (int i = 0; i < 3; i++){
                    ventas << datos[i] << ";";
            }
            ventas << endl;
        }        
    }
    ventas << endl;
    ventas.close();
     
} 

int ventasxDia(){
    ifstream arch_empleados;
    string info, datos[3];
    int clave, contador = 0, ventas_dias = 0;
    size_t posicion;

    arch_empleados.open("ventas.bin", ios::in);

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
            if(datos[0] == currentDateTime()){
                ventas_dias += 1;
            }
        }        
    }
    return ventas_dias;
}
