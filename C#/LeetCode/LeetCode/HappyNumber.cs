using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class HappyNumber
    {
        public bool IsHappy(int n)
        {
            HashSet<int> encountered = new HashSet<int>();
            int val = n;

            while (val != 1 && !encountered.Contains(val))
            {
                encountered.Add(val);
                int num = 0;
                while(val != 0)
                {
                    num += (val % 10) * (val % 10);
                    val /= 10;
                }
                val = num;
            }

            return val == 1 ? true : false;
        }
    }
}
