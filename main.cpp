#include <iostream>
#include <cstring>
#include <fstream> // lectura de archivos
// #include <conio.h>
// #include "trabajadores.h"
// #include "productos.h"
#include "num_letras.h"
// #include "ventas.h"
using namespace std;

void AgregarProducto(int ID, string NOMBRE, string GENERICO, int tipo,float COSTO, float VENTA, int EXISTENCIA){
    // variable del archivo
    ofstream arch_empleados;
    arch_empleados.open("productos.txt", ios::app);

    if(arch_empleados.fail()){
        cout << "No se pudo abrir el archivo";
    }

    arch_empleados <<ID<<";"<<NOMBRE<<";"<<GENERICO<<";"<<tipo<<";"<<COSTO<<";"<<VENTA<<";"<<EXISTENCIA<<";"<<endl;
    // cerramos el archivos
    arch_empleados.close();

    cout << "Producto agregado" << endl;
}

void RestarExistenciaProducto(int ID){
    ifstream arch_empleados;
    ofstream arch_empleados_in;
    string info, datos[6];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("productos.txt", ios::in);
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
                int temp = atoi(datos[6].c_str());
                temp -= 1;
                datos[6] = to_string(temp);
            }else{
                for (int i = 0; i < 6; i++){
                    arch_empleados_in << datos[i] << ";";
                }
                arch_empleados_in << endl;
            }
        }        
    }
    remove("productos.txt");
    rename("temp.txt", "productos.txt");
}

int BusquedaUltimoProcuto(){
    ifstream arch_empleados;
    string info, datos[6];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("productos.txt", ios::in);

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
        }        
    }
    int id = atoi(datos[0].c_str());
    if(id<3){
        return 3;
    }else{
        return id +1;
    }
}

void TodosProductos(){
    ifstream arch_empleados;
    string info, datos[6];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("productos.txt", ios::in);

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
            for (int i = 0; i < 6; i++){
                    cout << datos[i] << "\t|\t";
            }
            cout << endl;
        }        
    }
}

string *BusquedaProductos(int ID){
    ifstream arch_empleados;
    string info;
    static string datos[6];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("productos.txt", ios::in);

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
                break; break;
            }else{
                cout << "Producto no encontrado" << endl;
            }
        }        
    }
    return datos;
}

void BajaProductos(int ID){
    ifstream arch_empleados;
    ofstream arch_empleados_in;
    string info, datos[6];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("productos.txt", ios::in);
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
                cout << "El producto ha sido eliminado" << endl;
            }else{
                for (int i = 0; i < 6; i++){
                    arch_empleados_in << datos[i] << ";";
                }
                arch_empleados_in << endl;
            }
        }        
    }
    remove("productos.txt");
    rename("temp.txt", "productos.txt");
}

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

    cout << "Usuario agregado" << endl;
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

int BusquedaUltimoEmpleado(){
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
        }        
    }
    int id = atoi(datos[0].c_str());
    return id +1;
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
            }else{
                cout << "Trabajador no encontrado" << endl;
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
                    cout << datos[i] << "\t|\t";
            }
            cout << endl;
        }        
    }
}

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
    ventas.open("ventas.txt", ios::app);

    if(ventas.fail()){
        cout << "No se pudo abrir el archivo";
    }

    ifstream arch_empleados;
    string info, datos[3];
    int clave, contador = 0;
    size_t posicion;

    arch_empleados.open("carrito.txt", ios::in);

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

    arch_empleados.open("ventas.txt", ios::in);

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
            string *info = BusquedaProductos(id);

            AddCarrito(info);
            RestarExistenciaProducto(id);
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

                        cout << "Ingresa el costo: ";
                        cin >> costo;

                        cout << "Ingresa el tipo (1.Medicamento\t2.Dulces\t3.Limpieza\t4.Etc)";
                        cin >> tipo;

                        cout << "Ingresa el precio de venta: ";
                        cin >> venta;

                        cout << "Ingresa la existencia: ";
                        cin >> existencia;

                        id = BusquedaUltimoProcuto();

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

                        string* info = BusquedaProductos(idaux);
                        for (int i = 0; i < 6; i++){
                            cout << info[i] << "\t|\t";
                        }
                        cout << endl;
                        
                        break;
                    }

                    case 4:{
                        int aux2;
                        cout << "Ingrese el ID: ";
                        cin >> aux2;

                        BajaProductos(aux2);

                        break;
                    }
                    default: cout << "Valor fuera de rango" << endl; system("pause"); break;
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

                        AltaTrabajador(ID, NOMBRE, PATERNO, MATERNO, telefono, civil, DEPARTAMENTO, turno);
                        system("pause");
                        break;
                    }

                    case 2:{
                        int id;
                        cout << "Bajas Trabajadores" << endl << endl;
                        cout << "Ingresa el ID para dar de baja: ";
                        cin >> id;

                        BajaTrabajador(id);
                        system("pause");
                        break;
                    }

                    case 3:{
                        int id;
                        cout << "Consulta por ID" << endl << endl;
                        cout << "Ingresa el ID a buscar: ";
                        cin >> id;
                        BusquedaEmpleado(id);
                        system("pause");
                        break;
                    }

                    case 4: {
                        cout << "Lista de empleados" << endl << endl;
                        TodosEmpleados();
                        system("pause");
                        break;
                    }

                    case 5: {break;}
                    default: cout << "Valor fuera de rango" << endl; system("pause"); break;
                }
                ans = 0;
                break;
            }
            case 5: continua = false; break;
            default: cout << "Valor fuera de rango" << endl; system("pause"); break;
        }
        menu = 0;
    }

    return 0;
}