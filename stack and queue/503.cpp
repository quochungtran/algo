class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res (nums.size());

        if (nums.empty() )
        {
            return res;
        }
        
        
        
        stack<int> stack;
        
        for (int i = nums.size()*2; i >= 0 ; --i)
        {
           while(!stack.empty() && nums[i % nums.size()] >= nums[stack.top()] )
           {
               stack.pop();
           }    
           
           if (!stack.empty())
           {
               res[i%nums.size()] = nums[stack.top()];
           }
           else
           {
               res[i % nums.size()] =  -1 ;    
           } 
           stack.push(i % nums.size());
        
        }
        
        
        
        return res ;
    }
};