//RAHUL CHAWLA - 14UCS090
//RISHI RAJ -   14UCS096
//SHUBHAM DUBEY - 14UCS114
//SHAILESH JINDAL - 14UCS105
#include<string.h>
#include<math.h>
#include<stdlib.h>
char* dec_to_bin(int num)
{
    int rem, i=1, binary=0;
    int n=ceil(log(num)/log(2));
    char *binary1;
	binary1=(char*)malloc(sizeof(char)*n);
    while (num!=0)
    {
        rem=num%2;
        num/=2;
        binary1[--n]=rem;
    }
    return binary1;
}

char * zero_addr(char * str)
{
	if(strcmp(str,"HLT")==0)
		return "0000000000000000";

		else return "-1";

}

char * one_addr(char *str)
{
	if(strcmp(str,"JMP")==0)
		return "0000100000000";

	else if(strcmp(str,"JLEQ")==0)
		return "0001000000000";

	else if(strcmp(str,"INC")==0)
		return "0001100000000";


	else return "-1";
}


char* two_addr(char *str)
{
	if(strcmp(str,"IN")==0)
	{
		return "001000000";
	}

	else if(strcmp(str,"OUT")==0)
		return "001010000";

	else if(strcmp(str,"XOR")==0)
		return "001100000";

	else if(strcmp(str,"AND")==0)
		return "001110000";

	else if(strcmp(str,"CMP1")==0)
		return "010000000";

	else if(strcmp(str,"CMP2")==0)
		return "010010000";

	else if(strcmp(str,"MOV1")==0)
		return "010100000";

	else if(strcmp(str,"MOV2")==0)
		return "010110000";


	else return "-1";
}
char* three_addr(char *str)
{
	if(strcmp(str,"DIV")==0)
	{
		return "01100";
	}

	else if(strcmp(str,"MUL")==0)
		return "01101";

	else if(strcmp(str,"ADD")==0)
		return "01110";

	else
        return "-1";
}







char * regester(char *str)
{
	if(strcmp(str,"R00")==0)
		return "0000";

	else if(strcmp(str,"R01")==0)
		return "0001";

	else if(strcmp(str,"R02")==0)
		return "0010";

	else if(strcmp(str,"R03")==0)
		return "0011";

	else if(strcmp(str,"R04")==0)
		return "0100";

	else if(strcmp(str,"R05")==0)
		return "0101";

	else if(strcmp(str,"R06")==0)
		return "0110";

	else if(strcmp(str,"R07")==0)
		return "0111";

	else if(strcmp(str,"R08")==0)
		return "1000";

	else if(strcmp(str,"R09")==0)
		return "1001";

	else
		return "-1";
}

char * label(char *str)
{
	if(strcmp(str,"L0")==0)
		return "0000";

	else if(strcmp(str,"L1")==0)
		return "0001";

	else if(strcmp(str,"L2")==0)
		return "0010";

	else if(strcmp(str,"L3")==0)
		return "0011";

	else if(strcmp(str,"L4")==0)
		return "0100";

	else if(strcmp(str,"L5")==0)
		return "0101";

	else if(strcmp(str,"L6")==0)
		return "0110";

	else if(strcmp(str,"L7")==0)
		return "0111";

  	else if(strcmp(str,"L8")==0)
  		return "1000";
  else
  	return "-1";
}
char * addr_check(char *str)
{
	if(atoi(str)>=21 && atoi(str)<64)
		return dec_to_bin(atoi(str));
}
