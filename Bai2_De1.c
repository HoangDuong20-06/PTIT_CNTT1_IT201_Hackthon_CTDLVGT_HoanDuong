#include <stdio.h>
#include <string.h>

typedef struct {
    char action[100];
    char value[100];
}Operation;
int main() {
    int choice;
    do {
        printf("==========MENU==========\n");
        printf("1. Insert x\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Hien thi\n");
        printf("5. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Tam biet");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while (choice!=5);
    return 0;
}