#include <stdio.h>
#include <stdlib.h>

// 顺序表结构体
typedef struct {
    int *data;     // 动态数组
    int length;    // 当前元素个数
    int capacity;  // 最大容量
} SeqList;

// 清空输入缓冲区
void clearInput() {
    while (getchar() != '\n');
}

// 初始化空表
void initList(SeqList *L) {
    L->data = NULL;
    L->length = 0;
    L->capacity = 0;
}

// 扩容（只用 malloc，不用 realloc）
void expandList(SeqList *L) {
    int new_cap = L->capacity * 2;
    int *new_data = (int *)malloc(new_cap * sizeof(int));
    if (!new_data) {
        printf("❌ 扩容失败\n");
        exit(1);
    }
    // 拷贝旧数据
    for (int i = 0; i < L->length; i++) {
        new_data[i] = L->data[i];
    }
    free(L->data);
    L->data = new_data;
    L->capacity = new_cap;
    printf("✅ 已扩容，新容量：%d\n", new_cap);
}

// ===================== 自定义数量建立顺序表 =====================
void createList(SeqList *L) {
    // 先释放原有空间
    if (L->data) {
        free(L->data);
    }

    int n;
    printf("\n👉 请输入要建立的顺序表元素个数：");
    while (scanf("%d", &n) != 1 || n < 0) {
        clearInput();
        printf("❌ 请输入非负整数：");
    }

    if (n == 0) {
        L->data = NULL;
        L->length = 0;
        L->capacity = 0;
        printf("✅ 已创建空顺序表\n");
        return;
    }

    // 自定义容量 = 你输入的元素个数
    L->data = (int *)malloc(n * sizeof(int));
    if (!L->data) {
        printf("❌ 内存分配失败\n");
        exit(1);
    }
    L->length = n;
    L->capacity = n;

    printf("👉 请依次输入 %d 个整数：\n", n);
    for (int i = 0; i < n; i++) {
        printf("第 %d 个：", i + 1);
        while (scanf("%d", &L->data[i]) != 1) {
            clearInput();
            printf("❌ 输入错误，请重新输入：");
        }
    }
    printf("✅ 顺序表创建成功！共 %d 个元素\n", n);
}
// =================================================================

// 插入元素
int insertList(SeqList *L) {
    if (L->capacity == 0) {
        printf("❌ 请先建立顺序表！\n");
        return 0;
    }
    int pos, e;
    printf("\n👉 插入位置（1~%d）：", L->length + 1);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > L->length + 1) {
        clearInput();
        printf("❌ 位置不合法\n");
        return 0;
    }
    printf("👉 元素值：");
    if (scanf("%d", &e) != 1) {
        clearInput();
        printf("❌ 输入错误\n");
        return 0;
    }

    if (L->length >= L->capacity) {
        expandList(L);
    }

    for (int i = L->length; i >= pos; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[pos - 1] = e;
    L->length++;
    printf("✅ 插入成功\n");
    return 1;
}

// 删除元素
int deleteList(SeqList *L) {
    if (L->length == 0) {
        printf("❌ 表为空\n");
        return 0;
    }
    int pos;
    printf("\n👉 删除位置（1~%d）：", L->length);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > L->length) {
        clearInput();
        printf("❌ 位置不合法\n");
        return 0;
    }
    int e = L->data[pos - 1];
    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    printf("✅ 删除元素 %d 成功\n", e);
    return 1;
}

// 修改元素
int updateList(SeqList *L) {
    if (L->length == 0) {
        printf("❌ 表为空\n");
        return 0;
    }
    int pos, e;
    printf("\n👉 修改位置（1~%d）：", L->length);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > L->length) {
        clearInput();
        printf("❌ 位置不合法\n");
        return 0;
    }
    printf("👉 新值：");
    if (scanf("%d", &e) != 1) {
        clearInput();
        printf("❌ 输入错误\n");
        return 0;
    }
    L->data[pos - 1] = e;
    printf("✅ 修改成功\n");
    return 1;
}

// 按位查找
int getElem(SeqList *L) {
    if (L->length == 0) {
        printf("❌ 表为空\n");
        return 0;
    }
    int pos;
    printf("\n👉 查找位置（1~%d）：", L->length);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > L->length) {
        clearInput();
        printf("❌ 位置不合法\n");
        return 0;
    }
    printf("✅ 元素：%d\n", L->data[pos - 1]);
    return 1;
}

// 按值查找
int locateElem(SeqList *L) {
    if (L->length == 0) {
        printf("❌ 表为空\n");
        return 0;
    }
    int e;
    printf("\n👉 请输入要查找的值：");
    if (scanf("%d", &e) != 1) {
        clearInput();
        printf("❌ 输入错误\n");
        return 0;
    }
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            printf("✅ 元素 %d 在位置 %d\n", e, i + 1);
            return i + 1;
        }
    }
    printf("❌ 未找到\n");
    return 0;
}

// 打印
void printList(SeqList *L) {
    if (L->length == 0) {
        printf("\nℹ️ 顺序表为空\n");
        return;
    }
    printf("\nℹ️ 元素：");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\nℹ️ 长度：%d  容量：%d\n", L->length, L->capacity);
}

// 销毁
void destroyList(SeqList *L) {
    if (L->data) {
        free(L->data);
        L->data = NULL;
    }
    L->length = 0;
    L->capacity = 0;
    printf("✅ 顺序表已销毁\n");
}

// 菜单
void menu() {
    printf("\n========== 顺序表管理系统 ==========\n");
    printf("1. 插入元素\n");
    printf("2. 删除元素\n");
    printf("3. 修改元素\n");
    printf("4. 按位置查找\n");
    printf("5. 按值查找\n");
    printf("6. 打印顺序表\n");
    printf("7. 建立顺序表（自定义数量）\n");
    printf("0. 退出\n");
    printf("===================================\n");
    printf("请选择：");
}

int main() {
    SeqList L;
    initList(&L);
    int choice;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) {
            clearInput();
            printf("❌ 输入错误\n");
            continue;
        }
        switch (choice) {
            case 1: insertList(&L); break;
            case 2: deleteList(&L); break;
            case 3: updateList(&L); break;
            case 4: getElem(&L); break;
            case 5: locateElem(&L); break;
            case 6: printList(&L); break;
            case 7: createList(&L); break;
            case 0:
                destroyList(&L);
                printf("👋 再见\n");
                return 0;
            default:
                printf("❌ 无效选项\n");
        }
    }
}