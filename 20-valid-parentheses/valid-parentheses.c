typedef struct {
    char *array2;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity) {
    if (capacity<=0) {
        printf("%d\n", capacity);
        return NULL;
    }
    Stack *stack = malloc(sizeof(Stack));
    if (stack==NULL) {
        return NULL;
    }
    stack->array2 = malloc(sizeof(char)*(capacity)+1);
    if (stack->array2 == NULL) {
        free(stack);
        return NULL;
    }
    // printf("%d\n", capacity);
    stack->capacity = capacity;
    stack->size=0;
    return stack;
}

bool push(Stack *stack, char item) {
    if (stack->size >= stack->capacity) {
        fprintf(stderr, "over capacity of stack yoyoy\n");
        return false;
    }
    stack->array2[stack->size]=item;
    stack->size++;
    return true;
}

char pop(Stack *stack) {
    if (stack->size <= 0) {
        fprintf(stderr, "nothing to pop\n");
        return false;
    }
    char popped = stack->array2[stack->size-1];
    stack->size--;
    return popped;
}
char peek(Stack *stack) {
    return stack->array2[stack->size-1];
}

bool isValid(char* s) {
    if (s ==NULL) {
        return false;
    }
    Stack *stack = create_stack(strlen(s)+1);

    for (int i=0; i<strlen(s); i++) {
        if (s[i]=='('|| s[i]=='['||s[i]=='{') {
            printf("first, %c\n", s[i]);
            push(stack, s[i]);
            printf("second, %c\n", s[i]);
        }
        else if (s[i]==')'|| s[i]=='}'||s[i]==']') {
            if (stack->size ==0) {
                printf("test1");
                return false;
            }
            if ((s[i]==')'&& peek(stack)!='(') ||
            (s[i]==']'&& peek(stack)!='[') ||
            (s[i]=='}'&& peek(stack)!='{')) {
                printf("Comparison result: %s\n", peek(stack) != '(' ? "true" : "false");
                printf("third, %c\n", s[i]);
                printf("fourth, %c\n", s[i]);
                printf("test2");
                return false;
            } 
            pop(stack); 
        }
    }
    if (stack->size != 0) {
        printf("test3");
        return false;
    }
    return true;
}
    // int capacity =(sizeof(char)*strlen(s)/2)*4; //in bytes because we will be comparing it to sizeof the char pointer.
    // int fla =0;
    // char *array = (char*)malloc(sizeof(char)*strlen(s)/2+1);
    // char *array2 = (char*)malloc(sizeof(char)*strlen(s)/2+1);
    // // printf("%d\n", sizeof(array2));
    // strncpy(array, s+0, strlen(s)/2-0);
    // array[strlen(s)/2] ='\0';
    // // printf("%s,\n", array); 
    // strncpy(array2, s+strlen(s)/2, strlen(s)-strlen(s)/2);
    // array2[strlen(s)-strlen(s)/2] ='\0';
    // // printf("%s,\n", array2);

    // char *ptr = array2;
    // char *endptr= array + strlen(s)/2-1;


    // for (int i=0;i<sizeof(array2); i++) {
    //     char res = push(array2[i]);
    //     printf("%c\n", res);
    // }
    // for (int i=sizeof(array2)-1; i>=0;i-- ) {
    //     pop(array2[i]);
    //     printf("popped: %c\n",array2[i]);
    // }
    // int i=0; I was trying to split the array into two parts and compare the two but realized, if it's the same then it should be false because an open bracket have to coreespond to a closed, not open again. so now Im going to try to use a stack data struture and pop the last element in the array2 and compare with array[i], where i is incrementing, iterating through all of array[i], implementing false and true based on what the comparision results are.

    //     strncpy(array, s+0, strlen(s)/2-0);
    //     printf("%s,\n", array); 
    //     strncpy(array2, s+strlen(s)/2, strlen(s)-strlen(s)/2);
    //     printf("%s,\n", array2);
    //     if (strcmp(array, array2)==false) {
    //         fla =1;
    //     }
//         if (fla=1) {
//             int i=0;
//             while (s[i] != '\0') {
//                 switch(s[i]) {
//                     case '(':
//                         if (s[i+1]!= ')') {
//                             // check=false;
//                             return false;
//                             printf("%d\n", false);
//                         }
//                         else {
//                             i++;
//                         }
//                         break;
//                     case '{':
//                         if (s[i+1]!= '}') {
//                             // check=false;
//                             return false;
//                             printf("%d\n", false);
//                         }
//                         else {
//                             i++;
//                         }
//                         break;
//                     case '[':
//                         if (s[i+1]!= ']') {
//                             // check=false;
//                             return false;
//                             printf("%d\n", false);
//                         }
//                         else {
//                             i++;
//                         }
//                         break;
//                     default:
//                         return true;
//                 }
//         }
//         return false;
//         }
// }

