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
    cout << "\nChoose an Option: \n";
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
        // Not inserting any possible empty lines
        if (!career.empty()) {
            trie.insert(career);
        }
    }

    file.close();

        
    cout << "\n=== Career Trie Data Structure ===" << endl;

    int choice_num;
    string user_input;

    while (true) {
        printMenu();
        cin >> choice_num;
        cin.ignore();

        // Choice 1: Inserting User Given Career
        if (choice_num == 1) {
            cout << "\nType a Career to be Inserted Into the Trie: \n";
            getline(cin, user_input);
            trie.insert(user_input);
            cout << "\nSuccessfully Inserted " << user_input << " into the Trie Tree." << endl;
        }
            
        // Choice 2: Search for an exact career in Trie   
        else if (choice_num == 2) {
            cout << "\nSearch for an Exact Career Name: \n";
            getline(cin, user_input);

            if (trie.search(user_input)) {
                cout << "\n" << user_input << " was found in the current Trie Tree." << endl;
            }
            else {
                cout << "\n" << user_input << " was not found." << endl;
            }
        }
            
        // Choice 3: Use the autocomplete function for a career search
        else if (choice_num == 3) {
            cout << "\n~Search for a Career from the O*NET Dataset~ \n \n*Limited to first 10 results*\n";

            string prefix;

            while (true) {
                cout << "\nHit Enter to Search or 'exit' to Return to the Menu:\n";
                getline(cin, prefix);

                if (prefix == "exit") break;
        
                if (prefix == "") {
                    cout << "Empty Input. Please type a prefix." << endl;
                    continue;
                }

                vector<string> results = trie.autocomplete(prefix);

                if (results.empty()) {
                    cout << "\nNo matches found." << endl;
                } 
                else {
                    cout << "\nFound Suggestions:" << endl;
            
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
        }
            
        // Choice 4: Exit out of system
        else if (choice_num == 4) {
            cout << "\nThank You! Goodbye!\n \n";
            break;
        }
    }

    return 0;
}