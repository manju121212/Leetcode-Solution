class TopVotedCandidate {
public:
    vector<int>persons;
    vector<int>times;
    int n ;
     vector<int>curr_winner;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
         this->n = persons.size();
         this->persons = persons;
         this->times = times;
         
         unordered_map<int,int>mpp;
         int curr_ele = persons[0];
         curr_winner.assign(n,-1);
         mpp[0]++;
         curr_winner[0] = persons[0];
         for(int i = 1;i<n;i++){
               mpp[persons[i]]++;
               if(curr_ele == persons[i]){
                   curr_winner[i] = persons[i];
               }
               else{
                   if(mpp[curr_ele] > mpp[persons[i]]){ 
                       curr_winner[i] = curr_ele;
                   }
                   else {
                       curr_ele = persons[i];
                       curr_winner[i] = curr_ele;
                      
                   }
                   
               }
         }

         

    }

   
    
    
    int q(int t) {
        
          int it = upper_bound(times.begin(),times.end(),t)-times.begin()-1;
          
         
          
          return curr_winner[it];
          
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */