#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int makenum(int i,int a,int b,char s[i][b])
{
    int num=0;
    for(int k=a;k<b;k++)
    {
   //printf("char is %c\n",s[0][k]);
    if(s[0][k]>=48&&s[0][k]<=57)
    num=num*10+s[0][k]-48;
    }
    return num;
}

int main()
{
    int first;
    int n;
    char s[99][99];
    scanf("%d\n",&n);
    char expressions[n][99];
    for(int i=0;i<n;i++)
    {
        fgets(expressions[i],999,stdin);
    }

    for(int i=0;i<n;i++)
    {
        int add=0;
        int j=0;
        int num1=0;
        int num2=0;
        int b;
        int a;
        int firstcharpos;
        int lastcharpos;

        while(j<strlen(expressions[i]))
        {
            first=0;
            a=j;
            int count=0;
            int pass=0;
            while(expressions[i][j]>=48&&expressions[i][j]<=57)
            {
                 s[i][j]=expressions[i][j];
                // printf("%d th digit is %c\n",j,s[i][j]);
                 j=j+1;
                 firstcharpos=a;
                 count=count+1;
                 lastcharpos=firstcharpos+count;
            }
            b=j;
        //  printf("a is %d\n",a);
        //  printf("b is %d\n",b);
        //  for(int j=firstcharpos;j<lastcharpos;j++)
        //  {
        //     printf("s[%d][%d] is %c\n",i,j,s[i][j]);
        //  }

            if(expressions[i][j]==' ')
           {
                j=j+1;
                pass=1;
           }

        if (pass==0)
        {
             switch (add)
             {
                case 0:
                    first=1;
                    break;
                case 1:
                   num2=makenum(i,firstcharpos,lastcharpos,s[i]);
                // printf("num 2 is %d\n",num2);
                    num1=num1+num2;
                  //  printf("new num 1 is d\n",num1);
                 //  printf("it is plus\n");
                    add=0;
                    break;
                case -1:
                   num2=makenum(i,firstcharpos,lastcharpos,s[i]);
                    //printf("num 2 is %d\n",num2);
                    num1=num1-num2;
                   // printf("new num 1 is d\n",num1);
                    // printf("it is minus\n");
                     add=0;
                    break;
             }

            if(first==1)
            {
                num1=makenum(i,firstcharpos,lastcharpos,s[i]);
                // printf("first is %d\n",num1);

            }

            switch(expressions[i][j])
            {
                case '+':
                    add=1;
                    j=j+1;
                    break;
                case '-':
                    add=-1;
                    j=j+1;
                    break;
                default:
                    j=j+1;
                    break;
             }
        }
    }
    printf("%d\n",num1);
    }
    return 0;
}

