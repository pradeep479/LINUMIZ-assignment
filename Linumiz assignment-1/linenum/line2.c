#include <stdio.h>

void file(FILE *fp1);

void file(FILE *fp1)
{
	char ch;

	while((ch = fgetc(fp1)) != EOF)
	{
	     printf("%c",ch);
	}

}

int main()

{

    FILE *fp1, *fp2;

    char filename[40];

    char ch;

    int del_line;
    
    int line_no;

    char str[40];    

    printf("Enter file name: ");

    scanf("%s", filename);

    //open file in read mode

    fp1 = fopen(filename, "r");
    printf("\n Contents of file before modification : \n");
    
    file(fp1);
    
    rewind(fp1);

    printf(" \n Enter line number of the line to be deleted:");

    scanf("%d", &del_line);

     //open new file in write mode

    fp2 = fopen("replica.c", "w");
    
    while ( fgets(str, 39, fp1) != NULL)
    {
       line_no++;
     
    	if (line_no != del_line)
    	{
       	fputs(str, fp2);
        }
    }
   

    fclose(fp1);

    fclose(fp2);

    remove(filename);

    //rename the file replica.c to original name

    rename("replica.c", filename);

    printf("\n The contents of file after being modified are as follows:\n");

    fp1 = fopen(filename, "r");

    file(fp1);

    fclose(fp1);

    return 0;

}

