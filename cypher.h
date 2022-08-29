#ifndef CYPHER_H
#define CYPHER_H

#include <iostream>
#include <vector>

using namespace std;

class Cypher{
    private:
        unsigned char key;
        vector<unsigned char> block[16];

    public:
        string encrypt (unsigned char, vector<unsigned char>);
        string columnar_transposition (unsigned char);
        string row_transposition (unsigned char);
        string polyalphabetic_shift (unsigned char, vector<unsigned char>)
        string xor_tecnique (unsigned char, vector<unsigned char>);

        string decrypt(unsigned char, vector<unsigned char>);
};

//string Cypher :: encrypt(unsigned char key, vector<unsigned char>block){
//}

#endif