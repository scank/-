#define  _CRT_SECURE_NO_WARNINGS
#define c 3
#define k 3
#include<stdio.h>
//#include"game.h"
int pj(char arr[c][k],int C,int K)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < C; i++)//�ж�ƽ��
	{
		for (j = 0; j < K; j++)
		{
			if (arr[i][j] != ' ')
			{
				return 0;//����û����
			}
		}

	}
	return 'l';//��������
}



char panduan(char arr[c][k], int C, int K)
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < C; i++)//�ж�3��
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
		   return arr[i][1];
	    }
	}

	for (i = 0; i < K; i++)//�ж�3��
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			return arr[1][i];
		}

	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')//�ж϶Խ���
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}

	int ed = pj(arr, C, K);
	if (ed == 1)
	{
		return 'Q';
	}
		return '!';
}

void wanjia1(char arr[c][k], int C, int K) {
	printf("\n���1��\n");
	int q = 0;
	int w = 0;
	while (1) 
	{
		printf("\n����������\n");
		scanf("%d %d", &q, &w);
		if (q >= 0 && q < C && w >= 0 && w < K)
		{
			if (arr[q][w] == ' ') 
			{
			arr[q][w] = '*';
			break;
		    }
			else
			{
				printf("\n�����Ա�ռ�ã�����������\n");
			}
		}
		else 
		{
			printf("\n�����������������\n");
		}
    }
}
void wanjia2(char arr[c][k], int C, int K) {
	printf("\n���2��\n");
	int q = 0;
	int w = 0;
	while (1)
	{
		printf("\n����������\n");
		scanf("%d %d", &q, &w);
		if (q >= 0 && q < C && w >= 0 && w < K)
		{
			if (arr[q][w] == ' ')
			{
				arr[q][w] = '#';
				break;
			}
			else
			{
				printf("\n�����Ա�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("\n�����������������\n");
		}
	}
}
void dayin(char arr[c][k],int C,int K )//��ӡ�����������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < C; i++)
	{
		for (j = 0; j < K; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < K - 1)
			{
				printf("|");
			}
		}

		printf("\n");
		if (i < C - 1)
		{
			for (j = 0; j < K; j++)
			{
				printf("---");
				if (j < K - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void chushihua(char arr[c][k], int C, int K) //�������ʼ��
{
	int x = 0;
	int y = 0;
	for (x = 0; x < c; x++)
	{
		for (y = 0; y < k; y++)
		{
			arr[x][y] = ' ';
		}
	}
}
void game() 
{
	char arr[c][k];//����һ������
	chushihua(arr,c,k);//�������ʼ��
	dayin(arr,c,k);//��ӡ�����������
	char ret;
	while (1)
	{
		wanjia1(arr, c, k);//�����
		dayin(arr, c, k);//�ٴδ�ӡ����
		ret=panduan(arr,c,k);//�ж���Ϸ����Ӯ
		if (ret != '!')
		{
			break;
		}
		wanjia2(arr, c, k);//��һ�������
		dayin(arr, c, k);//�ٴδ�ӡ
		ret = panduan(arr, c, k);//�ж���Ϸ����Ӯ
		if (ret != '!')
		{
			break;
		}
	}
	if (ret == '*')
	{

		printf("\n���1Ӯ��\n");
		printf("\n������Ӯ��:\n");
		dayin(arr, c, k);
		
	}
	else if (ret == '#')
	{
		printf("\n���2Ӯ��\n");
		printf("\n������Ӯ��:\n");
		dayin(arr, c, k);

	}
	else
	{
		printf("\nƽ��\n");
		printf("\n������ƽ�ֵ�:\n");
		dayin(arr, c, k);
	}
}
void menu() 
{
	printf("\n----1.������Ϸ-----\n");
	printf("\n----0.�˳���Ϸ-----\n");
}
int main()
{
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 0:
			{
				printf("�˳���Ϸ\n");
				break;
			}
			case 1:
			{
				printf("��ʼ��Ϸ\n");
				game();
				break;
			}
			default:
			{
				printf("�����������������\n");
				break;
			}
		}
	} while (input);

	return 0;
}