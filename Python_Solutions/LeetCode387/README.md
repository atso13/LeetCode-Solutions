# 387. First Unique Character in a String

## Problem Description
Given a string `s`, find the first non-repeating character in it and return its index. If it does not exist, return `-1`.

## Solution Approach
I used a **Hash Map (Dictionary)** to solve this problem efficiently in two passes:
1. **First Pass:** Iterate through the string to build a frequency map of all characters.
2. **Second Pass:** Iterate through the string again and check the frequency map. The first character with a count of `1` is our answer.

## Complexity Analysis
* **Time Complexity:** $O(n)$ – We traverse the string twice, where $n$ is the length of the string.
* **Space Complexity:** $O(1)$ – Although we use a Hash Map, the number of possible characters (lowercase English letters) is constant (26).