# LeetCode 2064: Minimized Maximum of Products to Any Store

## 📝 Problem Description

You are given an integer `n` representing the number of stores, and an integer array `quantities` of size `m`, where `quantities[i]` represents the number of products of the $i^{th}$ type.

You need to distribute **all products** to the stores according to the following rules:
1. A store can only be given **at most one type** of product.
2. A store can be given **any amount** of products of that type (including `0`).
3. All products must be distributed.

After distributing all products, let $x$ be the maximum number of products given to any store. Your goal is to **minimize** $x$.

Return the *minimum possible value* of $x$.

---

## 💡 Method: Binary Search on Answer

The problem asks us to find a minimum value of a maximum capacity ($x$). This structure strongly hints at **Binary Search on the Answer Space** (also known as the "Feasibility Test" pattern).

### Key Insights:
1. **Monotonicity:** If it's possible to distribute the products such that no store gets more than $x$ items, then it is also possible for any capacity greater than $x$. If it's impossible for $x$, it's impossible for any capacity less than $x$.
2. **Search Range:** 
   - The minimum possible value for $x$ is `1` (if we have enough stores).
   - The maximum possible value for $x$ is `max(quantities)` (when a single store takes the entire product type).
3. **Ceiling Division Trick:** To calculate how many stores are needed for a specific product quantity given a max capacity `x`, we use integer ceiling division: 
   $$\text{Stores Needed} = \frac{\text{quantity} + x - 1}{x}$$
   This allows us to avoid casting to floating-point numbers (`double`/`Math.Ceiling`), keeping the execution optimal.

---

## 🚀 Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \cdot \log(\max(\text{quantities})))$
  - The binary search takes $\log(\max(\text{quantities}))$ steps.
  - In each step, we iterate through the `quantities` array of size $m$ to validate the feasibility.
- **Space Complexity:** $\mathcal{O}(1)$
  - Constant space is used as we only maintain a few primitive tracking variables (`low`, `high`, `mid`, `storecnt`).

---

## 💻 C# Implementation

```csharp
public class Solution 
{
    public static int MinimizedMaximum(int n, int[] quantities)
    {
        int maxQuantity = 0;
        for (int i = 0; i < quantities.Length; i++)
        {
            maxQuantity = Math.Max(maxQuantity, quantities[i]);
        }

        int low = 1;
        int high = maxQuantity;
        int mid;

        while (low < high)
        {
            mid = low + (high - low) / 2;

            if (CanSplit(n, quantities, mid))
            {
                high = mid; // Try to find a smaller maximum
            }
            else
            {
                low = mid + 1; // Current max is too small, need more capacity
            }
        }

        return low;
    }

    private static bool CanSplit(int n, int[] quantities, int x)
    {
        int storeCount = 0;
        for (int i = 0; i < quantities.Length; i++)
        {
            // Ceiling division trick to calculate required stores for current type
            storeCount += (quantities[i] + x - 1) / x;
        }
        
        return storeCount <= n;
    }
}