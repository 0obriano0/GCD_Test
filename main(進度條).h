#ifndef LAB107_HOMEWORK_20180326_MAIN_H_INCLUDED
#define LAB107_HOMEWORK_20180326_MAIN_H_INCLUDED

/**
 *  本次的作業專案架構：
 *  + hw20180326/      <--------- 建立hw20180326資料夾
 *    + main.c         <--------- 主程式檔名為 main.c （實作要求在下面）
 *    + main.h         <--------- 本檔案 main.h 必須被 main.c 引入（#include "main.h"）
 *    + README.xxx     <--------- 報告原始檔案 副檔名不限（如 .md .docx .doc）
 *    + README.pdf     <--------- 報告pdf檔案
 *  完成後打包本專案資料夾成 hw20180326-<姓名>.zip 檔
 *  <姓名>請改成自己的名字，並上傳至群組中
 *  提醒一下，請用C語言實作本次作業
 * （如果用C++編譯的話會發生有趣的事情）
 */

typedef int boolean;
enum { false, true };

/**
 *  函式 gcd_using_factorization
 *  因子分解法求最大公因數
 *  測試正確返回非0值，測試失敗返回0 "
 *  傳入之參數必須皆為正整數，函數返回最大公因數
 *  若傳入之參數為非正整數，則返回0
 *  函數必須在10秒內執行完成並返回數值
 */
int gcd_using_factorization(int,int);

/**
 * 函式 gcd_using_euclidean_algorithm
 * 輾轉相除法求最大公因數
 * 測試正確返回非0值，測試失敗返回0
 * 傳入之參數必須皆為正整數，函數返回最大公因數
 * 若傳入之參數為非正整數，則返回0
 * 函數必須在10秒內執行完成並返回數值
 */
int gcd_using_euclidean_algorithm(int,int);

/**
 * 函式 test_gcd_using_factorization
 * 因子分解法求最大公因數測試
 * 測試正確返回 true，測試失敗返回 false
 */
boolean test_gcd_using_factorization(int *n);

/**
 * 函式 test_gcd_using_euclidean_algorithm
 * 輾轉相除法求最大公因數測試
 * 測試正確返回 true，測試失敗返回 false
 */
boolean test_gcd_using_euclidean_algorithm(int *n);

/**
 * 主函式 main
 * 內部必須執行上面2個測試函數
 * 並將測試之結果列印至 stderr 
 * （提示，google "stderr" 和 "fprintf" 的用法）
 * 若二個測試皆正確無誤，返回0，否則返回1
 */

void test_gcd_using_factorization_thread(long *clk_end,boolean *TGUF); 

void test_gcd_using_euclidean_algorithm_thread(long *clk_end,boolean *TGUEA); 

void displayProgress(int);

int main();

#endif // LAB107_HOMEWORK_20180326_MAIN_H_INCLUDED
