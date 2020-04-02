using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class SingleNumber
    {
        public int SingleNum(int[] nums)
        {
            /*Dictionary<int, int> appearanceCount = new Dictionary<int, int>();

            foreach (int val in nums)
            {
                if (appearanceCount.ContainsKey(val))
                {
                    appearanceCount[val]++;
                }
                else
                {
                    appearanceCount[val] = 1;
                }
            }

            int res = 0;

            foreach (KeyValuePair<int, int> mapValue in appearanceCount)
            {
                if (mapValue.Value == 1)
                {
                    res = mapValue.Key;
                    break;
                }
            }*/

            // Using BIT manipulation
            // If we XOR 0 & a it gives a, a^0 = a, a^a = 0

            int res = 0;

            foreach (int val in nums)
            {
                res ^= val;
            }

            return res;
        }
    }
}
