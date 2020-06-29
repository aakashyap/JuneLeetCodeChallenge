/*

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.

*/

#define alpha 26
class Solution {
    int prime = 10000001;
    vector<int> power;
    string rabinKarp(string S,int len) {
        if(len == 0) return "";
        int size = S.size();
        unordered_map<int,vector<int>> hash;
        int curr = 0;
        for (int i = 0;i< len;++i) {
            curr = (alpha*curr + S[i] - 'a') % prime;
        }
        hash[curr] = {0};
        for(int i = len;i<size;++i) {
            bool flag = true;
            curr = (alpha*((curr - (power[len-1]*(S[i-len]-'a')))%prime + prime) + S[i]-'a') % prime;
            if (hash.find(curr) == hash.end()) {
                hash[curr] = {i-len+1};
            } else {
                for (auto& x:hash[curr]) {
                    if (S.substr(x,len) == S.substr(i-len+1,len)) {
                        return S.substr(x,len);
                    }
                }
            }
        }
        return "";
    }
public:
    string longestDupSubstring(string S) {
        int size = S.size();
        int l = 0;
        int h = size-1;
        string result ="";
        power.resize(size);
        power[0] = 1;
        for(int i = 1;i<size;++i) {
            power[i] = (power[i-1] * alpha) % prime;
        }
        
        while (l <= h) {
            int mid = l + (h-l)/2;
            string temp = rabinKarp(S,mid);
            if (!temp.empty()) {
                if (temp.size() > result.size()) result = temp;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return result;
    }
};

/* TLE
class Solution {
    string lcs(string s1,string s2){
        int s1_ = s1.size();
        int s2_ = s2.size();
        int i =0;
        while(i != s1.size() || i != s2.size()) {
            if (s1[i] != s2[i]) {
                break;
            }
            ++i;
        }
        return s1.substr(0,i);
    }
public:
    string longestDupSubstring(string S) {
        int size = S.size();
        vector<string> cache(size);
        for(int i =0;i<size;++i) {
            cache[i] = S.substr(i,size-i);
        }
        sort(cache.begin(),cache.end());
        string result;
        for(int i = 0;i<size-1;++i) {
            string temp = lcs(cache[i],cache[i+1]);
            if (temp.size() > result.size()) {
                result = temp;
            }
        }
        return result;
    }
};
*/