#include <iostream>
using namespace std;
int main() {
    int n, key;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> key;
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==key){
            cout << m;
            return 0;
        }
        else if(a[m]>key) r=m-1;
        else l=m+1;
    }
    cout << -1;
}
