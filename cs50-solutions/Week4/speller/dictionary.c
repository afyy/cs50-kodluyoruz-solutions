// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node=malloc(sizeof(node));
        if(new_node==NULL)
        {
        	unload();
        	return false;
		}
		strcpy(new_node->word,word);
		new_node->next=hashtable[hash(word)];
		hashtable[hash(word)]=new_node;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}
int number=0;
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
	node *cursor=NULL;
    for(int i=0; i<N; i++)
    {
    	cursor=hashtable[i];
    	while(cursor!=NULL)
    	{
    		number++;
    		cursor=cursor->next;
		}
	}
	return number;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor=hashtable[hash(word)];
    while(cursor!=NULL)
    {
    	if(strcasecmp(cursor->word,word)==0)
    		return true;
    	cursor=cursor->next;
	}
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
	node *cursor=NULL;
	for(int i=0; i<N; i++)
	{
    	cursor=hashtable[i];
    	while(cursor!=NULL)
    	{
    		node *temp=cursor;
    		cursor=cursor->next;
    		free(temp);
		}
		if(i==25 && cursor==NULL)
            return true;
	}
	return false;
}