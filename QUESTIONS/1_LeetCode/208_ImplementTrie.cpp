class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
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
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';

            if (curr->children[idx] == nullptr)
            {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';

            if (curr->children[idx] == nullptr) // letter doesn't present in Trie
            {
                return false; // word doesn't present in Trie
            }

            curr = curr->children[idx];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            int idx = prefix[i] - 'a';

            if (curr->children[idx] == nullptr)
            {
                return false;
            }

            curr = curr->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Trie
// TC = O(L), L = length of (longest) inserted word
// SC = O(T), T = total characters of all inserted words