# LeetCode 19: Remove Nth Node From End of List

## 📝 Description
Given the `head` of a linked list, remove the $n^{th}$ node from the end of the list and return its head.

**Constraints:**
* The number of nodes in the list is `sz`.
* $1 \leq sz \leq 30$
* $0 \leq Node.val \leq 100$
* $1 \leq n \leq sz$

---

## 💡 Solution: Two-Pointer Technique (One Pass)
The most efficient way to solve this problem is by using two pointers to maintain a constant "gap" of $n$ nodes between them. This allows us to find the target node in a single traversal ($O(n)$).

### The Logic:
1.  **Initialize:** Both `temp` (fast) and `renode` (slow) pointers start at the `head`.
2.  **Create the Gap:** Move the `temp` pointer $n$ steps forward.
3.  **Handle Edge Case:** If `temp` is `null` after the move, it means we need to remove the **first node** (the head). In this case, we simply return `head.GetNext()`.
4.  **Sync Movement:** Move both pointers forward until `temp` reaches the last node (`temp.GetNext() == null`).
5.  **Delete Node:** Now, `renode` is standing exactly **one node before** the one we want to remove. We skip the target node by updating the reference: `renode.SetNext(renode.GetNext().GetNext())`.

---

## 🛠️ Implementation (C#)

