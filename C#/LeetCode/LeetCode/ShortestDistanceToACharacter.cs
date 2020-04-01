using System;

namespace LeetCode
{
	public class ShortestDistanceToACharacter
	{
		public int[] ShortestToChar(string S, char C)
		{
			int[] res = new int[S.Length];
			for (int i = 0; i < res.Length; i++)
			{
				res[i] = S.Length;
			}

			int last_c = -1;

			for (int i = 0; i < S.Length; i++)
			{
				if (last_c >= 0)
				{
					res[i] = i - last_c;
				}
				if (S[i] == C)
				{
					res[i] = 0;
					FindShortest(last_c, i, ref res);
					last_c = i;
				}
			}

			return res;
		}

		static void FindShortest(int lastIdx, int currIdx, ref int[] result)
		{
			for (int i = currIdx - 1; i > lastIdx; i--)
			{
				result[i] = Math.Min(result[i], currIdx - i);
			}
		}
	}
}
