# 451. Sort Characters By Frequency

## Intuition & Strategy
Instead of sorting the frequency array or using a priority queue, we leverage a **Frequency Loop / Bucket approach**:
1. **Frequency Counting**: Count character occurrences using a fixed-size ASCII array (`hist[128]`).
2. **Sequential Writing**: Iterate through possible frequencies from $n$ (string length) down to 1. For each frequency match, write the corresponding ASCII character into the result string.

This avoids any explicit sorting algorithms, maintaining a linear time complexity.

## Complexity Analysis
- **Time Complexity**: $\mathcal{O}(n)$
  - Counting frequencies takes $\mathcal{O}(n)$.
  - The outer loop runs $n$ times, inner ASCII scan runs $128$ times ($\mathcal{O}(1)$), and the `while` loop executes exactly $n$ times across the entire execution.
  - Total time: $n + 128n + n \Rightarrow \mathcal{O}(n)$.
- **Space Complexity**: $\mathcal{O}(1)$ auxiliary space
  - Uses a fixed array of size 128 regardless of input size.

## C Pitfalls & Notes
- Used `(unsigned char)` cast during array indexing to prevent negative indices with potential Extended ASCII characters.
- Ensured sequential dynamic memory allocation (`write_index++`) and proper `\0` null-termination.