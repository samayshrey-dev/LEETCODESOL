#include <stdlib.h>
#include <string.h>

int encode(char c) {
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    return 3; // T
}

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = 0;

    if(n < 10) return NULL;

    int seen[1 << 20] = {0};   // 2^20 possible hashes
    int added[1 << 20] = {0};

    char** result = malloc(n * sizeof(char*));

    int hash = 0;

    // first 9 chars
    for(int i = 0; i < 9; i++) {
        hash = (hash << 2) | encode(s[i]);
    }

    for(int i = 9; i < n; i++) {
        hash = ((hash << 2) | encode(s[i])) & ((1 << 20) - 1);

        if(seen[hash] && !added[hash]) {
            char* temp = malloc(11);
            strncpy(temp, s + i - 9, 10);
            temp[10] = '\0';

            result[*returnSize] = temp;
            (*returnSize)++;
            added[hash] = 1;
        }

        seen[hash] = 1;
    }

    return result;
}
