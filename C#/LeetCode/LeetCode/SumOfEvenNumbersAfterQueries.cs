using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class SumOfEvenNumbersAfterQueries
    {
        public int[] SumEvenAfterQueries(int[] A, int[][] queries)
        {
            int[] res = new int[A.Length];
            int totalSum = 0;

            foreach (int val in A)
            {
                if (val % 2 == 0)
                {
                    totalSum += val;
                }
            }

            for (int i = 0; i < queries.Length; i++)
            {
                int value = queries[i][0];
                int index = queries[i][1];

                if (A[index] % 2 == 0)
                {
                    totalSum -= A[index];
                }

                A[index] += value;

                if (A[index] % 2 == 0)
                {
                    totalSum += A[index];
                }

                res[i] = totalSum;
            }

            return res;
        }
    }
}
