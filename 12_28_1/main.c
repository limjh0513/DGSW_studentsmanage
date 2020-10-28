#include "header.h"

int main(void)
{
	Stu* stu; //200명 저장
	int NumOfData = 0; //현재 저장된 학생 수
	int choose; //기능 선택
	int put_grade; //찾고싶은 학번
	int check = 0; //찾은 여부
	int i; //for문 사용
	int sub_choose; //과목 선택
	int Big_korean; //국어점수 1등
	int Big_data; //자료구조 1등
	int step; //과목 1등 번지수 저장
	int remove = 0;//삭제된 데이터의 갯수

	stu = (Stu*)malloc(sizeof(Stu) * MAX);

	while (1) //0입력시 종료시키기 위해서 무한반복문
	{
		check = 0;
		printf("\t-1번 : 정보 입력-\n\t-2번 : 정보 검색-\n\t-3번 : 정보 삭제-\n\t-4번 : 1등 출력-\n\t-5번 : 데이터 총 갯수-\n\t(0 입력시 종료)\n\n");
		printf("입력 : ");
		scanf("%d", &choose);
		printf("\n");
		if (choose == 0)
		{
			break;
		}
		switch (choose)
		{
		case(1)://정보 입력
		{
			if (NumOfData > MAX)
			{
				printf("%d명 이상 저장할 수 없습니다.\n", MAX);
			}
			else
			{
				Input(&stu[NumOfData]);
				printf("입력 성공!\n\n");
				NumOfData++;
			}
			printf("\n1초 후 이동됩니다...\n");
			Sleep(1000); //1초 후 콘솔 클리어
			system("cls");
			break;
		}
		case(2): //정보 검색
		{
			printf("찾고자 하는 학번을 입력해주세요(형식-0000)(0 입력시 기능선택으로 이동) : ");
			scanf("%d", &put_grade);

			if (put_grade == 0)
			{
				printf("이동합니다.\n\n");
				Sleep(1000); //1초 후 콘솔 클리어
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
				printf("입력한 학번을 찾지 못했습니다.\n");
			}

			printf("\n2초 후 이동됩니다...\n");
			Sleep(2000); //2초 후 콘솔 클리어
			system("cls");
			break;
		}
		case (3): //정보 삭제
		{
			printf("삭제하고자 하는 학번 입력(형식-0000) : ");
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
				printf("\n삭제 완료!\n");
				Serch(&stu[i]);
				remove++;
			}
			else
			{
				printf("입력한 학번을 찾지 못했습니다.\n\n");
			}

			printf("\n2초 후 이동됩니다...\n");
			Sleep(2000); //1초 후 콘솔 클리어
			system("cls");
			break;
		}
		case (4): //1등 출력
		{
			Big_korean = -1; //가장 높은 국어 점수 번지수 -1로 초기화
			Big_data = -1; //가장 높은 자료구조 점수 번지수 -1로 초기화
			printf("1번 : 국어\n2번 : 자료구조\n");
			printf("입력 : ");
			scanf("%d", &sub_choose);

			switch (sub_choose)
			{
			case (1):
			{
				for (i = 0; i < NumOfData; i++) //가장 큰 점수 찾기
				{
					if (Big_korean < stu[i].korean)
					{
						Big_korean = stu[i].korean; //가장 큰 점수 저장
						step = i;//국어점수의 가장 큰 학생의 배열 번지수 저장
					}
				}
				if (Big_korean == -1) //초기화 한 값이 그대로라면 데이터가 없음
				{
					printf("데이터가 없습니다.\n\n");
				}
				else
				{
					printf("\n	국어 1등	");
					Serch(&stu[step]);
				}
				printf("\n5초 후 이동됩니다...\n");
				Sleep(5000); //5초 후 콘솔 클리어
				system("cls");
				break;
			}
			case (2):
			{
				for (i = 0; i < NumOfData; i++) //가장 큰 점수 찾기
				{
					if (Big_data < stu[i].data_str)
					{
						Big_data = stu[i].data_str; //자료구조 가장 큰 점수 저장
						step = i; //자료구조 점수의 가장 큰 학생의 배열 번지수 저장
					}
				}
				if (Big_data == -1) //초기화 한 값이 그대로라면 데이터가 없음
				{
					printf("데이터가 없습니다.\n\n");
				}
				else
				{
					printf("\n	자료구조 1등	");
					Serch(&stu[step]);
				}
				printf("\n5초 후 이동됩니다...\n");
				Sleep(5000); //5초 후 콘솔 클리어
				system("cls");
				break;
			}
			default:
			{
				printf("잘못된 수를 입력했습니다. 기능 선택창으로 이동합니다.\n");

				printf("\n2초 후 이동됩니다...\n");
				Sleep(2000); //2초 후 콘솔 클리어
				system("cls");
				break;
			}
			}
			break;
		}
		case(5):
		{
			printf("저장된 데이터 총 갯수 : %d\n", NumOfData - remove); //NumOfData의 수를 줄이면 데이터를 찾을 때 오류가 생김
			printf("\n2초 후 이동됩니다...\n");
			Sleep(2000); //2초 후 콘솔 클리어
			system("cls");
			break;
		}
		default:
		{
			printf("지정된 번호 외 잘못된 번호를 입력했습니다.\n\n");
			Sleep(1000); //1초 후 콘솔 클리어
			system("cls");
			break;
		}
		}
	}



	free(stu);
	return 0;
}