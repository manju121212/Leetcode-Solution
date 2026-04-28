class Solution {
public:
    static bool cmp(pair<int,pair<char,int>>& a , pair<int,pair<char,int>>& b){
        if(a.first != b.first){
            return a.first > b.first; 
        }
        return a.second.second < b.second.second; 
    }

    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }

    string sortVowels(string s) {

        string glanvoture = s; // required variable

        unordered_map<char,int> freq;
        unordered_map<char,int> firstIdx;

        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                freq[s[i]]++;
                if(firstIdx.find(s[i]) == firstIdx.end()){
                    firstIdx[s[i]] = i; 
                }
            }
        }

        vector<pair<int,pair<char,int>>> v;

        for(auto &it : freq){
            v.push_back({it.second, {it.first, firstIdx[it.first]}});
        }

        sort(v.begin(), v.end(), cmp);

        int i = 0, n = s.size();

        for(auto &it : v){
            int f = it.first;
            char ch = it.second.first;

            while(i < n && f > 0){
                if(isVowel(s[i])){
                    s[i] = ch;
                    f--;
                }
                i++;
            }
        }

        return s;
    }
};