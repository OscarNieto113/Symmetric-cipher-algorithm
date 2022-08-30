#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <iostream> 

    using namespace std;

const int SIZE_BLOCK = 16; //16 caracteres = 128 bits
const char ADD_CHARACTER = 'x'; //Caracter con el que se va a rellenar si el bloque no esta completo
const int MATRIX_SIZE = SIZE_BLOCK/4;
const string INPUT_FILE = "input.txt";
const string ENCRYPT_FILE = "encrypt.txt";
const string DECRYPT_FILE = "decrypt.txt";

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

void clear_file(string filename){
    std::ofstream ofs;
    ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void write_on_file(string filename, string message){
    ofstream myfile;
    myfile.open (filename, std::fstream::in | std::fstream::out | std::fstream::app);
    myfile << message;
    myfile.close();
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
        block[aux] = message.at(i);
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
    bool flag = true;
    int message_length;
    
    while (flag){
        option = menu();

        switch (option){
            case '1': {
                string password, message, encrypted_message;
                int number_of_blocks;
                vector <unsigned char> block(SIZE_BLOCK, ADD_CHARACTER);
                vector <unsigned char> key(SIZE_BLOCK, ADD_CHARACTER);

                message = get_message_from_file(INPUT_FILE);
                cout << "Escribe una contraseña alfanumerica de tamanio de 16 caracteres: " << endl;
                password = "0123456789abcdef"; //borrar
                //cin >> password;
                //cin.ignore();
                password_to_vector(password, key);
                message = fill_block(message);
                number_of_blocks = message.size()/SIZE_BLOCK;

                clear_file(ENCRYPT_FILE);
                
                for (int i = 0; i < number_of_blocks; i++){
                    get_blocks(message, i*SIZE_BLOCK, i*SIZE_BLOCK + SIZE_BLOCK, block);
                    Cypher encrypted_block(&block, &key);
                    encrypted_message = encrypted_block.encrypt();
                    write_on_file(ENCRYPT_FILE, encrypted_message);
                    //encrypted_block.~Cypher(); //Destruir objeto
                }
                break;
            }
            case '2': {
                string password, message, decrypted_message;
                int number_of_blocks;
                vector <unsigned char> block(SIZE_BLOCK, ADD_CHARACTER);
                vector <unsigned char> key(SIZE_BLOCK, ADD_CHARACTER);
                string filename = ("encrypt.txt");

                message = get_message_from_file(ENCRYPT_FILE);
                cout << "Escribe la contraseña para descifrar el mensaje: " ;
                password = "0123456789abcdef"; //borrar
                //cin >> password;
                //cin.ignore();
                password_to_vector(password, key);

                message = fill_block(message);
                number_of_blocks = message.size()/SIZE_BLOCK;

                clear_file(DECRYPT_FILE);

                for (int i = 0; i < number_of_blocks; i++){
                    get_blocks(message, i*SIZE_BLOCK, i*SIZE_BLOCK + SIZE_BLOCK, block);
                    Cypher encrypted_block2(&block, &key);
                    decrypted_message = encrypted_block2.decrypt();
                    write_on_file(DECRYPT_FILE, decrypted_message);
                    //encrypted_block2.~Cypher(); //Destruir objeto
                }
                
                break;
            }
            case '3': {
                flag = false;
                break;
            }
        }
    }
    return 0;
}