# CSPB2270_Final_Flick
Final for CSPB 2270 (Spring 2026) - Trie Tree Algorithm

This Trie is built on a real-world dataset of hundreds of occupations from O*NET, demonstrating scalability and efficient prefix-based search.

---

## Project Proposal: Trie Tree

#### Goal: 
Simulate career autocomplete in C++ as a standalone project, inspired by a previously built python web application, to explore Trie data structures.

#### Motivation: 
In another class, my group created a website where users select a career, rank skills related to that career, and receive a skill compatibility analysis. Currently, the career selection uses a dropdown menu, but the list of careers (pulled from the O*NET database) is quite long and cumbersome. 

Inspired by this, I want to replace the dropdown with a Trie to enable a fast and responsive autocomplete, improving user experience. Tries are widely used in search engines with predictive text because they store words efficiently for prefix-based queries. 

While this project is in C++, not Python, the C++ implementation will model the same functionality, allowing exploration of this data structure concept, pointer management, and algorithmic efficiency for a future project. 

---
                                                                                                                                                                                                       
## What is a Trie?
A Trie stores words as paths in a tree where each node represents a character. Each word is marked with nodes at the end of the path flagged “end of word”.

#### Key Properties:
- Each node can have multiple children
- Search/insertion of word length m takes O(m) time
- Prefix searches are efficient: words sharing a prefix share the same path
	
#### Operations:
- Insert(word): Adds characters as nodes
- Search(word): Check if a word exists
- Autocomplete(prefix): Return words starting with the prefix

#### Trie Diagram Examples:
- Typing “an” suggests: “and”, “ant”
- Typing “d” suggests: “do”, “dad”

---

## Project Plan:
- Implement a C++ Trie with insertion, search, and prefix autocomplete
- Populate the Trie with example career names for demonstration
- Demo: Simulate typing a prefix and showing career suggestions

#### Deliverables:
- C++ code repo with clear documentation, and explanation of design decisions and challenges
- Demo showing insertion, search, and autocomplete
