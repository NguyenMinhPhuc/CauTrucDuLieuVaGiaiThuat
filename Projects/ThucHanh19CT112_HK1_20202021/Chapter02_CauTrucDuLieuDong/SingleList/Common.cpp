#include "iostream"
#include "time.h"
using namespace std;
//Hàm sinh số ngẫu nhiên
static int GeneralRamdom(){
	srand((int)time(0));
	return rand();
}
//Hàm sinh ngẫu nhiên trong khoảng [min,max]
static int GeneralRamdomGroup(int minN, int maxN){
	srand((int)time(0));
	return minN + rand() % (maxN + 1 - minN);
}
//Sinh số ngẫu nhiên kiểu Float
static float float_rand(float min, float max){
	float scale = rand() / (float)RAND_MAX; /* [0, 1.0] */
	return min + scale * (max - min);      /* [min, max] */
}
//Sinh số ngẫu nhiên kiểu Long long
static long long Long_Rand(long long l, long long h){
	return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
		(long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
		(long long)rand() * (RAND_MAX + 1) +
		rand()) % (h - l + 1);
}
//Kiểm tra một số nguyên là số nguyên tố
static bool IsPrimeNumber(int n){
	if (n < 2){
		return false;
	}
	for (int i = 2; i < (n - 1); i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}
//Hàm kiểm tra số nguyên có phải là số hoàn hảo
//Số hoàn hảo được hiểu đơn giản là số có tổng các ước số của nó bằng chính nó.
//1 + 2 + 3 = 6.
static bool IsPerfect_Number(int number){
	int sum = 0;//khai báo biến sum
	for (int i = 1; i <= number / 2; i++){ //tạo vòng lặp for để tìm ước số của a
		if (number%i == 0)
			sum += i; //tổng các ước số của a
	}
	if (sum == number) 
		return true; // trả về true
	return false;
}
//Kiểm tra số chẵn lẻ
static bool IsEvenNumber(int number)
{
	return number % 2 == 0 ? true : false;
}
//Kiểm tra số chính phương.
//Số chính phương là số tự nhiên có căn bậc hai là một số tự nhiên, hay nói cách khác, số chính phương bằng bình phương của một số tự nhiên.
static bool IsSquareNumber(int number){
	int i = 0;
	while (i*i <= number){
		if (i*i == number){
			return true;
		}
		++i;
	}
	return false;
}