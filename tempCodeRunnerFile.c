#include<stdio.h>
#include<stdlib.h>

struct item{
  int profit;
  int weight;
};

// comp fun

int cmp(const void* a, const void* b){
  double r1 = ((double)((struct item*)b)->profit / (double)((struct item*)b)->weight);
  double r2 = ((double)((struct item*)a)->profit / (double)((struct item*)a)->weight);

  if(r1<r2){
    return -1;
  }

  else if(r1>r2){
    return 1;
  }

  else return 0;
}



double fractional(int w, struct item arr[], int n)
{
  qsort(arr, n, sizeof(struct item), cmp);

  double value = 0.0;

  for(int i=0; i<n;i++)
  {
    if(arr[i].weight<= w)
    {
      value += arr[i].profit;
      w -= arr[i].weight;
    }

    else {
      value += arr[i].profit*((double)w/(double)arr[i].weight);
    }
  }

  return value;
}


int main()
{
  int w,n;

  scanf("%d %d",&w,&n);

  struct item arr[n];

  for(int i=0;i<n;i++)
  {
    scanf("%d %d", &arr[i].profit, &arr[i].weight);
  }


  printf("%2f", fractional(w, arr, n));

  return 0;


}