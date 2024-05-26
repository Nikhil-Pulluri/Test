#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



struct job{
  char id;
  int dead;
  int profit;
};
int comp(const void* a, const void* b)
{
  int x = (int)((struct Job*)a->profit);
  int y = (int)((struct Job*)b->profit);

  return y-x;
}


int min(int m, int n)
{
  if(m<n) return m;

  else return n;
}

void job(int arr, int n)
{
  qsort(arr, n, sizeof(struct job), comp);


  int result[n];
  bool slot[n] = {false};

  for(int i=0; i<n ; i++)
  {
    for(int j=min(n, arr[i].dead)-1; j>=0; j--)
    {
      if(slot[j]==false)
      {
        result[j] = i;
        slot[j] = true;
        break;
      }
    }
  }


  	for (int i = 0; i < n; i++)
		if (slot[i])
			printf("%c ", arr[result[i]].id);
}



int main()
{
	struct job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf(
		"Following is maximum profit sequence of jobs \n");

	// Function call
	printJobScheduling(arr, n);
	return 0;
}

// int main()
// {
//   int n;
//   scanf("%d", &n);

//   int arr[n];

//   for(int i=0; i<n; i++)
//   {
//     scanf("%d ",&arr[i]);
//   }

//   heapsort(arr, n);

//   for(int i=0; i<n;i++)
//   {
//     printf("%d ", arr[i]);
//   }

//   return 0;
// }
