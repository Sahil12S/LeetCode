using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class BackspaceStringCompare2
    {
        public Boolean ArraysKeyPress(string str1, string str2)
        {
            List<char> arrS = new List<char>();
            List<char> arrT = new List<char>();

            for (int i = 0; i < str1.Length; i++)
            {
                if (str1[i] == '\\' && arrS.Count > 0)
                {
                    arrS.RemoveAt(arrS.Count - 1);
                    i++;
                }
                else if (str1[i] != '\\')
                {
                    arrS.Add(str1[i]);
                }
            }
            for (int j = 0; j < str2.Length; j++)
            {
                if (str2[j] == '\\' && arrT.Count > 0)
                {
                    arrT.RemoveAt(arrT.Count - 1);
                    j++;
                }
                else if (str2[j] != '\\')
                {
                    arrT.Add(str2[j]);
                }
            }
            str1 = new string(arrS.ToArray());
            str2 = new string(arrT.ToArray());

            return str1.Equals(str2);
        }
    }
}
