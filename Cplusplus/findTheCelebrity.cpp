/**
 * Question: 277 Find the celebrity
 * https://leetcode.com/problems/find-the-celebrity/
 */

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution
{
public:
    int findCelebrity(int n)
    {
        int celebrity = 0;

        // So we check if our current celebrity knows any other person.
        // If it does then it can't be a celebrity
        // And according to definition of question
        // all other person should know the celebrity.
        // So if our current celebrity doesn't know any person
        // while travelling, it means they can't be celebrity
        // since current one doesn't know them.
        for (int i = 1; i < n; i++)
        {
            if (knows(celebrity, i))
            {
                celebrity = i;
            }
        }

        // Check if every other person knows this celebrity
        for (int i = 0; i < n; i++)
        {
            // Check if someone doesn't know celebrity
            // or if celebrity knows someone
            if (i != celebrity && (!knows(i, celebrity) || knows(celebrity, i)))
            {
                return -1;
            }
        }
        return celebrity;
    }
};