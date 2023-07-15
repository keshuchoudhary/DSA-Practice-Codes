#include<iostream>
using namespace std;

class polynomial{

    int* degreeCoefficient;
    int capacity;

    public:
        polynomial(){
            capacity=5;
            degreeCoefficient = new int[capacity];
            for(int i=0; i<capacity; i++){
                degreeCoefficient[i]=0;
            }
        }

        polynomial(polynomial const &obj){
            capacity=obj.capacity;
            degreeCoefficient = new int[capacity];
            
            for(int i=0; i<capacity; i++){
                degreeCoefficient[i]=obj.degreeCoefficient[i];
            }
        }

        void setCoefficient(int degree, int coefficient){
            if(degree<capacity){
                degreeCoefficient[degree]=coefficient;
            }
            else{
                int* newDegreeCoefficient = new int[degree+1];
                for(int i=capacity; i<degree+1; i++){
                    newDegreeCoefficient[i]=0;
                }
                for(int i=0; i<capacity; i++){
                    newDegreeCoefficient[i]=degreeCoefficient[i];
                }
                newDegreeCoefficient[degree]=coefficient;
                delete []degreeCoefficient;
                degreeCoefficient=newDegreeCoefficient;
                capacity=degree+1;
            }
        }


        polynomial operator=(polynomial const &obj){
            degreeCoefficient = new int[obj.capacity];
            capacity=obj.capacity;
            
            for(int i=0; i<capacity; i++){
                degreeCoefficient[i]=obj.degreeCoefficient[i];
            }
        }

        void print(){
            for(int i=0; i<capacity; i++){
                if(degreeCoefficient[i]==0){
                    continue;
                }
                else{
                    cout << degreeCoefficient[i] << "x" << i << " ";
                }
            }
            cout << endl;
        }

        polynomial operator+(polynomial const &obj){
            polynomial p;
            if(this->capacity == obj.capacity){
                for(int i=0; i<obj.capacity; i++){
                    p.setCoefficient(i,this->degreeCoefficient[i]+obj.degreeCoefficient[i]);
                }
            }
            else if(this->capacity > obj.capacity){
                for(int i=0; i<this->capacity; i++){
                    if(i>=obj.capacity){
                        p.setCoefficient(i,this->degreeCoefficient[i]);
                    }
                    else{
                        p.setCoefficient(i,this->degreeCoefficient[i]+obj.degreeCoefficient[i]);
                    }
                }
            }
            else if(obj.capacity > this->capacity){
                for(int i=0; i<obj.capacity; i++){
                    if(i>=this->capacity){
                        p.setCoefficient(i,obj.degreeCoefficient[i]);
                    }
                    else{
                        p.setCoefficient(i,this->degreeCoefficient[i]+obj.degreeCoefficient[i]);
                    }
                }
            }
            return p;
        }




};