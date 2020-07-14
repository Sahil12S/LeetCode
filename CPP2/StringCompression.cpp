#include <iostream>
#include <vector>

using namespace std;

void addToArr(vector<char>& chars, int& count, int& idx);
int compress(vector<char>& chars);

int main()
{
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int count = compress(chars);
    for (int i = 0; i < count; i++)
    {
        cout << chars[i] << ", ";
    }
    cout << '\n';
    return 0;
}

void addToArr(vector<char>& chars, int& count, int& idx)
{
    vector<char> arr;
    if (count > 1)
    {
        while (count > 0)
        {
            arr.push_back('0' + count % 10);
            count /= 10;
        }
        count = 1;
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        chars[idx++] = arr[i];
    }
}

int compress(vector<char>& chars)
{
    char c = chars[0];
    int count = 1;
    int j = 0;
    for (int i = 1; i < chars.size(); i++)
    {
        chars[j] = c;
        if (c == chars[i])
        {
            count++;    
        }
        else
        {
            c = chars[i];
            addToArr(chars, count, ++j);
        }
    }
    chars[j] = c;
    addToArr(chars, count, ++j);
    return j;
}