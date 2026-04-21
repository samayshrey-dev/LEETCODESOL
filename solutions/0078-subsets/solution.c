#include <stdio.h>
#include <stdlib.h>

int** result;
int* columnSizes;
int returnSize = 0;

// helper function
void backtrack(int* nums, int n, int start, int* temp, int tempSize) {
    // save current subset
    result = realloc(result, (returnSize + 1) * sizeof(int*));
    columnSizes = realloc(columnSizes, (returnSize + 1) * sizeof(int));

    result[returnSize] = malloc(tempSize * sizeof(int));
    for(int i = 0; i < tempSize; i++) {
        result[returnSize][i] = temp[i];
    }

    columnSizes[returnSize] = tempSize;
    returnSize++;

    // explore further
    for(int i = start; i < n; i++) {
        temp[tempSize] = nums[i];           // choose
        backtrack(nums, n, i + 1, temp, tempSize + 1);
        // no need to explicitly remove (overwrite next time)
    }
}

int** subsets(int* nums, int numsSize, int* returnSizeOut, int** returnColumnSizes) {
    result = NULL;
    columnSizes = NULL;
    returnSize = 0;

    int temp[numsSize];

    backtrack(nums, numsSize, 0, temp, 0);

    *returnSizeOut = returnSize;
    *returnColumnSizes = columnSizes;

    return result;
}
