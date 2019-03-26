#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#define CH 50

using namespace std;

struct term{
  string c;
  double value;
  double area;
  double result;
};

int main(){
    
    cout.setf(ios::fixed);
    cout.precision(2);

    ifstream infile;
    infile.open("hw2.txt");
    string s1 = "triangle";
    string s2 = "rectangle";
    string s3 = "circle";
    
    term A[CH];

    for (int i = 0; i<7; i++){
        infile >> A[i].c;

        if (s1.compare(A[i].c)==0){
            infile >>A[i].value >> A[i].area;
            A[i].result = (A[i].value*A[i].area)*0.5;
        }
        
        else if(s2.compare(A[i].c)==0){
            infile >> A[i].value >>A[i].area;
            A[i].result = A[i].value * A[i].area;
        }
        else if(s3.compare(A[i].c)==0){
            infile >> A[i].value;
            A[i].result = A[i].value *A[i].value;
        }
    }   

    for(int i =0; i<7; i++){
    cout<<A[i].c<<" "<<A[i].value<<" "<<A[i].area<<"     "<<A[i].result<<endl;
   
}

}
