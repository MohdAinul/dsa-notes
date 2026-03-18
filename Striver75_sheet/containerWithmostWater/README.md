# Container With Most Water

## Problem

Given an array `height[]`, where each element represents the height of a vertical line, find two lines that together with the x-axis form a container that holds the maximum amount of water.

---

## Formula

Area = min(height[i], height[j]) \* (j - i)

---

## Approach 1: Brute Force

### Idea

- Try all possible pairs (i, j)
- Calculate area and keep track of maximum

### Time Complexity

O(n^2)

### Space Complexity

O(1)

---

## Approach 2: Optimal (Two Pointer)

### Idea

- Start with two pointers (left = 0, right = n-1)
- Calculate area
- Move the pointer with smaller height

### Why it works

- Smaller height limits the area
- Moving larger height won't increase area

### Time Complexity

O(n)

### Space Complexity

O(1)

---

## Example

Input:
[1,8,6,2,5,4,8,3,7]

Output:
49

---

## Key Learning

- Use Two Pointer when dealing with two ends
- Always think about optimizing brute force
