#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "trie.h"

using namespace std;

// Menu for users to choose which function they want to use
void printMenu() {
    cout << "\n----------------------\n";
    cout << "         MENU         \n";
    cout << "----------------------\n";
    cout << "1. Insert a Career\n";
    cout << "2. Search for an Exact Career\n";
    cout << "3. Use an Autocomplete Search for a Career\n";
    cout << "4. Exit\n";
    cout << "Choose an Option: ";
}

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

        
    cout << "\n=== Career Autocomplete Demo ===" << endl;
    
    cout << "\n~Search for a Career from the O*NET Dataset~ \n \n*Limited to first 10 results*\n";
    
    string prefix;
    while (true) {
        cout << "\nHit Enter to Search or 'exit' to quit:\n";
        getline(cin, prefix);

        if (prefix == "exit") break;
        
        if (prefix == "") {
            cout << "Empty Input. Please type a prefix." << endl;
            continue;
        }

        vector<string> results = trie.autocomplete(prefix);

        if (results.empty()) {
            cout << "\nNo matches found." << endl;
        } else {
            cout << "\nSuggestions:" << endl;
            
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