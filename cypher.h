#ifndef CYPHER_H
#define CYPHER_H

#include <iostream>
#include <vector>

using namespace std;


class Cypher{
    private:
        vector<unsigned char> *key;
        vector<unsigned char> *block;

    public:
        Cypher();//Constructor por default / omision
        Cypher (vector<unsigned char> *b, vector<unsigned char> *k); // Constructor alterno
        //~Cypher (); //Destructor

        string encrypt ();
        string decrypt();

        void diffusion_technique_enc ();
        void diffusion_technique_dec ();
        void polyalphabetic_shift_enc ();
        void polyalphabetic_shift_dec ();
        void xor_tecnique ();

        void to_string (string);
};

Cypher :: Cypher(){
    vector <unsigned char> block(SIZE_BLOCK, ADD_CHARACTER);
    vector <unsigned char> key(SIZE_BLOCK, ADD_CHARACTER);
}

Cypher :: Cypher(vector <unsigned char> *b, vector <unsigned char> *k){
    block = b;
    key = k;
}

//Cypher:: ~Cypher() {
//    delete[] block;
//    delete[] key;
//}

string Cypher :: encrypt(){
    string encrypted_message;
    diffusion_technique_enc ();
    //to_string("Column and row transposition");
    polyalphabetic_shift_enc();
    //to_string("Polyalphabetic shift");
    xor_tecnique();
    //to_string("XOR");

    for (int i = 0; i < SIZE_BLOCK; i++){
        encrypted_message += block->at(i);
    }

    return encrypted_message;
}


string Cypher :: decrypt(){
    string encrypted_message;
    xor_tecnique();
    //to_string("XOR");
    polyalphabetic_shift_dec();
    //to_string("Polyalphabetic shift");
    diffusion_technique_dec ();
    //to_string("Column and row transposition");
    
    for (int i = 0; i < SIZE_BLOCK; i++){
        encrypted_message += block->at(i);
    }

    return encrypted_message;
}

void Cypher :: diffusion_technique_enc (){
    unsigned char matrix_transposition [MATRIX_SIZE][MATRIX_SIZE];
    int aux = 0;
    //Filling the matrix
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            matrix_transposition [i][j] = block->at(aux);
            aux++;
        }
    }

    //Columnar transposition
    for (int i = 0; i < MATRIX_SIZE; i++){
        aux = matrix_transposition [i][0];
        matrix_transposition[i][0] = matrix_transposition[i][MATRIX_SIZE - 2];
        matrix_transposition[i][MATRIX_SIZE - 2] = aux;
    }

    //Row transposition
    for (int j = 0; j < MATRIX_SIZE; j++){
        aux = matrix_transposition [0][j];
        matrix_transposition[0][j] = matrix_transposition[MATRIX_SIZE - 2][j];
        matrix_transposition[MATRIX_SIZE - 2][j] = aux;
    }

    aux = 0;
    for (int j = 0; j < MATRIX_SIZE; j++){
        for (int i = 0; i < MATRIX_SIZE; i++){
            block->at(aux) = matrix_transposition[i][j];
            aux++;
        }
    }

}

void Cypher :: diffusion_technique_dec (){
    unsigned char matrix_transposition [MATRIX_SIZE][MATRIX_SIZE];
    int aux = 0;
    //Filling the matrix
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            matrix_transposition [i][j] = block->at(aux);
            aux++;
        }
    }

    //Row transposition
    for (int j = 0; j < MATRIX_SIZE; j++){
        aux = matrix_transposition [0][j];
        matrix_transposition[0][j] = matrix_transposition[MATRIX_SIZE - 2][j];
        matrix_transposition[MATRIX_SIZE - 2][j] = aux;
    }

    //Columnar transposition
    for (int i = 0; i < MATRIX_SIZE; i++){
        aux = matrix_transposition [i][0];
        matrix_transposition[i][0] = matrix_transposition[i][MATRIX_SIZE - 2];
        matrix_transposition[i][MATRIX_SIZE - 2] = aux;
    }

    aux = 0;
    for (int j = 0; j < MATRIX_SIZE; j++){
        for (int i = 0; i < MATRIX_SIZE; i++){
            block->at(aux) = matrix_transposition[i][j];
            aux++;
        }
    }
}

void Cypher :: polyalphabetic_shift_enc(){
    unsigned char aux;
    for (int i = 0; i < SIZE_BLOCK; i++){
        aux = block->at(i) + key->at(i);
        block->at(i) = aux;
    }
}

void Cypher :: polyalphabetic_shift_dec(){
    unsigned char aux;
    for (int i = 0; i < SIZE_BLOCK; i++){
        aux = block->at(i) - key->at(i);
        block->at(i) = aux;
    }
}

void Cypher :: xor_tecnique(){
    unsigned char aux;
    for (int i = 0; i < SIZE_BLOCK; i++){
        aux = block->at(i) ^ key->at(i);
        block->at(i) = aux;
    }
}

void Cypher :: to_string(string tecnique){
    cout << endl << "Bloque aplicando: " << tecnique << endl;
    for (int i = 0; i < SIZE_BLOCK; i++){
        cout << block->at(i) << ", ";
    }
    cout << endl;
    for (int i = 0; i < SIZE_BLOCK; i++){
        cout << (int)block->at(i) << ", ";
    }
    cout << endl;
}

#endif