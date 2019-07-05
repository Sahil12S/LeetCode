/**
 * Consider a special family of Engineers and Doctors. This family has the following rules:
 * Everybody has two children.
 * The first child of an Engineer is an Engineer and the second child is a Doctor.
 * The first child of a Doctor is a Doctor and the second child is an Engineer.
 * All generations of Doctors and Engineers start with an Engineer.
 * Given the level and position of a person in the ancestor tree above, find the profession of the person.
 * Note: in this tree first child is considered as left child, second - as right.
 */

#include <iostream>

std::string findProfession(int level, int pos);

int main()
{
    int level = 30;
    int pos = 163126329;
    std::cout << findProfession(level, pos) << '\n';
    return 0;
}

std::string findProfession(int level, int pos)
{
    if (level == 1)
    {
        return "Engineer";
    }

    if (findProfession(level - 1, (pos + 1) / 2) == "Doctor")
    {
        return (pos % 2) ? "Doctor" : "Engineer";
    }
    return (pos % 2) ? "Engineer" : "Doctor";
}