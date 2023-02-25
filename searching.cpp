#include<iostream>
using namespace std;
void linearsearch(int[],int,int);
void binarysearch(int[],int,int);
void jumpsearch(int[],int,int);
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i,k;
        cin>>n;
        int* arr=new int(n);
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>k;
        //linearsearch(arr,n,k);
        //binarysearch(arr,n,k);
        jumpsearch(arr,n,k);
    }
}
void linearsearch(int arr[],int n,int k){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==k){
            cout<<"Element "<<k<<" found at index "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}
void binarysearch(int arr[],int n,int k){
    int start,last;
    start=0;
    last=n-1;
    while(start<=last){
        int mid=(start+last)/2;
        if(arr[mid]==k){
            cout<<"Element "<<k<<" found at index "<<mid<<endl;
            return;
        }
        else if(arr[mid]>k){
            last=mid-1;
        } 
        else{
            start=mid+1;
        }
    }
    cout<<"Element not found"<<endl;
}

void jumpsearch(int arr[],int n,int k){
    int l=0,r=l+1;
    while(r<=n){
        if(arr[r]==k){
            cout<<"Element "<<k<<" found at index "<<r<<endl;
            return;
        }
        else if(arr[r]<k){
            l+=2;
            r+=2;
            if(r>n-1){
                r=n;
            }
            continue;
        }
        else if(arr[r]>k){
            for(int i=l;i<r;i++){
                if(arr[i]==k){
                    cout<<"Element "<<k<<" found at index "<<i<<endl;
                    return;
                }
            }
            cout<<"Element not found"<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}