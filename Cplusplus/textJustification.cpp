#include <iostream>
#include <vector>

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth);
std::string createSentence(int start_idx, int end_idx, const std::vector<std::string> &words, int curr_len, int maxWidth);

int main()
{
    // std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    // int maxWidth = 16;
    // std::vector<std::string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    // int maxWidth = 16;
    std::vector<std::string> words = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
                                      "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth = 20;
    fullJustify(words, maxWidth);
    return 0;
}

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth)
{
    std::vector<std::string> justifiedSentences;
    int words_len = 0;
    int num_spaces = 0;

    int start_idx = 0;
    for (int i = 0; i < words.size(); i++)
    {
        words_len += words[i].size();
        num_spaces++; // 1 for space
        if (words_len + num_spaces - 1 > maxWidth)
        {
            justifiedSentences.push_back(createSentence(start_idx, i, words, words_len - words[i].size(), maxWidth));
            words_len = words[i].size();
            num_spaces = 1;
            start_idx = i;
        }
    }
    justifiedSentences.push_back(createSentence(start_idx, words.size(), words, words_len, maxWidth));

    for (auto s : justifiedSentences)
    {
        std::cout << s << ",\n";
    }

    return justifiedSentences;
}

std::string createSentence(int start_idx, int end_idx, const std::vector<std::string> &words, int curr_len, int maxWidth)
{
    std::string sentence = "";
    int num_words = end_idx - start_idx;
    int num_spaces = maxWidth - curr_len;
    int equal_space = num_words > 1 ? num_spaces / (num_words - 1) : 0;
    int rem_space = num_words > 1 ? num_spaces % (num_words - 1) : 0;

    for (int i = start_idx; i < end_idx; i++)
    {
        sentence += words[i];
        if (end_idx != words.size())
        {
            for (int j = 0; j < equal_space && i != end_idx - 1; j++)
            {
                sentence += " ";
            }
            if (i != end_idx - 1 && rem_space > 0)
            {
                sentence += " ";
                rem_space--;
            }
        }
        else
        {
            if (i != end_idx - 1)
            {
                sentence += " ";
            }
        }
    }

    int n = maxWidth - sentence.size();
    for (int j = 0; j < n; j++)
    {
        sentence += " ";
    }
    return sentence;
}