using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class ReverseString
    {
        public void ReverseStr(char[] s)
        {
            int i = 0;
            int j = s.Length - 1;

            while (i < j)
            {
                swap(ref s, i, j);
                i++;
                j--;
            }

        }
        private void swap(ref char[] s, int i, int j)
        {
            char x = s[i];
            s[i] = s[j];
            s[j] = x;
        }
    }
}
