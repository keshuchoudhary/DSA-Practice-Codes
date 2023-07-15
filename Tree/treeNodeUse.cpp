#include <iostream>
#include<queue>
#include "treeNode.h"
using namespace std;

treeNode<int>* takeInput(){
    cout << "Enter data :- ";
    int rootData;
    cin >> rootData;

    treeNode<int>* root=new treeNode<int>(rootData);
    cout << "Enter number of child nodes for " << rootData << " node :- ";
    int num;
    cin >> num;
    for(int i=0; i<num; i++){
        treeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout << root->data << ":- ";
    for(int i=0; i<root->children.size(); i++){
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}


treeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data :- ";
    cin >> rootData;

    treeNode<int>* root=new treeNode<int>(rootData);
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        treeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cout << "Enter the number of child nodes of " << front->data << " node :- ";
        cin >> numChild;

        for(int i=0; i<numChild; i++){
            cout << "Enter " << i << "th child of " << front->data << " node :- ";
            int childData;
            cin >> childData;

            treeNode<int>* child=new treeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }


    }

    return root;

}

void printTreeLevelWise(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<treeNode<int>*> myQueue;
    myQueue.push(root);
    while(myQueue.size()!=0){
        treeNode<int>* front= myQueue.front();
        myQueue.pop();

        cout << front->data << ":- ";
        for(int i=0; i<front->children.size(); i++){
            cout << front->children[i]->data << ", ";
            myQueue.push(front->children[i]);
        }
        cout << endl;


    }
}

int countTreeNodes(treeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int count=1;
    for(int i=0; i<root->children.size(); i++){
        count+=countTreeNodes(root->children[i]);
    }
    return count;
}

int largestNode(treeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int largest=root->data;
    for(int i=0; i<root->children.size(); i++){
        int smallAns=largestNode(root->children[i]);
        if(largest<smallAns){
            largest=smallAns;
        }
    }
    return largest;
}

int sumOfTreeNodes(treeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int sum=root->data;
    for(int i=0; i<root->children.size(); i++){
        // sum+=root->children[i]->data;
        sum+=sumOfTreeNodes(root->children[i]);
    }
    return sum;
}

int heightOfTree(treeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int height=1;
    int compHeight=0;
    for(int i=0; i<root->children.size(); i++){
        int temp=heightOfTree(root->children[i]);
        if(temp>compHeight){
            compHeight=temp;
        }
    }
    height+=compHeight;
    return height;
}

void printNodesAtLevelK(treeNode<int>* root, int k){
    if(root==NULL){
        return;
    }

    if(k==0){
        cout << root->data << ", ";
        return;
    }

    for(int i=0; i<root->children.size(); i++){
        printNodesAtLevelK(root->children[i],k-1);
    }


}

int countLeafNodes(treeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans=0;
    if(root->children.size()==0){
        ans+=1;
    }
    else{
        for(int i=0; i<root->children.size(); i++){
            ans+=countLeafNodes(root->children[i]);
        }
    }
    return ans;
}

void preOrderTraversal(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout << root->data << ", ";
    for(int i=0; i<root->children.size(); i++){
        preOrderTraversal(root->children[i]);
    }
}

void postOrderTraversal(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        postOrderTraversal(root->children[i]);
    }
    cout << root->data << ", ";
}

void deleteTree(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

int main(){
    
    // Taking input of tree recursively and printing it
    // treeNode<int>* root=takeInput();
    // printTree(root);

    treeNode<int>* root=takeInputLevelWise();
    //Level-order Traversal
    printTreeLevelWise(root);

    cout << "Total number of nodes :- " << countTreeNodes(root) << endl;
    cout << "Sum of all the nodes is :- " << sumOfTreeNodes(root) << endl;
    cout << "Height of tree is :- " << heightOfTree(root) << endl;

    //Printing nodes which are at level k
    cout << "Nodes at level 2 are :- "; 
    printNodesAtLevelK(root,2);
    cout << endl;
    cout << "Number of leaf nodes in the tree are :- " << countLeafNodes(root) << endl;


    //Largest node of the tree    
    cout << "Largest node of the tree :- " << largestNode(root) << endl;



    //Printing leaf nodes -----------NOT WORKING---------------
    // cout << "Leaf nodes of the tree are :- ";
    // printNodesAtLevelK(root,heightOfTree(root)-1),
    // cout << endl;

    //Pre-order Traversal
    cout << "Pre-order Traversal of tree is :- ";
    preOrderTraversal(root);
    cout << endl;

    //Post-order Traversal
    cout << "Post-order Traversal of tree is :- ";
    postOrderTraversal(root);
    cout << endl;

    //Deleting the whole tree (or freeing the memory of all tree nodes), via normal function which uses post-order traversal for deletion.
    // deleteTree(root);

    //Tree can also be deleted by calling the destructor of tree
    delete root;

}