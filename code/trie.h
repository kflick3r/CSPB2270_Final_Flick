#ifndef TRIE_H__
#define TRIE_H__

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {

public:

    
    
private:
    
    struct TrieNode {
        unordered_map<char, TrieNode*>children;
        bool isTheEnd = false;
    };

    TrieNode* root;