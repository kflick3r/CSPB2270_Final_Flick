#ifndef TRIE_H__
#define TRIE_H__

#include <string>
#include <map>
#include <vector>

using namespace std;

/*
 * Trie Data Structure:
 * This is a tree-based data structure.
 * It is used for efficient storage and retrieval of strings.
 *
 * Each node represents a single character, and paths from the root to 
 * the end nodes represent complete words.
 * In this case, each path represents a career title from the O*NET database.
 *
 * My implementation includes the following functions:
 * - Insertion of words
 * - Exact word search
 * - Autocomplete search 
 */

class Trie {

public:
    //Constructor
    // Initializes the Trie with an empty root node
    Trie();


    // Destructor
    ~Trie();


    // Inserts a word into the Trie.
    // Each character is added as a node if it does not already exist.
    // The final node is marked as the end of a valid word.
    // Insertion using lowercase for case-insensitive searches
    void insert(string word);


    // Traverses through each character of the parameter string.
    // Returns true if the exact word exists in the Trie.
    // Returns false otherwise. 
    // Compares string character to Trie character from the root node.
    // Seaches using lowercase.
    bool search(string word);


    // Returns a list of all words in the Trie that begin with the given prefix.
    // Navigates to the node representing the prefix, then performs a 
    // depth-first search.
    // Collects the original casing for the found word.
    vector<string> autocomplete(string prefix);


private:

    // Each node will represents a single character in the Trie.
    // children maps each character to its corresponding next node. 
    // isTheEnd marks the end of the complete career name.
    // originalWord stores the original string for correct case display in results.
    struct TrieNode {
        map<char, TrieNode*> children;
        bool isTheEnd = false;
        // Store the original word for results
        string originalWord;
    };


    // Root of the Trie
    TrieNode* root;


    // Depth-First Search helper function for autocomplete.
    // Starting at the given Trie node, explore all possibile paths, 
    // building complete words.
    // At the end of the word, store the originalWord
    // in the results reference vector.
    void dfs(TrieNode* node, vector<string>& results);
};

#endif