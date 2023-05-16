#define  _CRT_SECURE_NO_WARNINGS
#define c 3
#define k 3
#include<stdio.h>
//#include"game.h"
int pj(char arr[c][k],int C,int K)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < C; i++)//判断平局
	{
		for (j = 0; j < K; j++)
		{
			if (arr[i][j] != ' ')
			{
				return 0;//棋盘没有满
			}
		}

	}
	return 'l';//棋盘满了
}



char panduan(char arr[c][k], int C, int K)
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < C; i++)//判断3行
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
		   return arr[i][1];
	    }
	}

	for (i = 0; i < K; i++)//判断3列
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			return arr[1][i];
		}

	}

	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')//判断对角线
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
	printf("\n玩家1走\n");
	int q = 0;
	int w = 0;
	while (1) 
	{
		printf("\n请输入坐标\n");
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
				printf("\n坐标以被占用，请重新输入\n");
			}
		}
		else 
		{
			printf("\n坐标错误，请重新输入\n");
		}
    }
}
void wanjia2(char arr[c][k], int C, int K) {
	printf("\n玩家2走\n");
	int q = 0;
	int w = 0;
	while (1)
	{
		printf("\n请输入坐标\n");
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
				printf("\n坐标以被占用，请重新输入\n");
			}
		}
		else
		{
			printf("\n坐标错误，请重新输入\n");
		}
	}
}
void dayin(char arr[c][k],int C,int K )//打印三子棋的棋盘
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
void chushihua(char arr[c][k], int C, int K) //将数组初始化
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
	char arr[c][k];//定义一个数组
	chushihua(arr,c,k);//将数组初始化
	dayin(arr,c,k);//打印三子棋的棋盘
	char ret;
	while (1)
	{
		wanjia1(arr, c, k);//玩家走
		dayin(arr, c, k);//再次打印棋盘
		ret=panduan(arr,c,k);//判断游戏的输赢
		if (ret != '!')
		{
			break;
		}
		wanjia2(arr, c, k);//另一个玩家走
		dayin(arr, c, k);//再次打印
		ret = panduan(arr, c, k);//判断游戏的输赢
		if (ret != '!')
		{
			break;
		}
	}
	if (ret == '*')
	{

		printf("\n玩家1赢了\n");
		printf("\n是这样赢的:\n");
		dayin(arr, c, k);
		
	}
	else if (ret == '#')
	{
		printf("\n玩家2赢了\n");
		printf("\n是这样赢的:\n");
		dayin(arr, c, k);

	}
	else
	{
		printf("\n平局\n");
		printf("\n是这样平局的:\n");
		dayin(arr, c, k);
	}
}
void menu() 
{
	printf("\n----1.进入游戏-----\n");
	printf("\n----0.退出游戏-----\n");
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
				printf("退出游戏\n");
				break;
			}
			case 1:
			{
				printf("开始游戏\n");
				game();
				break;
			}
			default:
			{
				printf("输入错误，请重新输入\n");
				break;
			}
		}
	} while (input);

	return 0;
}