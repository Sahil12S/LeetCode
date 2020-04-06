using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class GroupAnagrams
    {
        public IList<IList<string>> GroupAnagram(string[] strs)
        {
            List<IList<string>> res = new List<IList<string>>();

            if (strs.Length == 0)
            {
                return res;
            }

            Dictionary<string, List<string>> mapping = new Dictionary<string, List<string>>();

            foreach (string word in strs)
            {
                char[] temp = word.ToCharArray();
                Array.Sort(temp);

                string sorted_word = new string(temp);

                if (!mapping.ContainsKey(sorted_word))
                {
                    mapping[sorted_word] = new List<string>();
                }
                mapping[sorted_word].Add(word);
            }

            foreach (KeyValuePair<string, List<string>> kv in mapping)
            {
                res.Add(kv.Value);
            }

            return res;
        }
    }
}
