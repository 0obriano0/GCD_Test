#include <stdio.h> //fprintf() ��ܷ|�ϥΨ즹���Y�� 
#include <time.h> //�u�O�Q�n���K�p��@�U�ɶ� 
#include <process.h> //�h������禡�w
#include <unistd.h> 
#include "main(�i�ױ�).h"
#define test_Num_End 4000 

int GCD_From_WIKI(int a, int b)
{
	if (b) while((a %= b) && (b %= a));
	return a + b;
}

int main(){
	fprintf(stderr,"���ժ��d��:\n\tNum1: 1~%d\n\tNum2: 1~%d\n\n���դ�....\n",test_Num_End,test_Num_End);
	
	long clk_start; //��J�{�������{�b���ɶ�
	boolean TGUF,TGUEA;
	long clk_end[2];
	
	fprintf(stderr,"\n���� gcd_using_factorization()...\n");
	test_gcd_using_factorization_thread(&clk_end[0],&TGUF);
	
	fprintf(stderr,"\n���� gcd_using_euclidean_algorithm()...\n");
	test_gcd_using_euclidean_algorithm_thread(&clk_end[1],&TGUEA);
	
	fprintf(stderr,"\n\n\n���յ��G:\n");
	
	fprintf(stderr,"- gcd_using_factorization()...");
	if(TGUF)
		fprintf(stderr,"\t\t���ե��`\t\t");
	else
		fprintf(stderr,"\t\t######���ղ��`######\t");
	fprintf(stderr,"���ծɶ�: %d ��\n",clk_end[0]);
	
	fprintf(stderr,"- gcd_using_euclidean_algorithm()...");
	if(TGUEA)
		fprintf(stderr,"\t���ե��`\t\t");
	else
		fprintf(stderr,"\t######���ղ��`######\t");
	fprintf(stderr,"���ծɶ�: %d ��\n",clk_end[1]);
	
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
	long clk_start = clock()/CLOCKS_PER_SEC; //��J�{�������{�b���ɶ�
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
	a[2] = 0;
	long clk_start = clock()/CLOCKS_PER_SEC; //��J�{�������{�b���ɶ�
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
        putchar('\r');												//���ʴ�Ш쨺�@�檺�̫e���A�Ψӧ@���i�ױ���ܶi��  
        int j = 0;
        fprintf(stderr,"  �i��: ");
        for (j=0; j<progress/2; j++)  
                putchar('>');										//�i�ק�����������">"�Ӫ�� 
        for (j=1; j<=50-progress/2; j++)  
                putchar('-');										//�i�ץ�������������"="�Ӫ��
        fprintf(stdout, "  %3d%%",progress);  
        fflush(stdout);
}
