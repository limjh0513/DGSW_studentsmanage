#include "header.h"

void Serch(Stu* stu)
{
	printf("\n");
	printf("----------------------------------\n");
	printf("�й� : %d\n", stu->grade);
	printf("�̸� : %s\n", stu->name);
	printf("�ּ� : %s\n", stu->ad);
	printf("��ȭ��ȣ : %s\n", stu->phone);
	printf("�������� : %d\n", stu->korean);
	printf("�ڷᱸ�� ���� : %d\n", stu->data_str);
	printf("----------------------------------");
	printf("\n\n");
}
void Input(Stu* stu)
{
	int grade_check; //�й��� 4�ڸ��� �´��� Ȯ��
	int school_grade; //��Ұ� �й��� �´��� Ȯ��
	int phone_check_len; //��ȭ��ȣ�� ��Ŀ� �´��� Ȯ��
	int korea_check; //���� ������ 0~100����
	int data_check; //�ڷᱸ�� ������ 0~100����

	while (1)
	{
		printf("�й� �Է�(����-0000) : ");
		scanf("%d", &stu->grade);
		grade_check = Check_Grade(stu->grade);
		school_grade = DGSW_Check(stu->grade);
		if (grade_check == 4) //4�ڸ��� ������ ����
		{
			if (school_grade == 1)
			{
				printf("�̸� �Է� : ");
				scanf("%s%*c", stu->name); //���۰� �����־� ������ ���� -> %*c ���
				printf("�ּ� �Է� : ");
				gets(stu->ad); //�ּҴ� ������� ����ؾߵǱ� ������ gets�� ����
				while (1)
				{
					printf("��ȭ��ȣ �Է�(010-XXXX-XXXX) : ");
					scanf("%s", stu->phone);
					phone_check_len = Str_len(stu->phone);
					if (phone_check_len == 13) //010-XXXX-XXXX -> 13�ڸ�
					{
						break;
					}
					else
					{
						printf("��ȭ��ȣ �Է��� ���Ŀ� ���� �ʾ� �ٽ� �Է��մϴ�.\n\n");
					}
				}
				while (1) //����� �ڷᱸ�� ������ �ùٸ���
				{
					printf("���� ���� �Է� : ");
					scanf("%d", &stu->korean);
					printf("�ڷᱸ�� ���� �Է� : ");
					scanf("%d", &stu->data_str);
					korea_check = Score_Check(stu->korean);
					data_check = Score_Check(stu->data_str);
					if (korea_check == 1 && data_check == 1)
					{
						break;
					}
					else
					{
						printf("������ 0~100�� �ƴϱ� ������ �ٽ� �Է��մϴ�.\n\n");
					}
				}
				break;
			}
			else //��Ұ� �йݹ�ȣ�� ���� �ʴٸ�
			{
				printf("��Ұ� �й��� ���� �ʾ� �ٽ� �Է��մϴ�.\n\n");
			}
		}
		else //4�ڸ��� �ƴϸ� �ٽ� �Է�
		{
			printf("�й� ������ ���� �ʾ� �ٽ� �Է��մϴ�.\n\n");
		}
	}
}

int Check_Grade(int grade) //�й� ������ �´��� Ȯ��
{
	int cnt = 0;

	while (grade > 0)
	{
		grade /= 10;
		cnt++;
	}
	return cnt;
}

int Score_Check(int score)
{
	if (score >= 0 && score <= 100) //0~100
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Str_len(char* arr)
{
	return strlen(arr); //���ڿ� ���� ���ϱ�
}

int Delete(Stu* stu)
{
	stu->grade = NULL; //�й� 0���� �ʱ�ȭ
	strcpy(stu->name, "����"); //�̸� �ʱ�ȭ
	strcpy(stu->ad, ""); //�ּ� �ʱ�ȭ
	strcpy(stu->phone, ""); //��ȭ��ȣ �ʱ�ȭ
	stu->korean = NULL; //�������� -1�� �ʱ�ȭ
	stu->data_str = NULL; //�ڷᱸ�� ���� -1�� �ʱ�ȭ
}

int DGSW_Check(int grade)
{
	int i;//�г�
	int j;//��
	int k;//��ȣ

	i = grade / 1000;
	j = grade / 100 % 10;
	k = grade % 100;

	if (i > 0 && i <= DGSW_GRADE)
	{
		if (j > 0 && j <= DGSW_CLASS)
		{
			if (k > 0 && k <= DGSW_NUMBER)
			{
				return 1;
			}
		}
	}
	return 0;
}