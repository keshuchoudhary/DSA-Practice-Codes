#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(){
            data=0;
            next=NULL;
        }

        ~node(){
            delete next;
        }
};

node* pushNode(node* head, int d){

    node* newNode=new node;
    newNode->data=d;
    if(head==NULL){
        head=newNode;
    }
    else{
        node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;

}

void printLinkList(node* head){

    if(head==NULL){
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

int lengthOfLinkList(node* head){
    int length=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}

int midpointOfLinkList(node* head){
    // Assuming length of link list is atleast 1
    // If length of link list is even then returning 1st mid node, else in case of odd returning the only mid node
    int length=lengthOfLinkList(head);
    int traverse=0;
    if(length%2==0){
        traverse=(length/2)-1;
    }
    else{
        traverse=length/2;
    }

    //If length of link list is 0
    if(length==0){
        return -1;
    }
    else{
        node* temp=head;
        while(traverse--){
            temp=temp->next;
        }
        return temp->data;
    }

}

int midpointOfLinkList2(node* head){
    // Assuming length of link list is atleast 1

    //If length of link list is 0
    if(head==NULL){
        return -1;
    }
    node *slow=head, *fast=head->next;


    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    int midValue = slow->data;

    return midValue;


}

node* mergeTwoSortedLinkList(node* head1, node* head2){
    node* head=NULL, *tail=NULL;
    while(head1!=NULL && head2!=NULL){
        // cout << "chala\n";

        node* newNode=new node;
        if(head==NULL){
            head=newNode;
        }

        // cout << head1->data << "\t" << head2->data << "\t";

        if(head1->data <= head2->data){
            newNode->data=head1->data;
            if(tail!=NULL){
                tail->next=newNode;
            }
            tail=newNode;
            head1=head1->next;
        }
        else{
            newNode->data=head2->data;
            if(tail!=NULL){
                tail->next=newNode;
            }
            tail=newNode;
            head2=head2->next;
        }

        // cout << head1 << "\t" << head2 << "\t"  << newNode->data << "\n";

    }
    // cout << "chala\n";
    while(head1!=NULL){
        node* newNode=new node;
        newNode->data=head1->data;
        if(tail!=NULL){
            tail->next=newNode;
        }
        tail=newNode;
        head1=head1->next;
    }
    while(head2!=NULL){
        node* newNode=new node;
        newNode->data=head2->data;
        if(tail!=NULL){
            tail->next=newNode;
        }
        tail=newNode;
        head2=head2->next;
    }

    return head;
}

node* reverseLinkListIteratively(node* head){
    node* temp=head, *prev=NULL;
    while(temp!=NULL){
        if(temp->next==NULL){
            temp->next=prev;
            break;
        }
        else{
            node* extra=temp->next;
            temp->next=prev;
            prev=temp;
            temp=extra;
        }
        // cout << temp->data << "\t";
    }
    // prev->next->next=prev;
    head=temp;
    return temp;
}

node* reverseLinkList_1(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* smallAnswer = reverseLinkList_1(head->next);

    node* temp=smallAnswer;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=head;
    head->next=NULL;

    return smallAnswer;

}

class pairNode{
    public:
        node* head;
        node* tail;
};

pairNode reverseLinkList_2(node* head){


    if(head==NULL || head->next==NULL){
        pairNode ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }

    pairNode smallAnswer = reverseLinkList_2(head->next);

    smallAnswer.tail->next=head;
    head->next=NULL;
    smallAnswer.tail=head;

    return smallAnswer;
}

node* reverseLinkList_2_call(node* head){
    return reverseLinkList_2(head).head;
}

node* reverseLinkList_3(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* smallAnswer = reverseLinkList_3(head->next);

    node* tail=head->next;
    tail->next=head;
    head->next=NULL;

    return smallAnswer;


}



int main(){

    //Created link list
    node* head=NULL;
    for(int i=0; i<=100; i=i+10){
        //Pushing/Inserting nodes at the end
        head=pushNode(head, i);
    }
    //Printing link list
    printLinkList(head);
    cout << "Length of link list is :- " << lengthOfLinkList(head) << endl;
    cout << "Mid point of link list is :- " << midpointOfLinkList(head) << endl;
    // cout << "Mid point of link list is :- " << midpointOfLinkList2(head) << endl;

    node* head2=NULL;
    for(int i=5; i<100; i=i+10){
        head2=pushNode(head2,i);
    }
    // printLinkList(head2);

    //Merging two sorted link list
    node* newHead=mergeTwoSortedLinkList(head2,head);
    cout << "Merged sorted link list is :- "; 
    printLinkList(newHead);

    //Reverse a link list
    // head2=reverseLinkListIteratively(head2);
    // head2=reverseLinkList_1(head2);
    // head2=reverseLinkList_2_call(head2);
    head2=reverseLinkList_3(head2);
    cout << "Reversed link list is :- ";
    printLinkList(head2);



    
    delete head2;
    delete head;



}