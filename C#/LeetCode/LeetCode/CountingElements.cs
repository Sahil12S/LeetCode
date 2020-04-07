using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class CountingElements
    {
        public int CountElements(int[] arr)
        {
            HashSet<int> uniques = new HashSet<int>();
            
            foreach (int val in arr)
            {
                if (!uniques.Contains(val))
                {
                    uniques.Add(val);
                }
            }
            int res = 0;
            foreach (int val in arr)
            {
                if (uniques.Contains(val + 1))
                {
                    res++;
                }
            }
            return res;
        }
    }
}
