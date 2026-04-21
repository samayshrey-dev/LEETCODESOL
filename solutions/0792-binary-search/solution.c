#include <stdio.h>

int search(int nums[], int n, int target) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2; // avoids overflow

        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // not found
}
