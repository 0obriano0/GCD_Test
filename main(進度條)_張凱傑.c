#include <stdio.h> //fprintf() 函示會使用到此標頭檔 
#include <time.h> //只是想要順便計算一下時間 
#include <process.h> //多執行續函式庫
#include <unistd.h> 
#include "main(進度條).h"
#define test_Num_End 4000 

int GCD_From_WIKI(int a, int b)
{
	if (b) while((a %= b) && (b %= a));
	return a + b;
}

int main(){
	fprintf(stderr,"測試的範圍:\n\tNum1: 1~%d\n\tNum2: 1~%d\n\n測試中....\n",test_Num_End,test_Num_End);
	
	long clk_start; //輸入程式執行到現在的時間
	boolean TGUF,TGUEA;
	long clk_end[2];
	
	fprintf(stderr,"\n測試 gcd_using_factorization()...\n");
	test_gcd_using_factorization_thread(&clk_end[0],&TGUF);
	
	fprintf(stderr,"\n測試 gcd_using_euclidean_algorithm()...\n");
	test_gcd_using_euclidean_algorithm_thread(&clk_end[1],&TGUEA);
	
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

int gcd_using_factorization(int Num1,int Num2){
    int c,GCD=1;
	if(Num1<=Num2)
    	c=Num1;
	else
	    c=Num2;
	for(int LoopNum1=2; LoopNum1<=c; LoopNum1++){
    	if((Num1%LoopNum1==0)&&(Num2%LoopNum1==0)){
        	GCD*=LoopNum1;
        	Num1/=LoopNum1;
        	Num2/=LoopNum1;
        	LoopNum1--;
    	}
	}
	return GCD;
}
int gcd_using_euclidean_algorithm(int Num1,int Num2){
    int GCD;
    while(Num1>0 || Num2>0){
        if(Num1>Num2 && Num1%Num2!=0){
            Num1-=Num2;
            GCD=Num1;
        }else if (Num2>Num1 && Num2%Num1!=0){
            Num2-=Num1;
            GCD=Num2;
        }else{
            if(Num2>Num1)
                GCD=Num1;
            else
                GCD=Num2;
            break;
        }
    }
    return GCD;
}


boolean test_gcd_using_factorization(int *n){
	for(int LoopNum1 = 1 ; LoopNum1 <= test_Num_End ; LoopNum1++){
		for(int LoopNum2 = 1 ; LoopNum2 <= test_Num_End ; LoopNum2++){
			if(gcd_using_factorization(LoopNum1,LoopNum2) != GCD_From_WIKI(LoopNum1,LoopNum2)){
				*(n+1) = 0;
				*(n+2) = 1;
				return false;
			}
		}
		*n = (LoopNum1*100/test_Num_End)+1;
	}	
	*(n+1) = 1;
	*(n+2) = 1;
	return true;
}

boolean test_gcd_using_euclidean_algorithm(int *n){
	for(int LoopNum1 = 1 ; LoopNum1 <= test_Num_End ; LoopNum1++){
		for(int LoopNum2 = 1 ; LoopNum2 <= test_Num_End ; LoopNum2++){
			if(gcd_using_euclidean_algorithm(LoopNum1,LoopNum2) != GCD_From_WIKI(LoopNum1,LoopNum2)){
				*(n+1) = 0;
				*(n+2) = 1;
				return false;
			}
		}
		*n = (LoopNum1*100/test_Num_End)+1;
	}	
	*(n+1) = 1;
	*(n+2) = 1;
	return true;
}

void test_gcd_using_factorization_thread(long *clk_end,boolean *TGUF){
	int a[3],buffer;
	a[0] = 0;
	a[2]=0;
	long clk_start = clock()/CLOCKS_PER_SEC; //輸入程式執行到現在的時間
	_beginthread(test_gcd_using_factorization, 0,a);
	
	while(a[2]==0){
		if(buffer != a[0]){
			if(a[0] <= 100)
				displayProgress(a[0]);
			buffer = a[0];
		}
	}
	*TGUF = a[1];
	*clk_end = clock()/CLOCKS_PER_SEC - clk_start;
}

void test_gcd_using_euclidean_algorithm_thread(long *clk_end,boolean *TGUEA){
	int a[3],buffer;
	a[0] = 0;
	a[2]=0;
	long clk_start = clock()/CLOCKS_PER_SEC; //輸入程式執行到現在的時間
	_beginthread(test_gcd_using_euclidean_algorithm, 0,a);
	
	while(a[2]==0){
		if(buffer != a[0]){
			if(a[0] <= 100)
				displayProgress(a[0]);
			buffer = a[0];
		}
	}
	*TGUEA = a[1];
	*clk_end = clock()/CLOCKS_PER_SEC - clk_start;
}

void displayProgress(int progress){  
        int k = 0;  
        for (k=0; k<106; k++)  
                putchar('\b');										//清除游標在的那一行，用來作為進度條顯示進度  
        int j = 0;
        fprintf(stderr,"  進度: ");
        for (j=0; j<progress/2; j++)  
                putchar('>');										//進度完成的部分用">"來表示 
        for (j=1; j<=50-progress/2; j++)  
                putchar('-');										//進度未完成的部分用"="來表示
        fprintf(stdout, "  %3d%%",progress);  
        fflush(stdout);
}
