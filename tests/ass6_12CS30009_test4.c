// Test file 4
// Function calls

int add(int a, int b)
{
	a = b+a;
	return a;
}

int max(int* arr, int b)
{
	int ma = 0;
	int i;
	for(i = 0; i<b; i++)
	{
		if(ma<arr[i]) ma = arr[i];
	}
	return ma;
}

int fib(int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;

	return fib(n-1) + fib(n-2);
}

int abs(int a)
{
	if(a<0) return -a;
	return a;
}

int main()
{
	int i;
	int arr[10];
	int a,b,c;

	for(i = 0; i<10; i++) arr[i] = abs(i-5);

	for(i = 0; i<10; i++)
	{
		prints("arr[i] = ");
		printi(arr[i]);
		prints("\n");
	}

	a = max(arr, 10);
	prints("a = max arr[i] = ");
	printi(a);
	prints("\n");

	b = fib(6);
	prints("b = fib(6) = ");
	printi(b);
	prints("\n");

	c = add(a,b);
	prints("c = a + b = ");
	printi(c);
	prints("\n");

	c = fib(20);
	prints("c = fib(20) = ");
	printi(c);
	prints("\n");

	return 0;
}