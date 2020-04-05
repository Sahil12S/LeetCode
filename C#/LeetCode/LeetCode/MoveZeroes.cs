﻿using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class MoveZeroes
    {
        public void MoveZero(int[] nums)
        {
            int j = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != 0)
                {
                    nums[j++] = nums[i];
                }
            }

            while (j < nums.Length)
            {
                nums[j++] = 0;
            }
        }
    }
}
