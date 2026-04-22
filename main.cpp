#include <iostream>
#include <vector>
#include <fstream>
#include "trie.h"

using namespace std;

int main() {
    Trie trie;

    // Load careers from file
    ifstream file("careers.txt");
    string career;

    // Check if the file was loaded correctly
    if (!file) {
        cout << "Error: Could not open careers.txt" << endl;
        return 1;
    }

    // insert the careers into the trie
    while (getline(file, career)) {
        if (!career.empty()) {
            trie.insert(career);
        }
    }

    file.close();
        
    cout << "=== Career Autocomplete Demo ===" << endl;

    string prefix;
    while (true) {
        cout << "\nSearch for a Career (or 'exit' to quit): ";
        getline(cin, prefix);

        if (prefix == "exit") break;

        vector<string> results = trie.autocomplete(prefix);

        if (results.empty()) {
            cout << "No matches found." << endl;
        } else {
            cout << "Suggestions:" << endl;
            
            // tracker for number of results
            int count = 0;
            
            for (const string& word : results) {
                cout << " - " << word << endl;
                // limit to 10 results
                count++;
                if (count == 10) break; 
            }
        }
    }

    return 0;
}