# LeetCode 2024: Maximize the Confusion of an Exam 🚀

## 📝 Problem Summary
Given a string `answerKey` consisting of 'T' and 'F', and an integer `k`, return the maximum number of consecutive 'T's or 'F's you can get by performing at most `k` operations (changing 'T' to 'F' or vice versa).

---

## 💡 Solution Strategy
- **Pattern:** Variable-Size Sliding Window.
- **Approach:**
  1. Maintain counters `tcnt` and `fcnt` for character frequencies in the current window `[left, right]`.
  2. The number of changes required to make all elements in the window identical is `(window_size) - max(tcnt, fcnt)`.
  3. If required changes exceed `k`, shrink the window from the left until it becomes valid again.
  4. Track the maximum valid window size reached.

---

## ⏱️ Complexity
- **Time Complexity:** $O(N)$ — Single pass over the string with two pointers.
- **Space Complexity:** $O(1)$ — Only integer counters used.