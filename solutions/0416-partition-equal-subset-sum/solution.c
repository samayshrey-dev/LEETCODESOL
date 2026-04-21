#include <stdio.h>

int canPartition(int* nums, int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];
    }

    if(sum % 2 != 0) return 0; // odd → impossible

    int target = sum / 2;

    int dp[target + 1];

    // initialize
    for(int i = 0; i <= target; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    // fill dp
    for(int i = 0; i < n; i++) {
        for(int j = target; j >= nums[i]; j--) {
            if(dp[j - nums[i]]) {
                dp[j] = 1;
            }
        }
    }

    return dp[target];
}
