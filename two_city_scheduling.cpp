/*

There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000

*/

class Solution {
public:
    int size;
    /*int util(const vector<vector<int>> &costs,int i,int a,int b) {
        if (i == size) return 0;
        else if (a == 0) {
            return costs[i][1] + util(costs,i+1,a,b-1);
        } else if (b == 0) {
            return costs[i][0] + util(costs,i+1,a-1,b);
        } else {
            return min(costs[i][0] + util(costs,i+1,a-1,b),costs[i][1] + util(costs,i+1,a,b-1));
        }
    }*/
    int twoCitySchedCost(vector<vector<int>>& costs) {
        size = costs.size();
        //return util(costs,0,size/2,size/2);
        sort(costs.begin(),costs.end(),[](const vector<int>& a,const vector<int>& b){
           return  a[0] - a[1] < b[0] - b[1];
        });
        int result = 0;
        for (int i = 0;i < size/2;++i) {
            result += costs[i][0];
        }
        for(int i = size/2;i<size;++i) {
            result +=costs[i][1];
        }
        return result;
    }
};