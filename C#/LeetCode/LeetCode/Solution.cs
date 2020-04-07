using System;
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

            /*SumOfEvenNumbersAfterQueries obj = new SumOfEvenNumbersAfterQueries();
            int[] A = { 1, 2, 3, 4 };
            int[][] queries = {
                new int[] { 1, 0 },
                new int[] { -3, 1 },
                new int[] { -4, 0 },
                new int[] { 2, 3 }
            };
            int[] res = obj.SumEvenAfterQueries(A, queries);
            
            Console.WriteLine("[{0}]", string.Join(", ", res));*/

            /*SingleNumber obj = new SingleNumber();
            int[] nums = { 4, 1, 2, 1, 2 };
            //int[] nums = { 1 };

            Console.WriteLine(obj.SingleNum(nums));*/

            /*HappyNumber obj = new HappyNumber();
            int n = 19;

            Console.WriteLine(obj.IsHappy(n));*/

            /*MaximumSubarray obj = new MaximumSubarray();

            //int[] nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
            int[] nums = { -2, 1, 10, -10, 10, 1 };
            int res = obj.MaxSubArray(nums);

            Console.WriteLine(res);*/

            /*MoveZeroes obj = new MoveZeroes();
            int[] nums = { 0, 1, 0, 3, 12 };
            obj.MoveZero(nums);

            Console.WriteLine("[{0}]", string.Join(", ", nums));*/

            /*BestTimeToBuyAndSellStock2 obj = new BestTimeToBuyAndSellStock2();
            //int[] prices = { 7, 1, 5, 3, 6, 4 };
            //int[] prices = { 1, 2, 3, 4, 5 };
            int[] prices = { };
            int profit = obj.MaxProfit(prices);
            Console.WriteLine("profit: {0}", profit);*/

            /*ReverseString obj = new ReverseString();
            //char[] s = { 'h', 'e', 'l', 'l', 'o' };
            char[] s = { 'a', 'b', 'c' };
            obj.ReverseStr(s);
            Console.WriteLine("[{0}]", string.Join(", ", s));*/

            /*GroupAnagrams obj = new GroupAnagrams();
            string[] strs = { "eat", "tea", "tan", "ate", "nat", "bat", "bat" };
            IList<IList<string>> res = obj.GroupAnagram(strs);

            foreach (IList<string> l in res)
            {
                Console.WriteLine("[{0}]", string.Join(", ", l));
            }*/

            /*CountingElements obj = new CountingElements();
            //int[] arr = { 1, 3, 2, 3, 5, 0 };
            //int[] arr = { 1, 1, 3, 3, 5, 5, 7, 7 };
            int[] arr = { 1, 2, 3 };
            int res = obj.CountElements(arr);
            Console.WriteLine(res);*/

            /*DivisorGame obj = new DivisorGame();
            int N = 3;
            bool res = obj.DivisorGames(N);
            Console.WriteLine(res);*/

            LastStoneWeight obj = new LastStoneWeight();
            int[] stones = { 2, 7, 4, 1, 8, 1 };
            int res = obj.LastStoneWt(stones);
            Console.WriteLine(res);

        }
    }
}
