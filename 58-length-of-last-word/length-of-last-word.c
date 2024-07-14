int lengthOfLastWord(char* s) {

    int stringSize = strlen(s);
    int length = 0;
    int i = stringSize - 1;

    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    //note: and operator uses short-circuit evaluation, so switching order caused the out of bounds memory error
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
