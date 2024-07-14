int removeDuplicates(int* nums, int numsSize) {
    int *temp = nums;
    int indexk = 1;

    if (numsSize == 1) {
        return numsSize;
    }

    while (indexk < numsSize) {
        if (nums[indexk]==*temp) {
            printf("yo\n");
            for (int i= indexk; i <numsSize-1; i++) {
                nums[i]= nums[i+1];
            }
            numsSize--;
        }
        else {
            indexk++;
            temp++;
        }
    }

    return numsSize;
    
}