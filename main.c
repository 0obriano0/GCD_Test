#include <stdio.h> //fprintf() 函示會使用到此標頭檔 
#include <time.h> //只是想要順便計算一下時間 
#include "main.h"
#define test_Num_End 10000

int GCD_From_WIKI(int a, int b)
{
	if (b) while((a %= b) && (b %= a));
	return a + b;
}

int main(){
	fprintf(stderr,"測試的範圍:\n\tNum1: 1~%d\n\tNum2: 1~%d\n\n測試中....",test_Num_End,test_Num_End);
	
	long clk_start = clock()/CLOCKS_PER_SEC; //輸入程式執行到現在的時間
	boolean TGUF = test_gcd_using_factorization();
	long clk_end[2];
	clk_end[0] = clock()/CLOCKS_PER_SEC - clk_start;
	
	clk_start = clock()/CLOCKS_PER_SEC;
	boolean TGUEA = test_gcd_using_euclidean_algorithm();
	clk_end[1] = clock()/CLOCKS_PER_SEC - clk_start;
	
	fprintf(stderr,"\n\n\n測試結果:\n");
	
	fprintf(stderr,"- gcd_using_factorization()...");
	if(TGUF)
		fprintf(stderr,"\t\t測試正常\t\t");
	else
		fprintf(stderr,"\t\t######測試異常######\t");
	fprintf(stderr,"測試時間: %d 秒\n",clk_end[0]);
	
	fprintf(stderr,"- gcd_using_euclidean_algorithm()...");
	if(TGUEA)
		fprintf(stderr,"\t測試正常\t\t");
	else
		fprintf(stderr,"\t######測試異常######\t");
	fprintf(stderr,"測試時間: %d 秒\n",clk_end[1]);
	
	fprintf(stderr,"\n\n");
	system("pause");
	return 0;
}

int gcd_using_factorization(int num1,int num2){
	int bufferNum[2] = {0,1};
	bufferNum[0] = (num1>num2)?num2:num1;
	for(int LoopNum = 2 ; LoopNum <= bufferNum[0];){
		if(num1 % LoopNum == 0 && num2 % LoopNum == 0){
			num1/=LoopNum;
			num2/=LoopNum;
			bufferNum[1]*=LoopNum;
		}else{
			LoopNum++;
		}
	}
	return bufferNum[1];
}

int gcd_using_euclidean_algorithm(int num3,int num4){
	int bufferNum = 1;
	while(bufferNum){
		bufferNum=num3%num4;
        num3=num4;
        num4=bufferNum;
	}
	return num3;
}

boolean test_gcd_using_factorization(){
	for(int LoopNum1 = 1 ; LoopNum1 <= test_Num_End ; LoopNum1++)
		for(int LoopNum2 = 1 ; LoopNum2 <= test_Num_End ; LoopNum2++)
			if(gcd_using_factorization(LoopNum1,LoopNum2) != GCD_From_WIKI(LoopNum1,LoopNum2))
				return false;
	return true;
}

boolean test_gcd_using_euclidean_algorithm(){
	for(int LoopNum1 = 1 ; LoopNum1 <= test_Num_End ; LoopNum1++)
		for(int LoopNum2 = 1 ; LoopNum2 <= test_Num_End ; LoopNum2++)
			if(gcd_using_euclidean_algorithm(LoopNum1,LoopNum2) != GCD_From_WIKI(LoopNum1,LoopNum2))
				return false;
	return true;
}
