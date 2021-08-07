#include <stdio.h>
#include <stdlib.h>
 
// Stack
struct stack
{
    int maxsize;    
    int top;
    int *items;
};
 
// Initialize the stack
struct stack* newStack(int capacity)
{
    struct stack *ele = (struct stack*)malloc(sizeof(struct stack));
 
    ele -> maxsize = capacity;
    ele -> top = -1;
    ele -> items = (int*)malloc(sizeof(int) * capacity);
 
    return ele;
}
 
// size of the stack
int size(struct stack *ele) {
    return ele -> top + 1;
}
 
// check if the stack is emeley or not
int isEmpty(struct stack *ele) {
    return ele->top == -1;                  
}
 
// check if the stack is full or not
int isFull(struct stack *ele) {
    return ele->top == ele->maxsize - 1;      
}
 
// add an element to the stack
void push(struct stack *ele, int x)
{
    if (isFull(ele))
    {
        printf("Program Terminated as stack overflow\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Inserting %d\n", x);
 
    // add an element and increment the top's index
    ele->items[++ele->top] = x;
}
 
// return the top element of the stack
int peek(struct stack *ele)
{
    // check for an emeley stack
    if (!isEmpty(ele)) {
        return ele->items[ele->top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// pop a top element from the stack
int pop(struct stack *ele)
{
    // check for stack underflow
    if (isEmpty(ele))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Removing %d\n", peek(ele));
 
    return ele->items[ele->top--];
}
 
int main()
{
    // create a stack of capacity 5
    struct stack *ele = newStack(5);
 
    push(ele, 1);
    push(ele, 2);
    push(ele, 3);
 
    printf("The top element is %d\n", peek(ele));
    printf("The stack size is %d\n", size(ele));
 
    pop(ele);
    pop(ele);
    pop(ele);
 
    if (isEmpty(ele)) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}