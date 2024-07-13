/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
* without typedef:    struct demo{

                        };
                        struct demo synth;
                        //define struct variable 

 with typedef:        typedef struct demo{

                        }; demo_t;
                        demo_t synth;  

*
*/


typedef struct {
    struct ListNode *head;
    struct ListNode *tail;
    int size;
} Queue;

struct ListNode* createListNode(int val);
Queue *create_queue(struct ListNode *list);
int size(Queue *queue);
bool is_empty(Queue *queue); 
int dequeue(Queue *queue);
void enqueue(Queue *queue, int val);
struct ListNode* queueToList(Queue *queue);

struct ListNode* createListNode(int val) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
Queue *create_queue(struct ListNode *list) {
    Queue *queue = malloc(sizeof(Queue));
    if (!queue) {
        fprintf(stderr, "oyoyoy");
        exit(1);
    }
    queue->head = list;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int size(Queue *queue) {
    return queue->size;
}

bool is_empty(Queue *queue) {
    return (queue->size==0);
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        // isValid =false;
        return -1; //or NULL Im not sure if you can return Null if return type is int
    }
    int value = queue->head->val;
    struct ListNode *tempNode= queue->head;
    queue->head = queue->head->next;
    // if (queue->head ==NULL) {
    //     queue->tail = NULL;
    // }
//     printf("%d\n", queue->head->val);
//     printf("%d\n", queue->head->next->val);


//    // delete the node after returning
//     if (queue->size == 1) {
//         free(tempNode);
//         queue->head = NULL;
//         queue->tail = NULL;
//     }
//     else {
//         free(tempNode);
//     }
    free(tempNode);
    queue->size--;
    return value;
}

void enqueue(Queue *queue, int val) {
    struct ListNode *newNode = createListNode(val);

    if (is_empty(queue)) {
        queue->tail = newNode;
        queue->head = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}

// struct ListNode* queueToList(Queue *queue) {
//     struct ListNode* head = NULL;
//     struct ListNode* tail = NULL;
//     while (!is_empty(queue)) {
//         int data = dequeue(queue);
//         struct ListNode *newNode = 
//     }
// }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    Queue *newlist1 = create_queue(list1);
    Queue *newlist2 = create_queue(list2);
    while (list1 !=NULL) {
        int val = list1->val;
        enqueue(newlist1, val);
        list1 = list1->next;
    }
    while (list2 !=NULL) {
        int val = list2->val;
        enqueue(newlist2, val);
        list2 = list2->next;
    }

    struct ListNode* mergedList = NULL;
    struct ListNode* mergedtail = NULL;

    // struct ListNode *list3 = malloc(sizeof(int)*(length_list1 + length_list2));
    if (is_empty(newlist1) && is_empty(newlist2)) {
        printf("hello\n");

        printf("hello\n");

        free(newlist1);
        free(newlist2);
        return NULL;
    }
    printf("jojo");
            if (!is_empty(newlist1)) {
        printf("blah\n");
        }
        if (!is_empty(newlist2)){
            printf("gogog");
        }
    if (is_empty(newlist1) || is_empty(newlist2)) {
        printf("momo\n");
        if (!is_empty(newlist1)) {
            printf("hello1\n");
            while(!is_empty(newlist1)) {
                int val = dequeue(newlist1);
                struct ListNode* newNode = createListNode(val);
                if (mergedList ==NULL) {
                    mergedList = newNode;
                    mergedtail = newNode;
                }
                else {
                    mergedtail->next = newNode;
                    mergedtail = newNode;
                }
                printf("dequeued value of list1: %d\n", val);
            }
            free(newlist1);
        }
        else {
            printf("hello2\n");
            while(!is_empty(newlist2)) {
                int val = dequeue(newlist2);
                printf("vallist2: %d\n", val);
                struct ListNode* newNode = createListNode(val);
                if (mergedList ==NULL) {
                    mergedList = newNode;
                    mergedtail = newNode;
                }
                else {
                    mergedtail->next = newNode;
                    mergedtail = newNode;
                }
                printf("dequeued value of list2: %d\n", val);
            }
            free(newlist2);
        }

        return mergedList;
    }
    else {
            while (!is_empty(newlist1) && !is_empty(newlist2)) {
                struct ListNode* newNode;
                if (newlist1->head->val <= newlist2->head->val) {
                    newNode = createListNode(dequeue(newlist1));
                    //how to increment the nodes in the list? because in the function I think Im just setting the head Node value in the linked list?
                }
                else {
                    newNode = createListNode(dequeue(newlist2));
                }
                if (mergedList ==NULL) {
                    mergedList = newNode;
                    mergedtail = newNode;
                }
                else {
                    mergedtail ->next = newNode;
                    mergedtail = newNode;
                }
            }
            while (!is_empty(newlist2)) {
                struct ListNode* newNode = createListNode(dequeue(newlist2));
                if (mergedList == NULL) {
                    mergedList = newNode;
                    mergedtail = newNode;
                }
                else {
                    mergedtail ->next = newNode;
                    mergedtail = newNode;
                }
            }
            while (!is_empty(newlist1)) {
                struct ListNode* newNode = createListNode(dequeue(newlist1));
                if (mergedList == NULL) {
                    mergedList = newNode;
                    mergedtail = newNode;
                }
                else {
                    mergedtail ->next = newNode;
                    mergedtail = newNode;
                }
            }
                 

        free(newlist1);
        free(newlist2);
        }

    return mergedList;
}