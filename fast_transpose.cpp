#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define MAX_COL 20

struct term{
    int row;
    int col;
    int value;
};

void fast_transpose(term a[], term b[]){
    
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i,j,num_cols =a[0].col;
    int num_terms = a[0].value;
    

    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    if (num_terms >0){
        for (i = 0; i<num_cols; i++){
            row_terms[i] =0;
        }
        for (i =1; i<= num_terms; i++){
            row_terms[a[i].col]++;
        }
        starting_pos[0] =1;
        for (i =1; i<num_cols; i++){
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        }
       
        for (i =1; i<=num_terms; i++){
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}
int main(){
    ifstream infile;
    infile.open("input.txt");
    if (infile.fail()){
        cout<<"can't open the file"<<endl;
        exit(1);
    }

    term a[MAX_COL];
    term b[MAX_COL];
    
    infile >> a[0].row >> a[0].col >> a[0].value;

    int i;
    for (i =1; i<= a[0].value; i++){
        infile >> a[i].row >> a[i].col>>a[i].value;
    }
    fast_transpose(a,b);
   
     for (i= 0; i<=b[0].value; i++){
         cout<<b[i].row<<" "<<b[i].col<<" "<<b[i].value<<endl;
     }
    return 0;
}
