using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class KthLargest
    {
        MinHeap pq;
        int size;
        public KthLargest(int k, int[] nums)
        {
            pq = new MinHeap(k + 1);
            size = k;
            foreach (int n in nums)
            {
                pq.Add(n);
                if (pq.Count() > size)
                {
                    Console.WriteLine("removing: ", pq.Peek());
                    pq.Pop();
                }
            }
        }

        public int Add(int val)
        {
            pq.Add(val);
            if (pq.Count() > size)
            {
                pq.Pop();
            }
            return pq.Peek();
        }
    }
}
