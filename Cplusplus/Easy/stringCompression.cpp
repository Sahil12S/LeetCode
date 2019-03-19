// Given an array of characters, compress it in-place.

#include <iostream>
#include <vector>

using namespace std;

int compress (vector<char>& chars);
void print(vector<char> chars, int k);

int main(int argc, char const *argv[])
{
    // vector<char> chars = {'a', 'b', 'c'};
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    // vector<char> chars = {'a', 'a', 'a', 'b', 'c'};
    // vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    cout << compress(chars) << endl;
    return 0;
}

int compress (vector<char>& chars)
{
    int iter = 0, ptr = 0;

    for (int i = 0; i < chars.size(); i++)
    {
        if (i + 1 == chars.size() || chars[i] != chars[i+1])
        {
            chars[iter++] = chars[ptr];
            if (ptr < i)
            {
                cout << "iter: " << iter << ", i: " << i << endl;
                for (char c : to_string(i - ptr + 1))
                {
                    cout << c << endl;
                    chars[iter++] = c;
                }
            }
            ptr = i + 1;
        }
    }

    print (chars, iter);

    return iter;
}

void print(vector<char> chars, int k) {

    for (int i = 0; i < k; i++)
    {
        cout << chars[i] << ", ";
    }
    cout << endl;
}
