#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;


int HighestSmaller_than_num_util(vector<int> &v, int point, int num){
    
    /*
     *Sorting not required because already 
     *pushing in greatest first order.
     */
    
    //sort(v.begin(),v.end());
    
    int idx = v.back();
    
    /*
      Find out the highest number
      smaller than point
     */
    
    for(int i=0; i < v.size();i++){
        if((v[i] > idx) && (v[i] < point)) {
            idx = v[i];
        }
        
    }
    
    num = (num *10) + idx;
    
    /*
       Push the numbers larget than point
       and than push point followed by 
       smaller numbers
     */
    
    for(int i =0; i < (int)v.size();i++){
    
        if(v[i] > point) num = (num *10) + v[i];
        
        else {
            if(point){
                num = num*10 + point;
                point = 0;
            }
            else num = num*10 + v[i];
        
        }

    }

    return num;
}

int HighestSmaller_than_num(int num){
    
    vector<int> v;

    int smallest = num %10;
    v.push_back(smallest);
    
    int point;
    num /= 10;
    
    
    while((num % 10) < smallest){
        v.push_back(num % 10);
        smallest = num %10;
        num /= 10;
        
    }
    
    if(num) {
       point = num %10;
       num /= 10;
       return HighestSmaller_than_num_util(v,point,num);
    }

    return -1;

}


int main(){

    cout<<HighestSmaller_than_num(97248)<<endl;

return 0;
}
