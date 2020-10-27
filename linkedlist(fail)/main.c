#include "header.h"


int main(void)
{
	Link link;
	stu stus;
	stu cpystu;
	stuInit(&link, &stus);
	int choose; //기능 선택
	int grade_put; //학번 검색
	int grade_bring = 0; //함수에서 return 받은 grade값
	int check = 0; //값이 있는지 확인

	while (1)
	{
		check = 0;
		printf("-1번 : 정보 입력-\n-2번 : 정보 검색-\n-3번 : 정보 삭제-\n-4번 : 1등 출력-\n(0 입력시 종료)\n\n");
		printf("입력 : ");
		scanf("%d", &choose);
		if (choose == 0) // 0 입력 시 종료
		{
			break;
		}
		switch (choose)
		{
		case (1): //정보 입력
		{
			printf("학번, 이름, 주소, 전화번호(010-XXXX-XXXX),\n국어점수, 자료구조 점수를 차례대로 입력\n\n");
			scanf("%d %s %s %s %d %d", &stus.grade, stus.name, stus.ad, stus.phone, &stus.korean, &stus.data_str);
			SInsert(&link, &stus);
			break;
		}
		case(2): //정보 검색
		{
			printf("검색하고 싶은 학번을 입력 : ");
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
				printf("값을 찾지 못했습니다.\n\n");
			}

			break;
		}
		case(3): //정보 삭제
		{

			printf("삭제하고자 하는 학번을 입력 : ");
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
				printf("값을 찾지 못했습니다.\n\n");
			}
			else
			{
				printf("%d 삭제 완료!\n\n", check);
			}
			break;
		}
		case (4): //1등 출력
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
			printf("지정된 번호 외 잘못된 번호를 입력했습니다.\n\n");
			break;
		}
		}
		printf("%d", link.numOfData);
		Sleep(2000);
		system("cls");
	}

	printf("현재 데이터 수 : %d\n", link.numOfData);
	

	return 0;
}