#include<iostream>
#include "bst.h"
#include "binarySearchTree.h"
using namespace std;

int main(){
    binarySearchTree b;
    b.insert(50);
    b.insert(25);
    b.insert(75);
    b.insert(10);
    b.insert(90);
    b.insert(60);
    b.insert(40);

    b.printTree();

    cout << endl;

    b.deleteData(60);
    b.deleteData(5);
    b.printTree();

    cout << endl;

    b.deleteData(50);
    b.printTree();

}