# 702. Search in a Sorted Array of Unknown Size

## Intuition & Strategy
Since the size of the array is unknown, we cannot use standard binary search boundaries right away. We solve this in two phases:
1. **Exponential Range Expansion**: Start with a small window (`high = 1`) and double `high` iteratively as long as `reader_get(reader, high) < target`. This efficiently bounds the target within $\mathcal{O}(\log n)$ steps.
2. **Standard Binary Search**: Once the upper bound is found, perform a standard binary search between `0` and `high`.

## Local Testing & Mock API
To enable local execution and testing outside of the LeetCode platform, a custom **Mock API** structure (`ArrayReader` and `reader_get`) was implemented. This simulates the hidden array and the interface behavior (returning $2^{31} - 1$ out of bounds) for smooth offline validation.

## Complexity Analysis
- **Time Complexity**: $\mathcal{O}(\log n)$
  - Exponential search takes $\mathcal{O}(\log n)$ steps to find the upper bound.
  - Binary search takes $\mathcal{O}(\log n)$ steps.
- **Space Complexity**: $\mathcal{O}(1)$ auxiliary space.