//add two poly using exp-coeff in ascending order of exp
int poly_add(poly polyA[50], poly polyB[50], poly polyC[50], int n1, int n2) 
{
  int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) //use < not <=
    {
        if (polyA[i].exp < polyB[j].exp) 
            polyC[k++] = polyA[i++];   //copy from polyA 
	    else if (polyA[i].exp > polyB[j].exp) 
		    polyC[k++] = polyB[j++];   //copy from polyB
    	else 
		{	polyC[k].coeff = polyA[i].coeff + polyB[j].coeff;
      		if (polyC[k].coeff != 0) //this check is must
			else
			{	polyC[k].exp = polyA[i].exp;
				k++;
      		}
      		i++;j++;
    }
  	while (i < n1) 
    	polyC[k++] = polyA[i++];
	while (j < n2) 
    	polyC[k++] = polyB[++j];
    return k;
}

//ques 3: check corrcet parenthesization using ()
int check_paren(char expr[])
{
	i=0;
	while (expr[i]!='\0')
	{
	    if (expr[i] == '(' )
		  push('(');
		else if (expr[i] ==')')
		{
			if (pop()=='$')//checking whether pop was successful or not is must
				return -1;  //correspong ( not present, hence incorrect paren
		}
		i++;    
	}
	if (pop() == '$') //check thru pop not thru stack[top]
	// other way to do it can be if (isempty() == TRUE)
		return 1;   //correct paren, as no extra ( present in stack
	else return -1;   
}
void push (char sym)
{
	if (top >= MAX-1)  //use >= not >
	    printf("Stack Full");
	else
		stack[++top] = sym;
}

char pop ()  //return type must be char
{
	if (top <= -1) 
	{
		return ('$');  //MUST to return unsuccessful
	}
	else
		return stack[top--];
}


//Ques 2: quicksort based changes
int partition(int arr[],int l,int h)
{
	int i=l;
	int j=h+1;
	int pivot=arr[l];
	while(i<j)
	{
		do
			i++;
		while((i<=h)&&(arr[i]<pivot)); //use < for pivot comparison
		do
			j--;
		while(arr[j]>pivot);
		if(i<j)
		{
			printf("\n%d at index %d being swapped with %d at index %d",arr[i],i,arr[j],j);
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	printf("\npivot %d being swapped with %d at index %d",arr[l],arr[j],j);		
	int temp=arr[j];
	arr[j]=arr[l];
	arr[l]=temp;
	return j;
}
void quicksort(int arr[],int l,int h)
{
	if(l<h)
	{
	int	j=partition(arr,l,h);
		printf("\nLeft sublist is ");
		for (i=l;i<=j-1;i++)  
		    printf("%d ", arr[i]);
		printf("\nRight sublist is ");
		for (i=j+1;i<=h;i++)  
		    printf("%d ", arr[i]);
		quicksort(arr,l,j-1);
		quicksort(arr,j+1,h);
	}
}

