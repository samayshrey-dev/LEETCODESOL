#include <stdio.h>

int canJump(int nums[], int n) {
    int maxReach = 0;

    for(int i = 0; i < n; i++) {
        if(i > maxReach) {
            return 0; // false
        }

        if(i + nums[i] > maxReach) {
            maxReach = i + nums[i];
        }
    }

    return 1; // true
}
