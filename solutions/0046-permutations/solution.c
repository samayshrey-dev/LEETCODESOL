#include <stdio.h>
#include <stdlib.h>

int** result;
int returnSize = 0;

// swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// backtracking
void backtrack(int* nums, int numsSize, int start) {
    if(start == numsSize) {
        result = realloc(result, (returnSize + 1) * sizeof(int*));
        result[returnSize] = malloc(numsSize * sizeof(int));

        for(int i = 0; i < numsSize; i++) {
            result[returnSize][i] = nums[i];
        }

        returnSize++;
        return;
    }

    for(int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);       // choose
        backtrack(nums, numsSize, start + 1);
        swap(&nums[start], &nums[i]);       // backtrack
    }
}

int** permute(int* nums, int numsSize, int* returnSizeOut, int** returnColumnSizes) {
    result = NULL;
    returnSize = 0;

    backtrack(nums, numsSize, 0);

    *returnSizeOut = returnSize;

    *returnColumnSizes = malloc(returnSize * sizeof(int));
    for(int i = 0; i < returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    return result;
}
