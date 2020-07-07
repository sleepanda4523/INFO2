#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define X 19
typedef struct MyStruct
{
	int y, x;
}Dir;
int win = 0;
int wx, wy;
Dir move[4] = { {0,1},{1,0},{1,1},{-1,1} }; //������ ����, ������ ����, ������ �밢�� �Ʒ�, ���� �밢�� �Ʒ�

void find(int(*pdata)[X], int y, int x, int cnt, int color, int d)
{
	if (x == -1 || y == -1 || y == X || x == X)		return;

	if (cnt == 1) {
		for (int i = 0; i < 4; i++) {
			if (pdata[y + move[i].y][x + move[i].x] == color) {
				find(pdata, y + move[i].y, x + move[i].x, cnt + 1, color, i);
			}
		}
	}
	if (cnt == 5 && pdata[y + move[d].y][x + move[d].x] != color && pdata[y - move[d].y * 5][x - move[d].x * 5] != color) {
		win = color;
		wy = y - move[d].y * 4 + 1;
		wx = x - move[d].x * 4 + 1;
		return;
	}
	if (cnt >= 2 && pdata[y + move[d].y][x + move[d].x] == color) {
		find(pdata, y + move[d].y, x + move[d].x, cnt + 1, color, d);
	}
	else {
		return;
	}
}
int input(int(*pdata)[X], int* turn)
{
	int x, y;
	int cnt = 0;
	printf("%s�� �����Դϴ�. \n", ((*turn == 0) ? "��" : "��"));
	printf("��� ��ǥ�� ���� �����ðڽ��ϱ�?(���� ����) >> ");
	scanf("%d %d", &y, &x);
	if (x == -1 || y == -1 || x == X || y == X) {
		printf("������ ������ϴ�.\n");
	}
	else if (pdata[y][x] != 0) {
		printf("�̹� ���� �ֽ��ϴ�.\n");
	}
	else {
		pdata[y][x] = (*turn == 0) ? 1 : 2;
		for (int i = 0; i < X; i++) {
			if (win != 0) break;
			for (int j = 0; j < X; j++) {
				if (pdata[i][j] != 0) {
					find(pdata, i, j, 1, pdata[i][j], 0);
				}
			}
		}
		if (win > 0) {
			if (win == 1) {
				printf("���� �¸��Դϴ�!\n");
				return 1;
			}
			else if (win == 2) {
				printf("���� �¸��Դϴ�!\n");
				return 1;
			}
		}
		if (*turn == 0) {
			*turn = 1;
		}
		else if (*turn == 1) {
			*turn = 0;
		}
	}
	return 0;

}
void output(int(*pdata)[X])
{
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X; j++) {
			printf("%d ", pdata[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int turn = 0;
	int table[X][X];
	int end = 0;
	for (int i = 0; i < X; i++) {
		memset(table[i], 0, sizeof(int) * X);
	}

	output(table);
	while (1) {
		end = input(table, &turn);
		if (end == 1) {
			output(table);
			return 0;
		}
		output(table);
	}

	return 0;
}