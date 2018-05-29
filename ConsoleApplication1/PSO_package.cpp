/*	
	-----粒子群优化算法解0/1背包问题-----
	设定背包容量，物品重量、价值属性
	位置x = 背包方案（可行解）
	速度v = 用0、1表示的是否放入物品
	评估对象 = 背包总价值
	pbest = 单个背包方案历史最大价值
	gbest = 群体背包历史最大价值
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 10	// 物品个数
#define FANG 20	// 方案个数
#define BACK 269 // 背包容量
#define ROUND 43 // 迭代轮数
typedef int value;
typedef int weight;

int x[FANG][NUM] = { 0 };	// 背包方案（可行解）
int v[FANG][NUM] = { 0 };	// 用0、1表示的是否放入物品
weight things_weight[NUM] = { 95,4,60,32,23,72,80,62,65,46 };	// 每件物品的重量
weight backpack_weight[FANG] = { 0 };	// 每个背包方案当前的总重量
value things_values[NUM] = { 55,10,47,5,4,50,8,61,85,87 };	// 每件物品的价值
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

int rand_drop() {
	int number;
	number = rand() % NUM;
	return number;	// 随机数0~4
}

float rand_float() {
	float number;
	number = rand() / (RAND_MAX + 1.0);
	return number;	// 随机数0~1
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

	return 0;
}

// 计算总价值最高的方案序号
int compare() {
	int count = 0, max = 0;
	int i;
	for (i = 0; i < FANG; i++) {
		if (f_0[i] > max) {
			max = f_0[i];
			count = i;
		}
	}
		

	return count;
}

/*
	1.评估背包价值
	2.更新pbest
	3.更新gbest
*/
int evaluate(){
	int i, j, k, drop;

	// ==================================================
	// 计算每个背包方案的总重量
	for (i = 0; i < FANG; i++) {
		backpack_weight[i] = 0;
		for (j = 0; j < NUM; j++) {
			backpack_weight[i] += x[i][j];
		}
	}

	// 如果更新后的方案总重量大于背包容量则随机丢弃一件物品
	// 任意丢弃一件物品直到不超过背包大小
	// 最多丢弃NUM，也就是把物品全丢掉
	for (i = 0; i < FANG; i++) {
		for (j = 0; j < NUM; j++) {
			if (backpack_weight[i] <= BACK)break;
			// 使得丢弃的物品是背包中存在的物品，最多随机等同物品种类次数
			drop = 0;
			for (k = 0; k < 10*NUM; k++) {
				drop = rand_drop();
				if (v[i][drop] > 0)break;
			}
			if (backpack_weight[i] > BACK) {
				v[i][drop] = 0;
				x[i][drop] = 0;
				// 减去丢弃的物品重量
				backpack_weight[i] -= things_weight[drop];
			}
			else
				break;
		}
	}
	// ==================================================

	// 计算当前每个背包方案的总价值
	for (i = 0; i < FANG; i++) {
		f[i] = 0;
		for (j = 0; j < NUM; j++) {
			f[i] += things_values[j] * v[i][j];
		}
	}

	// 更新当前方案历史最佳方案、价值
	for (i = 0; i < FANG; i++) {
		if (f_0[i] < f[i]) {
			f_0[i] = f[i];
			for (j = 0; j < NUM; j++)
				pbest[i][j] = x[i][j];
		}
	}
		
	// 更新群体历史最佳方案
	int best;
	best = compare();
	for (i = 0; i < FANG; i++) {
		if (i == best) {
			for (j = 0; j < NUM; j++)
				gbest[j] = pbest[i][j];
		}	
	}
		

	return 0;
}

// 更新背包方案
// 如果更新方案的总重量大于背包容量，随机丢弃一件物品
int update(int round){
	float w = 0.9, c1 = 2.0, c2 = 2.0;//惯量权重、加速系数
	float r1, r2;
	int i, j, k;
	int drop;
	float temp;
	int test = 0;
	r1 = rand_float();
	r2 = rand_float();

	// w的线性衰减
	w = w - round / (ROUND * 2);
	
	for (i = 0; i < FANG; i++) {
		for (j = 0; j < NUM; j++) {
			// 采用四舍五入进行0，1量化
			// 除以v[i][j]+2*(pbest[i][j] - x[i][j])
			if (pbest[i][j] != x[i][j])
				temp = (w*v[i][j] + c1*r1*(pbest[i][j] - x[i][j]) + c2*r2*(pbest[i][j] - x[i][j])) / (v[i][j] + 2 * (pbest[i][j] - x[i][j]));
			else
				temp = rand_float();
			v[i][j] = int(temp + 0.5);
			if (v[i][j] > 1)v[i][j] = 1;
			if ((v[i][j] == 1) && (x[i][j] == 0))	// 当速度变为1且该物品之前未放入，则将该物品放入
				x[i][j] = things_weight[j];
			printf("随机更新出的速度 = %f\n", temp);
		}
	}

	// ==================================================
	// 计算每个背包方案的总重量
	for (i = 0; i < FANG; i++) {
		backpack_weight[i] = 0;
		for (j = 0; j < NUM; j++) {
			backpack_weight[i] += x[i][j];
		}
	}
		
	// 如果更新后的方案总重量大于背包容量则随机丢弃一件物品
	// 任意丢弃一件物品直到不超过背包大小
	// 最多丢弃NUM，也就是把物品全丢掉
	for (i = 0; i < FANG; i++) {
		for (j = 0; j < NUM; j++) {
			if (backpack_weight[i] <= BACK)break;
			// 使得丢弃的物品是背包中存在的物品，最多随机等同物品种类次数
			drop = 0;
			for (k = 0; k < 10*NUM;k++) {
				drop = rand_drop();
				if (v[i][drop] > 0)break;
			}
			if (backpack_weight[i] > BACK) {
				v[i][drop] = 0;
				x[i][drop] = 0;
				// 减去丢弃的物品重量
				backpack_weight[i] -= things_weight[drop];
			}
			else
				break;
		}
	}

	// ==================================================

	return 0;
}

int main(){
	int i, j, temp, drop;
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
	// 迭代ROUNd轮
	for (i = 0; i < ROUND; i++) {
		update(i);
		evaluate();
	}

	int value=0;
	temp = compare();
	printf("\n最佳方案内容 = ");
	for (i = 0; i < NUM; i++) {
		printf("%d ", gbest[i]);
		value += (gbest[i] > 0) ? things_values[i] : 0;
	}
	printf("\n最佳方案号 = %d ", temp);
	printf("\n最佳方案背包总价值 = %d ", value);
	printf("\n所有方案中的历史最高价值f_0 = %d ", f_0[temp]);
	printf("hello");
	getchar();
	return 0;
}