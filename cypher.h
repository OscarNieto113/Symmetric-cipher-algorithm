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
        Cypher (vector<unsigned char>, vector<unsigned char>); // Constructor alterno

        ~Cypher (); //Destructor

        void encrypt (vector<unsigned char>, vector<unsigned char>);
        void decrypt(vector<unsigned char>, vector<unsigned char>);

        void columnar_transposition (vector<unsigned char>);
        void row_transposition (vector<unsigned char>);
        void polyalphabetic_shift (vector<unsigned char>, vector<unsigned char>);
        void xor_tecnique (vector<unsigned char>, vector<unsigned char>);

        void to_string (vector<unsigned char>);
};

Cypher :: Cypher(){
    vector <unsigned char> block(SIZE_BLOCK, ADD_CHARACTER);
    vector <unsigned char> key(SIZE_BLOCK, ADD_CHARACTER);
}

Cypher :: Cypher(vector <unsigned char> block_, vector <unsigned char> key_){
    block = block_;
    key = key_
}

Cypher :: ~Cypher() { delete[] block, delete[] key; }

void Cypher :: encrypt(vector<unsigned char> block, vector<unsigned char> key){
    //columnar_transposition(block);
    to_string(block);
}

void Cypher :: columnar_transposition(vector<unsigned char> block){

    
}

void Cypher :: to_string(vector<unsigned char> block){
    for (int i = 0; i < SIZE_BLOCK; i++){
        cout << endl << block[i] << ", ";
    }
    cout << endl;
}

#endif