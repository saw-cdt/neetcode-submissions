class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        let count = 0;
        for(let i =0; i<nums.length; i++) {
            for(let j = 0; j < nums.length; j++) {
                if (nums[i] === nums [j]) {
                    count = count + 1;
                }
            }
        }
        if (count > nums.length) {
            return true
        }
        else {
            return false
        }
            }
}
