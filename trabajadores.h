#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream> 
using namespace std;

void AltaTrabajador(int ID, string NOMBRE, string PATERNO, string MATERNO, long telefono, int civil, string DEPARTAMENTO, int turno){
    // variable del archivo
    ofstream arch_empleados;
    arch_empleados.open("empleados.bin", ios::app); // se abre el archivo en modo de ampliación de este

    // por si falla el archivo
    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    // guardamos la informacion enviada en el archivo con separadores, para su proximo procesamiento
    arch_empleados <<ID<<";"<<NOMBRE<<";"<<PATERNO<<";"<<MATERNO<<";"<<telefono<<";"<<civil<<";"<<DEPARTAMENTO<<";"<<turno<<";"<<endl;
    // cerramos el archivo
    arch_empleados.close();

    cout << "Usuario agregado" << endl;
}

void BajaTrabajador(int ID){
    ifstream arch_empleados; // variable para el archivo de modo lectura
    ofstream arch_empleados_in; // variable para el archivo en modo escritura
    string info, datos[8];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("empleados.bin", ios::in); // modo lectura del archio
    arch_empleados_in.open("temp.bin", ios::app); // modo escritura del archivo

    // por si el archivo falla
    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    bool encontrado = false;
    /*
    hacemos la lectura completa del archivo, y al mismo tiempo vamos leyendo
    linea por linea la informacion
    */
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

    arch_empleados.close();
    arch_empleados_in.close();
    remove("empleados.bin");
    rename("temp.bin", "empleados.bin");
}

int BusquedaUltimoEmpleado(){
    // comprobamos si existe el documento
    ifstream comprobacion; // variable del archivo 
    comprobacion.open("empleados.bin"); // abrimos el archivo
    // si existe y es bueno, se busca el ultimo empleado
    if(comprobacion.good()){
        ifstream arch_empleados; // variable del archivo
        string info, datos[8];
        int clave, contador = 0, posiciones = 0;
        size_t posicion;
        
        // abrimos el archivo en modo de lectura
        arch_empleados.open("empleados.bin", ios::in);

        if(arch_empleados.fail()){ // por si el archivo falla
            cout << "No se pudo abrir el archivo";
        }

        /*
        este algoritmo nos permite leer todo el archivo, y 
        separarlo en los distintos componentes que tiene, mediante
        sus separadores ';', y guardarlos en un array de tipo string
        */
        bool encontrado = false;
        // mientras no se acabe el archivo
        while (!arch_empleados.eof()){
            // obtenemos una linea del archivo
            while(getline(arch_empleados, info)){
                // y gaurdamos la informacion en el array, separandola
                while((posicion=info.find(";"))!=string::npos){
                    datos[contador] = info.substr(0, posicion);
                    info.erase(0, posicion+1);
                    contador++;
                }
            }
            posiciones += 1;       
        }
        /*
        al momento de acabarse el archivo la ultima informacion que nos
        va a quedar es la de la ultima posicion, por ende, el ultimo id
        */
       arch_empleados.close();
        int id = atoi(datos[0].c_str());
        return id + 1;
    }else{ // si no, se retorna 1;
        comprobacion.close();
        return 1;
    }    
}

void BusquedaEmpleado(int ID){
    ifstream arch_empleados;
    string info, datos[8];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("empleados.bin", ios::in);

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
                    cout << datos[i] << "\t";
                }
                cout << endl;
            }else{
                cout << "Trabajador no encontrado" << endl;
            }
        }        
    }
    arch_empleados.close();
}

void TodosEmpleados(){
    ifstream arch_empleados;
    string info, datos[8];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("empleados.bin", ios::in);

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
                    cout << datos[i] << "\t";
            }
            cout << endl;
        }        
    }
    arch_empleados.close();
}
