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

## 各函式 介紹

### *GCD_From_WIKI(int,int)*

 此程式是從wiki上擷取下來
 
 參考網站: https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%85%AC%E5%9B%A0%E6%95%B8

```ruby
int GCD_From_WIKI(int a, int b)
{
	if (b) while((a %= b) && (b %= a));
	return a + b;
}
```
