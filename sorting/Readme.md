# 🔢 Sorting Algorithms (DSA Repository)

This folder contains implementations of various sorting algorithms in C/C++.  
Each algorithm is implemented from scratch to understand its **working principle, time complexity, and trade-offs**.

---

## 📚 Implemented Sorting Algorithms

1. **Bubble Sort**
2. **Selection Sort**
3. **Insertion Sort**
4. **Quick Sort**
5. **Merge Sort**
6. **Counting Sort**
7. **Bucket / Bin Sort**
8. **Radix Sort**
9. **Shell Sort**

---

## ⏱️ Time & Space Complexities

| Algorithm       | Best Case   | Average Case | Worst Case   | Space Complexity | Stable? |
|-----------------|-------------|--------------|--------------|------------------|---------|
| Bubble Sort     | O(n)        | O(n²)        | O(n²)        | O(1)             | ✅ Yes |
| Selection Sort  | O(n²)       | O(n²)        | O(n²)        | O(1)             | ❌ No |
| Insertion Sort  | O(n)        | O(n²)        | O(n²)        | O(1)             | ✅ Yes |
| Quick Sort      | O(n log n)  | O(n log n)   | O(n²)        | O(log n)         | ❌ No |
| Merge Sort      | O(n log n)  | O(n log n)   | O(n log n)   | O(n)             | ✅ Yes |
| Counting Sort   | O(n + k)    | O(n + k)     | O(n + k)     | O(k)             | ✅ Yes |
| Bucket/Bin Sort | O(n + k)    | O(n + k)     | O(n²)        | O(n + k)         | ✅ Yes |
| Radix Sort      | O(nk)       | O(nk)        | O(nk)        | O(n + k)         | ✅ Yes |
| Shell Sort      | O(n log n)  | O(n^(3/2))   | O(n²)        | O(1)             | ❌ No |

> **Notes**:  
> - `k` = range of input (for Counting, Bucket, Radix).  
> - Stability = whether equal elements preserve their input order.

---

## 📂 File Structure

