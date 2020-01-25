#include "trie.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int n, char* arr[]){
	bool b = false;
	if (n==2 && strcmp(arr[1], "r")==0)
		b = true;
	char s [50];
	TrieNode* head = new_TrieNode();
	if(stdin){
		while(fscanf(stdin, "%49s", s) == 1)
			insert (head,s);
		fclose(stdin);
	}
	s[0] = '\0';
	print (head, s, sizeof(s), b);
	_delete (head);
	return 0;
}
