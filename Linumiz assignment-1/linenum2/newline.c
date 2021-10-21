#include<stdio.h>
int main()
{

	FILE *fp1,*fp2;
	char file1[] = "file1.txt";
	char str;
	int del, line_num;	
       
	printf("enter the line no: ");
	scanf("%d",&del);
	fp1 = fopen(file1,"r");
	remove(file1);
	fp2 = fopen(file1,"w");
	
	str = getc(fp1);
	if(str!=EOF){line_num=1;}
	while(1)
	{
	 if(del !=line_num)
	  putc(str,fp2);
	  str = getc(fp1);
	  if(str =='\n')line_num++;
	  if(str==EOF)break;
	}
	fclose(fp1);

}
