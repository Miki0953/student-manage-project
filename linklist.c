//
// Created by Liuyc on 2012/6/1.
//
#include "linklist.h"

/**
 * 创建一个新的链表结点
 *
 * @param value
 * @return
 */
LinkedList *createNewNode() {
    LinkedList *newNode = malloc(sizeof(LinkedList));
    if (newNode == NULL) {
        printf("ERROR: malloc failed in createNewNode \n");
        exit(EXIT_FAILURE);
    }

    return newNode;
}

/**
 * 创建一个链表，只有一个结点，且结点的值初始化为0
 *
 * @return
 */
LinkedList *initLinkedList() {
    return NULL;
}

/**
 * 头部插入法：向链表中头部插入一个新结点，新结点成为链表的第一个结点。此时链表的头指针指向第一个结点
 *
 * @param prevNode 「指向前一个结点的指针」的指针
 * @param value
 * @return
 */
void addListAtHead(LinkedList **prevNode, ElementData value) {
    //创建一个新的结点
    LinkedList *newNode = createNewNode();

    newNode->value = value;

    if (*prevNode == NULL) {
        newNode->next = NULL;
        *prevNode = newNode;
    } else {
        newNode->next = *prevNode;
        *prevNode = newNode;
    }
}

/**
 * 链表尾部插入元素：新结点成为链表最后一个结点，此时链表的头指针依然指向的第一个结点
 *
 * @param prevNode
 * @param value
 */
void addListAtEnd(LinkedList **prevNode, ElementData value) {
    LinkedList *newNode = createNewNode();

    newNode->value = value;
    //由于是在链表末尾添加元素，所以无论何种情况 newNode->next 都是 NULL
    newNode->next = NULL;

    if (*prevNode == NULL) {
        *prevNode = newNode;
        return;
    }

    //核心算法
    LinkedList *temp = *prevNode;
    //在实际使用的时候，传入的 *prevNode 实际是链表的头指针，保不齐此时链表不止一个元素
    while (temp->next != NULL) {
        //一直找到链表的末尾元素，将末尾元素的指针赋值给temp
        temp = temp->next;
    }
    //将末尾元素的指针域设置为新结点的地址
    temp->next = newNode;

}

/**
 * 在第 index 个元素之后插入新元素，0表示在头部插入
 *
 * @param prevNode
 * @param index
 * @param value
 */
void insertAt(LinkedList **prevNode, int index, ElementData value) {
    if (index < 0 || index > length(*prevNode)) {
        printf("error: invalid index, index can not be less than 0 or more than the length!\n");
        return;
    }

    LinkedList *newNode = createNewNode();

    //在头部插入元素，新结点作为第一个结点
    if (index == 0) {
        newNode->value = value;
        //原来的第一个结点作为新结点的后继结点
        newNode->next = *prevNode;
        //将链表的头指针设置为新结点的地址
        *prevNode = newNode;
        return;
    }

    //非头部插入元素，需要找到位置为index的结点，这是新结点的前驱结点

    //前驱结点
    LinkedList *current = *prevNode;

    int position = 1;
    while (current != NULL && position < index) {
        //current->next 正好是位置在index的结点，找到了该结点，我们就可以在其后插入新结点了
        current = current->next;
        position++;
    }

    newNode->value = value;
    //当前结点的后继结点变成新结点的后继结点
    newNode->next = current->next;
    //新结点变成前驱结点的后继结点
    current->next = newNode;

}

/**
 * 获取链表的长度
 *
 * @param list
 * @return
 */
int length(LinkedList *list) {
    int length = 0;
    LinkedList *current = list;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

/**
 * 删除元素值为value的结点
 *
 * @param linkedList
 * @param value
 * @return
 */
LinkedList *delNode(LinkedList **linkedList, ElementData value) {
    /**
     * 追踪指针的思想
     */
    //当前结点的指针
    LinkedList *cur;
    //前一个结点的指针
    LinkedList *prev;

    //1.定位要删除的结点
    for (cur = *linkedList, prev = NULL; cur->value.id != value.id && cur != NULL; prev = cur, cur = prev->next) {

    }

    //2.绕过删除结点
    if (cur == NULL) {
        //表明 value 不在链表当中
    }

    if (cur == *linkedList) {
        //首结点就是要删除的元素,绕过删除结点
        *linkedList = cur->next;
        cur->next = NULL;
    } else {
        //要删除的结点不是首结点，同样绕过删除结点
        prev->next = cur->next;
        cur->next = NULL;
    }

    return cur;
}

/**
 * 查找链表中元素值等于value的元素
 *
 * @param linkedList
 * @param value
 * @return
 */
LinkedList *search(LinkedList *linkedList, ElementData value) {

    LinkedList *p;

    for (p = linkedList; p != NULL; p = p->next) {
        if (p->value.id == value.id) {
            return p;
        }
    }

    return NULL;
}

/**
 * 清空链表
 * @param linkedList
 */
void clear(LinkedList **linkedList) {
    LinkedList *current = *linkedList;
    LinkedList *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    //因为需要在这里将链表的头指针设置为NULL，所以方法的参数必须传 linkedList 的二级指针
    *linkedList = NULL;
}

/**
 * 销毁链表
 * @param linkedList
 */
void destroy(LinkedList **linkedList) {
    clear(linkedList);
}

/**
 * 判断链表是否为空
 *
 * @param linkedList
 * @return
 */
int isEmpty(LinkedList *linkedList) {
    if (linkedList == NULL) {
        return 1;
    }

    return 0;
}