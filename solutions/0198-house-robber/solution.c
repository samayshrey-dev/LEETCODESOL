#include <stdio.h>

int rob(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    if(numsSize == 1) return nums[0];

    int prev2 = 0;        // dp[i-2]
    int prev1 = 0;        // dp[i-1]

    for(int i = 0; i < numsSize; i++) {
        int pick = nums[i] + prev2;
        int notPick = prev1;

        int curr = (pick > notPick) ? pick : notPick;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
