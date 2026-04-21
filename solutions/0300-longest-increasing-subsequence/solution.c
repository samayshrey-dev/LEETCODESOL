#include <stdio.h>

int lengthOfLIS(int* nums, int n) {
    int dp[n];
    int maxLen = 1;

    for(int i = 0; i < n; i++) {
        dp[i] = 1;

        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }

        if(dp[i] > maxLen) {
            maxLen = dp[i];
        }
    }

    return maxLen;
}
