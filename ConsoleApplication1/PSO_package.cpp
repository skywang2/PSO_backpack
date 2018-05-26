/*	
	-----0/1背包问题-----
	设定背包，物品重量、价值属性
	位置x = 背包方案（可行解）
	速度v = 用0、1表示的是否放入物品
	评估对象 = 背包总价值
	pbest = 个人背包历史最大价值
	gbest = 群体背包历史最大价值
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 5	// 物品个数
#define FANG 8	// 方案个数
typedef int value;
typedef int weight;

// 生成随机数
int rand_num(){
	int i;
	int number;
	srand((unsigned)time(NULL));
	number = rand() % 2;
	return number;	// 随机数0,1
}

// 初始化各个背包方案、速度
int init(int v[FANG][NUM], int x[FANG][NUM]){
	int i, j;
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++) {
			v[i][j] = rand_num();
		}
	
	// 用物品重量表示背包方案
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++) {
			x[i][j] = things_weight[j];
			x[i][j] = x[i][j] && things_weight[j];	// 与运算计算实际放入的物品
		}

	return 0;	// 想办法返回两个二维数组???
}

/*
	1.评估背包价值
	2.更新pbest
	3.更新gbest
*/
int evaluate(int things_value[NUM], int x[FANG][NUM], int pbest[FANG][NUM], int gbest[NUM]){
	int i, j;
	// 计算每个背包方案的总价值
	for(i=0;i<FANG;i++)
		for (j = 0; j < NUM; j++) {
			f[i] = f[i] + x[i][j] * things_value[j];
		}
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++)
			pbest[i][j] = x[i][j];
	for (i = 0; i < FANG; i++)
		if (i == compare(f))
			for (j = 0; j < NUM; j++)
				gbest[NUM] = pbest[i][j];

	return 0;	// 返回???
}

// 计算总价值最高的方案序号
int compare(int f[FANG]) {
	int count = 0, max = 0;
	int i;
	for (i = 0; i < FANG; i++)
		if (f[i] > max) {
			max = f[i];
			count = i;
		}

	return count;
}

// 更新背包方案
int update(){

}

int v[FANG][NUM] = { 0 };
int x[FANG][NUM] = { 0 };
weight things_weight[NUM] = { 2,2,6,5,4 };	// 每件物品的重量
value things_values[NUM] = { 6,3,5,4,6 };	// 每件物品的价值
value f[FANG] = { 0 };	// 该背包方案当前的总价值
int pbest[FANG][NUM] = { 0 };	// 初始化个体历史最佳方案
int gbest[NUM] = { 0 };	//初始化群体历史最佳方案
 
int main(){
	int i, j;
	for (i = 0; i < FANG; i++)
		for (j = 0; j < NUM; i++) {
			pbest[i][j] = 9999;
			gbest[j] = 9999;
		}		
	// 随机初始化背包方案、速度
	init(v, x);
	evaluate(things_values, x, pbest, gbest);

	

	return 0;
}