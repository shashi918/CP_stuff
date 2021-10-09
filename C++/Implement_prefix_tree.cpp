// Implement Prefix tree

#include <bits/stdc++.h>
#include <cstddef>
#include <string>

using namespace std;

class TrieNode {
 public:
  bool is_word;
  TrieNode* children[26];
  TrieNode() {
    is_word = false;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }
};

class Trie {
  public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    int len = word.length();
    int k = 0;
    TrieNode* curr = root;
    for (int i = 0; i < len; i++) {
      k = word[i] - 'a';
      if (curr->children[k] == NULL) {
        curr->children[k] = new TrieNode();
      }
      curr = curr->children[k];
    }
    curr->is_word = true;
  }

  bool search(string word) {
    int len = word.length();
    int k = 0;
    TrieNode* curr = root;
    for (int i = 0; i < len; i++) {
      k = word[i] - 'a';
      curr = curr->children[k];
      if (curr == NULL)
        return false;
    }
    return curr->is_word;
  }

  bool startsWith(string word) {
    int len = word.length();
    int k = 0;
    TrieNode* curr = root;
    for (int i = 0; i < len; i++) {
      k = word[i] - 'a';
      curr = curr->children[k];
      if (curr == NULL)
        return false;
    }
    return true;
  }
 private:
  TrieNode* root;
};



int main() {
  Trie* trie = new Trie();
  trie->insert("apple");
  cout << trie->search("apple");
  cout << trie->search("app");
  cout << trie->startsWith("app");
  trie->insert("app");
  cout << trie->search("app");
}