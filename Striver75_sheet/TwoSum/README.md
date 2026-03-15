# Two Sum

---

## Problem Statement

Given an array of integers `arr[]` and an integer `target`.

### Variant 1

Return **"YES"** if there exist two numbers such that their sum is equal to the target. Otherwise return **"NO"**.

### Variant 2

Return the **indices of the two numbers** such that their sum is equal to the target. Otherwise return:

```
{-1, -1}
```

---

# Brute Force Approach

## Idea

For each element of the array, we try to find another element such that their sum equals the target.

If such two numbers exist, we return either:

- `"YES"` (Variant 1)
- the indices of the pair (Variant 2)

---

## Algorithm

1. Use a loop (say `i`) to select each element of the array.
2. For every `i`, traverse the remaining array using another loop (`j`).
3. Check if:

```
arr[i] + arr[j] = target
```

4. If such a pair is found, return the result.

---

## Observation

If the inner loop starts from index `0`, we would check the same pair multiple times.

Example:

Iteration 1:

```
i = 0
check arr[0] + arr[1]
```

Iteration 2:

```
i = 1
check arr[1] + arr[0]
```

This repeats the same pair.

To avoid this, the inner loop should start from:

```
j = i + 1
```

This ensures each pair is checked **only once**.

---

## Complexity Analysis

### Time Complexity

```
O(N²)
```

Because we use two nested loops to check every possible pair.

### Space Complexity

```
O(1)
```

Only constant extra space is used.

---

# Better Approach (Using Hash Map)

## Idea

In the brute force approach, after selecting an element we search for its pair using another loop.

Instead, we can use a **Hash Map** to check whether the required element already exists.

This reduces the search time from **O(N)** to **O(1)** on average.

---

## Algorithm

1. Create a hash map.
2. Traverse the array using a loop (`i`).
3. For each element calculate the required value:

```
required = target - arr[i]
```

4. Check if this required value exists in the hash map.

- If it exists:
  - For Variant 1 → return `"YES"`
  - For Variant 2 → return the indices.

5. If it does not exist:
   - Store the current element and its index in the map.

```
map[arr[i]] = i
```

6. Continue the process.

7. If the loop finishes and no pair is found:

- return `"NO"` (Variant 1)
- return `{-1, -1}` (Variant 2)

---

## Complexity Analysis

### Time Complexity

```
O(N)
```

We traverse the array only once and each hash map lookup takes **O(1)** on average.

### Space Complexity

```
O(N)
```

In the worst case, all elements of the array may be stored in the hash map.

# Optimal Approach

## Algorithm

In this approach, we will first sort the array and will try to choose the numbers in a greedy way.

1. We will keep a left pointer at the first index and a right pointer at the last index. Now until left < right, we will check the sum of arr[left] and arr[right]. Now if the sum < target, we need bigger numbers and so we will increment the left pointer. But if sum > target, we need to consider lesser numbers and so we will decrement the right pointer.

2. If sum == target we will return either “YES” or the indices as per the question. But if the left crosses the right pointer, we will return “NO” or {-1, -1}.
3. We will sort the given array first.
4. Now, we will take two pointers i.e. left, which points to the first index, and right, which points to the last index.
5. Now using a loop we will check the sum of arr[left] and arr[right] until left < right.
6. If arr[left] + arr[right] > sum, we will decrement the right pointer.
7. If arr[left] + arr[right] < sum, we will increment the left pointer.
8. If arr[left] + arr[right] == sum, we will return the result.
9. Finally, if no results are found we will return “NO” or {-1, -1}.

# Complexity Analysis

### Time Complexity:

```
O(N log N)
```

due to sorting the array initially, where N is the number of elements. The two-pointer traversal runs in O(N).

### Space Complexity:

```
O(N)
```

because we store the array elements along with their original indices in a separate list or vector for sorting, maintaining original positions.
