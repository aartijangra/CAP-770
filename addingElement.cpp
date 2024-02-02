//adding element in an unsorted array 
#include<iostream>
using namespace std;
int adding(int arr[], int n){

    int k,num;
    cout<<"enter at which index element to be added: "<<endl;
    cin>>k;
    cout<<"enter the element to add: "<<endl;
    cin>>num;

    for(int i=n-1; i>=k; i--){
        arr[i+1]=arr[i];
    }
    arr[k]=num;
    n=n+1;

}
int main(){
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

   
    adding(arr,n);
    n=n+1;

    //updated array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
return 0;
}