#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int last[256]; // ASCII
    for(int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    int left = 0;
    int maxLen = 0;

    for(int right = 0; s[right] != '\0'; right++) {
        char c = s[right];

        // if duplicate found inside window
        if(last[c] >= left) {
            left = last[c] + 1;
        }

        last[c] = right;

        int len = right - left + 1;
        if(len > maxLen) {
            maxLen = len;
        }
    }

    return maxLen;
}
