using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class ThirdMaximumNumber
    {
        public int ThirdMax(int[] nums)
        {
            long f_max = long.MinValue;
            long s_max = long.MinValue;
            long t_max = long.MinValue;
            foreach (int n in nums)
            {
                if (n > t_max && n > s_max && n >= f_max)
                {
                    t_max = s_max;
                    s_max = f_max;
                    f_max = n;
                }
                else if (n > t_max && n >= s_max)
                {
                    t_max = s_max;
                    s_max = n;
                }
                else if (n >= t_max)
                {
                    t_max = n;
                }
            }

            return (t_max == long.MinValue) ? (int)f_max : (int)t_max;
        }
    }
}
