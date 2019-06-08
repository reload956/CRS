//
// Created by igor on 22.04.19.
//

#ifndef LAB5_HASH_H
#define LAB5_HASH_H

#include <vector>
#include <string>
#include<iostream>
#include <jmorecfg.h>

struct element{
    std::string data;
    unsigned int date;
    unsigned int code;
};

class Hashtable {
private:
    struct element *vector;
    unsigned int size;
    bool *status;
    unsigned int Hashing1(element);
    unsigned int Hashing2(unsigned int,unsigned int);
public:
    Hashtable(unsigned int Mysize);
    bool Del(element);
    unsigned int Add(element);
    ~Hashtable();
    unsigned int Search(element element1);
    void Statwriter();
    void print();

};

void Error(int c);

#endif //LAB5_HASH_H
