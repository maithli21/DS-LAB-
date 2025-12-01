#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n-1];
    for(int i=0;i<n-1;i++) cin >> a[i];

    int l=0,r=n-2,ans=n;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m] != m+1){
            ans = m+1;
            r = m-1;
        } else l = m+1;
    }
    cout << ans;
}
