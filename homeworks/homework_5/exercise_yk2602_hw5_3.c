#include <strings.h> // for the strcasecmp
#include <stdio.h>   // for the printing
#include <stdlib.h>  // for the malloc

struct cell
{
    char *key;
    struct cell *next;
};
// §3-1
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
            printf("string is in the list, congrats!\n");
            return 1;
        }
        cur_node = cur_node->next;
    }
    // returning false
    printf("STRING IS NOT FOUND :( \n");
    return 0;
}

struct cell *cons(char *string, struct cell *list)
{
    // intialize the pointer to the struct cell
    struct cell *new_cell;
    // allocate memory for the pointer to the struct cell
    new_cell = (struct cell *)malloc(sizeof(struct cell));
    // copy the string to the newly declared struct cell
    new_cell->key = strdup(string);
    // ensure that the pointer to the struct cell
    new_cell->next = list;
    // return the pointer to the newly added cell
    return new_cell;
}

void free_list(struct cell *list)
{
    struct cell *temp, *cur_node = list;
    // iterate through the array of strings
    while (cur_node != NULL)
    {
        temp = cur_node;
        cur_node = cur_node->next;
        if (temp->key != NULL)
        {
            free(temp->key);
        }
        free(temp);
    }
    printf("_____________________________\n");
    printf("the memory is deallocated now\n");
    return;
}
// §3-2
int main()
{
    char s[] = "Today";
    char s2[] = "Weather";
    char s3[] = "Beautiful";

    struct cell *test_list = NULL;

    test_list = cons(s, NULL);
    test_list = cons(s2, test_list);
    test_list = cons(s3, test_list);

    list_member("Cloudy", test_list);
    list_member("Beautiful", test_list);

    free_list(test_list);
}
