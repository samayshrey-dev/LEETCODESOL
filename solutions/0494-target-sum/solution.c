#include <stdio.h>
#include <stdlib.h> // for abs()

int findTargetSumWays(int* nums, int n, int target) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];
    }

    // 🔥 FIXED CONDITION
    if(abs(target) > sum || (sum + target) % 2 != 0) {
        return 0;
    }

    int P = (sum + target) / 2;

    int dp[P + 1];

    for(int i = 0; i <= P; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = P; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[P];
}
