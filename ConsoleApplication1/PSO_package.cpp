/*	
	-----0/1��������-----
	�趨��������Ʒ��������ֵ����
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
typedef int value;
typedef int weight;

// ���������
int rand_num(){
	int i;
	int number;
	srand((unsigned)time(NULL));
	number = rand() % 2;
	return number;	// �����0,1
}

// ��ʼ�����������������ٶ�
int init(int v[FANG][NUM], int x[FANG][NUM]){
	int i, j;
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++) {
			v[i][j] = rand_num();
		}
	
	// ����Ʒ������ʾ��������
	for (i = 0; i<FANG; i++)
		for (j = 0; j < NUM; j++) {
			x[i][j] = things_weight[j];
			x[i][j] = x[i][j] && things_weight[j];	// ���������ʵ�ʷ������Ʒ
		}

	return 0;	// ��취����������ά����???
}

/*
	1.����������ֵ
	2.����pbest
	3.����gbest
*/
int evaluate(int things_value[NUM], int x[FANG][NUM], int pbest[FANG][NUM], int gbest[NUM]){
	int i, j;
	// ����ÿ�������������ܼ�ֵ
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

	return 0;	// ����???
}

// �����ܼ�ֵ��ߵķ������
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

// ���±�������
int update(){

}

int v[FANG][NUM] = { 0 };
int x[FANG][NUM] = { 0 };
weight things_weight[NUM] = { 2,2,6,5,4 };	// ÿ����Ʒ������
value things_values[NUM] = { 6,3,5,4,6 };	// ÿ����Ʒ�ļ�ֵ
value f[FANG] = { 0 };	// �ñ���������ǰ���ܼ�ֵ
int pbest[FANG][NUM] = { 0 };	// ��ʼ��������ʷ��ѷ���
int gbest[NUM] = { 0 };	//��ʼ��Ⱥ����ʷ��ѷ���
 
int main(){
	int i, j;
	for (i = 0; i < FANG; i++)
		for (j = 0; j < NUM; i++) {
			pbest[i][j] = 9999;
			gbest[j] = 9999;
		}		
	// �����ʼ�������������ٶ�
	init(v, x);
	evaluate(things_values, x, pbest, gbest);

	

	return 0;
}