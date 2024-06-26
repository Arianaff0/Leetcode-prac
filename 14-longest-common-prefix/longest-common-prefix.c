char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize ==0) {
        return "";
    }

    //first, I'm space for an array with the size of strlen of the first string +1 for null terminator. This is to store the first string in strs. Later as seen, strcpy...I know the longest prefix cant be bigger than the first string in the strs array so we allocate the array for that by strlen of the first string in strs. 
    char *copy_ptr = (char*)malloc(sizeof(char)* (strlen(strs[0])+1));
    if (copy_ptr == NULL) {
        printf("memory alloc error\n");
        exit(1);
    }
    char *LongestPrefix_ptr = (char*)malloc(sizeof(char)* (strlen(strs[0])+1));
    if (LongestPrefix_ptr == NULL) {
        printf("memory alloc error\n");
        exit(1);
    }
        //then, I want to get length for the first string in copy_ptr, I'm using this as a base to compare with the next few strings in the original array.
    int length = strlen(strs[0]);
    strcpy(copy_ptr, strs[0]);

    if (strsSize == 1) {
        LongestPrefix_ptr=copy_ptr;
        return LongestPrefix_ptr;
    }
    
    //so now the copy_ptr holds the first string in the strs array. Now for each follwing string in strs array, we compare each char to each char in the copy_ptr array.
    else {
        for (int string=1; string<strsSize; string++) {
            printf("strs strlen: %d\nlength of strcopy: %d\n", strlen(strs[string]), length);
            //this is so you only compare each char upto the last char of the smallest string.
            if (strlen(strs[string])< length) {
                length = strlen(strs[string]);
            }
            for (int chara=0; chara < length; chara++) {
                //if the chars are the same, we put them in longestPrefix_ptr array.
                if (copy_ptr[chara]== strs[string][chara]) {
                    LongestPrefix_ptr[chara]= copy_ptr[chara];
                }
                else {
                    LongestPrefix_ptr[chara]='\0';
                    length = chara;
                    break;
                }
            }
            
            LongestPrefix_ptr[length]='\0';

        }
    //return the longestPrefix
        
    }
    free(copy_ptr);
    return LongestPrefix_ptr;
    free(LongestPrefix_ptr);
}