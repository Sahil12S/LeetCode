/**
 * On a broken calculator that has a number showing on its display, we can perform two operations:
 * 
 * Double: Multiply the number on the display by 2, or;
 * Decrement: Subtract 1 from the number on the display.
 * Initially, the calculator is displaying the number X.
 * 
 * Return the minimum number of operations needed to display the number Y.
 */

#include <iostream>

int brokenCalc(int X, int Y);

int main()
{
    int X = 2;
    int Y = 3;
    std::cout << brokenCalc(X, Y) << '\n';
    return 0;
}

int brokenCalc(int X, int Y)
{
    // Description
    // https://leetcode.com/problems/broken-calculator/discuss/236565/detailed-proof-of-correctness-greedy-algorithm
    /**
        Let's say we have X = 2 and Y = 9
        If we move from X to Y, our approach would be to multiply X while it's less than Y
        & then decrement it.
        It would be something like
        (2 * 2 * 2 * 2) - 1 - 1 - 1 - 1 - 1 - 1 - 1 which is 3 multiplication and 7 subtraction (Total 10 operations)
        but optimal solution would be somthing like
        (((((2 * 2) - 1) * 2) - 1) * 2) - 1 which is 3 multiplication and 3 subtraction (Total 6 operations)
        
        But how do decide when to multiply or subtract?
        Our optimal solution gives us Y, so it will be something like
        (((((2 * 2) - 1) * 2) - 1) * 2) - 1 = Y
        (((((2 * 2) - 1) * 2) - 1) * 2) - 1 = 9
        (((((2 * 2) - 1) * 2) - 1) * 2) = 9 + 1 = 10
        ((((2 * 2) - 1) * 2) - 1) = 10 / 2 = 5
        (((2 * 2) - 1) * 2) = 5 + 1 = 6
        ((2 * 2) - 1) = 6 / 2 = 3
        2 * 2 = 3 + 1 = 4
        2 = 4 / 2 = 2 (= X)

        When we see this, we see that for Y, we are adding one when it's odd
        and dividing by 2 when it's even.
        this takes Y close to Y and hence to our answer
     */

    int res = 0;
    while (Y > X)
    {
        res++;
        if (Y % 2 == 1)
        {
            Y++;
        }
        else
        {
            Y /= 2;
        }
    }
    return res + X - Y;
}