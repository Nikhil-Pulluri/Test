int maxsum(int arr[], int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;



       int le = maxsum(arr,l,mid);
       int r =  maxsum(arr,mid+1,h);
       int c = cross(arr,le, mid, r);



    return max(le,c,r);
    }
}


int cross(int arr[],int l, int mid, int r)
{
    int sum = 0;




    for(int i=mid; i>=l; i--)
    {
        sum+=arr[i];

        if(sum>left)
        {
            ledt
        }
    }



    return left+right-sum;
}
