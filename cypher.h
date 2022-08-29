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

        void columnar_transposition ();
        void row_transposition ();
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
    //columnar_transposition();
    to_string();
}

void Cypher :: columnar_transposition(){

    
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