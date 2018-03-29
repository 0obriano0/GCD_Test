# 最大公因數

## GCD_From_WIKI

 此程式是從wiki上擷取下來
 
 參考網站: https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%85%AC%E5%9B%A0%E6%95%B8

```ruby
int GCD_From_WIKI(int a, int b)
{
	if (b) while((a %= b) && (b %= a));
	return a + b;
}
```
