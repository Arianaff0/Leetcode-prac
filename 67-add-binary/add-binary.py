#1. iterate through entire string, 
#2. sum_a means decimal value of binary, 
#     -if a[i]==1, we add up base 2 to the power of {value} dependent on the index in the iteration
#3. add to the sum_a. print it to check (Repeat for str b) store in total.

# Change from dec to binary
#4. divide by 2, ans is pow(2, ans), so in str, 


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        sum_a =0
        sum_b =0
        total =0
        for i in range(len(a)):
            if a[i]=='1':
                sum_a += pow(2, len(a)-1-i)

        for i in range(len(b)):
            if b[i]=='1':
                sum_b += pow(2, len(b)-1-i)
        total = sum_a+ sum_b
        bin_string = bin(total)
        bin_digits = bin_string[2:]
        return bin_digits


