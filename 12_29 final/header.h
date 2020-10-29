#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#pragma warning(disable : 4996)

#define MAX 200 //저장가능 한 최대 크기
#define DGSW_GRADE 3 //대소고 학년 최대크기
#define DGSW_CLASS 3 //대소고 반 최대크기
#define DGSW_NUMBER 22 //대소고 한 반의 인원 최대크기

typedef struct _stu {
	int grade; //학번
	char name[10]; //이름
	char ad[50]; //주소
	char phone[13]; //전화번호
	int korean; //국어 점수
	int data_str;//자료구조 점수

}student;

typedef student Stu;

void Serch(Stu* stu);
void Input(Stu* stu);
int Check_Grade(int grade);
int Score_Check(int score);
int Str_len(char* arr);
int Delete(Stu* stu);
int DGSW_Check(int grade);
void scorePrint();