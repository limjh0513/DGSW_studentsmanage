#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma warning(disable : 4996)

#define TRUE 1
#define FALSE 0
#define LIST_LEN 200

typedef struct _stu {
	int grade; //�й�
	char name[10]; //�̸�
	char ad[50]; //�ּ�
	char phone[13]; //��ȭ��ȣ
	int korean; //���� ����
	int data_str;//�ڷᱸ�� ����
	struct _stu* next; // ���� �л�
	
}student;

typedef student stu;

typedef struct studentLink
{
	stu* head;
	stu* cur;
	stu* before;
	int numOfData; //�� ����� ����
} stuLink;

typedef stuLink Link;


void stuInit(Link* plist, stu* data);//�ʱ�ȭ
void SInsert(Link* plist, stu* data);//�л� ������ �߰�
int First(Link* plist, stu* pdata, int* g);//ù��° �� ����
int Next(Link* plist, stu* pdata, int* g);//���� �� ����
int Delete(Link* plist); //����
void Serch(Link* plist); //���ϴ� �� ���