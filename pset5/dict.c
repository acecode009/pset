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
#define ALPHABET 27
#define CHAR(c) ((int)c - 97)
int count = 0;
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    node* current = root;
    char index;
    int len = strlen(word);
    for(int i=0; i<len; i++)
    {
        index = tolower(word[i]);
        if(index == '\'')
        {
            index = 123;
        }
        struct node* temp = current->children[CHAR(index - 97)];
        if(temp == NULL)
            return false;
        else
            current = temp;
    }
    if(current->is_word)
        return true;
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE* fp = fopen(dictionary, "r");
    if(!fp)
    {
        printf("Error loading %s\n",dictionary);
        return false;
    }
    root = calloc(1,sizeof(node));
    node* current =NULL;
    //char ch;
    for(char ch = tolower(fgetc(fp)); ch != EOF; ch = fgetc(fp))
    {
         
        if(ch == '\n')
        {
            if(current !=root)
            {
                current->is_word = true;
                count++;
            
            //set current to root
                current = root;
            }
        }
        else{
           
            if(ch == '\'')
            {
                    ch = 123;
            }
            struct node* temp = current->children[ch-97];
            if(temp == NULL)
            {
                // allocate memory for each letter
                current->children[CHAR(ch)] = calloc(1,sizeof(node));
                current = current->children[CHAR(ch)];
            }
            else
            {
                current = temp;
            }
        }
        
        /*if(current !=root && !current->is_word)
        {
            current->is_word = true;
            count++;
        }*/
    }
    
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
void freeNode(node* current)
{
    int i;
    for(i=0; i<ALPHABET; i++)
    {
        if(current->children[i] == NULL)
            freeNode(current->children[i]);
    }
    free(current);
}
bool unload(void)
{
    // TODO
    freeNode(root);
    return true;
}
