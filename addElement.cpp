//adding element in sorted array
#include<iostream>
using namespace std;
int adding(int arr[], int n){
    

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

    //updated array
    for(int i=0; i<=n; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}