#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma warning(disable : 4996)

#define TRUE 1
#define FALSE 0
#define LIST_LEN 200

typedef struct _stu {
	int grade; //학번
	char name[10]; //이름
	char ad[50]; //주소
	char phone[13]; //전화번호
	int korean; //국어 점수
	int data_str;//자료구조 점수
	struct _stu* next; // 다음 학생
	
}student;

typedef student stu;

typedef struct studentLink
{
	stu* head;
	stu* cur;
	stu* before;
	int numOfData; //총 저장된 갯수
} stuLink;

typedef stuLink Link;


void stuInit(Link* plist, stu* data);//초기화
void SInsert(Link* plist, stu* data);//학생 데이터 추가
int First(Link* plist, stu* pdata, int* g);//첫번째 값 설정
int Next(Link* plist, stu* pdata, int* g);//다음 값 지정
int Delete(Link* plist); //삭제
void Serch(Link* plist); //원하는 값 출력