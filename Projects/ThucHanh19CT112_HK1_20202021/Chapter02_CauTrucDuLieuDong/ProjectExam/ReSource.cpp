#include "iostream"
#include "time.h"
using namespace std;
static int GeneralRamdom(){
	srand((int)time(0));
	return rand();
}
//Hàm sinh ngẫu nhiên trong khoảng [min,max]
static int GeneralRamdomGroup(int minN, int maxN,int seek){
	srand(seek);
	return minN + rand() % (maxN + 1 - minN);
}