#include<iostream>
#include "ourmap.h"
using namespace std;

int main(){
    ourmap<int> mapu;
    // mapu.insert("keshav",100);
    // mapu.insert("keshav1",101);
    // mapu.insert("keshav2",102);
    // mapu.insert("keshav3",103);

    // cout << mapu.getSize() << endl;

    // cout << mapu.getValue("keshav") << endl;
    // cout << mapu.remove("keshav1") << endl;
    // cout << mapu.getValue("keshav3") << endl;
    // cout << mapu.getValue("keshav1") << endl;

    // cout << mapu.getSize() << endl;

    for(int i=0; i<10; i++){
        string key="abc";
        char ch='0'+i;
        key+=ch;
        mapu.insert(key,i);
    }

    cout << "Size :- " << mapu.getSize() << endl;
    mapu.remove("abc2");
    mapu.remove("abc8");
    

    for(int i=0; i<10; i++){
        string key="abc";
        char ch='0'+i;
        key+=ch;
        cout << "Key :- " << key << ", Value :- " << mapu.getValue(key) << endl;
    }
    
    cout << "Size :- " << mapu.getSize() << endl;

}