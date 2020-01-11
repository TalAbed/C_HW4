#include "trie.h"
#include <stdio.h>
#include <stdbool.h>

#define letters (26)

typdef struct TrieNode {
	long unsinged int counter;
	struct TrieNode* children [letters];
} TrieNode;

TrieNode* new_TrieNode(){
	TrieNode* tn = (TrieNode*)malloc(sizeof(TrieNode));
	tn->counter = 0;
	for (int i=0; i<letters; i++)
		tn->children[i] = NULL;
	return tn;
}

void insert (TrieNode* head, const char* str){
	if (head == NULL || str == NULL)
		return;
	TrieNode* tn = head;
	char c = *str;
	int i;
	while (*str++){
		if (isBigLetter(c))
			c = c - 'A' + 'a';
		i = c - 'a';
		if (tn->children[i] == NULL)
			tn->children[i] = new_TrieNode();
		tn = tn->children[i];
		c = *str;
	}
	tn->counter++;
}

bool isBigLetter (char c){
	if (c>='A' && c<='Z')
		return true;
	return false;
}
