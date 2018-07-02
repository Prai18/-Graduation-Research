/*２次方程式(ax^2+bx+c=0)の解を求めるプログラム(熊大院試問題)*/

/*解の公式->x=(-b±√b^2-4ac)/2aを作る*/
#include <stdio.h>
#include <math.h>
 
int main(void)
{
 
  /* 2次方程式の定数 */
  float a, b, c;
 
  /* 判別式 */
  float discriminant;
 
  /* 2次方程式の解 */
  float kai1, kai2;
 
  /* 解が複素数を含む場合 */
  float real, imag;
 
  /* 2次方程式の定数を入力 */
  printf("2次方程式の定数を入力してください。\n");
 
  printf("a = ");
  scanf("%f", &a);
 
  printf("b = ");
  scanf("%f", &b);
 
  printf("c = ");
  scanf("%f", &c);
 
  /* 判別式を計算 */
  discriminant = b * b - 4 * a * c;
 
  /* 判別式に数値による条件分岐 */
  if ( discriminant > 0 ) {
 
    // 解の計算
    kai1 = ( -b + sqrt(discriminant) ) / (2*a) ;
    kai2 = ( -b - sqrt(discriminant) ) / (2*a);
 
    // 解の出力
    printf("2次方程式の解: x = %.2f, %.2f\n", kai1, kai2);
 
  } else if ( discriminant == 0 ) {
 
    // 解の計算
    kai1 = kai2 = -b / ( 2 * a );
 
    // 解の出力
    printf("2次方程式の解: x = %.2f, %.2f\n", kai1, kai2);
 
  } else {
 
    // 解の計算
    real = -b / (2*a);
    imag = sqrt(-discriminant) / (2*a);
 
    // 解の出力
    printf("2次方程式の解: %.2f+%.2fi, %.2f-%.2fi\n", real, imag, real, imag);
  }
 
  return 0;
}
