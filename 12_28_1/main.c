#include "header.h"

int main(void)
{
	Stu* stu; //200�� ����
	int NumOfData = 0; //���� ����� �л� ��
	int choose; //��� ����
	int put_grade; //ã����� �й�
	int check = 0; //ã�� ����
	int i; //for�� ���
	int sub_choose; //���� ����
	int Big_korean; //�������� 1��
	int Big_data; //�ڷᱸ�� 1��
	int step; //���� 1�� ������ ����
	int remove = 0;//������ �������� ����

	stu = (Stu*)malloc(sizeof(Stu) * MAX);

	while (1) //0�Է½� �����Ű�� ���ؼ� ���ѹݺ���
	{
		check = 0;
		printf("\t-1�� : ���� �Է�-\n\t-2�� : ���� �˻�-\n\t-3�� : ���� ����-\n\t-4�� : 1�� ���-\n\t-5�� : ������ �� ����-\n\t(0 �Է½� ����)\n\n");
		printf("�Է� : ");
		scanf("%d", &choose);
		printf("\n");
		if (choose == 0)
		{
			break;
		}
		switch (choose)
		{
		case(1)://���� �Է�
		{
			if (NumOfData > MAX)
			{
				printf("%d�� �̻� ������ �� �����ϴ�.\n", MAX);
			}
			else
			{
				Input(&stu[NumOfData]);
				printf("�Է� ����!\n\n");
				NumOfData++;
			}
			printf("\n1�� �� �̵��˴ϴ�...\n");
			Sleep(1000); //1�� �� �ܼ� Ŭ����
			system("cls");
			break;
		}
		case(2): //���� �˻�
		{
			printf("ã���� �ϴ� �й��� �Է����ּ���(����-0000)(0 �Է½� ��ɼ������� �̵�) : ");
			scanf("%d", &put_grade);

			if (put_grade == 0)
			{
				printf("�̵��մϴ�.\n\n");
				Sleep(1000); //1�� �� �ܼ� Ŭ����
				system("cls");
				break;
			}
			for (i = 0; i < NumOfData; i++)
			{
				if (put_grade == stu[i].grade)
				{
					check = 1;
					break;
				}
			}
			if (check == 1)
			{
				Serch(&stu[i]);
			}
			else
			{
				printf("�Է��� �й��� ã�� ���߽��ϴ�.\n");
			}

			printf("\n2�� �� �̵��˴ϴ�...\n");
			Sleep(2000); //2�� �� �ܼ� Ŭ����
			system("cls");
			break;
		}
		case (3): //���� ����
		{
			printf("�����ϰ��� �ϴ� �й� �Է�(����-0000) : ");
			scanf("%d", &put_grade);
			for (i = 0; i < NumOfData; i++)
			{
				if (put_grade == stu[i].grade)
				{
					check = 1;
					break;
				}
			}
			if (check == 1)
			{
				Delete(&stu[i]);
				printf("\n���� �Ϸ�!\n");
				Serch(&stu[i]);
				remove++;
			}
			else
			{
				printf("�Է��� �й��� ã�� ���߽��ϴ�.\n\n");
			}

			printf("\n2�� �� �̵��˴ϴ�...\n");
			Sleep(2000); //1�� �� �ܼ� Ŭ����
			system("cls");
			break;
		}
		case (4): //1�� ���
		{
			Big_korean = -1; //���� ���� ���� ���� ������ -1�� �ʱ�ȭ
			Big_data = -1; //���� ���� �ڷᱸ�� ���� ������ -1�� �ʱ�ȭ
			printf("1�� : ����\n2�� : �ڷᱸ��\n");
			printf("�Է� : ");
			scanf("%d", &sub_choose);

			switch (sub_choose)
			{
			case (1):
			{
				for (i = 0; i < NumOfData; i++) //���� ū ���� ã��
				{
					if (Big_korean < stu[i].korean)
					{
						Big_korean = stu[i].korean; //���� ū ���� ����
						step = i;//���������� ���� ū �л��� �迭 ������ ����
					}
				}
				if (Big_korean == -1) //�ʱ�ȭ �� ���� �״�ζ�� �����Ͱ� ����
				{
					printf("�����Ͱ� �����ϴ�.\n\n");
				}
				else
				{
					printf("\n	���� 1��	");
					Serch(&stu[step]);
				}
				printf("\n5�� �� �̵��˴ϴ�...\n");
				Sleep(5000); //5�� �� �ܼ� Ŭ����
				system("cls");
				break;
			}
			case (2):
			{
				for (i = 0; i < NumOfData; i++) //���� ū ���� ã��
				{
					if (Big_data < stu[i].data_str)
					{
						Big_data = stu[i].data_str; //�ڷᱸ�� ���� ū ���� ����
						step = i; //�ڷᱸ�� ������ ���� ū �л��� �迭 ������ ����
					}
				}
				if (Big_data == -1) //�ʱ�ȭ �� ���� �״�ζ�� �����Ͱ� ����
				{
					printf("�����Ͱ� �����ϴ�.\n\n");
				}
				else
				{
					printf("\n	�ڷᱸ�� 1��	");
					Serch(&stu[step]);
				}
				printf("\n5�� �� �̵��˴ϴ�...\n");
				Sleep(5000); //5�� �� �ܼ� Ŭ����
				system("cls");
				break;
			}
			default:
			{
				printf("�߸��� ���� �Է��߽��ϴ�. ��� ����â���� �̵��մϴ�.\n");

				printf("\n2�� �� �̵��˴ϴ�...\n");
				Sleep(2000); //2�� �� �ܼ� Ŭ����
				system("cls");
				break;
			}
			}
			break;
		}
		case(5):
		{
			printf("����� ������ �� ���� : %d\n", NumOfData - remove); //NumOfData�� ���� ���̸� �����͸� ã�� �� ������ ����
			printf("\n2�� �� �̵��˴ϴ�...\n");
			Sleep(2000); //2�� �� �ܼ� Ŭ����
			system("cls");
			break;
		}
		default:
		{
			printf("������ ��ȣ �� �߸��� ��ȣ�� �Է��߽��ϴ�.\n\n");
			Sleep(1000); //1�� �� �ܼ� Ŭ����
			system("cls");
			break;
		}
		}
	}



	free(stu);
	return 0;
}