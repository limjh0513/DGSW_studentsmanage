#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#pragma warning(disable : 4996)

#define MAX 200 //���尡�� �� �ִ� ũ��
#define DGSW_GRADE 3 //��Ұ� �г� �ִ�ũ��
#define DGSW_CLASS 3 //��Ұ� �� �ִ�ũ��
#define DGSW_NUMBER 22 //��Ұ� �� ���� �ο� �ִ�ũ��

typedef struct _stu {
	int grade; //�й�
	char name[10]; //�̸�
	char ad[50]; //�ּ�
	char phone[13]; //��ȭ��ȣ
	int korean; //���� ����
	int data_str;//�ڷᱸ�� ����

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