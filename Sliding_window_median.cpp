#include<iostream> 
#include<vector> 
#include<set> 

using namespace std; 

class Solution{
public: 
      vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians; 
        multiset<int> window(nums.begin(), nums.begin()+k); 

        auto mid = next(window.begin(), k/2); 

        for(int i=k; ; ++i){
          medians.push_back(((double)(*mid) + *next(mid, k%2-1))*0.5);
          if(i==nums.size()) break; 
          window.insert(nums[i]); 
          if(nums[i]< *mid) --mid; 
          if(nums[i-k]<=*mid) ++mid; 
          window.erase(window.lower_bound(nums[i-k])); 
        }
        return medians; 
      }
};
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3 ; 
    Solution sol; 
    vector<double> res= sol.medianSlidingWindow(nums, k); 
    for(double n:res) cout << n << " , " ; 
    cout << endl; 
    
    return 0; 
}
