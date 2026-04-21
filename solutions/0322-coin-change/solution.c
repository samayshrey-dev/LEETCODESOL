#include <stdio.h>
#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];

    // initialize
    for(int i = 0; i <= amount; i++) {
        dp[i] = amount + 1; // large value (infinity)
    }

    dp[0] = 0;

    // fill dp
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coinsSize; j++) {
            if(coins[j] <= i) {
                int sub = dp[i - coins[j]] + 1;
                if(sub < dp[i]) {
                    dp[i] = sub;
                }
            }
        }
    }

    return (dp[amount] > amount) ? -1 : dp[amount];
}
