#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int containsDuplicate(int nums[], int n) {
    qsort(nums, n, sizeof(int), compare);

    for(int i = 1; i < n; i++) {
        if(nums[i] == nums[i - 1]) {
            return 1; // true
        }
    }

    return 0; // false
}
