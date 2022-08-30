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

        void encrypt ();
        void decrypt();

        void diffusion_technique  ();
        void polyalphabetic_shift ();
        void xor_tecnique ();

        void to_string ();
};

Cypher :: Cypher(){
    vector <unsigned char> block(SIZE_BLOCK, ADD_CHARACTER);
    vector <unsigned char> key(SIZE_BLOCK, ADD_CHARACTER);
}

Cypher :: Cypher(vector <unsigned char> *b, vector <unsigned char> *k){
    block = b;
    key = k;
}

void Cypher :: encrypt(){
    diffusion_technique ();
    to_string();
    polyalphabetic_shift();
    to_string();
    xor_tecnique();
    to_string();
}

void Cypher :: diffusion_technique (){
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

    //borrar
    cout << endl << "Shifted matrix by column: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++){
            cout << matrix_transposition[i][j] << " ";
        }
        cout << endl;
    }
    //borrar

    //Row transposition
    for (int j = 0; j < MATRIX_SIZE; j++){
        aux = matrix_transposition [0][j];
        matrix_transposition[0][j] = matrix_transposition[MATRIX_SIZE - 2][j];
        matrix_transposition[MATRIX_SIZE - 2][j] = aux;
    }

    //borrar
    cout << endl << "Shifted matrix by row: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++){
            cout << matrix_transposition[i][j] << " ";
        }
        cout << endl;
    }
    //borrar

    aux = 0;
    for (int j = 0; j < MATRIX_SIZE; j++){
        for (int i = 0; i < MATRIX_SIZE; i++){
            block->at(aux) = matrix_transposition[i][j];
            aux++;
        }
    }

}

void Cypher :: polyalphabetic_shift(){
    unsigned char aux;
    for (int i = 0; i < SIZE_BLOCK; i++){
        aux = block->at(i) + key->at(i);
        if (aux > 127){
            aux -= 127;
        }
        block->at(i) = aux;
    }
}

void Cypher :: xor_tecnique(){
    unsigned char aux;
    for (int i = 0; i < SIZE_BLOCK; i++){
        aux = block->at(i) ^ key->at(i);
        if (aux > 127){
            aux -= 127;
        }
        block->at(i) = aux;
    }
}

void Cypher :: to_string(){
    cout << endl << "Bloque: " << endl;
    for (int i = 0; i < SIZE_BLOCK; i++){
        cout << block->at(i) << ", ";
    }
    cout << endl << endl << "Key: " << endl;

    for (int i = 0; i < SIZE_BLOCK; i++){
        cout << key->at(i) << ", ";
    }
    cout << endl;
}

#endif