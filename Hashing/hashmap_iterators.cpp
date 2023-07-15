#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string, int> mapu;
    mapu["abc"]=1;
    mapu["abc1"]=2;
    mapu["abc2"]=3;
    mapu["abc3"]=4;
    mapu["abc4"]=5;
    mapu["abc5"]=6;
    
    unordered_map<string, int>::iterator it = mapu.begin();
    while(it!=mapu.end()){
        cout << "Key :- " << it->first << ", Value :- " << it->second << endl;
        it++;
    }

    cout << "Size :- " << mapu.size() << endl;

    // FIND using iterators
    unordered_map<string, int>:: iterator it2 = mapu.find("abc4");
    mapu.erase(it2);

    cout << "Size :- " << mapu.size() << endl;

    it = mapu.begin();
    while(it!=mapu.end()){
        cout << "Key :- " << it->first << ", Value :- " << it->second << endl;
        it++;
    }

}