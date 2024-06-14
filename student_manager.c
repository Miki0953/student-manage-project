//
// Created by Liuyc on 2012/6/1.
//
#include "student_manager.h"

#define ADMINISTRATOR "admin"
#define PASSWORD "11"

//登录状态
bool login_status = false;



/**
 * 登录
 */
bool login() {
    bool status = false;

    char username[32];
    char password[32];


    printf("================登录================\n");
    printf("账号：");
    fgets(username, sizeof username, stdin);
    //fgets函数会将回车时的换行符也写入到username中，因此
    username[strlen(username) - 1] = '\0';

    printf("密码：");
    fgets(password, sizeof password, stdin);
    password[strlen(password) - 1] = '\0';

    if (strcmp(username, ADMINISTRATOR) == 0 && strcmp(password, PASSWORD) == 0) {
        login_status = true;
        status = true;
    } else {
        printf("账号或密码错误！请重新输入...\n");
    }

    return status;
}

/**
 * 插入学生信息
 *
 * @param linkedList
 */
void insertStudent(LinkedList **linkedList) {
    student stu = {0};
    stu.name = malloc(sizeof(20));
    stu.gender = malloc(sizeof(8));


    bool isExist = false;
    do {
        isExist = false;
        printf("------------------------------------\n");
        printf("请输入学生的信息[学号 姓名 性别 年龄 分数]：");
        scanf("%d %s %s %d %lf", &stu.id, stu.name, stu.gender, &stu.age, &stu.score);

        //清除缓存区
        while (getchar() != '\n');

        if (search(*linkedList, stu) != NULL) {
            isExist = true;
            printf("学号[%d]的学生的信息已经存在，请重新输入!\n", stu.id);
        }
    } while (isExist);


    addListAtEnd(linkedList, stu);
    printf("新增成功!\n");
    printf("-------------------------------------------------------------\n");

}

/**
 * 根据学号查找学生
 *
 * @param linkedList
 */
void findStudent(LinkedList *linkedList) {
    int id;
    printf("请输入要查找学生的学号: ");
    scanf("%d", &id);


    student stu = {.id = id};

    LinkedList *p = search(linkedList, stu);

    if (p) {
        printf("===========================学生信息表==========================\n");
        printf("-------------------------------------------------------------\n");
        printf("|%-10s \t|%-10s \t|%-10s \t|%-10s \t|%-10s \t|\n", "学号", "姓名", "性别", "年龄", "分数");
        printf("|%-6d \t|%-10s \t|%-10s \t|%-6d \t|%-6.1f \t|\n", p->value.id, p->value.name, p->value.gender,
               p->value.age,
               p->value.score);
        printf("-------------------------------------------------------------\n");
    } else {
        printf("学号为[%d]的学生信息不存在，请核对后重新操作!\n", id);
        printf("-------------------------------------------------------------\n");
        return;
    }

}

/**
 * 展示学生信息
 *
 * @param linkedList
 */
void displayStudent(LinkedList *linkedList) {
    LinkedList *p = linkedList;

    printf("===========================学生信息表==========================\n");
    printf("-------------------------------------------------------------\n");
    printf("|%-10s \t|%-10s \t|%-10s \t|%-10s \t|%-10s \t|\n", "学号", "姓名", "性别", "年龄", "分数");

    while (p != NULL) {

        printf("|%-6d \t|%-10s \t|%-10s \t|%-6d \t|%-6.1f \t|\n", p->value.id, p->value.name, p->value.gender,
               p->value.age,
               p->value.score);
        p = p->next;
    }
    printf("-------------------------------------------------------------\n");
}


/**
 * 更新学生信息
 *
 * @param linkedList
 */
void updateStudent(LinkedList *linkedList) {
    int id;
    printf("请输入要修改学生的学号: ");
    scanf("%d", &id);

    student stu = {.id = id};

    LinkedList *p = search(linkedList, stu);

    if (p) {
        printf("===========================学生信息表==========================\n");
        printf("-------------------------------------------------------------\n");
        printf("|%-10s \t|%-10s \t|%-10s \t|%-10s \t|%-10s \t|\n", "学号", "姓名", "性别", "年龄", "分数");
        printf("|%-6d \t|%-10s \t|%-10s \t|%-6d \t|%-6.1f \t|\n", p->value.id, p->value.name, p->value.gender,
               p->value.age,
               p->value.score);
        printf("-------------------------------------------------------------\n");
    } else {
        printf("学号为[%d]的学生信息不存在，请核对后重新操作!\n", id);
        return;
    }

    printf("请输入要修改学生的信息[姓名 性别 年龄 分数]: ");
    scanf("%s %s %d %lf", p->value.name, p->value.gender, &p->value.age, &p->value.score);

    while (getchar() != '\n');

    printf("修改成功!\n");

    printf("-------------------------------------------------------------\n");

}

/**
 *
 *
 * @param linkedList
 */
void deleteStudent(LinkedList **linkedList) {
    int id;
    printf("请输入要删除的学生的学号: ");
    scanf("%d", &id);


    student stu = {.id = id};

    LinkedList *p = search(*linkedList, stu);

    if (p) {
        printf("===========================学生信息表==========================\n");
        printf("-------------------------------------------------------------\n");
        printf("|%-10s \t|%-10s \t|%-10s \t|%-10s \t|%-10s \t|\n", "学号", "姓名", "性别", "年龄", "分数");
        printf("|%-6d \t|%-10s \t|%-10s \t|%-6d \t|%-6.1f \t|\n", p->value.id, p->value.name, p->value.gender,
               p->value.age,
               p->value.score);
        int del;
        printf("确定要删除该学生的信息吗?[1是 2否]:");
        scanf("%d", &del);

        if (del == 1) {
            delNode(linkedList, p->value);
            printf("删除成功!\n");
        }
    } else {
        printf("学号为[%d]的学生信息不存在，请核对后重新操作!\n", id);
        printf("-------------------------------------------------------------\n");
        return;
    }
}