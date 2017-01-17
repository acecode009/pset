/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

//number of word in dictionary
int word_count = 0;
/**
 * Returns true if word is in dictionary else false.
 */

//  function to free node
void freeNode(node* current);
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int length = strlen(word);

    // Points to current node as the program descends through the trie
    node* current = root;
    char ch;
    for (int i=0; i < length; i++)
    {
        ch = tolower(word[i]);

        // Check if character is apostrophe
        if (ch == '\'')
        {
            return false;
        }

        // Try to get the adress of the next node in the trie
        struct node* temp = current->children[CHAR(ch)];

        if (temp == NULL)
        {
            return false;
        }
        else
        {
            current = temp;
        }
    }

    // if word is present
    if (current->is_word)
    {
        return true;
    }

    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // Open the dictionary file
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Error loading %s\n",dictionary);
        return false;
    }

    // Allocate space for the first root node
    root = calloc(1, sizeof(node));

    // Points to current node as the program descends through the trie
    node* current = root;

    // Read the dictionary one character at a time
    for (char ch = tolower(fgetc(fp)); ch != EOF; ch = fgetc(fp))
    {
        // If end of word
        if (ch == '\n')
        {
            
            if (current != root)
            {
                word_count++;

                current->is_word = true;

                // Reset 
                current = root;                
            }
        }
        
        else
        {
            // Check if character is apostrophe
            if (ch == '\'')
            {
                ch = 123;
            }

            // next node
            struct node* temp = current->children[CHAR(ch)];
            if (temp == NULL)
            {
                // Allocate space for new node
                current->children[CHAR(ch)] = calloc(1, sizeof(node));

                current = current->children[CHAR(ch)];
            }
            else
            {
                current = temp;
            }
            
        }
    }

    fclose(fp);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_count;
}

//  function to free node
void freeNode(node* current)
{
    int i;
    for(i=0; i<ALPHABET; i++)
    {
        if(current->children[i] != NULL)
            freeNode(current->children[i]);
    }
    free(current);
}
/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    freeNode(root);
    return true;
}


