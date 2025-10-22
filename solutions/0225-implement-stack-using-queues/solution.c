#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack structure
typedef struct {
    int* data;      // Array to store stack elements
    int top;        // Index of top element
    int capacity;   // Maximum size of stack
} MyStack;

// Create a new stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->capacity = 1000; // Default size (can adjust as needed)
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

// Push an element onto the stack
void myStackPush(MyStack* obj, int x) {
    if (obj->top == obj->capacity - 1) {
        // Resize if full
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
    }
    obj->data[++(obj->top)] = x;
}

// Pop (remove and return) the top element
int myStackPop(MyStack* obj) {
    if (obj->top == -1)
        return -1;  // or handle underflow as needed
    return obj->data[(obj->top)--];
}

// Return the top element without removing it
int myStackTop(MyStack* obj) {
    if (obj->top == -1)
        return -1;
    return obj->data[obj->top];
}

// Check if the stack is empty
bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

// Free the memory used by the stack
void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Example usage:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, 10);
 * myStackPush(obj, 20);
 * int top = myStackTop(obj);   // returns 20
 * int val = myStackPop(obj);   // returns 20
 * bool empty = myStackEmpty(obj); // false
 * myStackFree(obj);
 */

