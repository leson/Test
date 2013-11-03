#include "BaseStudy.h"

/**
 *����ת���ַ��͡�
 */
char * int2char(int inta){
    char *str;
    sprintf(str,"%d",inta);
    return str;
}

/**
 *����ַ�ָ�����顣���ԡ�
 */
 void test(){
    char *str[20]={0};//
    str[0]="aaa";
    str[1]="bbb";
    str[2]="ccc";
    memset(str,0,sizeof(char*)*20);
    //�������str����������¸�ֵ���������£�
    str[0]="����";
    str[1]="����";


    printf("%s\n",str[0]);
    printf("%s\n",str[1]);//
    //printf("%s\n",str[2]);//����ط��ᱨ��˵����ճɹ���

 }
 /**
  *����㡣
  */
 void oper(){
    int a=101212;
    int b=1234;
    int c=0;
    a=a&b&c;
    printf("%d",a);
 }

 /**
  *sprintf ���÷���
  */
  void testSprintf(){
    char dest[30]={0};
    char *a="20131202 14:25:55";
    char *b="1234";
    int i=123,k=4567;
    long ll = 323;
    float fl=(float)ll/100;
    float ff=2.12;
//    sprintf(dest,"%6.6s",a+2);//��ȡ�ӿ�ʼλ�õ�ǰ��λ��
//    sprintf(dest,"%06.6s",b+1);//��ȡ�ӿ�ʼλ�õ�ǰ��λ,������λ�ģ���0��
//    sprintf(dest,"%06d",i);//��߲�0
//    sprintf(dest,"%-6d|",k);//�Ҳ��ո�
//    sprintf(dest,"%8s|%8s",a,b);
//    sprintf(dest,"%8d|%8d|",i,k);//����ת�����ַ�������ƴ�ӵ�һ��
//    sprintf(dest,"%6s|%4s|%02s|",a,b,"0");
    sprintf(dest,"%.2f",fl);
//    sprintf(dest,"%.2f",ff);
    printf("%s\n",dest);
  }

/**
 *����ת������
 */
void testConvert(){
    char *iStr="123.456";
    float dest=0.0f;
    dest=atof(iStr);
    printf("%0.3f",dest);
}

/**
 *��ӡascii ��ֵ��
 */
void printAscii(){
    int i ;
    for(i= 30; i < 127; i++ ) {
        printf("[ %c ]=%#04X\n", i, i, i);
    }
}
/**
 * �ݹ�ʵ��n�Ľ׳ˡ�
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
 *ǿ������ת����������ת��խ���ͣ�
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
 *�õ��ַ������ȡ�
 */
int getStrLen(char* str){
    int ret=0;
    while(str[ret]!='\0'){
        ret++;
    }
    return ret;
}
/**
 *�ַ������ơ�
 */
void copyStr(char* str1,char* str2){
   while(*str2!='\0'){
        *(str1++)=*(str2++);
   }
   *str1='\0';//�������һλ����null �����ַ�����
}
/**
 *�����ַ�����
 */
void swapStr(char* s1,char* s2){
    char *temp;
    copyStr(temp,s1);
    copyStr(s1,s2);
    copyStr(s2,temp);
}

/**
 *��ά�������
 */
void testArr(){
    char arrs[3][3]={"����","�Ա�","��Ȥ"};


}
