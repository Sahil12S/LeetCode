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

            /*LastStoneWeight obj = new LastStoneWeight();
            int[] stones = { 2, 7, 4, 1, 8, 1 };
            int res = obj.LastStoneWt(stones);
            Console.WriteLine(res);*/

            /*MaximumNumberOfBalloons obj = new MaximumNumberOfBalloons();
            string text = "loonbalxballpoon";
            int res = obj.MaxNumberOfBalloons(text);
            Console.WriteLine(res);*/

            /*BackspaceStringCompare obj = new BackspaceStringCompare();
            string S = "d##########c";
            string T = "d#c";
            bool res = obj.BackspaceCompare(S, T);
            Console.WriteLine(res);*/

            /*MinStack obj = new MinStack();
            obj.Push(-2);
            obj.Push(0);
            obj.Push(-3);
            int res = obj.GetMin();
            Console.WriteLine("{0}, expected: {1}", res, -3);
            obj.Pop();
            res = obj.Top();
            Console.WriteLine("{0}, expected: {1}", res, 0);
            res = obj.GetMin();
            Console.WriteLine("{0}, expected: {1}", res, -2);*/

            /*MinCostToRemoveAdjacentDuplicate obj = new MinCostToRemoveAdjacentDuplicate();
            int[] C = { 1,2 , 3, 4 };
            int ans = obj.MinCost("ababa", C);
            Console.WriteLine(ans);*/

            /*ContiguousArray obj = new ContiguousArray();
            int[] nums = { 0, 1, 1, 1, 1, 0, 1, 0 };
            Console.WriteLine(obj.FindMaxLength(nums));*/

            /*PerformStringShifts obj = new PerformStringShifts();
            string s = "abcdefg";
            int[][] shift = 
            {
                new int[] {1, 1},
                new int[] {1, 1},
                new int[] {0, 2},
                new int[] {1, 3}
            };
            Console.WriteLine(obj.StringShift(s, shift));*/

            /*ValidParenthesisString obj = new ValidParenthesisString();
            string s = "(*))";
            Console.WriteLine(obj.CheckValidString(s));*/

            /*DeviceNameSystem obj = new DeviceNameSystem();
            //string[] deviceNames = { "switch", "tv", "switch", "tv", "switch", "tv" };
            //string[] deviceNames = { "mixer", "toaster", "mixer", "tv" };
            string[] deviceNames = { "lamp", "lamp", "tv", "lamp" };
            string[] res = obj.GetUniqueDeviceNames(deviceNames);
            Console.WriteLine("[{0}]", string.Join(", ", res));*/

            /*ThirdMaximumNumber obj = new ThirdMaximumNumber();
            int[] nums = new int[] { 1, 1, 2 };
            Console.WriteLine(obj.ThirdMax(nums));*/

            int[] arr = new int[] { 4, 5, 8, 2 };
            int k = 3;
            KthLargest obj = new KthLargest(k, arr);
            Console.WriteLine(obj.Add(3));
            Console.WriteLine(obj.Add(5));
            Console.WriteLine(obj.Add(10));
            Console.WriteLine(obj.Add(9));
            Console.WriteLine(obj.Add(4));

            /*MinHeap obj = new MinHeap(11);
            obj.Add(3);
            obj.Add(2);
            obj.Add(1);
            obj.Add(15);
            obj.Add(5);
            obj.Add(4);
            obj.Add(45);
            Console.WriteLine(obj.Peek());
            Console.WriteLine(obj.Pop());
            Console.WriteLine(obj.Pop());
            obj.Add(-1);
            Console.WriteLine(obj.Peek());*/
        }
    }
}
