#include <iostream>
#include <bits/stdc++.h>
// Must include "bst.h" file wherever you want to use
// #include "bst.h"
using namespace std;

class binarySearchTree{

    bstNode<int>* root;

    public:
        binarySearchTree(){
            root=NULL;
        }

        ~binarySearchTree(){
            delete root;
        }

    private:
        bool hasData(int data, bstNode<int>* node){
            if(node==NULL){
                return false;
            }
            if(node->data==data){
                return true;
            }
            else if(node->data>data){
                return hasData(data, node->left);
            }
            else{
                return hasData(data, node->right);
            }
        }

        bstNode<int>* insert(int data, bstNode<int>* node){
            if(node==NULL){
                bstNode<int>* newNode=new bstNode<int>(data);
                return newNode;
            }
            if(node->data>data){
                node->left=insert(data, node->left);
                return node;
            }
            else{
                node->right=insert(data, node->right);
                return node;
            }
        }

        int maximum(bstNode<int>* node){
            if(node==NULL){
                return INT_MIN;
            }

            return max(node->data, max(maximum(node->left), maximum(node->right)));
        }

        int minimum(bstNode<int>* node){
            if(node==NULL){
                return INT_MAX;
            }

            return min(node->data, min(minimum(node->left), minimum(node->right)));
        }

        bstNode<int>* deleteData(int data, bstNode<int>* node){
            if(node==NULL){
                return NULL;
            }

            if(node->data>data){
                node->left = deleteData(data, node->left);
                return node;
            }
            else if(node->data<data){
                node->right = deleteData(data, node->right);
                return node;
            }
            else if(node->data==data){
                if(node->left==NULL && node->right==NULL){
                    delete node;
                    return NULL;
                }
                else if(node->left==NULL || node->right==NULL){
                    if(node->left!=NULL){
                        bstNode<int>* temp=node->left;
                        node->left=NULL;
                        delete node;
                        return temp;
                    }
                    else if(node->right!=NULL){
                        bstNode<int>* temp=node->right;
                        node->right=NULL;
                        delete node;
                        return temp;
                    }
                }
                else if(node->left!=NULL && node->right!=NULL){
                    // One possible way of replacement for the root node is the largest element in the left subtree of the root node
                    int leftLargestElement=maximum(node->left);
                    node->data=leftLargestElement;
                    node->left = deleteData(leftLargestElement, node->left);
                    return node;


                    // Another way of replacement for the root node is the smallest element in the right subtree of the root node
                    // int rightSmallestElement=minimum(node->right);
                    // node->data=rightSmallestElement;
                    // node->right = deleteData(rightSmallestElement, node->right);
                    // return node;

                }
            }

        }


        void printTreeLevelWise(bstNode<int>* node){
            if(node==NULL){
                return;
            }
            queue<bstNode<int>*> pendingNodes;
            pendingNodes.push(node);
            while(pendingNodes.size()!=0){
                bstNode<int>* front=pendingNodes.front();
                pendingNodes.pop();

                cout << front-> data << " : ";
                if(front->left!=NULL){
                    cout << "L" << front->left->data;
                    pendingNodes.push(front->left);
                }
                if(front->right!=NULL){
                    cout << "R" << front->right->data;
                    pendingNodes.push(front->right);
                }
                cout << endl;

            }
        }


    public:
        bool hasData(int data){
            return hasData(data, root);
        }

        void insert(int data){
            root=insert(data,root);
        }

        void deleteData(int data){
            root=deleteData(data, root);
        }

        void printTree(){
            printTreeLevelWise(root);
        }


};