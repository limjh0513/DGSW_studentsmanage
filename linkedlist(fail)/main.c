#include "header.h"


int main(void)
{
	Link link;
	stu stus;
	stu cpystu;
	stuInit(&link, &stus);
	int choose; //��� ����
	int grade_put; //�й� �˻�
	int grade_bring = 0; //�Լ����� return ���� grade��
	int check = 0; //���� �ִ��� Ȯ��

	while (1)
	{
		check = 0;
		printf("-1�� : ���� �Է�-\n-2�� : ���� �˻�-\n-3�� : ���� ����-\n-4�� : 1�� ���-\n(0 �Է½� ����)\n\n");
		printf("�Է� : ");
		scanf("%d", &choose);
		if (choose == 0) // 0 �Է� �� ����
		{
			break;
		}
		switch (choose)
		{
		case (1): //���� �Է�
		{
			printf("�й�, �̸�, �ּ�, ��ȭ��ȣ(010-XXXX-XXXX),\n��������, �ڷᱸ�� ������ ���ʴ�� �Է�\n\n");
			scanf("%d %s %s %s %d %d", &stus.grade, stus.name, stus.ad, stus.phone, &stus.korean, &stus.data_str);
			SInsert(&link, &stus);
			break;
		}
		case(2): //���� �˻�
		{
			printf("�˻��ϰ� ���� �й��� �Է� : ");
			scanf("%d", &grade_put);


			First(&link, &stus, &grade_bring);
			printf("%d\n", grade_bring);
			if (grade_bring == grade_put)
			{
				Serch(&link);
				check = 1;
			}
			else
			{
				for (int i = 0; i < link.numOfData-1; i++)
				{
					Next(&link, &stus, &grade_bring);
					printf("%d\n", grade_bring);
					if (grade_bring == grade_put)
					{
						Serch(&link);
						check = 1;
					}
				}
			}
			if (check != 1)
			{
				printf("���� ã�� ���߽��ϴ�.\n\n");
			}

			break;
		}
		case(3): //���� ����
		{

			printf("�����ϰ��� �ϴ� �й��� �Է� : ");
			scanf("%d", &grade_put);
			First(&link, &stus, &grade_bring);
			if (grade_bring == grade_put)
			{
				check = Delete(&link);
			}
			else
			{
				for (int i = 0; i < link.numOfData-1; i++)
				{
					Next(&link, &stus, &grade_bring);
					if (grade_bring == grade_put)
					{
						check = Delete(&link);
					}
				}
			}
			if (check == 0)
			{
				printf("���� ã�� ���߽��ϴ�.\n\n");
			}
			else
			{
				printf("%d ���� �Ϸ�!\n\n", check);
			}
			break;
		}
		case (4): //1�� ���
		{

			break;
		}
		case (5):
		{
			if (First(&link, &stus, &grade_bring))
			{
				printf("%d ", grade_bring);

				while (Next(&link, &stus, &grade_bring))
				{
					printf("%d ", grade_bring);
				}
			}
			break;
		}
		default:
		{
			printf("������ ��ȣ �� �߸��� ��ȣ�� �Է��߽��ϴ�.\n\n");
			break;
		}
		}
		printf("%d", link.numOfData);
		Sleep(2000);
		system("cls");
	}

	printf("���� ������ �� : %d\n", link.numOfData);
	

	return 0;
}