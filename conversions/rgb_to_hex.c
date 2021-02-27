#include<stdio.h>
int i=0;
int rgb(int r, int g, int b, char *output) {
if(r > 255)
 r = 255;
 if(g > 255)
g = 255;
if(b > 255)
b = 255;
convertor(r);
convertor(g);
convertor(b);
printf("\n");

}
void convertor(int num) {
  char hex[2];
int i = 0; 
while(num!=0) {
 int temp = 0;
 temp = num%16;
 if(temp < 10) {
 hex[i] = temp + 48;
 i++;
 }
 else {
   hex[i] = temp + 55;
   i++;
 }

 num = num/16;
}

if(i==2) {
  printf("%c",hex[0]);
  printf("%c",hex[1]);

}
if(i==0) {
  printf("%d",0);
  printf("%d",0);
}
}

int main() {
char output[6];
 rgb(255, 255, 255, output);
 rgb(255, 255, 300, output);
 rgb(0, 0, 0, output);
 rgb(148, 0, 211, output);

}