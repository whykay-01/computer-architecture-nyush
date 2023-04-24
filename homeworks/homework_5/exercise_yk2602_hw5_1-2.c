#include <stdio.h>  // for the printing
#include <string.h> // for the strdup
#include <stdlib.h> // for the malloc

struct cell // the new structure
{
    char *key;
    struct cell *next;
};

// §1-1
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

// §1-2
void print_list(struct cell *list)
{
    if (list == NULL)
    {
        printf("the list is NULL\n");
    }
    struct cell *cur_node = list;
    int i;
    // iterate through the array of strings
    while (cur_node != NULL)
    {
        i = 0;
        // instantiate the array of chars
        char *arr = cur_node->key;
        // iterate through the array of chars
        while (arr[i] != '\0')
        {
            printf("%c", arr[i]);
            i++;
        }
        // make sure that we move to the next string
        cur_node = cur_node->next;
        printf("\n");
    }
    return;
}

// §1-3
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

// §2-2
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
    printf("the memory is deallocated now\n");
    return;
}

// §2-1
int main()
{
    char s[] = "Today";
    char s2[] = "Weather";
    char s3[] = "Beautiful";
    char s4[13] = {'P', 'r', 'i', 'n', 't', ' ', 'w', 'o', 'r', 'k', 's', '!', '\0'};

    struct cell *test_list = NULL;

    test_list = cons(s, NULL);
    test_list = cons(s2, test_list);
    test_list = cons(s3, test_list);

    printf("The address for the first array is: %p\n", (void *)s3);
    printf("The length of the list is: %d\n", list_length(test_list));
    print_list(test_list);
    printf("________________________________________________\n");
    test_list = cons(s4, test_list);
    printf("The address for the second array is: %p\n", (void *)s4);
    printf("The length of the list is: %d\n", list_length(test_list));
    print_list(test_list);
    printf("________________________________________________\n");

    // §2-3
    free_list(test_list);

    return 0;
}