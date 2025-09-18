#include "myl.h"

char __buff[1024];								// To store the input line. Reading the input in one go makes it faster.
int __buffpos = -1;								// Stores position till which input has been read.
int __buffsize = 0;								// Stores number of characters in the buffer.
const int mlimit = (0x7fffffff)/10;
const float inf = 1.0/0.0;
const float ninf = -1.0/0.0;

int prints(char * str)
{
	int bytes = 0;
	while(str[bytes] != '\0') bytes++;			// Computes the length of string.

	__asm__ __volatile__
	(
		"movl 	$4, %%eax\n\t"
		"movl 	$1, %%ebx\n\t"
		"int 	$128\n\t"
		:
		:"c" (str), "d" (bytes)
	);

	return bytes;
}

int printi(int val)
{
	if(val == 0x80000000) return prints("-2147483648");	// Negative of this special integer does not exist.
	char str[15];
	int size = 0;
	int tval = val;
	if(tval < 0) tval = -tval;					// tval takes the magnitude of the number to be printed.
	while(tval > 0)								// Extracts the digits of tval and stores in str.
	{
		str[size++] = tval % 10 + '0';
		tval /= 10;
	}

	if(val < 0)									// If val is negative, puts '-' sign.
	{
		str[size++] = '-';
		val = -val;
	}
	else if(val == 0) str[size++] = '0';		// If val is 0 puts a '0'

	int i = 0, j = size-1, temp;
	while(i<j)									// Reverses the sequence of digits for printing in proper order.
	{
		temp = str[i];
		str[i] =  str[j];
		str[j] = temp;
		i++, j--;
	}
	
	// str[size++] = '\n';
	str[size++] = '\0';							// Marks end of string.
	return prints(str);
}

int printd(float val)
{
	if(val != val) return prints("nan");		// Checks for nan, inf, or -inf.
	if(val == inf) return prints("inf");
	if(val == ninf) return prints("-inf");

	char str[50];
	int size = 0, dig, i, start;
	double tval = val;
	if(val < 0) 								// If val is negative, put a '-' sign in the string.
	{
		tval = -(double)val;					// tval holds the magnitude of val.
		str[size++] = '-';
	}

	double p[41];								// p[i] holds the value of 10^i.
	p[0]=1;
	for(i=1;i<=40;i++) p[i] = p[i-1]*10.0;

	i = 40;										// Starts to check from 10^40 to find the digits of the integer part starting from the most significant digit.
	start = 0;

	while(i>=0)									// Finds the digits of the integer part and stores in str.
	{
		dig = (int)(tval/p[i]);					// Finds the i'th digit of the integer part.
		tval -= dig*p[i];
		if(dig>0||start)
		{
			str[size++] = dig+'0';
			start = 1;
		}
		i--;
	}

	if(!start) str[size++] = '0';				// If integer part is 0 then puts '0'.
	str[size++] = '.';							// Puts decimal point.
	for(i=0;i<6;i++)							// Finds 6 most significant digits of the fractional part.
	{
		tval *= 10;
		str[size++] = ((int)tval) + '0';
		tval -= (int) tval;
	}
	str[size++] ='\0';
	return prints(str);
}

char readchar()									// Reads one character from buffer and returns. If buffer is empty then takes input from input stream.
{
	if(__buffpos == __buffsize) __buffpos = -1, __buffsize = 0;
	if(__buffsize == 0)
	{
		__asm__ __volatile__
		(
			"movl	$3, %%eax\n\t"
			"movl 	$0, %%ebx\n\t"
			"int 	$128\n\t"
			:
			:"c"(__buff), "d"(1024)
		);

		while(__buff[__buffsize++] != '\0');
	}

	char ch = __buff[++__buffpos];
	return ch;
}

void unreadchar()								// Unreads the read character in case of error.
{
	__buffpos--;
}

int readi(int *eP)
{
	char ch;
	int sign = 1;
	int val = 0;
	int overflow = 0;
	*eP = OK;
	while((ch = readchar()) == ' '|| ch == '\n' || ch == '\t' || ch == '\0'); // Ignores all white spaces before integer.
	if(ch == '-') sign = -1;
	else if(ch > '9' || ch < '0') *eP = ERR;	// Error if encounters some non digit character.
	else val = ch - '0';

	if(*eP == OK)
	{
		while((ch = readchar()) != ' ' && ch != '\n' && ch != '\t' && ch != '\0') // Takes input till it encounters some white space.
		{
			if(ch > '9' || ch <'0') 			// Error if encounters some non digit character.
			{
				*eP = ERR;
				break;
			}
			if(val > mlimit) overflow = 1;
			val = val * 10 + ch - '0';
			if(val < 0) overflow = 1;
		}
	}

	if(*eP == ERR) unreadchar();				// Error occurs, then unread the character due to which error occurs.
	if(overflow) *eP = ERR;
	if(sign == -1) val = -val;
	return val;
}

int readf(float * val)
{
	char ch;
	int sign = 1;
	int eP = OK, done = 0;						// 'done' stores whether a complete number has been read or not.
	double intPart = 0.0, fracPart = 0.0, tenp = 10.0;

	while((ch = readchar()) == ' '|| ch == '\n' || ch == '\t' || ch == '\0'); // Ignores all white spaces before float.
	if(ch == '-') 
	{
		sign = -1;
		ch = readchar();
		if(ch > '9' || ch <'0') eP = 1;
		else unreadchar();
	}
	else if(ch > '9' || ch <'0') eP = 1;
	else intPart = ch - '0';

	if(eP == OK)								// Reads integer part.
	{
		while((ch = readchar()) != '.' && ch != ' ' && ch != '\n' && ch != '\t' && ch != '\0') // Reads till it encounters a white space.
		{
			if(ch > '9' || ch < '0')
			{
				eP = 1;
				break;
			}
			intPart = intPart * 10 + ch - '0';
		}
		if(ch == ' ' || ch == '\n' || ch == '\t' || ch == '\0') done = 1;
	}

	if(eP == OK && !done)						// Reads fractional part.
	{
		while((ch = readchar()) != ' ' && ch != '\n' && ch != '\t' && ch != '\0')
		{
			if(ch > '9' || ch <'0')
			{
				eP = 1;
				break;
			}
			fracPart += (ch - '0')/tenp;
			tenp *= 10;
		}
	}

	if(eP == ERR) unreadchar();					// If error, then unread the character that caused the error.

	double fval = intPart + fracPart;
	if(sign == -1) fval = -fval;
	*val = fval;
	return eP;
}