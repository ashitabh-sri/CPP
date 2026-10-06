// https://www.geeksforgeeks.org/problems/phone-directory4628/1

class Solution
{
    struct TrieNode
    {
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
    struct Trie
    {
        TrieNode *root;

        Trie()
        {
            root = new TrieNode();
        }

        void TrieIns(string word)
        {
            TrieNode *cur = root;

            for (char ch : word)
            {
                int idx = ch - 'a';

                if (cur->children[idx] == nullptr)
                {
                    cur->children[idx] = new TrieNode();
                }

                cur = cur->children[idx];
            }

            cur->isEnd = true;
        }

        void DFS(TrieNode *cur, string &prfx, vector<string> &res)
        {
            if (cur->isEnd) // word completed
            {
                res.push_back(prfx); // push word to answer
            }

            for (int i = 0; i < 26; i++)
            {
                if (cur->children[i] != nullptr) // if next letter exists
                {
                    prfx.push_back('a' + i); // add letter to prefix

                    DFS(cur->children[i], prfx, res); // recursive call for below branches

                    prfx.pop_back(); // words done with this letter
                }
            }
        }
    };

public:
    vector<vector<string>> displayContacts(vector<string> &contact, string &s)
    {
        // code here
        Trie t;
        for (string word : contact) // TC = O(N*L)
        {
            t.TrieIns(word);
        }

        vector<vector<string>> ans;

        TrieNode *cur = t.root;
        string prfx = "";

        for (char c : s) // TC = O()
        {
            prfx += c; // adding prefix

            // Base Case
            if (cur == nullptr)
            { // no further letters can exist in Trie
                ans.push_back({"0"});
                continue;
            }

            int idx = c - 'a';

            if (cur->children[idx] == nullptr)
            { // if next letter doesn't exist
                cur = nullptr;
                ans.push_back({"0"});
            }
            else
            {
                cur = cur->children[idx]; // update the cur node

                vector<string> res;

                t.DFS(cur, prfx, res); // bring words from prefix

                ans.push_back(res);
            }
        }

        return ans;
    }
};

// Trie + DFS
// TC = O(N*L*S)
// SC = O(N*L) + output
// N = total words in contact, L = max length of words, S = total length of s