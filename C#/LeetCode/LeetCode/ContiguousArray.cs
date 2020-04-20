using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class ContiguousArray
    {
        public int FindMaxLength(int[] nums)
        {
            Dictionary<int, int> countIdxMap = new Dictionary<int, int>();
            countIdxMap.Add(0, -1);
            int maxLen = 0;
            int count = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                count += nums[i] == 1 ? 1 : -1;

                if (countIdxMap.ContainsKey(count))
                {
                    maxLen = Math.Max(maxLen, i - countIdxMap[count]);
                }
                else
                {
                    countIdxMap.Add(count, i);
                }
            }
            return maxLen;
        }
    }
}
