class AutocompleteSystem
{
private:
    struct TrieNode
    {
        TrieNode *children[27];
        string sentence;
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
        TrieNode(string s, int t) : sentence(s), times(t) {}
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

        void insert(string s, int times)
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

        vector<TrieNode *> findsentence(string s)
        {
            vector<TrieNode *> list;
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
        void traverse(string s, TrieNode *curr, vector<TrieNode *> &list)
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
    AutocompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        for (int i = 0; i < times.size(); i++)
        {
            root.insert(sentences[i], times[i]);
        }
    }
    string curr_string = "";
    vector<string> input(char c)
    {

        vector<string> res;
        // Sentence ended
        if (c == '#')
        {
            root.insert(curr_string, 1);
            curr_string = "";
        }
        else
        {
            curr_string += c;
            vector<TrieNode *> sent_list;
            // Now get list
            sent_list = root.findsentence(curr_string);
            sort(sent_list.begin(), sent_list.end(),
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
            for (int i = 0; i < min(3, static_cast<int>(sent_list.size())); i++)
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