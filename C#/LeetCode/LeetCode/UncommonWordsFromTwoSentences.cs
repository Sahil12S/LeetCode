using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class UncommonWordsFromTwoSentences
    {
        public string[] UncommonFromSentences(string A, string B)
        {
            string[] wordsA = A.Split(' ');
            string[] wordsB = B.Split(' ');

            Dictionary<string, int> words = new Dictionary<string, int>();

            foreach (string word in wordsA)
            {
                words.Add(word, words.GetValueOrDefault(word, 0) + 1);
            }
            foreach (string word in wordsB)
            {
                if (words.ContainsKey(word))
                {
                    words[word] += 1;
                }
                else
                {
                    words.Add(word, 1);
                }
            }

            List<string> uncommonWords = new List<string>();

            foreach (KeyValuePair<string, int> entry in words)
            {
                if (entry.Value == 1)
                {
                    uncommonWords.Add(entry.Key);
                }
            }
            return uncommonWords.ToArray();
        }
    }
}
