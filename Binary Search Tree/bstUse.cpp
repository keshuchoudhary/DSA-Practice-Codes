#include<iostream>
#include<bits/stdc++.h>
#include "bst.h"
#include <queue>
using namespace std;

//ASSUMING WHEN -1 IS GIVEN WHILE TAKING INPUT OF BINARY TREE, IT MEANS NO NODE HAS TO BE CREATED


bstNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data :- ";
    cin >> rootData;

    if(rootData==-1){
        return NULL;
    }

    bstNode<int>* root = new bstNode<int>(rootData);
    queue<bstNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        bstNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cout << "Enter left child of " << front->data << " :- ";
        cin >> leftChild;

        if(leftChild!=-1){
            bstNode<int>* child = new bstNode<int>(leftChild);
            front->left=child;
            pendingNodes.push(child);
        }

        int rightChild;
        cout << "Enter right child of " << front->data << " :- ";
        cin >> rightChild;

        if(rightChild!=-1){
            bstNode<int>* child = new bstNode<int>(rightChild);
            front->right=child;
            pendingNodes.push(child);
        }


    }
    return root;
}

void printTreeLevelWise(bstNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<bstNode<int>*> pendingNodes;
    pendingNodes.push(root);
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

int countNodes(bstNode<int>* root){
    if(root==NULL){
        return 0;
    }

    // int ans=1;
    // ans+=countNodes(root->left);
    // ans+=countNodes(root->right);

    // return ans;

    return 1+countNodes(root->left)+countNodes(root->right);
}

void inOrder(bstNode<int>* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(bstNode<int>* root){
    if(root==NULL){
        return;
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(bstNode<int>* root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bstNode<int>* constructTreeFromPreOrderInOrder(int pre[], int in[], int preStart, int preEnd, int inStart, int inEnd){
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

    bstNode<int>* root = new bstNode<int>(rootData);

    root->left = constructTreeFromPreOrderInOrder(pre, in, preStart+1, preStart+(inRootIndex-inStart) , inStart, inRootIndex-1);
    root->right = constructTreeFromPreOrderInOrder(pre, in, preStart+(inRootIndex-inStart)+1 , preEnd, inRootIndex+1, inEnd);


    return root;

}

bstNode<int>* constructTree(int pre[], int in[], int size){
    return constructTreeFromPreOrderInOrder(pre, in, 0, size-1, 0, size-1);
}


bstNode<int>* searchBST(bstNode<int>* root, int search){
    if(root==NULL){
        return NULL;
    }
    if(root->data==search){
        return root;
    }
    if(search<root->data){
        return searchBST(root->left ,search);
    }
    else{
        return searchBST(root->right,search);
    }

}

void printElementsInRange(bstNode<int>* root, int x, int y){

    if(root==NULL){
        return;
    }

    if(root->data>=x && root->data<=y){
        cout << root->data << " ";
        printElementsInRange(root->left,x,y);
        printElementsInRange(root->right,x,y);
    }
    else if(y<root->data){
        printElementsInRange(root->left,x,y);
    }
    else if(x>root->data){
        printElementsInRange(root->right,x,y);
    }
}

int maximum(bstNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}

int minimum(bstNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left),minimum(root->right)));
}


bool isBST1(bstNode<int>* root){
    if(root==NULL){
        return true;
    }
    int maximumLeft=maximum(root->left),minimumRight=minimum(root->right);
    if(root->data>maximumLeft && root->data<minimumRight){
        return (isBST1(root->left) && isBST1(root->right));
    }
    else{
        return false;
    }
}

class isBSTReturn{
    public:
        int maximum;
        int minimum;
        bool isBST;
};

isBSTReturn isBST2Helper(bstNode<int>* root){
    if(root==NULL){
        isBSTReturn output;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        output.isBST=true;
        return output;
    }
    isBSTReturn leftOutput=isBST2Helper(root->left);
    isBSTReturn rightOutput=isBST2Helper(root->right);

    int maximum,minimum;
    maximum=max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    minimum=min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    bool isBSTFinal=(root->data>leftOutput.maximum)&&(root->data<rightOutput.minimum)&&(leftOutput.isBST)&&(rightOutput.isBST);

    isBSTReturn output;
    output.maximum=maximum;
    output.minimum=minimum;
    output.isBST=isBSTFinal;

    return output;

}

bool isBST2(bstNode<int>* root){
    isBSTReturn output=isBST2Helper(root);
    return output.isBST;
}

bool isBST3(bstNode<int>* root, int min=INT_MIN, int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }
    bool isLeftOk=isBST3(root->left, min, root->data-1);
    bool isRightOk=isBST3(root->right, root->data+1, max);
    return (isLeftOk && isRightOk);
}

bstNode<int>* constructBSTFromSortedArray(int arr[], int startIndex, int endIndex){
    if(startIndex>endIndex){
        return NULL;
    }
    int midIndex=(startIndex+endIndex)/2;
    bstNode<int>* root = new bstNode<int>(arr[midIndex]);
    root->left=constructBSTFromSortedArray(arr, startIndex, midIndex-1);
    root->right=constructBSTFromSortedArray(arr, midIndex+1, endIndex);
    
    return root;
}


class LLNode{
    public:
        int data;
        LLNode* next;

        LLNode(int x){
            data=x;
            next=NULL;
        }
};

class LLNodeOutput{
    public:
        LLNode* head;
        LLNode* tail;
};

LLNodeOutput constructSortedLLFromBSTHelper(bstNode<int>* root){
    if(root==NULL){
        LLNodeOutput output;
        output.head=NULL;
        output.tail=NULL;
        return output;
    }

    LLNode* myNode=new LLNode(root->data);

    LLNodeOutput leftOutput=constructSortedLLFromBSTHelper(root->left);
    LLNodeOutput rightOutput=constructSortedLLFromBSTHelper(root->right);

    LLNodeOutput output;


    myNode->next = rightOutput.head;
    output.head=leftOutput.head;
    output.tail=rightOutput.tail;

    if(leftOutput.head==NULL){
        output.head=myNode;
    }
    else{
        leftOutput.tail->next=myNode;
    }

    if(rightOutput.head==NULL){
        output.tail=myNode;
    }

    

    // if(leftOutput.head){
    //     cout << leftOutput.head->data << "   ";
    // }
    // cout << leftOutput.head << "   `````    " << leftOutput.tail  <<endl;

    return output;

}

LLNode* constructSortedLLFromBST(bstNode<int>* root){
    return constructSortedLLFromBSTHelper(root).head;
}

void printLL(LLNode* head){
    LLNode* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

vector<int>* getRootToNodePath(bstNode<int>* root, int element){

    if(root==NULL){
        return NULL;
    }

    vector<int>* ans=NULL;
    if(root->data==element){
        ans=new vector<int>;
        ans->push_back(root->data);
    }

    else if(root->data>element){
        ans=getRootToNodePath(root->left, element);
        if(ans!=NULL){
            ans->push_back(root->data);
        }
    }
    else{
        ans=getRootToNodePath(root->right, element);
        if(ans!=NULL){
            ans->push_back(root->data);
        }
    }

    return ans;




    // Below code is of Sir but one problem is that it is navigating on both the childrens
    /*

    if(root==NULL){
        return NULL;
    }


    if(root->data==element){
        vector<int>* output=new vector<int>;
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left, element);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right, element);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
    */

}

void printVector(vector<int>* ans){
    if(ans==NULL){
        cout << "No path exist\n";
        return;
    }
    for(int i=0; i<ans->size(); i++){
        cout << ans->at(i) << " ";
    }
    cout << endl;
}

int main(){


    //Taking input of binary search tree level wise and printing it level wise
    bstNode<int>* root=takeInputLevelWise();

    if(isBST3(root)==false){
        cout << "The tree input given is not a binary search tree\n";
        exit(0);
    }

    cout << endl;
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


    //Search in BST
    int x;
    cout << "Enter the node to search in bst :- ";
    cin >> x;
    bstNode<int>* searchNode=searchBST(root,x);
    if(searchNode==NULL){
        cout << "Element " << x << " not found in BST\n";
    }
    else{
        cout << "Element " << searchNode->data << " found in BST\n";
    }

    // Printing elements of a BST between the range 'a' to 'b'
    int a,b;
    cout << "Enter x and y for printing elements in range of x and y :- ";
    cin >> a >> b;
    printElementsInRange(root,a,b);
    cout << endl;

    // Checking whether a tree is BST or not?
    cout << isBST1(root) << endl;
    cout << isBST2(root) << endl;
    cout << isBST3(root) << endl;

    // Constructing BST from a sorted array
    int sortedArray[10]={1,2,3,4,5,6,7,8,9,10};
    bstNode<int>* myTree = constructBSTFromSortedArray(sortedArray, 0, 9);
    printTreeLevelWise(myTree);

    // Constructing a Linked-list from BST
    LLNode* head=constructSortedLLFromBST(myTree);
    printLL(head);


    // Root to node path
    int z;
    cout << "Enter element to find the path of the node :- ";
    cin >> z;
    vector<int>* ans=getRootToNodePath(root, z);
    cout << "Path of the node is :- ";
    printVector(ans);


    delete myTree;
    delete ans;
    delete root;



}