//
// Created by Liuyc on 2012/6/1.
//

#ifndef STUDENT_MANAGE_PROJECT_LINKLIST_H
#define STUDENT_MANAGE_PROJECT_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct student ElementData;

typedef struct student {
    //学号
    int id;
    //姓名
    char *name;
    //性别
    char *gender;
    //年龄
    int age;
    //分数
    double score;
} student;


typedef struct LinkedList{
    ElementData value;
    struct LinkedList *next;
} LinkedList;

extern LinkedList *initLinkedList();

extern void addListAtHead(LinkedList **prevNode, ElementData value);

extern void addListAtEnd(LinkedList **prevNode, ElementData value);

extern void insertAt(LinkedList **prevNode, int index, ElementData value);

extern int length(LinkedList *list);

extern LinkedList *delNode(LinkedList **linkedList, ElementData value);

extern LinkedList *search(LinkedList *linkedList, ElementData value);

extern void clear(LinkedList **linkedList);

extern void destroy(LinkedList **linkedList);

extern int isEmpty(LinkedList *linkedList);

#endif //STUDENT_MANAGE_PROJECT_LINKLIST_H
