#include "header.h"

void Serch(Stu* stu)
{
	printf("\n");
	printf("----------------------------------\n");
	printf("학번 : %d\n", stu->grade);
	printf("이름 : %s\n", stu->name);
	printf("주소 : %s\n", stu->ad);
	printf("전화번호 : %s\n", stu->phone);
	printf("국어점수 : %d\n", stu->korean);
	printf("자료구조 점수 : %d\n", stu->data_str);
	printf("----------------------------------");
	printf("\n\n");
}
void Input(Stu* stu)
{
	int grade_check; //학번이 4자리가 맞는지 확인
	int school_grade; //대소고 학번이 맞는지 확인
	int phone_check_len; //전화번호가 양식에 맞는지 확인
	int korea_check; //국어 점수가 0~100인지
	int data_check; //자료구조 점수가 0~100인지

	while (1)
	{
		printf("학번 입력(형식-0000) : ");
		scanf("%d", &stu->grade);
		grade_check = Check_Grade(stu->grade);
		school_grade = DGSW_Check(stu->grade);
		if (grade_check == 4) //4자리가 맞으면 진행
		{
			if (school_grade == 1)
			{
				printf("이름 입력 : ");
				scanf("%s%*c", stu->name); //버퍼가 남아있어 문제가 생김 -> %*c 사용
				printf("주소 입력 : ");
				gets(stu->ad); //주소는 띄워쓰기 사용해야되기 때문에 gets로 받음
				while (1)
				{
					printf("전화번호 입력(010-XXXX-XXXX) : ");
					scanf("%s", stu->phone);
					phone_check_len = Str_len(stu->phone);
					if (phone_check_len == 13) //010-XXXX-XXXX -> 13자리
					{
						break;
					}
					else
					{
						printf("전화번호 입력이 형식에 맞지 않아 다시 입력합니다.\n\n");
					}
				}
				while (1) //국어와 자료구조 점수가 올바른지
				{
					printf("국어 점수 입력 : ");
					scanf("%d", &stu->korean);
					printf("자료구조 점수 입력 : ");
					scanf("%d", &stu->data_str);
					korea_check = Score_Check(stu->korean);
					data_check = Score_Check(stu->data_str);
					if (korea_check == 1 && data_check == 1)
					{
						break;
					}
					else
					{
						printf("점수가 0~100이 아니기 때문에 다시 입력합니다.\n\n");
					}
				}
				break;
			}
			else //대소고 학반번호에 맞지 않다면
			{
				printf("대소고 학번에 맞지 않아 다시 입력합니다.\n\n");
			}
		}
		else //4자리가 아니면 다시 입력
		{
			printf("학번 형식이 맞지 않아 다시 입력합니다.\n\n");
		}
	}
}

int Check_Grade(int grade) //학번 형식이 맞는지 확인
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
	return strlen(arr); //문자열 길이 구하기
}

int Delete(Stu* stu)
{
	stu->grade = NULL; //학번 0으로 초기화
	strcpy(stu->name, "전학"); //이름 초기화
	strcpy(stu->ad, ""); //주소 초기화
	strcpy(stu->phone, ""); //전화번호 초기화
	stu->korean = NULL; //국어점수 -1로 초기화
	stu->data_str = NULL; //자료구조 점수 -1로 초기화
}

int DGSW_Check(int grade)
{
	int i;//학년
	int j;//반
	int k;//번호

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