#ifndef trie_h
#define trie_h

typedef struct TrieNode TrieNode;

TrieNode* new_TrieNode();
void insert (TrieNode* head, const char* str);
