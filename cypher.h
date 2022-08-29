#ifndef CYPHER_H
#define CYPHER_H

#include <iostream>
#include <vector>

using namespace std;

class Cypher{
    private:
        vector<unsigned char> key[16];
        vector<unsigned char> block[16];

    public:
        string encrypt (vector<unsigned char>, vector<unsigned char>);
        string columnar_transposition (vector<unsigned char>);
        string row_transposition (vector<unsigned char>);
        string polyalphabetic_shift (vector<unsigned char>, vector<unsigned char>);
        string xor_tecnique (vector<unsigned char>, vector<unsigned char>);

        string decrypt(unsigned char, vector<unsigned char>);
};

//string Cypher :: encrypt(unsigned char key, vector<unsigned char>block){
//}

string Cypher :: columnar_transposition(vector<unsigned char> block){
    string example;
    for (int i = 2; i < block.size(); i+=4){
        example += block [i];
    }

    cout << example;
    return example;
}

#endif