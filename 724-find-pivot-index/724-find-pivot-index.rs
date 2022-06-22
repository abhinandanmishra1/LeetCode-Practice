impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let mut sum=0;
        let n=nums.len();
        for i in 0..n{
            sum+=nums[i];
        }
        
        let mut left=0;
        
        for i in 0..n{
            let x=nums[i];
            let right=sum-left-x;
            if(left==right) {
                return i as i32;
            }
            left+=x;
        }
        return -1;
    }
}