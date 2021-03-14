#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
      bool isEOW;
      TrieNode *children[26];
      TrieNode()
      {
            isEOW = false;
            for (int i = 0; i < 26; i++)
            {
                  children[i] = NULL;
            }
      }
};

class Trie
{
public:
      /** Initialize your data structure here. */
      TrieNode *root;
      Trie()
      {
            root = new TrieNode();
      }

      /** Inserts a word into the trie. */
      void insert(string word)
      {
            int i = 0;
            char c;
            TrieNode *crawler = root;
            while (word[i] != '\0')
            {
                  c = word[i++];
                  if (crawler->children[c - 'a'] == NULL)
                  {
                        crawler->children[c - 'a'] = new TrieNode();
                        crawler = crawler->children[c - 'a'];
                  }
                  else
                  {
                        crawler = crawler->children[c - 'a'];
                  }
            }
            crawler->isEOW = true;
      }

      bool search_helper(string word, TrieNode *crawler, int n)
      {
            if (n == word.length())
            {
                  return (crawler->isEOW);
            }
            for (int i = 0; i < 26; i++)
            {
                  if (word[n] == 'a' + i)
                  {
                        if (crawler->children[i])
                        {
                              return search_helper(word, crawler->children[i], n + 1);
                        }
                        else
                        {
                              return false;
                        }
                  }
            }
            return false;
      }

      /** Returns if the word is in the trie. */
      bool search(string word)
      {
            return search_helper(word, root, 0);
      }

      bool startsWith_helper(string word, int n, TrieNode **index, TrieNode *r)
      {
            cout << word << endl;
            TrieNode *crawler = r;
            if (n == word.length())
            {
                  cout << "true" << endl;
                  *index = crawler;
                  return true;
            }
            for (int i = 0; i < 26; i++)
            {
                  if (word[n] == 'a' + i)
                  {
                        if (crawler->children[i])
                        {
                              return startsWith_helper(word, n + 1, index, crawler->children[i]);
                        }
                        else
                        {
                              return false;
                        }
                  }
            }
            return false;
      }

      bool isWordExist(TrieNode *r)
      {
            TrieNode *crawler = r;
            bool result = false;

            if (r->isEOW)
            {
                  return true;
            }
            else
            {
                  for (int i = 0; i < 26; i++)
                  {
                        if (crawler->children[i])
                        {
                              result = result || isWordExist(crawler->children[i]);
                        }
                  }
            }
            return result;
      }

      /** Returns if there is any word in the trie that starts with the given prefix. */
      bool startsWith(string prefix)
      {
            TrieNode *index = NULL;
            if (startsWith_helper(prefix, 0, &index, root))
            {
                  // cout << "here " << endl;
                  return isWordExist(index);
            }
            return false;
      }

      void printTrie(string word, TrieNode *r, int level)
      {
            TrieNode *crawler = r;
            if (crawler->isEOW)
            {
                  cout << "op " << word << endl;
            }
            for (int i = 0; i < 26; i++)
            {
                  if (crawler->children[i])
                  {
                        word.push_back('a' + i);
                        printTrie(word, crawler->children[i], level + 1);
                        word.pop_back();
                  }
            }
            return;
      }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
      Trie trie;

      // trie.insert("bpp");
      trie.insert("ap");
      trie.insert("b");

      // trie.insert("baby");

      //trie.printTrie("", trie.root);
      char s[20];
      trie.printTrie("", trie.root, 0);
      return 0;
}