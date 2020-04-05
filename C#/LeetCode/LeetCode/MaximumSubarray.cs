using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class MaximumSubarray
    {
        public int MaxSubArray(int[] nums)
        {
            int sum = nums[0];
            int res = sum;
            //int j = 0;

            for (int i = 1; i < nums.Length; i++)
            {
                sum += nums[i];

                if (sum < nums[i])
                {
                    sum = nums[i];
                }
                if (sum > res)
                {
                    res = sum;
                }
                
            }
            return res;
        }
    }
}
