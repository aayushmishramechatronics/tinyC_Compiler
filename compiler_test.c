
void sort(int *a, int n)
{
	int i, j, temp;
	for(i = 0; i<n ; i++)
		for(j = 0; j<n-1; j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
}

int main()
{
	prints("Enter 10 integers to sort:\n");
	int a[10];
	int i;
	int ep;
	for(i = 0; i<10; i++) a[i] = readi(&ep);
	// for(i = 0; i<10; i++) printi(a[i]);
	sort(a,10);
	prints("The sorted integers are:\n");
	for(i = 0; i<10; i++)
	{
		printi(a[i]);
		prints(" ");
	}
	prints("\n");
	return 0;
}