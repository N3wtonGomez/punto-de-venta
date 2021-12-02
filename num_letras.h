#include <iostream>
#include <cstring>
#include <fstream> // lectura de archivos
// #include <conio.h>
using namespace std;

void numeros_a_letras(int numero){
    if (numero >= 0 && numero <= 9999){
        int unidad = numero % 10; numero = numero/10;
        int decena = numero % 10; numero = numero/10;
        int centena = numero % 10; numero = numero/10;
        int unimil = numero % 10; numero = numero/10;

        switch (unimil){
            case 0: cout << ""; break;
            case 1: cout << "mil"; break;
            case 2: cout << "dos mil"; break;
            case 3: cout << "tres mil"; break;
            case 4: cout << "cuatro mil"; break;
            case 5: cout << "cinco mil"; break;
            case 6: cout << "seis mil"; break;
            case 7: cout << "siete mil"; break;
            case 8: cout << "ocho mil"; break;
            case 9: cout << "nueve mil"; break;
            default:
                break;
        }

        switch (centena){
        case 0: cout << ""; break;
        case 1:{
            if (decena == 0 && unidad == 0){
                cout << "cien";
            }else{
                cout << "ciento";
            }
            break;
        }
        case 2: cout << " doscientos "; break;
        case 3: cout << " trescientos "; break;
        case 4: cout << " cuatrocientos "; break;
        case 5: cout << " quinientos "; break;
        case 6: cout << " seiscientos "; break;
        case 7: cout << " setecientos "; break;
        case 8: cout << " ochocientos "; break;
        case 9: cout << " novecientos "; break;
        
        default:
            break;
        }

        switch (decena){
            case 1: {
                    switch (unidad){
                        case 0: cout << " diez "; break;
                        case 1: cout << " once "; break;
                        case 2: cout << " doce "; break;
                        case 3: cout << " trece "; break;
                        case 4: cout << " catorce "; break;
                        case 5: cout << " quince "; break;
                        case 6: cout << " dieciseis "; break;
                        case 7: cout << " diecisiete "; break;
                        case 8: cout << " dieciocho "; break;
                        case 9: cout << " diecinueve "; break;
                        
                        default:
                            break;
                    }
                    break;
                }
            case 2:{
                    if(unidad == 0){
                        cout << " veinte ";
                    }else{
                        cout << " veinti ";
                    }
                    break;
                }
            case 3: {
                if (unidad==0){
                    cout << " treinta ";
                }else{
                    cout << " treinta y ";
                }
                
                break;
            }

            case 4: {
                if(unidad == 0){
                    cout << " cuarenta ";
                }else{
                    cout << " cuarenta y ";
                }
                break;
            }

            case 5: {
                if(unidad == 0){
                    cout << " cincuenta ";
                }else{
                    cout << " cincuenta y ";
                }
                break;
            }

            case 6: {
                if(unidad == 0){
                    cout << " sesenta ";
                }else{
                    cout << " sesenta y ";
                }
                break;
            }

            case 7: {
                if(unidad == 0){
                    cout << " setenta ";
                }else{
                    cout << " setenta y ";
                }
                break;
            }

            case 8: {
                if(unidad == 0){
                    cout << " ochenta ";
                }else{
                    cout << " ochenta y ";
                }
                break;
            }

            case 9: {
                if(unidad == 0){
                    cout << " noventa ";
                }else{
                    cout << " noventa y ";
                }
                break;
            }
            default:
                break;
        }

        if(decena>1){
            switch (unidad){
                case 1: cout << "uno"; break;
                case 2: cout << "dos"; break;
                case 3: cout << "tres"; break;
                case 4: cout << "cuatro"; break;
                case 5: cout << "cinco"; break;
                case 6: cout << "seis"; break;
                case 7: cout << "siete"; break;
                case 8: cout << "ocho"; break;
                case 9: cout << "nueve"; break;
                
                default:
                    break;
            }
        }
    }
}