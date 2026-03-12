# Stock Buy and Sell

---

## Problem Statement

You are given an array of prices where `prices[i]` is the price of a given stock on the `i-th` day.

You want to maximize your profit by choosing:

- a single day to **buy** one stock
- a different day in the future to **sell** that stock

Return the **maximum profit** you can achieve from this transaction.

If you cannot achieve any profit, return **0**.

---

## Examples

### Example 1

```
Input: prices = [7,1,5,3,6,4]
Output: 5
```

**Explanation**

Buy on day **2** (price = 1)  
Sell on day **5** (price = 6)

```
Profit = 6 - 1 = 5
```

Note: Buying on day 2 and selling on day 1 is **not allowed** because you must buy before you sell.

---

### Example 2

```
Input: prices = [7,6,4,3,1]
Output: 0
```

**Explanation**

In this case, no transactions are done and the maximum profit is **0**.

---

# Problem Understanding

> We are given an array where each element represents the stock price on a particular day. The goal is to buy once and sell once in the future such that the profit is maximized. If no profit is possible, we return 0.

Important constraint:

```
Buy before Sell
```

---

# Brute Force Approach

## Idea

The brute force approach is to check **every possible pair of days**.

For every day `i`, we consider **buying** the stock.  
For every future day `j`, we consider **selling** the stock.

We compute the profit for each pair and keep track of the **maximum profit**.

---

## Logic

Outer loop

```
i → buying day
```

Inner loop

```
j → selling day
```

The inner loop starts from

```
j = i + 1
```

because you must **sell after buying**.

---

## Profit Calculation

```
profit = selling price - buying price
```

Track maximum profit

```
maxProfit = max(maxProfit, profit)
```

---

## Time Complexity

```
O(n²)
```

Because for each element we check every future element using nested loops.

---

## Space Complexity

```
O(1)
```

No extra space is used, only variables for storing the maximum profit.

---

# Optimized Approach

> The brute force solution works but is inefficient because it checks every pair of days. We can optimize it by observing that we only need to know the minimum price seen so far and calculate profit relative to it.

---

## Key Insight

At any day:

```
profit = current price - minimum price seen before
```

Instead of checking all pairs, we track the **minimum price while scanning the array once**.

---

## Strategy

While scanning the array:

- Track the **lowest price encountered**
- Calculate profit if we **sell today**
- Update **maximum profit**

---

## Time Complexity

```
O(n)
```

This is because we iterate through the array only once.

---

## Space Complexity

```
O(1)
```

Only two variables are used:

- minimum price
- maximum profit

---

# Final Summary

> The brute force solution checks every buy and sell pair and runs in **O(n²)** time. However, we can optimize it by keeping track of the minimum price seen so far and computing the profit for each day relative to it. This reduces the time complexity to **O(n)** while maintaining constant space.
