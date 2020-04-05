using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class BestTimeToBuyAndSellStock2
    {
        public int MaxProfit(int[] prices)
        {
            if (prices.Length == 0)
            {
                return 0;
            }
            int max_profit = 0;
            int pp = Int32.MaxValue;

            for (int i = 0; i < prices.Length - 1; i++)
            {
                if (prices[i] < pp)
                {
                    pp = prices[i];
                    continue;
                }
                if ( prices[i + 1] < prices[i])
                {
                    max_profit += (prices[i] - pp);
                    pp = Int32.MaxValue;
                }
            }
            if (pp < prices[prices.Length - 1])
            {
                max_profit += (prices[prices.Length - 1] - pp);
            }
            return max_profit;
        }
    }
}
