using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class PerformStringShifts
    {
        public string StringShift(string s, int[][] shift)
        {
            int finalShift = 0;

            for (int i = 0; i < shift.Length; i++)
            {
                if (shift[i][0] == 1)
                {
                    finalShift += shift[i][1];
                }
                else
                {
                    finalShift -= shift[i][1];
                }
            }
            int move = Math.Abs(finalShift) % s.Length;
            if (finalShift < 0)
            {
                string firstPart = s.Substring(0, move);
                string remainingPt = s.Substring(move);
                return remainingPt + firstPart;
            }
            string remainingPart = s.Substring(0, s.Length - move);
            string secondPart = s.Substring(s.Length - move);
            return secondPart + remainingPart;
        }
    }
}
