#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream> // lectura de archivos
// #include <conio.h>
#include "trabajadores.h"
#include "productos.h"
#include "num_letras.h"
#include "ventas.h"
using namespace std;


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

void Venta(){
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
            string info = "hola";
            // string *info = BusquedaProductos(id);

            // AddCarrito(info);
            // RestarExistenciaProducto(id);
        }
        id = 0;
    }
}

int main(){

    bool continua = true;
    int dumb;

    while(continua){
        int menu = MenuPrincipal();
        switch (menu){
            case 1: {
                Venta();
                break;
            }
            case 2:{
                int res = MenuProductos();
                switch (res){
                    case 1:{
                        string nombre, generico;
                        float venta, costo;
                        int id, existencia, tipo;
                        cout << "Ingresa el nombre del medicamento: ";
                        cin >> nombre;

                        cout << "Ingresa el nombre generico: ";
                        cin >> generico;

                        cout << "Ingresa el tipo (1.Medicamento\t2.Dulces\t3.Limpieza\t4.Etc)";
                        cin >> tipo;

                        cout << "Ingresa el costo: ";
                        cin >> costo;

                        cout << "Ingresa el precio de venta: ";
                        cin >> venta;

                        cout << "Ingresa la existencia: ";
                        cin >> existencia;

                        id = BusquedaUltimoProducto();

                        AgregarProducto(id, nombre, generico, tipo, costo, venta, existencia);
                        break;
                    }
                    
                    case 2:{
                        TodosProductos();
                        break;
                    }

                    case 3:{
                        int idaux;
                        cout << "Ingrese el ID: ";
                        cin >> idaux;

                        // string* info = BusquedaProductos(idaux);
                        // for (int i = 0; i < 6; i++){
                        //     cout << info[i] << "\t|\t";
                        // }
                        // cout << endl;
                        
                        break;
                    }

                    case 4:{
                        int aux2;
                        cout << "Ingrese el ID: ";
                        cin >> aux2;

                        BajaProductos(aux2);

                        break;
                    }
                    default: cout << "Valor fuera de rango" << endl; int c = getchar(); break;
                }
                break;
            }
            case 3:{
                int les = MenuConsultas();
                switch (les){
                case 1:{
                    int ventasxdia = ventasxDia();
                    cout << "Se realizaron " << ventasxDia << " ventas";
                    break;
                }
                case 2:{
                    int atendidosxdai = ventasxDia();
                    cout << "Se atendieron " << atendidosxdai << " clientes";
                    break;
                }
                
                default:
                    break;
                }
                break;
            }
            case 4:{
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
                        while (c != '\n'){
                            /* code */
                        }
                        
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