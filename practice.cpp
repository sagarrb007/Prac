#include <vector>
#include <algorithm>
#include "iostream"
#include <stack>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include "list"
#include <sstream>
#include <iterator>
#include <queue>

using namespace std;

/*
 * RomanNumeralToInt supports Roman 
 * to numeric conversion between 0 - 500
 */

int RomanNumeralToInt(string s){
    
    unordered_map<char, int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100}};
    
    int temp;
    int ret = 0;

    stack <int> st;
    if(!s.size()) return 0;
    for(int i = 0; i<(int)s.size();i++){
        if(st.empty())st.push(m.find(s[i])->second);
        
        else {
            if(m.find(s[i])->second  > st.top()) {
                temp = st.top();
                st.pop();
                st.push(m.find(s[i])->second - temp);
            }
            else st.push(m.find(s[i])->second);
        }
    
    }
        while(!st.empty())
    {
        ret += st.top();
        st.pop();
    }
    return ret;
}

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

/*
 * firstUniqChar : Returns the first unique char
 *                 in the string. 
 * Leetcode: 387
 */

int firstUniqChar(string s) {

     int hmap[26] = {0};

     for(int i=0;i<s.length();i++)
         hmap[s[i] - 'a']++;

     for(int i=0;i<s.length();i++)
         if (hmap[s[i] - 'a'] == 1) return i;

     return -1;
}

int main(){

    cout<<HighestSmaller_than_num(97248)<<endl;
    cout<<RomanNumeralToInt("CLXXVIII");   

    return 0;
}
