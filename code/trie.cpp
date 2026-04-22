/* Note: refer to the header file (trie.h) for documentation of each method. */

#include "trie.h"
#include <cctype>  // for tolower(): lowercase insert and searches

using namespace std;


Trie::Trie() {
    // Initialize empty root node
    root = new TrieNode();
}

Trie::~Trie() {}


void Trie::insert(string word) {
    // Initialize pointer node to root 
    TrieNode* current = root;

    // Loop through each character in string parameter
    for (int i = 0; i < word.length(); i++) {
        // Normalize to Lowercase
        char c = tolower(word[i]);

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

    // Store original word casing for results
    current->originalWord = word;
}


bool Trie::search(string word) {
    // Initialize pointer node to root 
    TrieNode* current = root;

    // Traverse character by character
    for (int i = 0; i < word.length(); i++) {
        // Normalize to Lowercase
        char c = tolower(word[i]);

        // If the current character path does not exist,
        // the word is not in the Trie
        if (current->children.find(c) == current->children.end()) {
            // End the search. Sting parameter was not found
            return false;
        }
        // Move to the next node corresponding to the character
        current = current->children[c];
    }
    // check if this node marks the end of a complete word
    // Only returns complete words
    return current->isTheEnd;
}


// Depth-First Search helper function
void Trie::dfs(TrieNode* node, vector<string>& results) {
    // If this node marks the end of a valid word,
    // add the original word to results vector
    if (node->isTheEnd) {
        // Store the original word (for proper casing)
        results.push_back(node->originalWord);
    }

    // Explore all possible child paths recursively
    for (auto entry = node->children.begin(); entry != node->children.end(); entry++) {
        // call the recursive function with the next node
        dfs(entry->second, results);
    }
}


vector<string> Trie::autocomplete(string prefix) {
     // Initialize pointer node to root 
    TrieNode* current = root;

    // Traverse to the end of the prefix only
    for (int i =0; i < prefix.length(); i++) {
        // Normalize to Lowercase
        char c = tolower(prefix[i]);

        // If the current character path does not exist,
        // the word is not in the Trie
        if (current->children.find(c) == current->children.end()) {
            // return the function to not trigger dfs
            return {};
        }
        // Move to the next node corresponding to the character
        current = current->children[c];
    }
    // If the loop ends and hasn't been returned, 
    // the prefix exists in the Trie.
    
    // Initialize results vector
    vector<string> results;
    
    // Call depth-first search with validated prefix
    // and collect any the original words found in search
    dfs(current, results);

    return results;
}
