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
    return message;
}

string fill_block(string message){
    int message_difference = message.length() % SIZE_BLOCK;
    if (message_difference != 0){
        int aux = SIZE_BLOCK - (message_difference);
        for (int i = aux; i > 0; i--){
            message.push_back(ADD_CHARACTER);
        }
    }
    return message;
}

void get_blocks(string message, int start, int end, vector<unsigned char>& block){
    int aux = 0;
    for (int i = start; i < end; i++){
        block[i] = message.at(i);
        aux++;
    }
}

void password_to_vector(string password,vector<unsigned char>& block){
    for (int i = 0; i < SIZE_BLOCK; i++){
        block[i] = password.at(i);
    }
}


int main(int argc, char* argv[]) {
    char option;
    clock_t time_start, time_end;
    bool bandera = true;
    int message_length;
    

    while (bandera){
        option = menu();

        switch (option){
            case '1': {
                string password, message;
                int number_of_blocks;
                vector <unsigned char> block(SIZE_BLOCK, ADD_CHARACTER);
                vector <unsigned char> key(SIZE_BLOCK, ADD_CHARACTER);
                string file = ("input.txt");

                message = get_message_from_file(file);
                cout << "Escribe una contraseña alfanumerica de tamanio de 16 caracteres" << endl;
                cin >> password;
                cin.ignore();
                password_to_vector(password, key);
                
                message = fill_block(message);
                number_of_blocks = message.size()/SIZE_BLOCK;

                for (int i = 0; i < number_of_blocks; i++){
                    get_blocks(message, i*SIZE_BLOCK, i*SIZE_BLOCK + SIZE_BLOCK, block);
                    
                }

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