#include "header.h"

void stuInit(Link* plist, stu* data)
{
	plist->head = (stu*)malloc(sizeof(stu));
	plist->head->next = NULL;
	plist->numOfData = 0;
	data->next = NULL;
}

void SInsert(Link* plist, stu* data)
{
	stu* newNode = (stu*)malloc(sizeof(stu)); //새로운 노드 생성

	newNode = data; //새로운 노드에 데이터 추가

	newNode->next = plist->head->next; //새 노드가 다른 노드를 가르키게 함
	plist->head->next = newNode; //더미 노드가 새 노드를 가르키게 함

	//19, 20 줄이 바뀌게 되면 더미노드의 다음 부분이 새 노드가 되고 새 노드의 다음부분이 더미노드가 되므로 코드가 이상해짐

	(plist->numOfData)++; //저장된 데이터 수 하나 증가
	if (newNode->next == NULL)
	{
		printf("heelo");
	}
	
	printf("저장 완료!\n\n");
}

int First(Link* plist, stu* pdata, int* g)
{
	
	if (plist->head->next == NULL)//더미노드가 NULL을 가르키면 반환 X
	{
		return FALSE;
	}

	plist->before = plist->head; //before는 더미노드를 가르키게 함
	plist->cur = plist->head->next; // cur는 첫 번째 노드를 가르키게 함

	*g = plist->cur->grade; //첫번째 노드의 데이터 전달
	return TRUE; //반환 O
}

int Next(Link* plist, stu* pdata, int* g)
{
	if (plist->cur->next == NULL) //cur가 NULL을 가르키면 (마지막 부분)
	{
		return FALSE; // 반환 X
	}

	plist->before = plist->cur; // cur가 가르키던 것을 before로
	plist->cur = plist->cur->next; //cur를 cur->next로 가르킴

	*g = plist->cur->grade; //cur의 data를 전달
	return TRUE; //반환 O
}

int Delete(Link* plist)
{
	stu* rpos = plist->cur; //rpos에 cur를 가르키게 함
	int rdata = rpos->grade; //rdata에 rpos의 data 값을 넣음
	plist->before->next = plist->cur->next; //before->next에 cur->next를 넣음 (소멸대상 리스트에서 제거)
	plist->cur = plist->before; //cur를 before로 넣어 cur를 한단계 전인 before로 만듬(왼쪽으로 한칸) (위치 재조정)

	free(rpos); // 지우고자 했던 cur를 가르키는 rpos를 free(동적할당 해제)해줌
	(plist->numOfData)--; //데이터 갯수를 하나 줄여줌
	return rdata;// rpos->data를 저장해놨던 rdata를 반환
}

void Serch(Link* plist)
{
	printf("\n");
	printf("----------------------------------\n");
	printf("학번 : %d\n", plist->cur->grade);
	printf("이름 : %s\n", plist->cur->name);
	printf("주소 : %s\n", plist->cur->ad);
	printf("전화번호 : %s\n", plist->cur->phone);
	printf("국어점수 : %d\n", plist->cur->korean);
	printf("자료구조 점수 : %d\n", plist->cur->data_str);
	printf("----------------------------------");
	printf("\n\n");
}