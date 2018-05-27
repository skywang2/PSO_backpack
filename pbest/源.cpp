#include<stdio.h>
#include<stdlib.h>
//#include"db.h"

#define NUM 5	// 物品个数
#define FANG 8	// 方案个数
int pbest[FANG][NUM] = { 0 };	// 初始化个体历史最佳方案
int gbest[NUM] = { 0 };	//初始化群体历史最佳方案

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