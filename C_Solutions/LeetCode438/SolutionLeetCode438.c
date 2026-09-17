/*
 * LeetCode 438: Find All Anagrams in a String
 * 
 * Strategy: Sliding Window with Frequency Histograms
 * Time Complexity:  O(|s|)
 * Space Complexity: O(1) auxiliary space (excluding output array)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LETTERS 26

int* findAnagrams(char* s, char* p, int* returnSize);
bool hist_cmp(int hist_s[], int hist_p[]);

int main(void) {
    char* s = "abab";
    char* p = "ab";
    int size = 0;
    int* returnSize = &size;
    int* arr = findAnagrams(s, p, returnSize);

    for (int i = 0; i < *returnSize; i++) {
        printf("%d\n", arr[i]);
    }

    free(arr);
    return 0;
}

bool hist_cmp(int hist_s[], int hist_p[]) {
    for (int i = 0; i < LETTERS; i++) {
        if (hist_s[i] != hist_p[i]) {
            return false;
        }
    }
    return true;
}

int* findAnagrams(char* s, char* p, int* returnSize) {
    int hist_s[LETTERS] = {0};
    int hist_p[LETTERS] = {0};
    int anagrams_cnt = 0;
    int len_s = strlen(s);
    int len_p = strlen(p);

    if (len_s < len_p) {
        *returnSize = 0;
        return NULL;
    }

  
    for (int i = 0; i < len_p; i++) {
        hist_p[p[i] - 'a']++;
        hist_s[s[i] - 'a']++;
    }

    if (hist_cmp(hist_s, hist_p)) {
        anagrams_cnt++;
    }

   
    for (int i = len_p; i < len_s; i++) {
        hist_s[s[i] - 'a']++;
        hist_s[s[i - len_p] - 'a']--;
        if (hist_cmp(hist_s, hist_p)) {
            anagrams_cnt++;
        }
    }

    *returnSize = anagrams_cnt;
    int* index_arr = (int*)malloc(sizeof(int) * anagrams_cnt);
    if (index_arr == NULL) {
        return NULL;
    }

  
    for (int i = 0; i < LETTERS; i++) {
        hist_s[i] = 0;
    }
    for (int i = 0; i < len_p; i++) {
        hist_s[s[i] - 'a']++;
    }

    int curr_ind = 0;
    if (hist_cmp(hist_s, hist_p)) {
        index_arr[curr_ind++] = 0;
    }

    for (int i = len_p; i < len_s; i++) {
        hist_s[s[i] - 'a']++;
        hist_s[s[i - len_p] - 'a']--;
        if (hist_cmp(hist_s, hist_p)) {
            index_arr[curr_ind++] = i - len_p + 1;
        }
    }

    return index_arr;
}