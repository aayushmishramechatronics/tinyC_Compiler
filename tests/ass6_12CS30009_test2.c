// Test file 2
// Array and pointer expressions

int main()
{
	int a[10];
	int b,c,d;
	int* p, q;

	b = 2, c = 3;
	a[3] = 100;
	prints("a[3] = ");
	printi(a[3]);
	prints("\n");
	
	c = a[3];
	prints("c = ");
	printi(c);
	prints("\n");

	a[4] = a[3] + 10;
	prints("a[4] = ");
	printi(a[4]);
	prints("\n");

	p = &b;
	*p = 10;
	prints("b = ");
	printi(b);
	prints("\n");

	c = *p;
	prints("c = ");
	printi(c);
	prints("\n");

	p = &a[3];
	*p = 10;
	prints("a[3] = ");
	printi(a[3]);
	prints("\n");

	return 0;
}