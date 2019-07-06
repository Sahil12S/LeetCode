#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FORI(s, n) for (int i = s; i < n; i++)
#define FORJ(s, n) for (int j = s; j < n; j++)

using VS = std::vector<std::string>;
// using VVS = std::vector<VS>;

VS removeComments(VS &source);

int main()
{
    VS source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};

    std::cout << "Source:" << '\n';
    for (auto s : source)
    {
        std::cout << s << '\n';
    }
    VS res = removeComments(source);
    std::cout << "Result:" << '\n';
    for (auto s : res)
    {
        std::cout << s << '\n';
    }

    return 0;
}

VS removeComments(VS &source)
{
    VS res;
    bool isMultComment = false;
    std::string temp = "";
    for (auto s : source)
    {
        FORI(0, s.size())
        {
            if (isMultComment)
            {
                if (s[i] == '*' && i < s.size() - 1 && s[i + 1] == '/')
                {
                    isMultComment = false;
                    i++;
                }
            }
            else
            {
                // Check for multiline commment
                if (s[i] == '/' && i < s.size() - 1 && s[i + 1] == '*')
                {
                    isMultComment = true;
                    i++;
                }
                else if (s[i] == '/' && i < s.size() - 1 && s[i + 1] == '/')
                {
                    break;
                }
                else
                {
                    temp += s[i];
                }
            }
        }
        if (!isMultComment && temp.size() > 0)
        {
            res.emplace_back(temp);
            temp = "";
        }
    }
    return res;
}