#include <stdlib.h>

#define SIZE 10000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

int hash(int key) {
    return abs(key) % SIZE;
}

void insert(Node* table[], int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[idx];
    table[idx] = newNode;
}

int search(Node* table[], int key) {
    int idx = hash(key);
    Node* temp = table[idx];
    while (temp) {
        if (temp->key == key) return temp->value;
        temp = temp->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[SIZE] = {0};
    int* res = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int comp = target - nums[i];
        int found = search(table, comp);

        if (found != -1) {
            res[0] = found;
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        insert(table, nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}
