/*	
	-----0/1背包问题-----
	设定背包容量，物品重量、价值属性
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
#define BACK 10 // 背包容量
#define ROUND 2000000 // 迭代轮数
typedef int value;
typedef int weight;

int x[FANG][NUM] = { 0 };
int v[FANG][NUM] = { 0 };
weight backpack = BACK;
weight things_weight[NUM] = { 2,2,6,5,4 };	// 每件物品的重量
value things_values[NUM] = { 6,3,5,4,6 };	// 每件物品的价值
value f[FANG] = { 0 };	// 所有背包方案当前的总价值
value f_0[FANG] = { 0 };	// 所有背包方案历史最佳总价值
int pbest[FANG][NUM] = { 0 };	// 初始化个体历史最佳方案
int gbest[NUM] = { 0 };	//初始化群体历史最佳方案

// 生成随机数
int rand_int(){
	int number;
	number = rand() % 2;
	return number;	// 随机数0,1
}

float rand_float() {
	float number;
	number = rand() / (RAND_MAX + 1.0);
	return number;	// 随机数0,1
}

// 初始化各个背包方案、速度
int init(){
	int i, j;
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++) {
			v[i][j] = rand_int();
		}
	
	// 用物品重量表示背包方案
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++) {
			x[i][j] = things_weight[j];
			if (v[i][j] == 0)
				x[i][j] = 0;	// 与运算计算实际放入的物品
		}

	return 0;	// 想办法返回两个二维数组???
}

// 计算总价值最高的方案序号
int compare() {
	int count = 0, max = 0;
	int i;
	for (i = 0; i < FANG; i++)
		if (f_0[i] > max) {
			max = f_0[i];
			count = i;
		}

	return count;
}

/*
	1.评估背包价值
	2.更新pbest
	3.更新gbest
*/
int evaluate(){
	int i, j;
	// 计算当前每个背包方案的总价值
	for(i=0;i<FANG;i++)
		for (j = 0; j < NUM; j++) {
			f[i] = f[i] + things_values[j] * v[i][j];
		}
	// 更新个体历史最佳方案
	// 更新背包历史最佳总价值
	for (i = 0; i<FANG; i++)
		if (f_0[i] < f[i]) {
			f_0[i] = f[i];
			for (j = 0; j < NUM; j++)
				pbest[i][j] = x[i][j];
		}
	// 更新群体历史最佳方案
	int best;
	best = compare();
	for (i = 0; i < FANG; i++)
		if (i == best) {
			for (j = 0; j < NUM; j++)
				gbest[j] = pbest[i][j];
		}
			

	return 0;
}

// 更新背包方案
// 尚未限制速度范围，不知道确定在0，1之间算不算限定
int update(int round){
	float w = 0.9, c1 = 2.0, c2 = 2.0;//惯量权重、加速系数
	float r1, r2;
	r1 = rand_float();
	r2 = rand_float();
	int i, j;
	float temp;
	// w的线性衰减
	w = w - round / (ROUND * 2);
	for (i = 0; i < FANG; i++) {
		for (j = 0; j < NUM; j++) {
			// 采用四舍五入进行0，1量化
			// 除以v[i][j]+2*(pbest[i][j] - x[i][j])
			temp = (w*v[i][j] + c1*r1*(pbest[i][j] - x[i][j]) + c2*r2*(pbest[i][j] - x[i][j])) / (v[i][j] + 2 * (pbest[i][j] - x[i][j]));
			v[i][j] = int(temp + 0.5);
			// 需要观察测试v的变化
		}
		if (v[i][j] == 0)
			x[i][j] = 0;	// 与运算计算实际放入的物品
	}
	 

	return 0;
}

int main(){
	int i, j;
	for (i = 0; i < FANG; i++)
		for (j = 0; j < NUM; j++) {
			pbest[i][j] = 9999;
			gbest[j] = 9999;
		}
	// 初始化时间种子
	srand((unsigned)time(NULL));
	// 随机初始化背包方案、速度
	init();
	evaluate();
	// 迭代20轮
	for (i = 0; i < ROUND; i++) {
		update(i);
		evaluate();
	}

	for (i = 0; i < NUM; i++) {
		printf("%d ", gbest[i]);
	}

	getchar();
	return 0;
}