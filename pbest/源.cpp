#include<stdio.h>
#include<stdlib.h>
//#include"db.h"

#define NUM 5	// ��Ʒ����
#define FANG 8	// ��������
int pbest[FANG][NUM] = { 0 };	// ��ʼ��������ʷ��ѷ���
int gbest[NUM] = { 0 };	//��ʼ��Ⱥ����ʷ��ѷ���

int main() {
	int i, j;
	for (i = 0; i < FANG; i++)
		for (j = 0; j < NUM; j++) {
			pbest[i][j] = 9999;
			gbest[j] = 9999;
		}
	getchar();
	return 0;
}