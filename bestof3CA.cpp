#include<bits/stdc++.h>
using namespace std;

void trav(int arr[])
{   
    int sum=0;
    int smallest=arr[0];
    int max1, max2, max3;

    for(int i=1; i<4; i++ ){
       if(arr[i]<arr[0]){
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
       }
    }
    for(int i=4; i>smallest; i-- ){
        cout<<arr[i]<<" ";
        sum+=i;
    }
    cout<<endl;
    cout<<"sum is: "<<sum;

}
int main(){
    int arr[4];
    
    for(int i=0; i<4; i++){
        cin>>arr[i];
    }
    trav(arr);
    return 0;
}


