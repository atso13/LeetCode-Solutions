# LeetCode 438: Find All Anagrams in a String 🚀

## 📝 Problem Summary
Given two strings `s` and `p`, find all the start indices of `p`'s anagrams in `s`. An anagram is a word formed by rearranging the letters of another word using all original letters exactly once.

---

## 💡 Solution Strategy
- **Pattern:** Fixed-Size Sliding Window with Frequency Histograms.
- **Approach:**
  1. Maintain two 26-element frequency arrays to track character counts for `p` and the current window in `s`.
  2. Slide a window of size `strlen(p)` across string `s`, updating character frequencies in $O(1)$ time by adding the incoming character and removing the outgoing one.
  3. Compare frequency histograms at each step to record matching start indices into a dynamically allocated array.

---

## ⏱️ Complexity
- **Time Complexity:** $O(\vert{}s\vert{})$ — Single-pass iteration over string `s`.
- **Space Complexity:** $O(1)$ — Uses fixed-size arrays of size 26 for alphabet character counts.