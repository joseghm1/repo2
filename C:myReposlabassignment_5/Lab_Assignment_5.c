#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char letter;
    struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    int length1 = length(head);
    int i = 0;
    char* cString = malloc(length1 + 1);
    
    while (head!= NULL) {
        cString[i] = head->letter;
        head = head->next;
        i++;
    }
    
    cString[length1] = '\0';
    return cString;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newChar = (node*)malloc(sizeof(node));
    newChar->letter = c;
    newChar->next = NULL;
    
    if (*pHead == NULL) {
        *pHead = newChar;
    }else{
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        
        current->next = newChar;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node *current = *pHead;
    while (current != NULL) {
        node* currentD = current;
        current = current->next;
        free(currentD);
    }
    *pHead = NULL;
}
int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}
