#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Huffman {
    int box = 0;
    double freq;
    Huffman *left = NULL;
    Huffman *right = NULL;
};

const int bufferSize = 256;
int tail;
Huffman *root;

void analyze (char *fileName, int sizeBuf){
    FILE *myfile;
    myfile = fopen(fileName,"rb");
    fseek (myfile, 0, SEEK_END);
    long size = ftell(myfile);
    fclose(myfile);
    ifstream file(fileName, ios::in | ios::binary);
    int divisor = size / bufferSize;
    cout << divisor << endl;
    
    
    if(file.is_open()){
        char memblock;
        int i;
        int j;
        for(i = divisor; i > 0; i--){
            for(j = 256/8; i > 0; i--){
                file.get(memblock);
                cout << memblock - '0';
            }
            
        }
        
    }
    
    file.close();
}



int main(int argc, char** argv){
    char *fileName = "Untitled.png";
    int size = 8;
    analyze(fileName,size);
    
}