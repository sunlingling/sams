#ifndef STRUCT_H
#define STRUCT_H

#include <stdint.h>

#define T_DATA_PATH  "data/tch.bin"
#define S_DATA_PATH  "data/stu.bin"
#define DT_DATA_PATH "data/d_tch.bin"
#define DS_DATA_PATH "data/d_stu.bin"

typedef struct Student
{
	uint32_t id;        // 学号
	float    scr_c;     // 语文成绩 
	float    scr_m;     // 数学成绩
	float    scr_e;     // 英语成绩
	char     name[20];  // 姓名
	char     sex;       // 性别
}Student;

typedef struct Teacher
{
    uint32_t wd;        // 工号
    uint32_t pd;        // 密码
    char     name[20];  // 姓名
    char     sex;       // 性别
}Teacher;

#endif//STRUCT_H
