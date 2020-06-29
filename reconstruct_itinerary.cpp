/*

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.

*/

class Solution {
    unordered_map<string,vector<string>> cache;
    vector<string> result;
    int size;
    int dfs(string key) {
        if (result.size() == size + 1) return 1;
        if (cache[key].size() == 0) return -1;
        for(int i = 0;i<cache[key].size();++i) {
            string temp = cache[key][i];
            if (cache[key][i] == "") {
                continue;
            }
            result.push_back(cache[key][i]);
            cache[key][i] = "";
            int res = dfs(temp);
            if (res == 1) return 1;
            if (res == -1) {
                result.pop_back();
                cache[key][i] = temp;
            }
        }
        return -1;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        size = tickets.size();
        for(int i =0;i<tickets.size();++i) {
            cache[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto it=cache.begin();it!=cache.end();++it) {
            sort(begin(it->second),end(it->second));
        }
        string key = "JFK";
        result.push_back("JFK");
        dfs(key);
        return result;
    }
};