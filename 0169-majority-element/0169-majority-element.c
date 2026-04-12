int majorityElement(int* nums, int numsSize){
    int candidate;
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(count == 0){
            candidate = nums[i];
            count = 1;
        }
        else if(nums[i] == candidate){
            count += 1;
        }
        else if(nums[i] != candidate){
            count -= 1;
        }
    }
    return candidate;
}