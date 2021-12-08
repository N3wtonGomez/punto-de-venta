#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

void AltaProducto(int ID, string NOMBRE, string GENERICO, string TIPO, string COSTO, string VENTA, string EXISTENCIA){
    // variable del acrhivo
    ofstream arch_productos;
    arch_productos.open("productos.bin", ios::app);

    // por si falla el archivo
    if(arch_productos.fail()){
        cout << "No se pudo abrir el archivo";
    }

    // guardamos la informacion recibida en el archivo
    arch_productos <<ID<<";"<<NOMBRE<<";"<<GENERICO<<";"<<TIPO<<";"<<COSTO<<";"<<VENTA<<";"<<EXISTENCIA<<";"<<endl;
    // cerramos el archivo
    arch_productos.close();

    cout << "Producto agregado" << endl;
}

void BajaProducto(int ID){
    ifstream arch_productos;
    ofstream arch_productos_in;
    string info, datos[6];
    int clave, contador = 0;
    size_t posicion;

    arch_productos.open("productos.bin", ios::in);
    arch_productos_in.open("temp.bin", ios::app);

    if(arch_productos.fail()){
        cout << "No se pudo abrir el archivo";
    }

    bool encontrado = false;

    while(!arch_productos.eof()){
        while(getline(arch_productos, info)){
            while((posicion = info.find(";")) != string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            if(datos[0] == to_string(ID)){
                cout << "El producto ha sido eliminado" << endl;
            }else{
                for(int i = 0; i < 6; i++){
                    arch_productos_in << datos[i]<<";";
                }
                arch_productos_in << endl;
            }
        }
    }
    arch_productos_in.close();
    arch_productos.close();
    remove("productos.bin");
    rename("temp.bin", "productos.bin");
}

int BusquedaUltimoProductos(){
    ifstream comprobacion;
    comprobacion.open("productos.bin");

    if(comprobacion.good()){
        ifstream arch_productos;
        string info, datos[6];
        int clave, contador = 0, posiciones = 0;
        size_t posicion;

        arch_productos.open("productos.bin", ios::in);

        if(arch_productos.fail()){
            cout << "No se pudo abrir el archivo" << endl;
        }

        bool encontrado = false;
        while(!arch_productos.eof()){
            while(getline(arch_productos, info)){
                while ((posicion = info.find(";"))!=string::npos){
                    datos[contador] = info.substr(0, posicion);
                    info.erase(0, posicion+1);
                    contador++;
                }
            }
            posiciones++;
        }
        arch_productos.close();
        int id = atoi(datos[0].c_str());
        return id +1;
    }else{
        return 3;
    }
}

void TodosProductos(){
    ifstream arch_productos;
    string info, datos[6];
    int clave, contador = 0;
    size_t posicion;

    arch_productos.open("productos.bin", ios::in);

    if(arch_productos.fail()){
        cout << "no se pudo abrir el archivo" << endl;
    }

    while (!arch_productos.eof()){
        while(getline(arch_productos, info)){
            while((posicion=info.find(";"))!=string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            for(int i = 0; i<6; i++){
                cout << datos[i] << "\t";
            }
            cout << endl;
        }
    }
    arch_productos.close();
}

void BusquedaProducto(int ID){
    ifstream arch_productos;
    string info, datos[6];
    int clave, contador= 0;
    size_t posicion;

    arch_productos.open("productos.bin", ios::in);

    if(arch_productos.fail()){
        cout << "No se pudo abrir el archivo";
    }

    bool encontrado = false;
    while(!arch_productos.eof()){
        while(getline(arch_productos, info)){
            while((posicion=info.find(";"))!=string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            if(datos[0]==to_string(ID)){
                for(int i=0;i<6;i++){
                    cout << datos[i] << "\t";
                }
                cout << endl;
            }else{
                cout << "Producto no encontrado" << endl;
            }
        }
    }
    arch_productos.close();
}

string* BusquedaProductos(int ID){
    ifstream arch_productos;
    static string datos[6];
    string info;
    int clave, contador= 0;
    size_t posicion;

    arch_productos.open("productos.bin", ios::in);

    if(arch_productos.fail()){
        cout << "No se pudo abrir el archivo";
    }

    bool encontrado = false;
    while(!arch_productos.eof()){
        while(getline(arch_productos, info)){
            while((posicion=info.find(";"))!=string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            if(datos[0]==to_string(ID)){
                break; break;
            }else{
                cout << "Producto no encontrado" << endl;
            }
        }
    }
    arch_productos.close();
    return datos;
}

void RestarExistenciaProducto(int ID){
    ifstream arch_productos;
    ofstream arch_productos_in;
    string info, datos[6];
    int clave, contador = 0;
    size_t posicion;

    arch_productos.open("productos.bin", ios::in);
    arch_productos_in.open("temp.bin", ios::app);

    if(arch_productos.fail()){
        cout << "No se pudo abrir el archivo";
    }

    bool encontrado = false;

    while(!arch_productos.eof()){
        while(getline(arch_productos, info)){
            while((posicion = info.find(";")) != string::npos){
                datos[contador] = info.substr(0, posicion);
                info.erase(0, posicion+1);
                contador++;
            }
            contador = 0;
            if(datos[0] == to_string(ID)){
                int existencia = stoi(datos[6]);
                existencia--;
                for(int j=0;j<5;j++){
                    arch_productos_in << datos[j] << ";";
                }
                arch_productos_in<<existencia<<";"<<endl;
            }else{
                for(int i = 0; i < 6; i++){
                    arch_productos_in << datos[i]<<";";
                }
                arch_productos_in << endl;
            }
        }
    }
    arch_productos_in.close();
    arch_productos.close();
    remove("productos.bin");
    rename("temp.bin", "productos.bin");
}