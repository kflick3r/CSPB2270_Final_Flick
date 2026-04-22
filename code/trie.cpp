/* Note: refer to the header file (trie.h) for documentation of each method. */

#include "trie.h"

using namespace std;


Trie::Trie() {
    // Initialize empty root node
    root = new TrieNode();
}

// Delete Node helper function
void Trie::deleteNode(TrieNode* node) {
    
    // Recursively delete all child nodes first
    for (auto entry = node->children.begin(); entry != node->children.end(); entry++) {
        deleteNode(entry->second);
    }

    // Delete current node
    delete node;
}

Trie::~Trie() {
    // Call the helper function to delete the nodes recursively
    deleteNode(root);
}


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


// Depth-First search helper function
void dfs(TrieNode* node, string prefix, vector<string>& results) {
    // If this node marks the end of a valid word,
    // add word to results vector
    if (node->isTheEnd) {
        results.push_back(prefix);
    }

    // Explore all possible child paths recursively
    for (auto entry = node->children.begin(); entry != node->children.end(); entry++) {
        char c = entry->first;

        TrieNode* childNode = entry->second;

        // call the recursive function with extended prefix
        dfs(childNode, prefix + c, results);
    }
}


vector<string> Trie::autocomplete(string prefix) {
     // Initialize pointer node to root 
    TrieNode* current = root;

    // Traverse to the end of the prefix only
    for (int i =0; i < prefix.length(); i++) {
        char c = prefix[i];

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
    // the prefix exists.
    
    // Initialize results vector
    vector<string> results;
    
    // Call depth-first search with validated prefix
    // and collect all words that extend this prefix
    dfs(current, prefix, results);

    return results;
}
