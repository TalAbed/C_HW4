#include "trie.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define letters (26)

typedef struct TrieNode {
	long unsigned int counter;
	struct TrieNode* children [letters];
} TrieNode;

TrieNode* new_TrieNode(){
	TrieNode* tn = (TrieNode*)malloc(sizeof(TrieNode));
	tn->counter = 0;
	for (int i=0; i<letters; i++)
		tn->children[i] = NULL;
	return tn;
}

bool isBigLetter (char c){
        if (c>='A' && c<='Z')
                return true;
        return false;
}

bool isSmallLetter (char c){
	if (c>= 'a' && c<= 'z')
		return true;
	return false;
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
		else if (!isSmallLetter(c)){
			c = *str;
			continue;
		}
		i = c - 'a';
		if (tn->children[i] == NULL)
			tn->children[i] = new_TrieNode();
		tn = tn->children[i];
		c = *str;
	}
	tn->counter++;
}

unsigned long int search (const TrieNode* head, const char* str){
	if (head == NULL || str == NULL)
		return 0;
	TrieNode const * tn = head;
	char c = *str;
	int i;
	while (*str++){
		if (isBigLetter(c))
			c = c - 'A' + 'a';
		else if(!isSmallLetter(c)){
			c = *str;
			continue;
		}
		i = c - 'a';
		if (tn->children[i] == NULL)
			return 0;
		tn = tn->children[i];
		c = *str;
	}
	return tn->counter;
}

void _delete (TrieNode* n){
	if (n==NULL)
		return;
	for (int i=0; i<letters; i++)
		_delete(n->children[i]);
	free(n);
}

void print (TrieNode* head, char pre[], int preBSize, bool b){
	if (head==NULL || pre==NULL)
		return;
	if (!b){
		if(head->counter >0)
			printf("%s\t%ld\n", pre, head->counter);
	}
	int preL = strlen(pre);
	if (preL<preBSize-1){
		int LI;
		for (int i=0; i<letters; i++){
			if(b)
				LI = letters-i-1;
			else
				LI = i;
			pre[preL] = 'a' + LI;
			pre[preL+1] = '\0';
			print (head->children[LI], pre, preBSize, b);
		}
		pre[preL] = '\0';
	}
	if(b){
		if (head->counter > 0)
			printf ("%s\t%ld\n", pre, head->counter);
	}
}

