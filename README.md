# CSPB2270_Final_Flick
## Final Project: Trie Tree Algorithm

**Author:** Kassidy Flick  
**Course:** CSPB 2270 - Data Structures  
**Semester:** Spring 2026  

---

## Project Overview
This project implements a Trie in C++ to simulate an autocomplete search system for career titles. It is built on a real-world dataset of hundreds of occupations from O*NET, demonstrating scalability and efficient prefix-based search.

The system allows users to:
- Insert Career Titles Manually (in addition to the O*NET data)
- Search for exact matches
- Retrieve autocomplete suggestions based on user input prefix

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
2. Each career title is inserted into the Trie 
3. The Trie struct stores
   - Child Character Mapping
   - A Boolean flag marking the end of the word
   - The original career string to display
4. Internally, input is converted to lowercase for consistent traversal
5. DFS traverses subtree to collect all matches
6. Users can insert their own career titles, search for exact matches, or search with autocomplete
   - Autocomplete is limited to 10 results

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

When the program runs, it loads career titles from `careers.txt` into the Trie.

#### Example interaction:

```text
=== Career Autocomplete Demo ===

~Search for a Career from the O*NET Dataset~ 
 
*Limited to first 10 results*

Hit Enter to Search or 'exit' to quit:
do

Suggestions:
 - Document Management Specialists
 - Door-to-Door Sales Workers, News and Street Vendors, and Related Workers

Hit Enter to Search or 'exit' to quit:
e

Suggestions:
 - Earth Drillers, Except Oil and Gas
 - Economics Teachers, Postsecondary
 - Economists
 - Editors
 - Education Administrators, All Other
 - Education Administrators, Kindergarten through Secondary
 - Education Administrators, Postsecondary
 - Education and Childcare Administrators, Preschool and Daycare
 - Education Teachers, Postsecondary
 - Educational Instruction and Library Workers, All Other

Hit Enter to Search or 'exit' to quit:
computer s

Suggestions:
 - Computer Science Teachers, Postsecondary
 - Computer Systems Analysts
 - Computer Systems Engineers/Architects

Hit Enter to Search or 'exit' to quit:
tea

Suggestions:
 - Teachers and Instructors, All Other
 - Teaching Assistants, All Other
 - Teaching Assistants, Postsecondary
 - Teaching Assistants, Preschool, Elementary, Middle, and Secondary School, Except Special Education
 - Teaching Assistants, Special Education
 - Team Assemblers

Hit Enter to Search or 'exit' to quit:
exit
[63:~/2270_Comp_Sci_2/CSPB2270_Final_Flick]$ 
```
