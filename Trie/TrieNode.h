#include<iostream>

class TrieNode{
    public:
        char data;
        TrieNode* *children;
        bool isTerminal;

        TrieNode(char x){
            data=x;
            children=new TrieNode*[26];
            isTerminal=false;

            for(int i=0; i<26; i++){
                children[i]=NULL;
            }

        }
};