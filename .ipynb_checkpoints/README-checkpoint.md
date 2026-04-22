# CSPB2270_Final_Flick
## Final Project: Trie Tree Algorithm
### Career Autocomplete Search

**Author:** Kassidy Flick
**Course:** CSPB 2270 - Data Structures
**Semester:** Spring 2026

---

## Project Overview
This project implements a Trie in C++ to simulate an autocomplete search system for career titles. It is built on a real-world dataset of hundreds of occupations from O*NET, demonstrating scalability and efficient prefix-based search.

The system allows users to:
- Insert Career Titles
- Search for exact matches
- Retieve autocomplete suggestions based on a prefix

---

## Data Structure: Trie

A Trie is a tree-based data structure used for retrieval of strings. Each node represents a character, and complete words are formed by paths from the root to the terminal node. 

---

## Features Implemented
- Insert career titles into Trie
- Case-insensitive search
- Autocomplete based on prefix
- Displays original career formatting
- Handles large dataset (O*NET careers)

---

## How It Works
1. Career titles are read from `careers.txt`
2. Each word is inserted into the Trie
    - Normalized to lowercase internally
3. The Trie stores the original formatting for display
4. User enters a prefix
5. DFS traverses subtree to collect all matches

---

## How to Run the Project
1. Clone the Repository
   `git clone https://github.com/kflick3r/CSPB2270_Final_Flick.git`
   `cd CSPB2270_Final_Flick`
2. From the project root, compile the program
   `g++ main.cpp code/trie.cpp -Icode -o trie_app`
3. Run the Executable
   `./trie_app`

---

## Demo



