//
// Created by Liuyc on 2012/6/1.
//

#ifndef STUDENT_MANAGE_PROJECT_STUDENT_MANAGER_H
#define STUDENT_MANAGE_PROJECT_STUDENT_MANAGER_H

#include "linklist.h"


enum option_id {
    ADD_STUDENT = 1,
    FIND_STUDENT,
    DISPLAY_STUDENT,
    MODIFY_STUDENT,
    DELETE_STUDENT,
    EXIT_SYSTEM
};

extern bool login_status;

extern bool login();

extern void insertStudent(LinkedList **linkedList);

extern void findStudent(LinkedList *linkedList);

extern void displayStudent(LinkedList *linkedList);

extern void updateStudent(LinkedList *linkedList);

extern void deleteStudent(LinkedList **linkedList);

#endif //STUDENT_MANAGE_PROJECT_STUDENT_MANAGER_H

