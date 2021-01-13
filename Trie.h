#include <stdio.h>
#include <stdlib.h>

#define NUM_LETTERS ((int)26) 
typedef struct node { //Struct for Trie
	char letter;
	long unsigned int counter; 
	struct node* children[NUM_LETTERS];
} node;

typedef struct Node { //Struct for Linkedlist
	char c;
	struct Node* next;
}Node;

Node* add(Node* head, char c);
void insert(node* root, char* str);
node* getNewTrieNode(char letter);
void printLexUp(node* head,char s [] ,int k);
void printLexDown(node* head, char s[], int k);
void printTreeLexUp(node* head);
void printTreeLexDown(node* head);
Node* freeList(Node*);
node* freeTree(node* root);
char* fromListToStr(Node* head, char* str, int count);

