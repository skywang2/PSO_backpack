/*	
	-----0/1��������-----
	�趨������������Ʒ��������ֵ����
	λ��x = �������������н⣩
	�ٶ�v = ��0��1��ʾ���Ƿ������Ʒ
	�������� = �����ܼ�ֵ
	pbest = ���˱�����ʷ����ֵ
	gbest = Ⱥ�屳����ʷ����ֵ
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 5	// ��Ʒ����
#define FANG 8	// ��������
#define BACK 10 // ��������
#define ROUND 2000000 // ��������
typedef int value;
typedef int weight;

int x[FANG][NUM] = { 0 };
int v[FANG][NUM] = { 0 };
weight backpack = BACK;
weight things_weight[NUM] = { 2,2,6,5,4 };	// ÿ����Ʒ������
value things_values[NUM] = { 6,3,5,4,6 };	// ÿ����Ʒ�ļ�ֵ
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

float rand_float() {
	float number;
	number = rand() / (RAND_MAX + 1.0);
	return number;	// �����0,1
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

	return 0;	// ��취����������ά����???
}

// �����ܼ�ֵ��ߵķ������
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
	1.����������ֵ
	2.����pbest
	3.����gbest
*/
int evaluate(){
	int i, j;
	// ���㵱ǰÿ�������������ܼ�ֵ
	for(i=0;i<FANG;i++)
		for (j = 0; j < NUM; j++) {
			f[i] = f[i] + things_values[j] * v[i][j];
		}
	// ���¸�����ʷ��ѷ���
	// ���±�����ʷ����ܼ�ֵ
	for (i = 0; i<FANG; i++)
		if (f_0[i] < f[i]) {
			f_0[i] = f[i];
			for (j = 0; j < NUM; j++)
				pbest[i][j] = x[i][j];
		}
	// ����Ⱥ����ʷ��ѷ���
	int best;
	best = compare();
	for (i = 0; i < FANG; i++)
		if (i == best) {
			for (j = 0; j < NUM; j++)
				gbest[j] = pbest[i][j];
		}
			

	return 0;
}

// ���±�������
// ��δ�����ٶȷ�Χ����֪��ȷ����0��1֮���㲻���޶�
int update(int round){
	float w = 0.9, c1 = 2.0, c2 = 2.0;//����Ȩ�ء�����ϵ��
	float r1, r2;
	r1 = rand_float();
	r2 = rand_float();
	int i, j;
	float temp;
	// w������˥��
	w = w - round / (ROUND * 2);
	for (i = 0; i < FANG; i++) {
		for (j = 0; j < NUM; j++) {
			// ���������������0��1����
			// ����v[i][j]+2*(pbest[i][j] - x[i][j])
			temp = (w*v[i][j] + c1*r1*(pbest[i][j] - x[i][j]) + c2*r2*(pbest[i][j] - x[i][j])) / (v[i][j] + 2 * (pbest[i][j] - x[i][j]));
			v[i][j] = int(temp + 0.5);
			// ��Ҫ�۲����v�ı仯
		}
		if (v[i][j] == 0)
			x[i][j] = 0;	// ���������ʵ�ʷ������Ʒ
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
	// ��ʼ��ʱ������
	srand((unsigned)time(NULL));
	// �����ʼ�������������ٶ�
	init();
	evaluate();
	// ����20��
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