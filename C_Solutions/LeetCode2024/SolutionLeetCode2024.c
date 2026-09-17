/*
 * LeetCode 2024: Maximize the Confusion of an Exam
 * 
 * Strategy: Variable Sliding Window with Frequency Tracking
 * Time Complexity:  O(N)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxConsecutiveAnswers(char* answerKey, int k) {
    int left = 0;
    int tcnt = 0;
    int fcnt = 0;
    int maxq = 0;
    int len = strlen(answerKey);

    for (int right = 0; right < len; right++) {
        if (answerKey[right] == 'T') {
            tcnt++;
        } else {
            fcnt++;
        }

        // Shrink window if operations needed exceed k
        while ((right - left + 1) - max(tcnt, fcnt) > k) {
            if (answerKey[left] == 'T') {
                tcnt--;
            } else {
                fcnt--;
            }
            left++;
        }

        if (maxq < right - left + 1) {
            maxq = right - left + 1;
        }
    }

    return maxq;
}

int main(void) {
    char answerKey[] = "TTFTTFTT";
    int k = 1;

    int result = maxConsecutiveAnswers(answerKey, k);
    printf("Max consecutive answers: %d\n", result); // Expected output: 5

    return 0;
}