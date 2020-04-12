using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class MinCostToRemoveAdjacentDuplicate
    {
        /*
         * Remove adjacent duplicate characters from a string
         * cost of removing S[i] is C[i]. Resultant string shouldn't have
         * any duplicate characters adjacent to each other.
         * Find the minimum cost for it.
         */
        public int MinCost(string S, int[] C)
        {
            int minCost = 0;
            int i = 0;
            int j =  i + 1;
            // abccdb
            
            while (j < S.Length)
            {
                
                if (S[j] == S[i])
                {
                    if (C[j] < C[i])
                    {
                        minCost += C[j];
                    }
                    else
                    {
                        minCost += C[i];
                        i = j;
                    }
                    j++;
                }
                else
                {
                    j++;
                    i = j - 1;
                }
                
            }

            return minCost;
        }
    }
}
