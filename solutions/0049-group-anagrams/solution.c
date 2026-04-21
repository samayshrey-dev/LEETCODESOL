#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char keys[strsSize][101];   // sorted keys
    char*** result = malloc(strsSize * sizeof(char**));
    int* colSizes = malloc(strsSize * sizeof(int));

    int groupCount = 0;

    for(int i = 0; i < strsSize; i++) {
        strcpy(keys[i], strs[i]);
        qsort(keys[i], strlen(keys[i]), sizeof(char), cmp);
    }

    int used[strsSize];
    memset(used, 0, sizeof(used));

    for(int i = 0; i < strsSize; i++) {
        if(used[i]) continue;

        result[groupCount] = malloc(strsSize * sizeof(char*));
        colSizes[groupCount] = 0;

        for(int j = i; j < strsSize; j++) {
            if(!used[j] && strcmp(keys[i], keys[j]) == 0) {
                result[groupCount][colSizes[groupCount]] = strs[j];
                colSizes[groupCount]++;
                used[j] = 1;
            }
        }

        groupCount++;
    }

    *returnSize = groupCount;
    *returnColumnSizes = colSizes;

    return result;
}
