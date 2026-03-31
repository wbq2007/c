#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENT 50  // 最大学生数量

// 学生结构体
typedef struct {
    char id[20];    // 学号
    char name[20];  // 姓名
    float chinese;  // 语文成绩
    float math;     // 数学成绩
    float english;  // 英语成绩
    float total;    // 总分
} Student;

Student students[MAX_STUDENT];  // 学生数组
int studentCount = 0;           // 当前学生数量

// 函数声明
void menu();                // 主菜单
void addStudent();           // 添加学生
void showAllStudents();      // 查看所有学生
void searchStudentById();    // 按学号查询
void modifyStudent();        // 修改成绩
void deleteStudent();        // 删除学生
void statisticScore();       // 成绩统计
void saveToFile();           // 保存到文件
void loadFromFile();         // 从文件读取

int main() {
    loadFromFile();  // 启动程序先加载文件数据
    int choice;

    while (1) {
        menu();
        printf("请输入操作序号：");
        scanf("%d", &choice);
        getchar();  // 吸收回车

        switch (choice) {
        case 1: addStudent(); break;
        case 2: showAllStudents(); break;
        case 3: searchStudentById(); break;
        case 4: modifyStudent(); break;
        case 5: deleteStudent(); break;
        case 6: statisticScore(); break;
        case 0:
            saveToFile();
            printf("已保存数据，程序退出！\n");
            return 0;
        default: printf("输入错误，请重新输入！\n");
        }
        printf("\n按回车键继续...");
        getchar();
        system("cls");  // Windows清屏，Linux/mac改为 system("clear");
    }
}

// 主菜单
void menu() {
    printf("=========================================\n");
    printf("          学生成绩管理系统\n");
    printf("=========================================\n");
    printf(" 1. 添加学生信息\n");
    printf(" 2. 查看所有学生信息\n");
    printf(" 3. 按学号查询学生信息\n");
    printf(" 4. 修改学生成绩\n");
    printf(" 5. 删除学生信息\n");
    printf(" 6. 成绩统计\n");
    printf(" 0. 退出系统\n");
    printf("=========================================\n");
}

// 添加学生
void addStudent() {
    if (studentCount >= MAX_STUDENT) {
        printf("学生数量已达上限，无法添加！\n");
        return;
    }

    Student* s = &students[studentCount];
    printf("请输入学号："); scanf("%s", s->id);
    printf("请输入姓名："); scanf("%s", s->name);
    printf("请输入语文成绩："); scanf("%f", &s->chinese);
    printf("请输入数学成绩："); scanf("%f", &s->math);
    printf("请输入英语成绩："); scanf("%f", &s->english);

    s->total = s->chinese + s->math + s->english;
    studentCount++;
    printf("学生信息添加成功！\n");
}

// 查看所有学生
void showAllStudents() {
    if (studentCount == 0) {
        printf("暂无学生信息！\n");
        return;
    }

    printf("=====================================================================\n");
    printf("学号\t\t姓名\t语文\t数学\t英语\t总分\n");
    printf("=====================================================================\n");
    for (int i = 0; i < studentCount; i++) {
        Student s = students[i];
        printf("%s\t\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",
            s.id, s.name, s.chinese, s.math, s.english, s.total);
    }
}

// 按学号查询
void searchStudentById() {
    char searchId[20];
    printf("请输入要查询的学号：");
    scanf("%s", searchId);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, searchId) == 0) {
            printf("查询成功！\n");
            printf("学号：%s\n姓名：%s\n语文：%.1f\n数学：%.1f\n英语：%.1f\n总分：%.1f\n",
                students[i].id, students[i].name,
                students[i].chinese, students[i].math,
                students[i].english, students[i].total);
            return;
        }
    }
    printf("未找到该学号的学生！\n");
}

// 修改成绩
void modifyStudent() {
    char modifyId[20];
    printf("请输入要修改的学生学号：");
    scanf("%s", modifyId);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, modifyId) == 0) {
            printf("请输入新的语文成绩："); scanf("%f", &students[i].chinese);
            printf("请输入新的数学成绩："); scanf("%f", &students[i].math);
            printf("请输入新的英语成绩："); scanf("%f", &students[i].english);
            students[i].total = students[i].chinese + students[i].math + students[i].english;
            printf("成绩修改成功！\n");
            return;
        }
    }
    printf("未找到该学号的学生！\n");
}

// 删除学生
void deleteStudent() {
    char deleteId[20];
    printf("请输入要删除的学生学号：");
    scanf("%s", deleteId);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, deleteId) == 0) {
            // 后面的学生向前覆盖
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("学生信息删除成功！\n");
            return;
        }
    }
    printf("未找到该学号的学生！\n");
}

// 成绩统计
void statisticScore() {
    if (studentCount == 0) {
        printf("暂无学生信息！\n");
        return;
    }

    float sumChinese = 0, sumMath = 0, sumEnglish = 0;
    float maxChinese = 0, maxMath = 0, maxEnglish = 0;

    for (int i = 0; i < studentCount; i++) {
        sumChinese += students[i].chinese;
        sumMath += students[i].math;
        sumEnglish += students[i].english;

        if (students[i].chinese > maxChinese) maxChinese = students[i].chinese;
        if (students[i].math > maxMath) maxMath = students[i].math;
        if (students[i].english > maxEnglish) maxEnglish = students[i].english;
    }

    printf("========== 成绩统计 ==========\n");
    printf("学生总数：%d\n", studentCount);
    printf("语文平均分：%.1f\t最高分：%.1f\n", sumChinese / studentCount, maxChinese);
    printf("数学平均分：%.1f\t最高分：%.1f\n", sumMath / studentCount, maxMath);
    printf("英语平均分：%.1f\t最高分：%.1f\n", sumEnglish / studentCount, maxEnglish);
}

// 保存数据到文件
void saveToFile() {
    FILE* fp = fopen("students.txt", "w");
    if (!fp) {
        printf("文件保存失败！\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(fp, "%s %s %.1f %.1f %.1f %.1f\n",
            students[i].id, students[i].name,
            students[i].chinese, students[i].math,
            students[i].english, students[i].total);
    }
    fclose(fp);
}

// 从文件读取数据
void loadFromFile() {
    FILE* fp = fopen("students.txt", "r");
    if (!fp) return;  // 文件不存在则直接返回

    while (fscanf(fp, "%s %s %f %f %f %f",
        students[studentCount].id,
        students[studentCount].name,
        &students[studentCount].chinese,
        &students[studentCount].math,
        &students[studentCount].english,
        &students[studentCount].total) != EOF) {
        studentCount++;
    }
    fclose(fp);
}