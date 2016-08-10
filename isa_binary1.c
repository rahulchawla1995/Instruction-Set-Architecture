//RAHUL CHAWLA - 14UCS090
//RISHI RAJ -   14UCS096
//SHUBHAM DUBEY - 14UCS114
//SHAILESH JINDAL - 14UCS105
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * three_addr(char*);
char * two_addr(char*);
char * one_addr(char *);
char * zero_addr(char*);
char * regester(char*);

/*void error_message()
{
	printf("Error in the given instruction\n");
}*/
void Input_Values(FILE *f1,char *string1)
{
	int temp;
          
	if(string1[0]=='@')
	{

		if(atoi(string1+1)!=0)
			fprintf(f1," %s",addr_check(string1+1));
		else	if(strcmp(regester(string1+1),"-1")!=0)
			fprintf(f1," %s",regester(string1+1));
	}
	else if(atoi(string1)!=0)
		fprintf(f1," %d",atoi(string1));
	else	if(strcmp(regester(string1),"-1")!=0)
			fprintf(f1," %s",regester(string1));
	else error_message();
}
void input(FILE *f1)
{
	char string1[200],string2[200],string3[200];
        char string4[200],string5[200],string6[200];
        char reg1[200],reg2[200],reg3[200];
	int count =1;
	do{

		scanf("%s",string1);
		strcpy(string6,three_addr(string1));
		strcpy(string2,two_addr(string1));
		strcpy(string3,one_addr(string1));
		strcpy(string4,zero_addr(string1));
		strcpy(string5,label(string1));
		if(strcmp(string6,"-1")!=0)
		{
			fprintf(f1,"%s000000000000000",three_addr(string1));
			scanf("%s%s%s",reg1,reg2,reg3);
			Input_Values(f1,reg1);
			Input_Values(f1,reg2);
			Input_Values(f1,reg3);
			fprintf(f1,"\n");
                 }
		else if(strcmp(string2,"-1")!=0)
		{
			fprintf(f1,"%s000000000000000",two_addr(string1));
			scanf("%s%s",reg1,reg2);
			Input_Values(f1,reg1);
			Input_Values(f1,reg2);
			fprintf(f1,"\n");
		}
		else if(strcmp(string3,"-1")!=0)
		{
			fprintf(f1,"%s0000000000000000",one_addr(string1));
			scanf("%s",reg1);
			Input_Values(f1,reg1);
			fprintf(f1,"\n");
		}
		else if(strcmp(string4,"-1")!=0)
		{
			fprintf(f1,"%s0000000000000000",zero_addr(string1));
			fprintf(f1,"\n");
		}
		else if(strcmp(string5,"-1")!=0)
		{
			fprintf(f1,"%s\n",string5);
		}
		else
		{
			scanf ("%[^\n]%*c", reg1);
			error_message();
		}

		count++;

	}while(strcmp(string1,"HLT")!=0);
	}
int main()
{
	FILE *f1;
	f1=fopen("ISA_BINARY.txt","w");
	input(f1);
	fclose(f1);
	return 0;
}
