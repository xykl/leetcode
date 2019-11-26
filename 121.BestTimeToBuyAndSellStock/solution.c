/**
 * *****************************************************************************
 * Problem Statement:
 * Say you have an array for which the ith element is the price of a given stock
 * on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy one
 * and sell one share of the stock), design an algorithm to find the maximum
 * profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6),
 * profit = 6-1 = 5. Not 7-1 = 6, as selling price needs to be larger than
 * buying price.
 *
 * Example 2:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 * -----------------------------------------------------------------------------
 * Soltuion Analysis:
 * Linear time complexity, linear space complexity
 *
 * -----------------------------------------------------------------------------
 * Submission:
 * Submission Detail @ https://leetcode.com/submissions/detail/281910913/
 *
 * *****************************************************************************
 */


int find_max(int *arr, int size)
{
    int max, i;

    max = INT_MIN;
    for (i = 0; i < size; ++i) {
        max = arr[i] > max ? arr[i] : max;
    }

    return max;
}


int maxProfit(int *prices, int prices_size)
{
    int buy_in;     // the day we start to loose money, ie. possible time to buy
    int *profits;   // dp array: to record the profit made if selling on i-th day
                    // (when buying on buy_in date)
    int i;
    
    if (!prices_size) {
        return 0;
    }
   

    profits = (int*)(malloc(sizeof(int) * prices_size));
    buy_in = 0;
    profits[buy_in] = 0;


    for (i = 1; i < prices_size; ++i) {
        profits[i] = prices[i] - prices[buy_in];

        // decide if we should consider this as a new buy_in day
        if (profits[i] < 0) {
            buy_in = i;
        }
    }

    return find_max(profits, prices_size);
}

