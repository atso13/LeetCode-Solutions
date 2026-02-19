# 1456. Maximum Number of Vowels in a Substring of Given Length

## 📝 Description
Given a string `s` and an integer `k`, return the maximum number of vowel letters in any substring of `s` with length `k`.

## 💡 Approach: Sliding Window
Instead of recalculating the number of vowels for every possible substring (which would take $O(n \cdot k)$ time), I used the **Sliding Window** technique:
1. Count vowels in the first `k` characters.
2. Slide the window one character at a time to the right.
3. For each move, update the count by adding the new character and removing the old one.

## 🚀 Complexity Analysis
- **Time Complexity:** $O(n)$, where $n$ is the length of the string. We traverse the string only once.
- **Space Complexity:** $O(1)$, as we only use a few integer variables.

## 🛠️ Language Used
- C#
