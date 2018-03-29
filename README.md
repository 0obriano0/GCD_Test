# 最大公因數

## 程式簡介

 **說明**

 此專案是挑戰使用 
 * 短除法`int gcd_using_factorization(int,int)` 
 * 輾轉相除法`int gcd_using_euclidean_algorithm(int,int)` 
 
 並製作兩個測試程式 `boolean test_gcd_using_factorization()` 、 `boolean test_gcd_using_euclidean_algorithm()` 來測試自己的兩個函式是否成功。
 
 我所使用的比對程式`GCD_From_WIKI(int,int)`是我從網路上載下來的。

**操作影片**

 [![Alt text](https://img.youtube.com/vi/zlT-50VEYGQ/0.jpg)](https://www.youtube.com/watch?v=zlT-50VEYGQ)

## 標頭檔

#include <stdio.h> 		//fprintf() 函示會使用到此標頭檔 

#include <time.h> 		//只是想要順便計算一下時間 

#include "main.h"

#define test_Num_End 1000 	//設定測試程式跑的範圍

## 各函式 介紹

### *int GCD_From_WIKI(int,int)*

 此程式是從wiki上擷取下來
 
 參考網站: https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%85%AC%E5%9B%A0%E6%95%B8

```ruby
int GCD_From_WIKI(int a, int b)
{
	if (b) while((a %= b) && (b %= a));
	return a + b;
}
```

### *int main()*

 此函式為`程式進入點`

```ruby
int main(){
	fprintf(stderr,"測試的範圍:\n\tNum1: 1~%d\n\tNum2: 1~%d\n\n測試中....",test_Num_End,test_Num_End);
	
	long clk_start = clock()/CLOCKS_PER_SEC; 		//紀錄 test_gcd_using_factorization() 運行前的時間
	boolean TGUF = test_gcd_using_factorization();		//運行 test_gcd_using_factorization()
	long clk_end[2];						
	clk_end[0] = clock()/CLOCKS_PER_SEC - clk_start;	//紀錄 test_gcd_using_factorization() 運行的時間
	
	clk_start = clock()/CLOCKS_PER_SEC;			//紀錄 test_gcd_using_euclidean_algorithm() 運行前的時間
	boolean TGUEA = test_gcd_using_euclidean_algorithm();	//運行 test_gcd_using_euclidean_algorithm()
	clk_end[1] = clock()/CLOCKS_PER_SEC - clk_start;	//紀錄 test_gcd_using_euclidean_algorithm() 運行的時間
	
	fprintf(stderr,"\n\n\n測試結果:\n");
	
	fprintf(stderr,"- gcd_using_factorization()...");	
	if(TGUF)						//檢測 test_gcd_using_factorization() 的回傳值(TGUF) 假如函式沒問題就回傳 true  假如函式沒問題就回傳 false
		fprintf(stderr,"\t\t測試正常\t\t");
	else
		fprintf(stderr,"\t\t######測試異常######\t");
	fprintf(stderr,"測試時間: %d 秒\n",clk_end[0]);
	
	fprintf(stderr,"- gcd_using_euclidean_algorithm()...");
	if(TGUEA)						//檢測 gcd_using_euclidean_algorithm() 的回傳值(TGUEA) 假如函式沒問題就回傳 true  假如函式沒問題就回傳 false
		fprintf(stderr,"\t測試正常\t\t");
	else
		fprintf(stderr,"\t######測試異常######\t");
	fprintf(stderr,"測試時間: %d 秒\n",clk_end[1]);
	
	fprintf(stderr,"\n\n");
	system("pause");
	return 0;
}
```

### *int gcd_using_factorization(int,int)*

 此函式為`短除法`程式

```ruby
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
```

### *int gcd_using_euclidean_algorithm(int,int)*

 此函式為`輾轉相除法`程式
 
```ruby
int gcd_using_euclidean_algorithm(int num3,int num4){
	int bufferNum = 1;
	while(bufferNum){
		bufferNum=num3%num4;
        num3=num4;
        num4=bufferNum;
	}
	return num3;
}
```

```ruby
boolean test_gcd_using_factorization(){
	for(int LoopNum1 = 1 ; LoopNum1 <= test_Num_End ; LoopNum1++)
		for(int LoopNum2 = 1 ; LoopNum2 <= test_Num_End ; LoopNum2++)
			if(gcd_using_factorization(LoopNum1,LoopNum2) != GCD_From_WIKI(LoopNum1,LoopNum2))
				return false;
	return true;
}
```

```ruby
boolean test_gcd_using_euclidean_algorithm(){
	for(int LoopNum1 = 1 ; LoopNum1 <= test_Num_End ; LoopNum1++)
		for(int LoopNum2 = 1 ; LoopNum2 <= test_Num_End ; LoopNum2++)
			if(gcd_using_euclidean_algorithm(LoopNum1,LoopNum2) != GCD_From_WIKI(LoopNum1,LoopNum2))
				return false;
	return true;
}
```
