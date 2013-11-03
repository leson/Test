#include "BaseStudy.h"

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
    long ll = 323;
    float fl=(float)ll/100;
    float ff=2.12;
//    sprintf(dest,"%6.6s",a+2);//截取从开始位置的前六位；
//    sprintf(dest,"%06.6s",b+1);//截取从开始位置的前六位,不够六位的，左补0；
//    sprintf(dest,"%06d",i);//左边补0
//    sprintf(dest,"%-6d|",k);//右补空格
//    sprintf(dest,"%8s|%8s",a,b);
//    sprintf(dest,"%8d|%8d|",i,k);//整形转换成字符串，并拼接到一起。
//    sprintf(dest,"%6s|%4s|%02s|",a,b,"0");
    sprintf(dest,"%.2f",fl);
//    sprintf(dest,"%.2f",ff);
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

/**
 *打印ascii 码值。
 */
void printAscii(){
    int i ;
    for(i= 30; i < 127; i++ ) {
        printf("[ %c ]=%#04X\n", i, i, i);
    }
}
/**
 * 递归实现n的阶乘。
 * @param ngasNum
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

/**
 *强制类型转换（宽类型转成窄类型）
 */
void forceConvert(){
    float f=1.61;
//    double d=2.14;
    long l=4.1;
//    int i=2.2;

//    int tmp=(int)(f*10000);
    int tmp=(int)((f+0.005)*100);
    printf("float to int %d;\n long to int %.2f;\n",tmp,l);
}
/**
 *得到字符串长度。
 */
int getStrLen(char* str){
    int ret=0;
    while(str[ret]!='\0'){
        ret++;
    }
    return ret;
}
/**
 *字符串复制。
 */
void copyStr(char* str1,char* str2){
   while(*str2!='\0'){
        *(str1++)=*(str2++);
   }
   *str1='\0';//数组最后一位加上null 构成字符串。
}
/**
 *交换字符串。
 */
void swapStr(char* s1,char* s2){
    char *temp;
    copyStr(temp,s1);
    copyStr(s1,s2);
    copyStr(s2,temp);
}

/**
 *二维数组测试
 */
void testArr(){
    char arrs[3][3]={"姓名","性别","兴趣"};


}
