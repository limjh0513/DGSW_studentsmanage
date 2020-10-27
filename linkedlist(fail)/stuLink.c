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
	stu* newNode = (stu*)malloc(sizeof(stu)); //���ο� ��� ����

	newNode = data; //���ο� ��忡 ������ �߰�

	newNode->next = plist->head->next; //�� ��尡 �ٸ� ��带 ����Ű�� ��
	plist->head->next = newNode; //���� ��尡 �� ��带 ����Ű�� ��

	//19, 20 ���� �ٲ�� �Ǹ� ���̳���� ���� �κ��� �� ��尡 �ǰ� �� ����� �����κ��� ���̳�尡 �ǹǷ� �ڵ尡 �̻�����

	(plist->numOfData)++; //����� ������ �� �ϳ� ����
	if (newNode->next == NULL)
	{
		printf("heelo");
	}
	
	printf("���� �Ϸ�!\n\n");
}

int First(Link* plist, stu* pdata, int* g)
{
	
	if (plist->head->next == NULL)//���̳�尡 NULL�� ����Ű�� ��ȯ X
	{
		return FALSE;
	}

	plist->before = plist->head; //before�� ���̳�带 ����Ű�� ��
	plist->cur = plist->head->next; // cur�� ù ��° ��带 ����Ű�� ��

	*g = plist->cur->grade; //ù��° ����� ������ ����
	return TRUE; //��ȯ O
}

int Next(Link* plist, stu* pdata, int* g)
{
	if (plist->cur->next == NULL) //cur�� NULL�� ����Ű�� (������ �κ�)
	{
		return FALSE; // ��ȯ X
	}

	plist->before = plist->cur; // cur�� ����Ű�� ���� before��
	plist->cur = plist->cur->next; //cur�� cur->next�� ����Ŵ

	*g = plist->cur->grade; //cur�� data�� ����
	return TRUE; //��ȯ O
}

int Delete(Link* plist)
{
	stu* rpos = plist->cur; //rpos�� cur�� ����Ű�� ��
	int rdata = rpos->grade; //rdata�� rpos�� data ���� ����
	plist->before->next = plist->cur->next; //before->next�� cur->next�� ���� (�Ҹ��� ����Ʈ���� ����)
	plist->cur = plist->before; //cur�� before�� �־� cur�� �Ѵܰ� ���� before�� ����(�������� ��ĭ) (��ġ ������)

	free(rpos); // ������� �ߴ� cur�� ����Ű�� rpos�� free(�����Ҵ� ����)����
	(plist->numOfData)--; //������ ������ �ϳ� �ٿ���
	return rdata;// rpos->data�� �����س��� rdata�� ��ȯ
}

void Serch(Link* plist)
{
	printf("\n");
	printf("----------------------------------\n");
	printf("�й� : %d\n", plist->cur->grade);
	printf("�̸� : %s\n", plist->cur->name);
	printf("�ּ� : %s\n", plist->cur->ad);
	printf("��ȭ��ȣ : %s\n", plist->cur->phone);
	printf("�������� : %d\n", plist->cur->korean);
	printf("�ڷᱸ�� ���� : %d\n", plist->cur->data_str);
	printf("----------------------------------");
	printf("\n\n");
}