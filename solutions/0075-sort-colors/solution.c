#include <stdio.h>

void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            // swap nums[mid] and nums[low]
            int temp = nums[mid];
            nums[mid] = nums[low];
            nums[low] = temp;

            low++;
            mid++;
        }
        else if(nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            // swap nums[mid] and nums[high]
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;

            high--;
        }
    }
}
