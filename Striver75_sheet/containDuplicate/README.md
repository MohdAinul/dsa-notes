# Contains Duplicate : Check if a value appears atleast twice

## Problem Statement: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

### Examples

Example 1:
Input: nums = [1, 2, 3, 1]
Output: true.
Explanation: 1 appeared two times in the input array.

Example 2:
Input: nums = [1, 2, 3, 4]
Output: false
Explanation: input array does not contain any duplicate number.

## Brute Force Approach

Algorithm
Intuition: To check if there are any duplicates in the array, we compare every element with all others after it. If any two elements match, we return true immediately. This brute-force method ensures we don’t miss any duplicate, but it’s inefficient for large inputs.

Iterate through the array using index i from 0 to n-1.
For each i, iterate through the remaining elements using index j from i+1 to n-1.
Compare nums[i] with nums[j].
If they are equal, return true indicating a duplicate is found.
If the loops finish without finding any duplicates, return false.

Time Complexity: O(n²), because every pair of elements is compared using nested loops.

Space Complexity: O(1), no additional space is used beyond variables.

## Better Approach

Algorithm
Intuition: By sorting the array first, any duplicate elements will appear next to each other. This allows us to detect duplicates by simply checking adjacent elements, avoiding the need to compare every pair.

Sort the array in non-decreasing order.
Iterate from index 1 to the end of the array.
At each step, compare the current element with the previous one.
If they are equal, return true indicating a duplicate is found.
If the loop finishes without finding duplicates, return false.

Complexity Analysis
Time Complexity: O(n log n), due to the sorting step.

Space Complexity: O(1), assuming in-place sorting is used.

## Optimal Approach

Algorithm
Intuition: A set only stores unique elements, so inserting all elements of the array into a set will automatically remove duplicates. If the size of the set is smaller than the size of the array, it means duplicates were present.

Create an empty unordered set.
Iterate through the array and insert each element into the set.
After insertion, compare the size of the set with the size of the original array.
If the set size is smaller, return true indicating duplicates exist.
Otherwise, return false.

Complexity Analysis
Time Complexity: O(n), inserting n elements into a hash set takes average O(1) per insert.

Space Complexity: O(n), space used by the unordered set to store unique elements.
