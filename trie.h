#ifndef trie_h
#define trie_h
#include <stdbool.h>

typedef struct TrieNode TrieNode;

TrieNode* new_TrieNode();
void insert (TrieNode* head, const char* str);
unsigned long int  search (const TrieNode* head, const char* str);
void _delete (TrieNode* n);
void print (TrieNode* head, char pre[], int preSize, bool b);

#endif
