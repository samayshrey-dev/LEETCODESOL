#include <stdio.h>

int findPeakElement(int nums[], int n) {
    int left = 0, right = n - 1;

    while(left < right) {
        int mid = left + (right - left) / 2;

        if(nums[mid] > nums[mid + 1]) {
            right = mid; // peak on left side
        } else {
            left = mid + 1; // peak on right side
        }
    }

    return left; // or right (both same)
}
