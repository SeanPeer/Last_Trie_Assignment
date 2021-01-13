#include "Trie.h"


extern int maxSize;

node *getNewTrieNode(char letter)// Create a new Trie node.
{
	node *n = (node *)malloc(sizeof(node));
	if (n != NULL)//if - creation Succeed
	{ 
		n->counter = 0;
		n->letter = letter;
		for (int i = 0; i < NUM_LETTERS; i++)// Initialize with NULL
			n->children[i] = NULL;
	}
	return n;
}


void insert(node *head, char *str)
{
	// start from root node
	node *curr = head;
	while (*str)
	{
		// create a new node if path doesn't exists
		if (curr->children[*str - 'a'] == NULL)
			curr->children[*str - 'a'] = getNewTrieNode(*str);

		// go to next node
		curr = curr->children[*str - 'a'];

		// move to next character
		str++;
	}

	// mark current node as leaf
	curr->counter++;
}
void printLexUp(node *head, char s[], int k)
{
	int i = 0;
	while (i < NUM_LETTERS)
	{ 

		if (head->children[i] != NULL)//if - there is a nieghbor
		{									  
			s[k] = head->children[i]->letter;//adding a letter to the array

			if (head->children[i]->counter > 0)//if - node has childrens then print the word
			{	
				s[k + 1] = 0;
				printf("%s", s);
				printf(" %ld\n", head->children[i]->counter);
			}
			//recursive call for the next nieghbor
			printLexUp(head->children[i], s, ++k);
			k--;
			i++;
			s[k + 1] = 0;
		}
		else
		{
			i++;
		}
	}
}
void printLexDown(node *head, char s[], int k)//printing up side down
{
	int i = NUM_LETTERS - 1;
	while (i >= 0)
	{ 
		if (head->children[i] != NULL)//if - there is a nieghbor
		{ 
			s[k] = head->children[i]->letter;//adding a letter to the array

			printLexDown(head->children[i], s, ++k); //recursive call for the next nieghbor
			if (head->children[i]->counter > 0)
			{
				s[k] = 0;
				printf("%s", s);
				printf(" %ld\n", head->children[i]->counter);
			}
			k--;
			i--;
			s[k] = 0;
		}
		else
		{
			i--;
		}
	}
}
void printTreeLexUp(node *head)
{

	if (head != NULL)
	{

		char *str = (char *)malloc(maxSize + 1);

		if (str != NULL)
		{
			printLexUp(head, str, 0);
			free(str);
		}
	}
	else
	{
		printf("The tree is empty");
		return;
	}
}
void printTreeLexDown(node *head)
{
	if (head != NULL)
	{
		char *str = (char *)malloc(maxSize + 1);

		if (str != NULL)
		{
			printLexDown(head, str, 0);
			free(str);
		}
	}
	else
	{
		printf("The tree is empty");
		return;
	}
}
Node *add(Node *head, char c)
{
	if (head == NULL)
	{
		head = (Node *)malloc(sizeof(Node));
		if (head != NULL)
		{
			head->c = c;
			head->next = NULL;
		}
		return head;
	}
	else
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		if (temp != NULL)
		{
			temp->c = c;
			temp->next = NULL;
			Node *help = head;
			while (help->next != NULL)
			{
				help = help->next;
			}
			help->next = temp;
		}
	}
	return head;
}

Node *freeList(Node *head)
{
	if (head != NULL)
	{ // if the list is not empty
		if (head->next != NULL)
		{ // if the list has more then 1 variable
			Node *temp = head->next;
			while (temp != NULL)
			{
				free(head);
				head = temp;
				temp = temp->next;
			}
		}
		// if the list has 1 variable
		free(head);
		head = NULL;
		return head;
	}

	else
	{
		head = NULL;
		return head;
	}
}

node *freeTree(node *root)
{
	int i = 25;
	while (i >= 0)
	{ // going over the children of the fist node from the last

		if (root->children[i] != NULL)
		{ // checking if the neighboor [i] exsits.

			freeTree(root->children[i]); // call the function again with the next neighboor
			if (root->children[i] != NULL)
			{
				free(root->children[i]);
			}
			i--;
		}
		else
		{
			i--;
		}
	}
	return root;
}

char *fromListToStr(Node *head, char *str, int count)
{
	str = (char *)malloc(count + 1);
	if (str != NULL)
	{
		Node *temp = head;
		while (temp != NULL)
		{
			*str = temp->c;
			str++;
			temp = temp->next;
		}
		*str = 0;
		str -= count;

		return str;
	}
	else
	{
		str = NULL;
		return str;
	}
}
