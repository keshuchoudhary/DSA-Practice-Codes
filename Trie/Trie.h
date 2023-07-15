using namespace std;
#include "TrieNode.h"

class Trie{

    TrieNode *root;

    public:

        Trie(){
            root = new TrieNode('\0');
        }

    private:
        void insertWord(TrieNode* root, string word){
            // Base case
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }

            // Small Calculation
            int index=word[0]-97;
            TrieNode* child=NULL;
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                child=new TrieNode(word[0]);
                root->children[index]=child;
            }

            //Recursive call
            insertWord(child, word.substr(1));
        }


        bool searchWord(TrieNode* root, string word){
            // Base case
            if(word.length()==0){
                if(root->isTerminal==true){
                    return true;
                }
                else{
                    return false;
                }
            }

            // Small calculation
            int index=word[0]-97;
            TrieNode* child=NULL;
            if(root->children[index]!=NULL){
                child=root->children[index];
                return searchWord(child, word.substr(1));
            }
            else{
                return false;
            }

        }

        void removeWord(TrieNode* root, string word){
            
            // Base case
            if(word.length()==0){
                root->isTerminal=false;
                return;
            }

            // Small Calculation
            int index=word[0]-97;
            TrieNode* child=NULL;
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                return;
            }

            removeWord(child, word.substr(1));

            if(child->isTerminal==false){
                for(int i=0; i<26; i++){
                    if(child->children[i]!=NULL){
                        return;
                    }
                }
                delete child;
                root->children[index]=NULL;
            }




        }

    public:

        void insertWord(string word){
            insertWord(root, word);
        }

        bool searchWord(string word){
            return searchWord(root, word);
        }

        void removeWord(string word){
            removeWord(root, word);
        }


};