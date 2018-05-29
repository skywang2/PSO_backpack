/*	
	-----����Ⱥ�Ż��㷨��0/1��������-----
	�趨������������Ʒ��������ֵ����
	λ��x = �������������н⣩
	�ٶ�v = ��0��1��ʾ���Ƿ������Ʒ
	�������� = �����ܼ�ֵ
	pbest = ��������������ʷ����ֵ
	gbest = Ⱥ�屳����ʷ����ֵ
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 10	// ��Ʒ����
#define FANG 20	// ��������
#define BACK 269 // ��������
#define ROUND 43 // ��������
typedef int value;
typedef int weight;

int x[FANG][NUM] = { 0 };	// �������������н⣩
int v[FANG][NUM] = { 0 };	// ��0��1��ʾ���Ƿ������Ʒ
weight things_weight[NUM] = { 95,4,60,32,23,72,80,62,65,46 };	// ÿ����Ʒ������
weight backpack_weight[FANG] = { 0 };	// ÿ������������ǰ��������
value things_values[NUM] = { 55,10,47,5,4,50,8,61,85,87 };	// ÿ����Ʒ�ļ�ֵ
value f[FANG] = { 0 };	// ���б���������ǰ���ܼ�ֵ
value f_0[FANG] = { 0 };	// ���б���������ʷ����ܼ�ֵ
int pbest[FANG][NUM] = { 0 };	// ��ʼ��������ʷ��ѷ���
int gbest[NUM] = { 0 };	//��ʼ��Ⱥ����ʷ��ѷ���

// ���������
int rand_int(){
	int number;
	number = rand() % 2;
	return number;	// �����0,1
}

int rand_drop() {
	int number;
	number = rand() % NUM;
	return number;	// �����0~4
}

float rand_float() {
	float number;
	number = rand() / (RAND_MAX + 1.0);
	return number;	// �����0~1
}

// ��ʼ�����������������ٶ�
int init(){
	int i, j;
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++) {
			v[i][j] = rand_int();
		}
	
	// ����Ʒ������ʾ��������
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++) {
			x[i][j] = things_weight[j];
			if (v[i][j] == 0)
				x[i][j] = 0;	// ���������ʵ�ʷ������Ʒ
		}

	return 0;
}

// �����ܼ�ֵ��ߵķ������
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
	1.����������ֵ
	2.����pbest
	3.����gbest
*/
int evaluate(){
	int i, j, k, drop;

	// ==================================================
	// ����ÿ������������������
	for (i = 0; i < FANG; i++) {
		backpack_weight[i] = 0;
		for (j = 0; j < NUM; j++) {
			backpack_weight[i] += x[i][j];
		}
	}

	// ������º�ķ������������ڱ����������������һ����Ʒ
	// ���ⶪ��һ����Ʒֱ��������������С
	// ��ඪ��NUM��Ҳ���ǰ���Ʒȫ����
	for (i = 0; i < FANG; i++) {
		for (j = 0; j < NUM; j++) {
			if (backpack_weight[i] <= BACK)break;
			// ʹ�ö�������Ʒ�Ǳ����д��ڵ���Ʒ����������ͬ��Ʒ�������
			drop = 0;
			for (k = 0; k < 10*NUM; k++) {
				drop = rand_drop();
				if (v[i][drop] > 0)break;
			}
			if (backpack_weight[i] > BACK) {
				v[i][drop] = 0;
				x[i][drop] = 0;
				// ��ȥ��������Ʒ����
				backpack_weight[i] -= things_weight[drop];
			}
			else
				break;
		}
	}
	// ==================================================

	// ���㵱ǰÿ�������������ܼ�ֵ
	for (i = 0; i < FANG; i++) {
		f[i] = 0;
		for (j = 0; j < NUM; j++) {
			f[i] += things_values[j] * v[i][j];
		}
	}

	// ���µ�ǰ������ʷ��ѷ�������ֵ
	for (i = 0; i < FANG; i++) {
		if (f_0[i] < f[i]) {
			f_0[i] = f[i];
			for (j = 0; j < NUM; j++)
				pbest[i][j] = x[i][j];
		}
	}
		
	// ����Ⱥ����ʷ��ѷ���
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

// ���±�������
// ������·��������������ڱ����������������һ����Ʒ
int update(int round){
	float w = 0.9, c1 = 2.0, c2 = 2.0;//����Ȩ�ء�����ϵ��
	float r1, r2;
	int i, j, k;
	int drop;
	float temp;
	int test = 0;
	r1 = rand_float();
	r2 = rand_float();

	// w������˥��
	w = w - round / (ROUND * 2);
	
	for (i = 0; i < FANG; i++) {
		for (j = 0; j < NUM; j++) {
			// ���������������0��1����
			// ����v[i][j]+2*(pbest[i][j] - x[i][j])
			if (pbest[i][j] != x[i][j])
				temp = (w*v[i][j] + c1*r1*(pbest[i][j] - x[i][j]) + c2*r2*(pbest[i][j] - x[i][j])) / (v[i][j] + 2 * (pbest[i][j] - x[i][j]));
			else
				temp = rand_float();
			v[i][j] = int(temp + 0.5);
			if (v[i][j] > 1)v[i][j] = 1;
			if ((v[i][j] == 1) && (x[i][j] == 0))	// ���ٶȱ�Ϊ1�Ҹ���Ʒ֮ǰδ���룬�򽫸���Ʒ����
				x[i][j] = things_weight[j];
			printf("������³����ٶ� = %f\n", temp);
		}
	}

	// ==================================================
	// ����ÿ������������������
	for (i = 0; i < FANG; i++) {
		backpack_weight[i] = 0;
		for (j = 0; j < NUM; j++) {
			backpack_weight[i] += x[i][j];
		}
	}
		
	// ������º�ķ������������ڱ����������������һ����Ʒ
	// ���ⶪ��һ����Ʒֱ��������������С
	// ��ඪ��NUM��Ҳ���ǰ���Ʒȫ����
	for (i = 0; i < FANG; i++) {
		for (j = 0; j < NUM; j++) {
			if (backpack_weight[i] <= BACK)break;
			// ʹ�ö�������Ʒ�Ǳ����д��ڵ���Ʒ����������ͬ��Ʒ�������
			drop = 0;
			for (k = 0; k < 10*NUM;k++) {
				drop = rand_drop();
				if (v[i][drop] > 0)break;
			}
			if (backpack_weight[i] > BACK) {
				v[i][drop] = 0;
				x[i][drop] = 0;
				// ��ȥ��������Ʒ����
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
	// ��ʼ��ʱ������
	srand((unsigned)time(NULL));
	// �����ʼ�������������ٶ�
	init();
	evaluate();
	// ����ROUNd��
	for (i = 0; i < ROUND; i++) {
		update(i);
		evaluate();
	}

	int value=0;
	temp = compare();
	printf("\n��ѷ������� = ");
	for (i = 0; i < NUM; i++) {
		printf("%d ", gbest[i]);
		value += (gbest[i] > 0) ? things_values[i] : 0;
	}
	printf("\n��ѷ����� = %d ", temp);
	printf("\n��ѷ��������ܼ�ֵ = %d ", value);
	printf("\n���з����е���ʷ��߼�ֵf_0 = %d ", f_0[temp]);
	printf("hello");
	getchar();
	return 0;
}