#ifndef HASH_H
#define HASH_H
#include<dado.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;


class HASH
{
private:
    DADO *tabela[10];


public:
    HASH();
    void index();

};

#endif // HASH_H
