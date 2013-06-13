#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char arrs[3][10]={"姓名","兴趣","性别"};

char * int2char(int inta);
 void test();

int main(void){
   /*
    strcpy(&arrs[0],"张三");
    strcpy(&arrs[1],"女");
    strcpy(&arrs[2],"男");

    //printf("|姓名|：%s；[兴趣]：%s;|性别|：%s;\n",arrs[0],arrs[1],arrs[2]);
    int a=10;
    printf("%s",int2char(a));
    test();

   */
   //oper();
//   testSprintf();
//    testConvert();
//    printAscii();

//    int tmp=fac(10);
//    printf("%d",tmp);

    testConv();
    return 0;
}
/**
 *整型转成字符型。
 */
char * int2char(int inta){
    char *str;
    sprintf(str,"%d",inta);
    return str;
}

/**
 *清空字符指针数组。测试。
 */
 void test(){
    char *str[20]={0};//
    str[0]="aaa";
    str[1]="bbb";
    str[2]="ccc";
    memset(str,0,sizeof(char*)*20);
    //现在想把str数组清空重新赋值。。。如下：
    str[0]="张三";
    str[1]="李四";


    printf("%s\n",str[0]);
    printf("%s\n",str[1]);//
    //printf("%s\n",str[2]);//这个地方会报错，说明清空成功。

 }
 /**
  *与计算。
  */
 void oper(){
    int a=101212;
    int b=1234;
    int c=0;
    a=a&b&c;
    printf("%d",a);
 }

 /**
  *sprintf 的用法。
  */
  void testSprintf(){
    char dest[30]={0};
    char *a="20131202 14:25:55";
    char *b="1234";
    int i=123,k=4567;
//    sprintf(dest,"%6.6s",a+2);//截取从开始位置的前六位；
//    sprintf(dest,"%06.6s",b+1);//截取从开始位置的前六位,不够六位的，左补0；
//    sprintf(dest,"%06d",i);//左边补0
//    sprintf(dest,"%-6d|",k);//右补空格
    sprintf(dest,"%8s|%8s",a,b);
//    sprintf(dest,"%8d|%8d|",i,k);//整形转换成字符串，并拼接到一起。
//    sprintf(dest,"%6s|%4s|%02s|",a,b,"0");
    printf("%s\n",dest);
  }

/**
 *类型转换测试
 */
void testConvert(){
    char *iStr="123.456";
    float dest=0.0f;
    dest=atof(iStr);
    printf("%0.3f",dest);
}

void printAscii(){
    int i ;
    for(i= 30; i < 127; i++ ) {
        printf("[ %c ]=%#04X\n", i, i, i);
    }
}
/**
 * 递归实现n的阶乘。
 * @param n
 * @return
 */
int fac(int n){
    if(n==1){
        return 1;
    }else{
        return n*fac(n-1);
    }
}

void CardNumber2str(char cardNum[], char str[])
{
    int k;
	for( k= 0; k < 5; k++)
	{
		str[k << 1] = cardNum[k] / 10 + '0';
		str[(k << 1) + 1] = cardNum[k] % 10 + '0';
	}
	str[5 * 2] = '\x0';
}

void str2CardNumber(char str[], char cardNum[])
{
    int k;
	for( k= 0; k < 5; k++)
	{
		cardNum[k] = ((str[k << 1] - '0') * 10) + (str[(k << 1) + 1] - '0');
	}
	cardNum[5] = 0;
}

void testConv(){
    char id[] = "\x0\xa\x1\x0\xa";
	char id2[10];
	char id_str[20] = {0};
	CardNumber2str(id, id_str);
//	str2CardNumber(id_str, id2);
    printf("%s",id_str);
}

