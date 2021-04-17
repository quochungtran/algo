class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> new_nums;
        vector<int> array ; 
        int index = 0;
        int taille = nums[0].size() * nums.size();
        
         if (r*c != taille || nums.size() == 0)
             return nums;
        
        for (vector<int> item : nums)
        {
            for (int i : item)
            {
                array.push_back(i);
            }
        }
        
      
        for (int i = 0; i < r; i++)
        {
            vector<int> temp ;
            for (int j = 0 ; j < c ; j++)
            {
                temp.push_back(array[index]);
                // std::cout << array[index] << " ";
                index++; 
            }
            new_nums.push_back(temp);
        }
       
        return  new_nums;
    }
};