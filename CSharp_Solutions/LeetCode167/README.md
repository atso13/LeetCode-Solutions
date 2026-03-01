# 167. Two Sum II - Input Array Is Sorted

## Problem
Given a 1-indexed array of integers `numbers` that is already sorted in non-decreasing order, find two numbers such that they add up to a specific `target` number.

## Solution Approach
Used the **Two Pointers** technique:
- One pointer at the beginning (`left`) and one at the end (`right`).
- If the sum is too large, move the `right` pointer to the left.
- If the sum is too small, move the `left` pointer to the right.
- This ensures $O(n)$ time complexity and $O(1)$ space complexity.

## Complexity
- Time Complexity: $O(n)$
- Space Complexity: $O(1)$
