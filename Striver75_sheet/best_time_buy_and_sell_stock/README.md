// Stock Buy And Sell

// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Examples
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
1️⃣ Problem Understanding (Start Like This)

In an interview you start with:

“We are given an array where each element represents the stock price on a particular day. The goal is to buy once and sell once in the future such that the profit is maximized. If no profit is possible, we return 0.”

Important constraint:
Buy before Sell

2️⃣ Brute Force Approach

Idea

“The brute force approach is to check every possible pair of days. For every day i, we consider buying the stock, and for every future day j, we consider selling it. We compute the profit for each pair and keep track of the maximum profit.”

Outer loop
i → buying day
Inner loop
j → selling day
Starts from:
j = i + 1
because you must sell after buying.
Profit calculation
profit = selling price - buying price
Track maximum
maxProfit = max(maxProfit, profit)
Time Complexity: O(n²) Because for each element, we are checking every future element nested loops.

Space Complexity: O(1) No extra space used, only variables for storing max profit.

⸻

3️⃣ Optimized Approach

Now say in interview:

“The brute force solution works but is inefficient because it checks every pair of days. We can optimize this by observing that we only need to know the minimum price seen so far and calculate profit relative to it.”
Key Insight

At any day:
profit = current price - minimum price seen before
So instead of checking all pairs, we track the minimum price while scanning the array once.

Idea

While scanning the array:
• Track the lowest price encountered
• Calculate profit if we sell today
• Update maximum profit

Time Complexity: O(n),This is because we are iterating through the array of prices exactly once. There are no nested loops or recursive calls.

Space Complexity: O(1),Only two variables are used to store the minimum price and maximum profit, regardless of the input size.

Final Interview Summary (What FAANG expects)

You can end with:

“The brute force solution checks every buy and sell pair and runs in O(n²) time. However, we can optimize it by keeping track of the minimum price seen so far and computing the profit for each day relative to it. This reduces the time complexity to O(n) while maintaining constant space.”
