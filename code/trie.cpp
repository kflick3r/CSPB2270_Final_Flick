/* Note: refer to the header file (trie.h) for documentation of each method. */

#include "trie.h"

using namespace std;

Trie::Trie() {
    // Initialize empty root node
    root = new TrieNode();
}

Trie::~Trie() {}


void Trie::insert(string word) {
    // Initialize pointer node to root 
    TrieNode* current = root;

    // Loop through each character in string
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];

        // If the current character does not have a node yet,
        // create a new TrieNode for it
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        
        // Move to the next node corresponding to the character
        current = current->children[c];
    }

    // End of loop = end of word
    current->isTheEnd = true;    
}

bool Trie::search(string word) {
    // Initialize pointer node to root 
    TrieNode* current = root;

    // Traverse character by character
    for (int i = 0; i < word.length(); i++) {
        char c = word[i];

        // If the current character path does not exist,
        // the word is not in the Trie
        if (current->children.find(c) == current->children.end()) {
            return false;
        }
        // Move to the next node corresponding to the character
        current = current->children[c];
    }
    // check if this node marks the end of a complete word
    return current->isTheEnd;
}

vector<string> Trie::autocomplete(string prefix) {
    // 

    return;
}
