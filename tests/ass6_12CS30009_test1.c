// Test file 1
// Arithmetic and boolean expressions

int main()
{
	int a,b,c,d;

	a= 3, b= 4, c= 5;

	d = a+b;
	prints("d = ");
	printi(d);
	prints("\n");

	d = a-b;
	prints("d = ");
	printi(d);
	prints("\n");

	d = (a+b)*c-a*(b+c);
	prints("d = ");
	printi(d);
	prints("\n");

	d = (b*c+a+1)%5;
	prints("d = ");
	printi(d);
	prints("\n");

	d = a < b? 1000: 2000;
	prints("d = ");
	printi(d);
	prints("\n");

	a = 100, b = 5, c = 3;

	d = a/b;
	prints("d = ");
	printi(d);
	prints("\n");

	d = 100/c;
	prints("d = ");
	printi(d);
	prints("\n");

	d = ((3+4)/3)*a;
	prints("d = ");
	printi(d);
	prints("\n");	
	
	a = 100, b = 5, c = 5;
	d = a < b;
	prints("d = ");
	printi(d);
	prints("\n");

	d = a > b;
	prints("d = ");
	printi(d);
	prints("\n");

	d = b == c;
	prints("d = ");
	printi(d);
	prints("\n");

	d = b != c;
	prints("d = ");
	printi(d);
	prints("\n");

	d = b <= c;
	prints("d = ");
	printi(d);
	prints("\n");

	d = (a < b) || (b <= c);
	prints("d = ");
	printi(d);
	prints("\n");

	d = (a < b) && (b <= c);
	prints("d = ");
	printi(d);
	prints("\n");
	return 0;
}