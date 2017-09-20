#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int n;
int arr[1000000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        arr[i]+=1000000;
    }
    
    for(int i=1;i<=8;i++){
        queue<int> q[10];
        for(int j=0;j<n;j++){
            int temp=arr[j];
            temp%=(int)pow(10,i);
            temp/=(int)pow(10,i-1);
            q[temp].push(arr[j]);
        }
        int idx=0;
        for(int j=0;j<10;j++)
            while(!q[j].empty()){
                int now=q[j].front();
                q[j].pop();
                arr[idx++]=now;
            }
    }
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]-1000000);
    return 0;
}
