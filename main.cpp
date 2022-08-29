#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cypher.h>
using namespace std;


int main(int argc, char* argv[]) {
    char option;
    clock_t time_start, time_end;
    bool flag = true;

    while (flag){
        cout << "Elige la opcion: " << endl;
        cout << "1. Encriptar" << endl;
        cout << "2. Desencriptar " << endl; 
        cout << "3. Salir " << endl << endl; 

        cin >> option;
        cin.ignore();

        switch (option){
            case '1': {
                string password;
                string message;
                ifstream file("input.txt");
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
                string password;
                string cyphered_message;
                string decrypt_message;
                ifstream file("encrypt.txt");
                if (file.is_open()){
                    while (getline(file, cyphered_message)){
                        
                    }
                    file.close();
                }
                else{
                    cout << "No se pudo abrir el archivo" << endl;
                }
                cout << cyphered_message;
                cout << "Escribe la contraseña" << endl;
                cin >> password;
                cin.ignore();
                
                //Realizar implementacion del encriptado con las variables cyphered_message y password

                //Guarda el resultado en el txt decrypt
                ofstream file2("decrypt.txt");
                if (file2.is_open()){
                    file2 << decrypt_message;
                    file2.close();
                }
                else{
                    cout << "No se pudo abrir el archivo" << endl;
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
