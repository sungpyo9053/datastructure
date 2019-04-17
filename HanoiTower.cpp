#include <iostream>

using namespace std;

void HanoiTowerMove(int num, char from, char by, char to){
   
    
    if (num ==1){
        cout<<"원반1을"<<from<<"에서"<<to<<"이동"<<endl;
        

    }
    else
      {   
        
        HanoiTowerMove(num-1,from,to,by);
        cout<<"원반"<<num<<"을"<<from<<"에서"<<to<<"로이동"<<endl;
        HanoiTowerMove(num-1,by,from,to);
    }
}

int main(){
    HanoiTowerMove(4,'A','B','C');
    return 0;
}
