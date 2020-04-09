using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class BackspaceStringCompare
    {
        public bool BackspaceCompare(string S, string T)
        {
            /*List<char> arrS = new List<char>();
            List<char> arrT = new List<char>();

            foreach (char c in S)
            {
                if (c == '#' && arrS.Count > 0)
                {
                    arrS.RemoveAt(arrS.Count - 1);
                }
                else if (c != '#')
                {
                    arrS.Add(c);
                }
            }
            foreach (char c in T)
            {
                if (c == '#' && arrT.Count > 0)
                {
                    arrT.RemoveAt(arrT.Count - 1);
                }
                else if (c != '#')
                {
                    arrT.Add(c);
                }
            }
            S = new string(arrS.ToArray());
            T = new string(arrT.ToArray());

            Console.WriteLine(S);
            Console.WriteLine(T);*/

            int ignoreCtS = 0;
            int ignoreCtT = 0;

            int i = S.Length - 1;
            int j = T.Length - 1;

            while (i >= 0 || j >= 0)
            {
                while (i >= 0 && (S[i] == '#' || ignoreCtS > 0))
                {
                    if (S[i] == '#')
                    {
                        ignoreCtS++;
                    }
                    else
                    {
                        ignoreCtS--;
                    }
                    i--;
                }
                while (j >= 0 && (T[j] == '#' || ignoreCtT > 0))
                {
                    if (T[j] == '#')
                    {
                        ignoreCtT++;
                    }
                    else
                    {
                        ignoreCtT--;
                    }
                    j--;
                }

                if ((i < 0 && j >= 0) || (i >= 0 && j < 0))
                {
                    return false;
                }
                if (i >= 0 && j >= 0 && S[i] != T[j])
                {
                    return false;
                }
                i--;
                j--;
            }
            return i < 0 && j < 0;
        }

    }
}
