#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int j = 0; // position for next non-zero

    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            // swap nums[i] and nums[j]
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            j++;
        }
    }
}
