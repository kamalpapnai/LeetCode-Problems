/**

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].



Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1


Constraints:

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9

**/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        int s=dominoes.size();
        map<int,int> m;
        int c=0;

        for(vector<int> k:dominoes)
        {
            int key  = min(k[0],k[1])*10+max(k[0],k[1]);
            m[key]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            int m = it->second;
            if(it->second>=2)
            {
                c+=(m *(m-1))/2;
            }
        }
        return c;
}
int main()
{
    vector<vector<int> > s={{1,2},{2,1},{3,4},{5,6}};
    cout<<numEquivDominoPairs(s);
}
