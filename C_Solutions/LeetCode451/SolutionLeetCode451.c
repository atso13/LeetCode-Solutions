#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * LeetCode 451: Sort Characters By Frequency
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary space (128 ASCII array)
 */
char* frequencySort(char* s) {
    int hist[128] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        hist[(unsigned char)s[i]]++;
    }
   
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    if (res == NULL) return NULL;

    int write_index = 0;

    for (int i = len; i > 0; i--) {
        for (int j = 0; j < 128; j++) {
            if (hist[j] == i) {
                while (hist[j] > 0) {
                    res[write_index++] = (char)j;
                    hist[j]--;
                }
            }
        }
    }

    res[len] = '\0';
    return res;
}