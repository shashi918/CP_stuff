#include<stdio.h>
#include<string.h>
void convertor(int,char*);
int j=0;
int rgb(int r, int g, int b, char *output) {
  j =0;
if(r > 255)
 r = 255;
 if(g > 255)
g = 255;
if(b > 255)
b = 255;
convertor(r,output);
convertor(g,output);
convertor(b,output);
printf("\n");
while(*output !='\0') {
  printf("%c",*output);
  output++;
}
}

void convertor(int num,char* output) {
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
output[j] =hex[0];
j++;
output[j] =hex[0];
j++;  
}
if(i==1) {
  hex[0] = [0];
}
if(i==0) {
  hex[0] = 48;
  hex[1] = 48;
  output[j] =hex[0];
j++;
output[j] =hex[0];
j++;  
}
}

int main() {
char output[19];
 rgb(255, 255, 255, output);
 rgb(255, 255, 300, output);
 rgb(0, 0, 0, output);
 rgb(148, 0, 211, output);
 rgb(1,2,3,output);

}