#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isEnd;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }

        isEnd = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void TrieIns(string word)
    {
        TrieNode *cur = root;

        for (char ch : word)
        {
            int idx = ch - 'A'; // get index of character (uppercase)

            if (cur->children[idx] == nullptr)
            {                                        // if letter doesn't exist
                cur->children[idx] = new TrieNode(ch); // create it's node
            }

            cur = cur->children[idx]; // go to next letter
        }

        cur->isEnd = true;
    }
    // TC = O(l), l = length of word

    bool TrieSrch(string word)
    {
        TrieNode *cur = root;

        for (char ch : word)
        {
            int idx = ch - 'A';

            if (cur->children[idx] == nullptr) // if character doesn't exist
            {
                return false; // word doesn't exist
            }

            cur = cur->children[idx]; // otherwise, check for next letter
        }

        return cur->isEnd; // last letter is end of word or not
    }
    // TC = O(l)

    bool DelWord(TrieNode *cur, const string &word, int i)
    {
        // Base Case
        if (i == (int)word.length())
        {
            if (cur->isEnd == false) // if Word doesn't actually exist
            {
                return false; // can't delete
            }

            cur->isEnd = false; // otherwise, remove word from Trie

            // For Space Optimization
            for (int j = 0; j < 26; j++)
            {
                if (cur->children[j] != nullptr) // if has other child letters
                {
                    return false; // can't delete
                }
            }

            return true; // otherwise, can delete
        }

        int idx = word[i] - 'A';
        if (cur->children[idx] == nullptr) // next letter doesn't present in Trie
        {
            return false; // can't delete
        }

        bool chk = DelWord(cur->children[idx], word, i + 1); // recursive call for next letter

        // Space Optimization
        if (chk) // can delete next letter
        {
            delete cur->children[idx];    // delete next letter
            cur->children[idx] = nullptr; // update the link

            if (cur->isEnd) // if current letter is end of other word
            {
                return false; // can't delete
            }
            for (int j = 0; j < 26; j++) // if current letter has other child
            {
                if (cur->children[j] != nullptr)
                {
                    return false; // can't delete
                }
            }

            return true; // otherwies, can delete current letter
        }
        else // can't delete next letter
        {
            return false; // can't delete current letter also, because it's needed by next letter
        }
    }
    void TrieDel(string word)
    {
        DelWord(root, word, 0);
    }
    // TC = O(l), l = length of word
};

int main()
{
    Trie t;

    t.TrieIns("ASH");
    t.TrieIns("TIME");

    cout << "Is ASH Present: " << t.TrieSrch("ASH") << '\n';
    cout << "Is TIME Present: " << t.TrieSrch("TIME") << '\n';
    cout << "Is TIM Present: " << t.TrieSrch("TIM") << "\n\n";

    t.TrieIns("TIM");
    cout << "Is TIM Present: " << t.TrieSrch("TIM") << "\n\n";

    t.TrieDel("TIM");
    cout << "Is TIME Present: " << t.TrieSrch("TIME") << '\n';
    cout << "Is TIM Present: " << t.TrieSrch("TIM") << '\n';

    return 0;
}