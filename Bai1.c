#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    int priority;
    char deadline[100];
}Task;
typedef struct Node {
    Task task;
    struct Node* next;
}Node;
typedef struct Compl {
    Task task;
    struct Node* prev;
    struct Node* next;
}Compl;
Node* head = NULL;
void addTask(){
    int id,priority;
    char title[100];
    char deadline[100];
    printf("Nhap id: ");
    scanf("%d",&id);
    getchar();
    printf("Nhap title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("Nhap priority: ");
    scanf("%d",&priority);
    getchar();
    printf("Nhap deadline: ");
    fgets(deadline, sizeof(deadline), stdin);
    title[strcspn(deadline, "\n")] = '\0';
    Node* temp = head;
    while (temp) {
        if (temp -> task.id == id) {
            printf("ID da ton tai\n");
            return;
        }
        if (strcmp(temp -> task.title, title) == 0) {
            printf("Title da ton tai\n");
            return;
        }
        temp = temp -> next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task.id = id;
    strcpy(newNode->task.title, title);
    newNode->task.priority = priority;
    strcpy(newNode->task.deadline, deadline);
    newNode->next = head;
    head = newNode;
    printf("Them nhiem vu thanh cong!\n");
}
void printTask() {
    Node* temp = head;
    if (!temp) {
        printf("Danh sach rong\n");
        return;
    }
    printf("Danh sach nhiem vu:\n");
    while (temp) {
        printf("ID: %d\n", temp->task.id);
        printf("Title: %s\n", temp->task.title);
        printf("Priority: %d\n", temp->task.priority);
        printf("Deadline: %s\n",temp->task.deadline);
        temp = temp->next;
    }
}
void deleteTask() {
    int id;
    printf("Nhap id muon xoa: ");
    scanf("%d", &id);
    Node* temp = head, *prev = NULL;
    while (temp && temp->task.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("ID khong ton tai\n");
        return;
    }
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Xoa thanh cong\n");
}
void updateTask() {
    int id;
    printf("Nhap id can cap nhat: ");
    scanf("%d", &id);
    Node* temp = head;
    while (temp && temp->task.id != id)
        temp = temp->next;
    if (!temp) {
        printf("Khong tim thay.\n");
        return;
    }
    getchar();
    printf("Ten moi: ");
    fgets(temp->task.title, sizeof(temp->task.title), stdin);
    temp->task.title[strcspn(temp->task.title, "\n")] = '\0';
    printf("Do uu tien moi: ");
    scanf("%d", &temp->task.priority);
    getchar();
    printf("Deadline moi: ");
    fgets(temp->task.deadline, sizeof(temp->task.deadline), stdin);
    temp->task.deadline[strcspn(temp->task.deadline, "\n")] = '\0';
    printf("Da cap nhat!\n");
}
void findTask() {
    char keyword[100];
    getchar();
    printf("Nhap ten nhiem vu can tim: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    Node* temp = head;
    int found = 0;
    while (temp) {
        if (strstr(temp->task.title, keyword) != NULL) {
            printf("Tim thay:\n");
            printf("ID: %d | Title: %s | Priority: %d | Deadline: %s\n",
                   temp->task.id, temp->task.title, temp->task.priority, temp->task.deadline);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("Khong tim thay nhiem vu co ten chua %s.\n", keyword);
}
void sortTask() {
    if (!head || !head->next) {
        printf("Khong can sap xep.\n");
        return;
    }
    Node* i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->task.priority > j->task.priority) {
                Task temp = i->task;
                i->task = j->task;
                j->task = temp;
            }
        }
    }
    printf("Da sap xep danh sach theo do uu tien tang dan.\n");
}
int main() {
    int choice;
    do {
        printf("==========MENU==========\n");
        printf("1.Them nhiem vu\n");
        printf("2.Hien thi danh sach nhiem vu\n");
        printf("3.Xoa nhiem vu\n");
        printf("4.Cap nhap thong tin nhiem vu\n");
        printf("5.Danh dau nhiem vu hoan thanh\n");
        printf("6.Sap xep nhiem vu\n");
        printf("7.Tim kiem nhiem vu\n");
        printf("8.Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                printTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                updateTask();
                break;
            case 5:
                break;
            case 6:
                sortTask();
                break;
            case 7:
                findTask();
                break;
            case 8:
                printf("Tam biet!!!");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while(choice!=8);
    return 0;
}