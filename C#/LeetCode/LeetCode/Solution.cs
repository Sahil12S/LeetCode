﻿using System;
using System.Collections.Generic;
using System.Text;
using LeetCode;

namespace LeetCode
{
    class Solution
    {
        public static void Main()
        {
            // Main class
            Console.WriteLine("Solution: ");


            /*ShortestDistanceToACharacter obj = new ShortestDistanceToACharacter();
            string s = "loveleetcode";
            char c = 'e';

            int[] res = obj.ShortestToChar(s, c);
            for (int i = 0; i < res.Length; i++)
            {
                Console.Write(res[i]);
                if (i < res.Length - 1)
                {
                    Console.Write(", ");
                }
            }
            Console.Write("\n");*/

            /*UncommonWordsFromTwoSentences obj = new UncommonWordsFromTwoSentences();
            string A = "this apple is sweet";
            string B = "this apple is sour";
            string[] res = obj.UncommonFromSentences(A, B);

            foreach (string word in res)
            {
                Console.WriteLine(word);
            }*/

            SumOfEvenNumbersAfterQueries obj = new SumOfEvenNumbersAfterQueries();
            int[] A = { 1, 2, 3, 4 };
            int[][] queries = {
                new int[] { 1, 0 },
                new int[] { -3, 1 },
                new int[] { -4, 0 },
                new int[] { 2, 3 }
            };
            int[] res = obj.SumEvenAfterQueries(A, queries);
            
            Console.WriteLine("[{0}]", string.Join(", ", res));
        }
    }
}
