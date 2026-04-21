#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void threeWayPartition(int nums[], int left, int right, int* low, int* high) {
    int pivot = nums[right];
    int i = left;
    int lt = left;
    int gt = right;

    while(i <= gt) {
        if(nums[i] < pivot) {
            swap(&nums[i++], &nums[lt++]);
        } else if(nums[i] > pivot) {
            swap(&nums[i], &nums[gt--]);
        } else {
            i++;
        }
    }

    *low = lt;
    *high = gt;
}

int quickSelect(int nums[], int left, int right, int k) {
    while(left <= right) {
        int low, high;

        // random pivot
        int pivotIndex = left + rand() % (right - left + 1);
        swap(&nums[pivotIndex], &nums[right]);

        threeWayPartition(nums, left, right, &low, &high);

        if(k < low) {
            right = low - 1;
        } else if(k > high) {
            left = high + 1;
        } else {
            return nums[k]; // inside equal region
        }
    }
    return -1;
}

int findKthLargest(int nums[], int n, int k) {
    srand(time(NULL));
    return quickSelect(nums, 0, n - 1, n - k);
}
