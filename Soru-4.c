#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* List1, struct ListNode* List2) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int tasi = 0;

    while (List1 != NULL || List2 != NULL) {
        int sum = tasi;
        if (List1 != NULL) {
            sum += List1->val;
            List1 = List1->next;
        }
        if (List2 != NULL) {
            sum += List2->val;
            List2 = List2->next;
        }
        tasi = sum / 10;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (tasi > 0) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = tasi;
        newNode->next = NULL;
        tail->next = newNode;
    }

    return head;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ->", head->val);
        head = head->next;
    }
}

int main() {
    struct ListNode* List1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    List1->val = 2;
    List1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    List1->next->val = 4;
    List1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    List1->next->next->val = 3;
    List1->next->next->next = NULL;


    struct ListNode* List2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    List2->val = 5;
    List2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    List2->next->val = 6;
    List2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    List2->next->next->val = 4;
    List2->next->next->next = NULL;

    printf("Giris: ");
    printList(List1);
    printf(" + ");
    printList(List2);

    struct ListNode* result = addTwoNumbers(List1, List2);

    printf(" Cikis: ");
    printList(result);

    return 0;
}