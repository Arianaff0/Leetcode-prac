#1. take the first element, and set num to ele, nums[0], use while loop (because we are chnging the len of list, iteration is manual)
#  while ele == nums[i], increment i, if ele != nums[i]: 

#   if you find another nums[i]== ele, then incr count. 
#         while count > 2, nums.pop(i), ele = nums[i]
#   return len(nums)

# stack method, /////////////////////previous notes^^^

# starting the comparision index from 1 and count as 1, to compare to the previous index (0 when starting)
# while loop to keep track of i so it doesnt go out of range and we are manually manipulating increment of i
# if the num== previous num, increment count, else keep count the same. 
# To determine whether we increment the index, if count is not >2, we increment.
#     - cant increment right away because it could be the case that its the third same num. in which case
# pop the item and keep index there
#

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=1
        count=1

        while i< len(nums):
            if nums[i]== nums[i-1]:
                count+=1
                print(count)
            else:
                count=1

            if count > 2:
                nums.pop(i)
            else:
                i+=1
                print(i)

        return len(nums)
        