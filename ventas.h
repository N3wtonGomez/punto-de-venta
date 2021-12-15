#include <iostream>
#include <cstring>
#include <fstream> 
using namespace std;

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

    ventas << "15/12/2021" << ";";
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
            if(datos[0] == "15/12/2021"){
                ventas_dias += 1;
            }
        }        
    }
    return ventas_dias;
}

void AddProductos_Vendidos(int id){
    // el estado nos sirve para saber si queremos el mas vendio
    // o el menos vendido
    ifstream archivo;
    ofstream temp;
    string info, datos[2];
    int contador =0;
    size_t posicion;

    archivo.open("productos_vendidos.bin", ios::in);
    temp.open("temp.bin", ios::app);

    while (!archivo.eof()){
        while (getline(archivo, info)){
            while((posicion=info.find(";"))!=string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            if(datos[0]==to_string(id)){
                int sumador = atoi(datos[1].c_str()) +1;
                temp << id << ";" << sumador << ";" << endl;
            }else{
                temp << id << ";1;"<<endl;
            }
        }
        
    }

    archivo.close();
    temp.close();

    remove("productos_vendidos.bin");
    rename("temp.bin", "productos_vendidos.bin");
    
}