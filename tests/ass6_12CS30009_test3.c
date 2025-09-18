// Test file 3
// Statements with boolean expressions

int main()
{
	int i,j,a,b;

	a = 0;
	for(i = 0; i<10; ++i) a = a+2;
	prints("a = ");
	printi(a);
	prints("\n");

	i = 0;
	for(;i<10;++i)
	{
		a = a+2;
	}
	prints("a = ");
	printi(a);
	prints("\n");

	i = 0;
	while(i<10) i++;
	prints("i = ");
	printi(i);
	prints("\n");

	i = 0;
	j = 10;
	while(j-i)
	{
		i = i+1;
	}
	prints("i = ");
	printi(i);
	prints("\n");

	a = 5, b = 4;
	if(a < b) i = 1;
	else i = 0;
	prints("i = ");
	printi(i);
	prints("\n");

	for(i = 0; i<3; i++)
	{
		if(i <= 0) printi(20);
		else if(i == 1) printi(21);
		else if(i >= 2) printi(22);

		prints("\n");
	}

	return 0;
}