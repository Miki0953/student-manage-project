#include "student_manager.h"


/**
 * 学生信息管理系统 v.0.0.1
 * @return
 */
int main() {
    //1.登录

    //检查登录状态
    while (!login_status) {
        if (login()) {
            printf("登录系统成功！\n");
        }
    }

    //2.创建一个空链表存储学生信息
    LinkedList *linkedList = initLinkedList();

    while (true) {
        printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━  \n");
        printf(" ┃ 学生管理系统               \n");
        printf(" ┣━━━━━━━━━━━━━━━━━━━━━━━  \n");
        printf(" ┃ 1. 增加学生              \n");
        printf(" ┃ 2. 查找学生              \n");
        printf(" ┃ 3. 展示学生              \n");
        printf(" ┃ 4. 修改学生              \n");
        printf(" ┃ 5. 删除学生              \n");
        printf(" ┃ 6. 退出系统              \n");
        printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━\n");

        int option;

        printf("请选择：");
        scanf("%d", &option);

        switch (option) {
            case ADD_STUDENT:
                insertStudent(&linkedList);
                break;
            case FIND_STUDENT:
                findStudent(linkedList);
                break;
            case DISPLAY_STUDENT:
                displayStudent(linkedList);
                break;
            case MODIFY_STUDENT:
                updateStudent(linkedList);
                break;
            case DELETE_STUDENT:
                deleteStudent(&linkedList);
                break;
            case EXIT_SYSTEM:
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }

    destroy(&linkedList);

    return 0;
}
