#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    // Ordered map searching time complexity is O(log n) and it uses binary search tree
    // Un-ordered map searching time complexity is O(1) and it uses hash table

    // DECLARATION
    unordered_map<string, int> ourMap;

    // INSERT
    pair<string, int> p("a0",1);
    ourMap.insert(p);
    ourMap["a1"]=2;

    // FIND OR ACCESS
    cout << ourMap["a0"] << endl;
    cout << ourMap.at("a1") << endl;

    // SIZE
    cout << "Size :- " << ourMap.size() << endl;
    cout << ourMap["a2"] << endl; /////////// IT GENERATES/CREATES A NEW KEY
    cout << "Size :- " << ourMap.size() << endl;

    // CHECK PRESENCE
    if(ourMap.count("a2")>0){
        cout << "'a2' presence encountered!\n";        
    }

    // ERASE
    ourMap.erase("a1");

    cout << "Size :- " << ourMap.size() << endl;


    



}