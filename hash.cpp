#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

using namespace std;

node::node(const string& in) {
    data = in;
    next = nullptr;
}

hashTable::hashTable(int k){
    len = k;
    storage = new node*[k];

    for(int i = 0; i < len; i++){
        storage[i] = nullptr;
    }

}

// Test hash functions here
int hashTable::hash_function(const string& text) {
    const double letter_weights[26] = {
        8.2,   // A
        1.5,   // B
        2.8,   // C
        4.3,   // D
        12.7,  // E
        2.2,   // F
        2.0,   // G
        6.1,   // H
        7.0,   // I
        0.15,  // J
        0.8,   // K
        4.0,   // L
        2.4,   // M
        6.7,   // N
        7.5,   // O
        1.9,   // P
        0.10,  // Q
        6.0,   // R
        6.3,   // S
        9.1,   // T
        2.8,   // U
        1.0,   // V
        2.4,   // W
        0.15,  // X
        2.0,   // Y
        0.07   // Z
    };


    int line = 1;
    int value = 0;

    for(char c : text){
        if(isalpha(c)){
            c = toupper(c);
        }

        value = 13 - letter_weights[c - 'A'];

        line += int(c) * value;
        line += floor(logf64(line));
    
    }


    line = line % len;

    place_node(text, line);

    return 1;
}

int hashTable::place_node(const string& in, int line){
    node* newNode = new node(in);

    if(storage[line] == nullptr){
        storage[line] = newNode;
    } else {
        newNode->next = storage[line];
        storage[line] = newNode;
    }

    return 1;
}

void hashTable::print_table(){
    for(int i = 0; i < 5; i++){
        node* curr = storage[i];

        cout << "Slot " << i << ":";

        while(curr != nullptr){
            cout << " " << curr->data;
            curr = curr->next;
        }

        cout << endl;
    }
}

void hashTable::print_table_lengths(){
    for(int i = 0; i < len; i++){
        int num = 0;
        node* curr = storage[i];

        cout << "Slot " << i << ": ";

        while(curr != nullptr){
            curr = curr->next;
            num++;
        }

        cout << num << endl;
    }
}

void hashTable::print_std_dev(){
    int slotLen[len];

    for (int i = 0; i < len; i++) {
        node* curr = storage[i];
        int count = 0;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        slotLen[i] = count;
    }

    float mean = 0.0f;
    for (int i = 0; i < len; i++) {
        mean += slotLen[i];
    }
    
    mean /= len;

    float variance = 0.0f;
    for (int i = 0; i < len; i++) {
        float diff = slotLen[i] - mean;
        variance += diff * diff;
    }

    float std_dev = sqrt(variance / len);

    cout << std_dev << endl;
}