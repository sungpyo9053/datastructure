#include <iostream>

using namespace std;

int list[] = {10,20,30,40,50,60,70,80,90,100 };

int recur_binary(int start , int end , int number){

	int mid = (start + end) / 2;	

	if( start > end) 
        return -1;

	if( list[mid] == number) 
        return mid;

	else if( list[mid] > number ) 
        return recur_binary(start , mid-1,number);

	else if( list[mid] < number ) 
        return recur_binary(mid+1 , end,number);


}

int iter_binary(int start , int end , int number){

	while( start <= end )
    {
		int mid = (start + end) / 2;
		if(list[mid] == number) 
            return mid;

		else if( list[mid] > number ) 
            end = mid-1;
		
        else if( list[mid] < number ) 
            start = mid+1;

	}

	return -1;

}

int main(){

	int input;
	int n;

	while(1){

		cout << " Enter an integer to search :  " ;
		cin >> n;
		cout << "Enter method of search: (1. Binary Search 2. Recursive binary search) : ";
		cin >> input;
		if ( input == 1){
			int result = iter_binary(0 , 9 , n);
			if( result == -1 )

				cout << n << " is NOT FOUND" << endl;
			else{
				cout << n << " is at position " << result << endl;
			}
		}

		else if( input == 2){

			int result = recur_binary(0 , 9 , n);
			if( result == -1 )
				cout << n << " is NOT FOUND" << endl;

			else{

				cout << n << " is at position " << result << endl;
			}
		}
	}
}
