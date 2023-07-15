#include<iostream>
#include "Trie.h"
using namespace std;

int main(){
    Trie myTrie;
    myTrie.insertWord("keshav");
    myTrie.insertWord("govind");
    cout << myTrie.searchWord("govind") << endl;
    cout << myTrie.searchWord("keshav") << endl;
    cout << myTrie.searchWord("kes") << endl;

    myTrie.removeWord("keshav");
    cout << myTrie.searchWord("keshav") << endl;
    cout << myTrie.searchWord("govind") << endl;


    myTrie.insertWord("and");
    myTrie.insertWord("ant");

    myTrie.removeWord("and");
    cout << myTrie.searchWord("and") << endl;
    cout << myTrie.searchWord("ant") << endl;

}