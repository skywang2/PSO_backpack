#define NUM 5	// 物品个数
#define FANG 8	// 方案个数
int pbest[FANG][NUM] = { 0 };	// 初始化个体历史最佳方案
int gbest[NUM] = { 0 };	//初始化群体历史最佳方案