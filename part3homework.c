#include <stdio.h>
#include <stdlib.h>

int average(int a,int b,int c){
    int p=(a+b+c)/3;
    return p;
}

int fc(int a,int b,int c,int p){
    int f=((p-a)*(p-a)+(p-b)*(p-b)+(p-c)*(p-c))/3;
    return f;
}

int zh(int p,int f){
    int z=3*p-f/3;
    return z;
}

void paiming(char *n1,int zh1,char *n2,int zh2,char *n3,int zh3){
    if (zh1 >= zh2 && zh2 >= zh3) {
      printf("%s > %s > %s", n1, n2, n3);
  } else if (zh1 >= zh3 && zh3 >= zh2) {
      printf("%s > %s > %s", n1, n3, n2);
  } else if (zh2 >= zh1 && zh1 >= zh3) {
      printf("%s > %s > %s", n2, n1, n3);
  } else if (zh2 >= zh3 && zh3 >= zh1) {
      printf("%s > %s > %s", n2, n3, n1);
  } else if (zh3 >= zh1 && zh1 >= zh2) {
      printf("%s > %s > %s", n3, n1, n2);
  } else { // zh3 >= zh2 && zh2 >= zh1
      printf("%s > %s > %s", n3, n2, n1);
  }
}

int main(){
  system("chcp 65001");
  int x1, x2, x3;
  int y1, y2, y3;
  int z1, z2, z3;

  printf("请输入小明的三项成绩（顺序为A B C,以一个空格为间隔）：");
  scanf("%d %d %d", &x1, &x2, &x3);
  printf("请输入小强的三项成绩（顺序为A B C,以一个空格为间隔）：");
  scanf("%d %d %d", &y1, &y2, &y3);
  printf("请输入小林的三项成绩（顺序为A B C,以一个空格为间隔）：");
  scanf("%d %d %d", &z1, &z2, &z3);

  int p1 = average(x1,x2,x3);
  int p2 = average(y1,y2,y3);
  int p3 = average(z1,z2,z3);

  int f1 = fc(x1,x2,x3,p1);
  int f2 = fc(y1,y2,y3,p2);
  int f3 = fc(z1,z2,z3,p3);

  int zh1 = zh(p1,f1);
  int zh2 = zh(p2,f2);
  int zh3 = zh(p3,f3);

  paiming ("小明",zh1,"小强",zh2,"小林",zh3);

  while(getchar() != '\n');
  getchar(); 
  return 0;
}