#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"

using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // Utilizes a maximum of 500 keys for testing
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }

    hashTable* h = new hashTable(k);

    for(string& s : texts){
        if(!s.empty()){
            h->hash_function(s);
        }
    }

    cout << "==== Printing the slot lengths ====" << endl;

    h->print_table_lengths();

    cout << "==== Printing the standard deviation =====" << endl;

    h->print_std_dev();

    free(h);

    return 0;
}