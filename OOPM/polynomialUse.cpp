#include<iostream>
using namespace std;
#include "polynomial.cpp"

int main(){
    int n;
    cin >> n;
    int degree1[n],coefficient1[n];
    for(int i=0; i<n; i++){
        cin >> degree1[i];
    }
    for(int i=0; i<n; i++){
        cin >> coefficient1[i];
    }

    
    int m;
    cin >> m;
    int degree2[m],coefficient2[m];
    for(int i=0; i<m; i++){
        cin >> degree2[i];
    }
    for(int i=0; i<m; i++){
        cin >> coefficient2[i];
    }



    polynomial p1,p2,p3;
    for(int i=0; i<n; i++){
        p1.setCoefficient(degree1[i],coefficient1[i]);
    }
    for(int i=0; i<m; i++){
        p2.setCoefficient(degree2[i],coefficient2[i]);
    } 

    p1.print();
    p2.print();


    p3=p2;
    p3.print();

    polynomial p4(p1);
    p4.print();

    polynomial p5=(p1+p2);
    p5.print();

}