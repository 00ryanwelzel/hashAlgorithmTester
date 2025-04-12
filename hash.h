#include <iostream>
#include <string>
#include <cmath>

#ifndef HASH_H
#define HASH_H

using namespace std;

struct node {
    string data;
    node* next;

    node(const string& in);
};

struct hashTable {
private:
    int len;      
    node** storage; 

public:
    hashTable(int k);

    int hash_function(const string& text);
    int place_node(const string& text, int line);

    void print_table();
    void print_table_lengths();
    void print_std_dev();
};

#endif