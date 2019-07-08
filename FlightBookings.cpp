/** https://leetcode.com/problems/corporate-flight-bookings : O(n) approach **/
#include<iostream>
#include<vector>
using namespace std;
vector<int> corpFlightBookings(vector<vector<int>> bookings, int n)
{
   vector<int> p(n+1,0);

   for(int i=0;i<bookings.size();i++)
    {
       p[bookings[i][0]-1]+=bookings[i][2];
       p[bookings[i][1]]-=bookings[i][2];
    }

    for(int i=1;i<n;i++){
            p[i]+=p[i-1];
    }
    p.pop_back();
    return p;
}
int main(){
    vector<int> s =corpFlightBookings({{1,2,10},{2,3,20},{2,5,25}},5);
    for(int k:s){
        cout<<k<<" ";
    }

    return 0;
}

/** In this approach , i learnt how we can save the time ie operations by simply applying basic mathematics that helped us to reduce the time complexity from
  O(n^2) to O(n).**/
