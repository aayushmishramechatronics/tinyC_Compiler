// Test file 5
// Bubble sorting n integers from user input

void sort(int* arr, int n)
{
	int i, j, temp;
	for(i = 0; i<n; i++)
		for(j = 0; j<n-1; j++)
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
}

int main()
{
	int arr[20];
	int i, n, ep;

	prints("Enter the number of integers n: ");
	n = readi(&ep);
	prints("You entered n = ");
	printi(n);
	prints("\n");

	prints("Enter n integers: ");
	for(i=0; i<n; i++) arr[i] = readi(&ep);
	sort(arr,n);
	
	prints("The n integers in ascending order: ");
	for(i=0; i<n; i++)
	{
		printi(arr[i]);
		prints(" ");
	}
	prints("\n");

	return 0;
}