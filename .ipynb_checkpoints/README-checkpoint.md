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
=== Career Trie Data Structure ===

----------------------
         MENU         
----------------------
1. Insert a Career
2. Search for an Exact Career
3. Use an Autocomplete Search for a Career
4. Exit

Choose an Option: 
2

Search for an Exact Career Name: 
teacher

teacher was not found.

----------------------
         MENU         
----------------------
1. Insert a Career
2. Search for an Exact Career
3. Use an Autocomplete Search for a Career
4. Exit

Choose an Option: 
2

Search for an Exact Career Name: 
Teacher

Teacher was not found.

----------------------
         MENU         
----------------------
1. Insert a Career
2. Search for an Exact Career
3. Use an Autocomplete Search for a Career
4. Exit

Choose an Option: 
4

Thank You! Goodbye!
 
[70:~/2270_Comp_Sci_2/CSPB2270_Final_Flick]$ g++ main.cpp code/trie.cpp -Icode -o trie_app && ./trie_app

=== Career Trie Data Structure ===

----------------------
         MENU         
----------------------
1. Insert a Career
2. Search for an Exact Career
3. Use an Autocomplete Search for a Career
4. Exit

Choose an Option: 
2

Search for an Exact Career Name: 
Teacher

Teacher was not found.

----------------------
         MENU         
----------------------
1. Insert a Career
2. Search for an Exact Career
3. Use an Autocomplete Search for a Career
4. Exit

Choose an Option: 
1

Type a Career to be Inserted Into the Trie: 
Teacher

Successfully Inserted Teacher into the Trie Tree.

----------------------
         MENU         
----------------------
1. Insert a Career
2. Search for an Exact Career
3. Use an Autocomplete Search for a Career
4. Exit

Choose an Option: 
2

Search for an Exact Career Name: 
Teacher

Teacher was found in the current Trie Tree.

----------------------
         MENU         
----------------------
1. Insert a Career
2. Search for an Exact Career
3. Use an Autocomplete Search for a Career
4. Exit

Choose an Option: 
3

~Search for a Career from the O*NET Dataset~ 
 
*Limited to first 10 results*

Hit Enter to Search or 'exit' to Return to the Menu:
doc

Found Suggestions:
 - Document Management Specialists

Hit Enter to Search or 'exit' to Return to the Menu:
en

Found Suggestions:
 - Endoscopy Technicians
 - Energy Auditors
 - Energy Engineers, Except Wind and Solar
 - Engine and Other Machine Assemblers
 - Engineering Teachers, Postsecondary
 - Engineering Technologists and Technicians, Except Drafters, All Other
 - Engineers, All Other
 - English Language and Literature Teachers, Postsecondary
 - Entertainers and Performers, Sports and Related Workers, All Other
 - Entertainment and Recreation Managers, Except Gambling

Hit Enter to Search or 'exit' to Return to the Menu:
Computer S

Found Suggestions:
 - Computer Science Teachers, Postsecondary
 - Computer Systems Analysts
 - Computer Systems Engineers/Architects

Hit Enter to Search or 'exit' to Return to the Menu:
 

No matches found.

Hit Enter to Search or 'exit' to Return to the Menu:
tu im

No matches found.

Hit Enter to Search or 'exit' to Return to the Menu:

Empty Input. Please type a prefix.

Hit Enter to Search or 'exit' to Return to the Menu:
s

Found Suggestions:
 - Sailors and Marine Oilers
 - Sales and Related Workers, All Other
 - Sales Engineers
 - Sales Managers
 - Sales Representatives of Services, Except Advertising, Insurance, Financial Services, and Travel
 - Sales Representatives, Wholesale and Manufacturing, Except Technical and Scientific Products
 - Sales Representatives, Wholesale and Manufacturing, Technical and Scientific Products
 - Sawing Machine Setters, Operators, and Tenders, Wood
 - School Bus Monitors
 - School Psychologists

Hit Enter to Search or 'exit' to Return to the Menu:
exit

----------------------
         MENU         
----------------------
1. Insert a Career
2. Search for an Exact Career
3. Use an Autocomplete Search for a Career
4. Exit

Choose an Option: 
4

Thank You! Goodbye!
 
[71:~/2270_Comp_Sci_2/CSPB2270_Final_Flick]$ 
```
