using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class LastStoneWeight
    {
        public int LastStoneWt(int[] stones)
        {
            Array.Sort(stones);
            int i = stones.Length - 1;
            while (i > 0)
            {
                int rem = Math.Abs(stones[i] - stones[i - 1]);
                stones[i - 1] = rem;
                Array.Sort(stones);
                i--;
            }
            return stones[0];
        }
    }
}
