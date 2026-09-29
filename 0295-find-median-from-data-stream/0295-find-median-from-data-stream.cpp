class MedianFinder {
public: 
    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int>>g;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         
         if(s.empty()){
              s.push(num);      
         }
         else if(s.size() > g.size()){
              
              if(s.top() > num){
                   int value = s.top();
                   s.pop();
                   g.push(value);
                   s.push(num);
              }
              else{
                 g.push(num);
              }
         }
         else{
              
              if(s.top() >num){
                   s.push(num);
              }
              else{
                  g.push(num);
                  int value = g.top();
                  g.pop();
                  s.push(value);
              }
         }
    }
    
    double findMedian() {
           
           int si = s.size() + g.size();
           if(si%2 == 0){
                double ans = double (s.top() + g.top())/2;
                return ans;
           }
           else{
                return s.top();
           }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */