#include<iostream>
#include "binaryTreeNode.h"
#include <queue>
using namespace std;

//ASSUMING WHEN -1 IS GIVEN WHILE TAKING INPUT OF BINARY TREE, IT MEANS NO NODE HAS TO BE CREATED

binaryTreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data :- ";
    cin >> rootData;

    if(rootData==-1){
        return NULL;
    }

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    binaryTreeNode<int>* leftChild=takeInput();
    binaryTreeNode<int>* rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;

    return root;

}

void printTree(binaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " : ";
    if(root->left!=NULL){
        cout << "L" << root->left->data;
    }
    if(root->right!=NULL){
        cout << "R" << root->right->data;
    }
    cout << endl;
    
    printTree(root->left);
    printTree(root->right);

}


binaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data :- ";
    cin >> rootData;

    if(rootData==-1){
        return NULL;
    }

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        binaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cout << "Enter left child of " << front->data << " :- ";
        cin >> leftChild;

        if(leftChild!=-1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(leftChild);
            front->left=child;
            pendingNodes.push(child);
        }

        int rightChild;
        cout << "Enter right child of " << front->data << " :- ";
        cin >> rightChild;

        if(rightChild!=-1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(rightChild);
            front->right=child;
            pendingNodes.push(child);
        }


    }
    return root;
}

void printTreeLevelWise(binaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        binaryTreeNode<int>* front=pendingNodes.front();
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

int countNodes(binaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    // int ans=1;
    // ans+=countNodes(root->left);
    // ans+=countNodes(root->right);

    // return ans;

    return 1+countNodes(root->left)+countNodes(root->right);
}

void inOrder(binaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(binaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(binaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

binaryTreeNode<int>* constructTreeFromPreOrderInOrder(int pre[], int in[], int preStart, int preEnd, int inStart, int inEnd){
    if(preStart>preEnd || inStart>inEnd){
        return NULL;
    }

    int rootData=pre[preStart];
    int inRootIndex=-1;
    for(int i=inStart; i<=inEnd; i++){
        if(in[i]==rootData){
            inRootIndex=i;
            break;
        }
    }

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);

    root->left = constructTreeFromPreOrderInOrder(pre, in, preStart+1, preStart+(inRootIndex-inStart) , inStart, inRootIndex-1);
    root->right = constructTreeFromPreOrderInOrder(pre, in, preStart+(inRootIndex-inStart)+1 , preEnd, inRootIndex+1, inEnd);


    return root;

}

binaryTreeNode<int>* constructTree(int pre[], int in[], int size){
    return constructTreeFromPreOrderInOrder(pre, in, 0, size-1, 0, size-1);
}


int heightOfBinaryTree(binaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    return 1+max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
}

pair<int, int> diameterOfBinaryTree(binaryTreeNode<int>* root){

    if(root==NULL){
        pair<int, int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int, int> leftAns=diameterOfBinaryTree(root->left);
    pair<int, int> rightAns=diameterOfBinaryTree(root->right);

    int ld=leftAns.second;
    int lh=leftAns.first;
    int rd=rightAns.second;
    int rh=rightAns.first;

    int height=1+max(lh,rh);
    int diameter=max(rh+lh, max(ld, rd));
    pair<int, int> ans;
    ans.first=height;
    ans.second=diameter;

    return ans;
}

int main(){

    // Taking input of binary tree recursively and printing it
    // binaryTreeNode<int>* root=takeInput();
    // printTree(root);

    //Taking input of binary tree level wise and printing it level wise
    binaryTreeNode<int>* root=takeInputLevelWise();
    printTreeLevelWise(root);

    //Total number of nodes
    cout << "Total number of nodes :- " << countNodes(root) << endl;


    //Pre-order Traversal
    cout << "Pre-order Traversal of tree is :- ";
    preOrder(root);
    cout << endl;

    //In-order Traversal
    cout << "In-order Traversal of tree is :- ";
    inOrder(root);
    cout << endl;

    //Post-order Traversal
    cout << "Post-order Traversal of tree is :- ";
    postOrder(root);
    cout << endl;


    cout << "Height of Binary tree is :- " << heightOfBinaryTree(root) << endl;

    //Diameter of Binary Tree
    pair<int, int> ansHeightDiameter=diameterOfBinaryTree(root);
    cout << "Height : " << ansHeightDiameter.first << " Diameter : " << ansHeightDiameter.second << endl;



    // Construction of binary tree using pre-order and in-order traversal
    // int pre[5]={1,2,4,5,3};
    // int in[5]={4,2,5,1,3};

    /*
    int in[9]={4,2,5,1,8,6,9,3,7};
    int pre[9]={1,2,4,5,3,6,8,9,7};
    binaryTreeNode<int>* myTree = constructTree(pre, in, 9);
    printTreeLevelWise(myTree);





    delete myTree;
    */
    delete root;



}