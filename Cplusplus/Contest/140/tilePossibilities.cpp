/**
 * You have a set of tiles, where each tile has one letter tiles[i] printed on it.
 * Return the number of possible non-empty sequences of letters you can make.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)

int numTilePossibilities(std::string tiles);

int main()
{
    std::string tiles = "AAB";
    std::cout << numTilePossibilities(tiles) << '\n';
    return 0;
}

int numTilePossibilities(std::string tiles)
{
    std::sort(tiles.begin(), tiles.end());
    std::unordered_set<std::string> perms;

    while (1)
    {
        FORI(0, tiles.size())
        {
            perms.insert(tiles.substr(0, i + 1));
        }
        if (!std::next_permutation(tiles.begin(), tiles.end()))
        {
            break;
        }
    }
    return perms.size();
}