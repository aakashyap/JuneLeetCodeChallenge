/*

There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.

*/

class Solution {
    int cache[100][100][100] ={0};
    int dfs(int src,int dst,int k) {
        if (src == dst) return 0;
        if (k < 0) return 10000001;
        int _min = 10000001;
        if (cache[src][dst][k]) return cache[src][dst][k];
        for (auto& x: adj[src]) {
            _min = min(_min,x.second + dfs(x.first,dst,k-1));
        }
        cache[src][dst][k] = _min;
        return _min;
    }
public:
    vector<vector<pair<int,int>>> adj;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        adj.resize(n);
        for(auto &x:flights) {
            adj[x[0]].push_back(make_pair(x[1],x[2]));
        }
        int result = dfs(src,dst,K);
        return result >= 10000001? -1:result;
    }
};