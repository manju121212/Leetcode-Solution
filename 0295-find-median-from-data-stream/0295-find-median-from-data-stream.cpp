class MedianFinder {
public:
    priority_queue<int>smaller;
    priority_queue<int,vector<int>,greater<int>>greater;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         if(smaller.empty()){
             smaller.push(num);
         }

         if(smaller.size()>greater.size()){
               if(smaller.top()<num){
                    int ele = smaller.top();
                    smaller.pop();
                    greater.push(ele);
                    smaller.push(num);
               }
               else{
                greater.push(num);
               }
         }
         else{
             
             if(greater.top()>num){
                int ele = greater.top();
                greater.pop();
                smaller.push(ele);
                greater.push(num);
             }
             else{
                smaller.push(num);
             }
         }
    }
    
    double findMedian() {
        return double(smaller.top() + greater.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */