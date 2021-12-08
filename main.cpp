#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream> // lectura de archivos
using namespace std;
// bibliotecas propias
#include "trabajadores.h"
#include "num_letras.h"
#include "ventas.h"
#include "productos.h"


// menus
int MenuPrincipal(){
    system("clear");
    int ans;

    cout << "                   FARMACIAS ''" << endl << endl;
    cout << "1..........................................COMPRAR" << endl;
    cout << "2........................................PRODUCTOS" << endl;
    cout << "3........................................CONSULTAS" << endl;
    cout << "4.....................................TRABAJADORES" << endl << endl << endl;
    cout << "5............................................SALIR" << endl;
    cout << "user$  ";
    cin >> ans;

    return ans;
}

int MenuProductos(){
    system("clear");
    int ans;

    cout << "1..........................................AGREGAR" << endl;
    cout << "2...................................CONSULTAR TODO" << endl;
    cout << "3.....................................CONSULTAR ID" << endl;
    cout << "4.........................................ELIMINAR" << endl << endl << endl;
    cout << "5............................................SALIR" << endl;
    cout << "user$  ";
    cin >> ans;

    return ans;
}

int MenuTrabajadores(){
    system("clear");
    int ans;

    cout << "1.............................................ALTA" << endl;
    cout << "2.............................................BAJA" << endl;
    cout << "3..................................CONSULTA POR ID" << endl;
    cout << "4....................................MOSTRAR TODOS" << endl << endl << endl;
    cout << "5.........................................REGRESAR" << endl;
    cout << "user$  ";
    cin >> ans;

    return ans;
}

int MenuConsultas(){
    system("clear");
    int ans;
    
    cout << "1.....................................VENTAS X DIA" << endl;
    cout << "2..................................ATENDIDOS X DIA" << endl;
    cout << "3.............................ARTICULOS + VENDIDOS" << endl;
    cout << "4..............................VENTAS X VENDEDORES" << endl;
    cout << "5.............................ARTICULOS + VENDIDOS" << endl;
    cout << "6.............................ARTICULOS - VENDIDOS" << endl;
    cout << "7...........................................VENTAS" << endl;
    cin >> ans;
    
    return ans;
}

// venta
void AddCarrito(string datos[6]){
    // variable del archivo
    ofstream arch_empleados;
    arch_empleados.open("carrito.txt", ios::app);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    arch_empleados << datos[1] << ";" << datos[3] << ";" << datos[5];
    // cerramos el archivos
    arch_empleados.close();
}

void VerCarrito(){
    ifstream arch_empleados;
    string info, datos[3];
    int clave, contador = 0;
    size_t posicion;
    float suma = 0;

    arch_empleados.open("carrito.txt", ios::in);
    if(arch_empleados.good()){
        if(arch_empleados.fail()){
            cout << "No se pudo abrir el archivo";
        }
        // if(arch_empleados.)
        while (!arch_empleados.eof()){
            while(getline(arch_empleados, info)){
                while((posicion=info.find(";"))!=string::npos){
                    datos[contador] = info.substr(0, posicion);
                    info.erase(0, posicion+1);
                    contador++;
                }
                contador = 0;
                cout << datos[0] << "\t" << datos[2];

                char aux[10];
                strcpy(aux, datos[4].c_str());
                suma += atof(aux);
                cout << endl << endl << "Total: " << suma;
                cout << endl;
            }        
        }
    }else{
        cout << "Aun no agregas nada al carrito" << endl;
    }
}

void Ticket(){
    system("clear");
    char ans;
    int suma = 0, id;
    string nombre_cliente;

    cout << "¿El comprador es mayor de 65?";
    cin >> ans;

    if(ans == 's' || ans == 'S'){
        ifstream arch_empleados;
        string info, datos[3];
        int clave, contador = 0;
        float aux;
        size_t posicion;

        cout << "Ingresa el nombre del cliente: ";
        cin >> nombre_cliente;

        cout << "INGRESA TU ID: ";
        cin >> id;

        arch_empleados.open("carrito.txt", ios::in);

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
                if(datos[2] == "1"){
                    aux = atof(datos[2].c_str());
                    aux = aux * 0.90;
                }
                cout << datos[0] << "\t" << aux << endl;
                suma += aux;
            }        
        }

        float iva = suma * 0.16;
        cout << "IVA -- " << iva << endl;
        suma = suma + iva;
        BusquedaEmpleado(id);

        numeros_a_letras(suma);

        ventas_hechas(id, nombre_cliente);
    }
}

int main(){

    bool continua = true;
    int dumb;

    while(continua){
        int menu = MenuPrincipal();
        switch (menu){
            case 1: {
                while (true){
                    system("clear");
                    VerCarrito();
                    
                    int id;
                    cout << endl << "1. Salir\t2. Cobrar";
                    cout << endl << "Ingresa el ID para agregar: ";
                    cin >> id;

                    if(id == 1){
                        break;
                    }
                    if(id == 2){
                        Ticket();
                    }
                    else{
                        string *info = BusquedaProductos(id);

                        AddCarrito(info);
                        RestarExistenciaProducto(id);
                    }
                    id = 0;
                }
                break;
            }
            case 2: {
                int ans = MenuProductos();
                switch (ans){
                    case 1: {
                        string nombre, generico, tipo, costo, venta, existencia;
                        int id;
                        cout << "Ingresa el nombre del Producto: ";
                        cin >> nombre;

                        cout << "Ingresa el generico del producto: ";
                        cin >> generico;

                        cout << "Ingresa el tipo de producto (1.Medicamento\t2.Dulces\t3.Etc): ";
                        cin >> tipo;

                        cout << "Ingresa el costo del producto: ";
                        cin >> costo;

                        cout << "Ingresa la venta del producto: ";
                        cin >> venta;

                        cout << "Existencia: ";
                        cin >> existencia;

                        id = BusquedaUltimoProductos();
                        AltaProducto(id, nombre, generico, tipo, costo, venta, existencia);
                        break;        
                    }
                    case 2: {
                        TodosProductos();
                        break;
                    }
                    case 3: {
                        int id;
                        cout << "Ingresa el ID: ";
                        cin >> id;
                        BusquedaProducto(id);
                        break;
                    }
                    case 4: {
                        int id;
                        cout << "Ingresa el ID del producto a eliminar: ";
                        cin >> id;
                        BajaProducto(id);
                        break;
                    }
                }
                ans = 0;
                break;
            }
            case 3: break;
            case 4: {
                int ans = MenuTrabajadores();
                switch(ans){
                    case 1:{
                        int civil, turno, ID;
                        string NOMBRE, PATERNO, MATERNO, DEPARTAMENTO;
                        long telefono;

                        cout << "Alta de Trabajadores" << endl << endl;
                        cout << "Ingresa el nombre: ";
                        cin >> NOMBRE;

                        cout << "Ingresa el paterno: ";
                        cin >> PATERNO;

                        cout << "Ingresa el materno: ";
                        cin >> MATERNO;

                        cout << "Ingresa el telefono: ";
                        cin >> telefono;

                        cout << "Ingresa el estado civil (1.Soltero\t2.Casado\t3.Divorsiado\t4.Viudo): ";
                        cin >> civil;

                        cout << "Ingresa el departamento: ";
                        cin >> DEPARTAMENTO;

                        cout << "Ingresa el turno (1.Matutino\t2.Vespertino\t3.Nocturno): ";
                        cin >> turno;

                        ID = BusquedaUltimoEmpleado();
                        cout << ID;
                        AltaTrabajador(ID, NOMBRE, PATERNO, MATERNO, telefono, civil, DEPARTAMENTO, turno);
                        // int c = getchar();
                        break;
                    }

                    case 2:{
                        int id;
                        cout << "Bajas Trabajadores" << endl << endl;
                        cout << "Ingresa el ID para dar de baja: ";
                        cin >> id;

                        BajaTrabajador(id);
                        int c = getchar();
                        break;
                    }

                    case 3:{
                        int id;
                        cout << "Consulta por ID" << endl << endl;
                        cout << "Ingresa el ID a buscar: ";
                        cin >> id;
                        BusquedaEmpleado(id);
                        int c = getchar();
                        break;
                    }

                    case 4: {
                        cout << "Lista de empleados" << endl << endl;
                        TodosEmpleados();
                        int c = getchar();
                        break;
                    }

                    case 5: {break;}
                    default: cout << "Valor fuera de rango" << endl; int c = getchar(); break;
                }
                ans = 0;
                break;
            }
            case 5: continua = false; break;
            default: cout << "Valor fuera de rango" << endl; int c = getchar(); break;
        }
        menu = 0;
    }

    return 0;
}