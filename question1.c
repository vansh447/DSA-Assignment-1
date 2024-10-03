#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    return (ptr->top == -1);
}

int isFull(struct stack *ptr)
{
    return (ptr->top == ptr->size - 1);
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (!s)
    {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
 }
    
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (!s->arr)
    {
        printf("Memory allocation for stack array failed. Exiting.\n");
        free(s);  // Clean up the previously allocated memory
        return 1;
    }
    
    // Now you can use your stack!
    // Don't forget to free the memory when you're done.
    
    free(s->arr);
    free(s);
    return 0;
}