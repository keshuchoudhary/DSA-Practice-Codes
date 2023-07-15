#include<iostream>
#include<string>
using namespace std;

template<typename V>
class mapNode{
    public:
        string key;
        V value;
        mapNode<V>* next;

        mapNode(string x, V y){
            key=x;
            value=y;
            next=NULL;
        }

        ~mapNode(){
            delete next;
        }
};

template<typename V>
class ourmap{
    public:
        mapNode<V>** bucket;
        int size;
        int bucketCapacity;

        ourmap(){
            bucketCapacity=5;
            size=0;
            bucket= new mapNode<V>*[bucketCapacity];

            for(int i=0; i<bucketCapacity; i++){
                bucket[i]=NULL;
            }

        }

        ~ourmap(){
            for(int i=0; i<bucketCapacity; i++){
                delete bucket[i];
            }
            delete [] bucket;
        }

    private:

        int getBucketIndex(string key){
            int hashcode=0;
            int coeff=1;

            for(int i=key.length()-1; i>=0; i--){
                hashcode+=key[i]*coeff;
                hashcode=hashcode%bucketCapacity;
                coeff*=37;
                coeff=coeff%bucketCapacity;
            }

            return hashcode%bucketCapacity;
        }

        void rehash(){
            mapNode<V>** temp=bucket;
            bucket = new mapNode<V>*[2*bucketCapacity];
            for(int i=0; i<(2*bucketCapacity); i++){
                bucket[i]=NULL;
            }
            int oldBucketCapacity=bucketCapacity;
            bucketCapacity*=2;
            size=0;

            for(int i=0; i<oldBucketCapacity; i++){
                mapNode<V>* head=temp[i];
                while(head!=NULL){
                    string key=head->key;
                    V value=head->value;
                    insert(key, value);
                    head=head->next;
                }
            }

            for(int i=0; i<oldBucketCapacity; i++){
                mapNode<V>* head=temp[i];
                delete head;
            }
            delete []temp;

        }

    public:

        int getSize(){
            return size;
        }

        void insert(string key, V value){
            int bucketIndex = getBucketIndex(key);

            mapNode<V>* head = bucket[bucketIndex];
            while(head!=NULL){
                if(head->key==key){
                    head->value=value;
                    return;
                }
                head=head->next;
            }
            head=bucket[bucketIndex];
            mapNode<V>* node=new mapNode<V>(key, value);
            node->next=head;
            bucket[bucketIndex]=node;

            size++;

            double loadFactor=float(size)/float(bucketCapacity);
            if(loadFactor>0.7){
                rehash();
            }

        }

        V getValue(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head=bucket[bucketIndex];
            while(head!=NULL){
                if(head->key==key){
                    return head->value;
                }
                else{
                    head=head->next;
                }
            }
            return 0;
        }

        V remove(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head=bucket[bucketIndex];
            mapNode<V>* prev = NULL;

            while(head!=NULL){
                if(head->key==key){
                    if(prev==NULL){
                        bucket[bucketIndex]=head->next;
                    }
                    else{
                        prev->next=head->next;
                    }
                    V value=head->value;
                    head->next=NULL;
                    delete head;
                    size--;
                    return value;
                }
                else{
                    prev=head;
                    head=head->next;
                }
            }

            return 0;
        }


        



};
