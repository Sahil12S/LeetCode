#include <vector>
#include <string>
#include <algorithm>

class AutocompleteSystem
{
private:
    struct TrieNode
    {
        TrieNode *children[27];
        std::string sentence;
        int times;
        TrieNode()
        {
            for (int i = 0; i < 27; i++)
            {
                children[i] = nullptr;
            }
            sentence = "";
            times = 0;
        }
        TrieNode(std::string s, int t) : sentence(s), times(t) {}
    };
    class Trie
    {
    private:
        TrieNode *root;

        int convert(char c)
        {
            return c == ' ' ? 26 : c - 'a';
        }

    public:
        Trie()
        {
            root = new TrieNode();
        }

        void insert(std::string s, int times)
        {
            TrieNode *curr = root;
            for (int i = 0; i < s.size(); i++)
            {
                int idx = convert(s[i]);
                // cout << s[i] << " "<< idx << endl;
                if (curr->children[idx] == nullptr)
                {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->times += times;
            curr->sentence = s;
        }

        std::vector<TrieNode *> findsentence(std::string s)
        {
            std::vector<TrieNode *> list;
            TrieNode *curr = root;
            for (char c : s)
            {
                if (curr->children[convert(c)] == nullptr)
                {
                    return {};
                }
                curr = curr->children[convert(c)];
            }
            traverse(s, curr, list);
            return list;
        }
        void traverse(std::string s, TrieNode *curr, std::vector<TrieNode *> &list)
        {
            if (curr->times > 0)
            {
                list.emplace_back(new TrieNode(s, curr->times));
            }
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (curr->children[i - 'a'] != nullptr)
                {
                    traverse(s + i, curr->children[i - 'a'], list);
                }
            }
            if (curr->children[26] != nullptr)
            {
                traverse(s + ' ', curr->children[26], list);
            }
        }
    };

    Trie root;

public:
    AutocompleteSystem(std::vector<std::string> &sentences, std::vector<int> &times)
    {
        for (int i = 0; i < times.size(); i++)
        {
            root.insert(sentences[i], times[i]);
        }
    }
    std::string curr_string = "";
    std::vector<std::string> input(char c)
    {

        std::vector<std::string> res;
        // Sentence ended
        if (c == '#')
        {
            root.insert(curr_string, 1);
            curr_string = "";
        }
        else
        {
            curr_string += c;
            std::vector<TrieNode *> sent_list;
            // Now get list
            sent_list = root.findsentence(curr_string);
            std::sort(sent_list.begin(), sent_list.end(),
                      [](const TrieNode *a, const TrieNode *b) -> bool {
                          if (a->times == b->times)
                          {
                              return a->sentence < b->sentence;
                          }
                          return a->times > b->times;
                      });
            // for( int i = 0; i < sent_list.size(); i++ )
            // {
            //     cout << sent_list[i]->sentence << " " << sent_list[i]->times << endl;
            // }
            // int n = ;
            for (int i = 0; i < std::min(3, static_cast<int>(sent_list.size())); i++)
            {
                res.emplace_back(sent_list[i]->sentence);
            }
        }

        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */