#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkList {
    int data;
    struct _LinkList *next;
} LinkList;

LinkList * createList() {
    LinkList * this = (LinkList *)malloc(sizeof(LinkList));
    this->next = NULL;
    return this;
}

LinkList * createNode(int data) {
    LinkList * this = (LinkList *)malloc(sizeof(LinkList));
    this->data = data;
    this->next = NULL;
    return this;
}

void insertNode(LinkList * this, LinkList * node) {
    node->next = this->next;
    this->next = node;
    return;
}

void appendNode(LinkList * this, LinkList * node) {
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = node;
    node->next = NULL;
    return;
}

void printNode(LinkList * this) {
    printf("%4d",this->data);
    return;
}

void visitList(LinkList * this) {
    this = this->next;
    while (this != NULL) {
        printNode(this);
        this = this->next;
    }
    printf("\n");
    return;
}

void divide2(LinkList * this, LinkList * odd, LinkList * even) {
    this = this->next;
    int flag = 1;
    LinkList * next = NULL;
    while (this != NULL) {
        next = this->next;
        if (flag == 1) {
            appendNode(odd,this);
        } else {
            insertNode(even,this);
        }
        this = next;
        flag ^= 1;
    }
    return;
}

LinkList * mergeList(LinkList * this, LinkList * that) {
    LinkList * result = this;
    this = this->next;
    that = that->next;
    LinkList * temp = NULL;
    while (that != NULL) {
        temp = this->next;
        this->next = that;
        this = temp;

        temp = that->next;
        that->next = this;
        that = temp;
    }
    return result;
}

int main() {
    LinkList * list = createList();

    for (int i = 0; i < 10; i++) {
        appendNode(list,createNode(i));
    }

    visitList(list);

    LinkList * odd = createList();
    LinkList * even = createList();

    divide2(list,odd,even);

    visitList(odd);

    visitList(even);

    list = mergeList(odd,even);

    visitList(list);

    return 0;
}