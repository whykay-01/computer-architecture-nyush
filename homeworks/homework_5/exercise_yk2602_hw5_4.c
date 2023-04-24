#include <stdio.h>  // for the printing
#include <stdlib.h> // for the malloc
#include <string.h> // for the strdup
#include <fcntl.h>  // for the open
#include <unistd.h> // for the close

struct cell
{
    char *key;
    struct cell *next;
};

// §4-1
struct cell *read_words(char *filename)
{
    // open the file
    FILE *fp = fopen(filename, "r");
    // check if the file is opened
    if (fp == NULL)
    {
        printf("There is an error in opening the file: '%s\n'", filename);
        return NULL;
    }
    // initialize the head of the list
    struct cell *head = NULL;
    char line[BUFSIZ];
    // read the file line by line
    while (fgets(line, BUFSIZ, fp) != NULL)
    {
        // declare the new node
        struct cell *new_node = malloc(sizeof(struct cell));
        // copy the string to the newly declared struct cell
        new_node->key = strdup(line);
        // ensure that the pointer to the struct cell
        new_node->next = head;
        // return the pointer to the newly added cell
        head = new_node;
    }
    // close the file
    fclose(fp);
    // return the head of the list
    return head;
}

int list_length(struct cell *list)
{
    int length = 0;
    if (list == NULL)
    {
        printf("The list is empty!\n");
        exit(1); // it is same with exit(EXIT_FAILURE)
    }
    struct cell *cur_node = list;
    while (cur_node != NULL)
    {
        length++;
        cur_node = cur_node->next;
    }

    return length;
}

int list_member(char *string, struct cell *list)
{
    struct cell *cur_node = list;

    // going through the list
    while (cur_node != NULL)
    {
        char *str = cur_node->key;
        // checking whether the strings are identical
        if (strcasecmp(str, string) == 0)
        {
            // returning true
            return 1;
        }

        cur_node = cur_node->next;
    }
    // returning false
    return 0;
}

void free_list(struct cell *list)
{
    struct cell *cur_node = list;
    struct cell *prev_node = NULL;
    while (cur_node != NULL)
    {
        prev_node = cur_node;
        cur_node = cur_node->next;
        free(prev_node->key);
        free(prev_node);
    }
    return;
}

// §4-3
// I decided to use two previous functions in this function
// also, the desired word would be passed as a parameter of the function
int spellchecker(void)
{
    struct cell *list = read_words("/usr/share/dict/words");

    // Read input from user
    char buffer[BUFSIZ];

    // Process each word in the input
    char *word = strtok(buffer, " \t\n");
    while (word != NULL)
    {
        // Check if the word is in the dictionary
        int result = list_member(word, list);
        if (result)
        {
            printf("%s is in the dictionary.\n", word);
        }
        else
        {
            printf("%s is not in the dictionary.\n", word);
        }

        // Move to the next word
        word = strtok(NULL, " \t\n");
    }

    // Free the linked list
    free_list(list);

    return 0;
}

// §4-2
int main()
{
    struct cell *list = read_words("/usr/share/dict/words");
    printf("The length of the list is: %d\n", list_length(list));
    spellchecker();
    free(list);
    return 0;
}
