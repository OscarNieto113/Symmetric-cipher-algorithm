#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

const int SIZE_BLOCK = 16; //16 caracteres = 128 bits
const char ADD_CHARACTER = 'x'; //Caracter con el que se va a rellenar si el bloque no esta completo

#include "cypher.h"

char menu(){
    char option;
    cout << endl << "Elige la opcion: " << endl;
    cout << "1. Encriptar" << endl;
    cout << "2. Desencriptar " << endl; 
    cout << "3. Salir " << endl << endl; 
    cin >> option;
    cin.ignore();
    return option;
}

string get_message_from_file(string file1){
    string message;
    ifstream file(file1);
    if (file.is_open()){
        while (getline(file, message)){
                        
                    }
                    file.close();
                }
                else{
                    cout << "No se pudo abrir el archivo" << endl;
                }
                cout << message;
                cout << "Escribe una contraseña simetrica alfanumerica de no maximo 16 caracteres" << endl;
                cin >> password;
                cin.ignore();

                //Realizar implementacion del encriptado con las variables message y password
                break;
            }
            case '2': {
                string password, message;
                int number_of_blocks;
                vector <unsigned char> block(SIZE_BLOCK, ADD_CHARACTER);
                vector <unsigned char> key(SIZE_BLOCK, ADD_CHARACTER);
                string file = ("encrypt.txt");

                message = get_message_from_file(file);
                cout << "Escribe la contraseña para descifrar el mensaje" << endl;
                cin >> password;
                cin.ignore();
                password_to_vector(password, key);

                for (int i = 0; i < number_of_blocks; i++){
                    get_blocks(message, i*SIZE_BLOCK, i*SIZE_BLOCK + SIZE_BLOCK, block);
                    Cypher encrypted_block(block, key);
                }
                
                break;
            }
            case '3': {
                bandera = false;
                break;
            }
        }
    }
    return 0;
}