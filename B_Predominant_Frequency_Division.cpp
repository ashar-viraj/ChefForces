#include<bits/stdc++.h>
using namespace std;

int main(){
    int t , n ;
    vector<int> v ;
    cin>>t;
    for(int i = 0 ; i< t ; i++){
        cin>>n;
        bool flag = true;
        vector<int> v(n,0);
        vector<int> c1(n,0);
        for(int j = 0 ; j <n ;j++){
            cin>>v[j];
        }

        if(v[0]==1)
            c1[0]=1;
        else
            c1[0]=0;
        for(int j = 1 ; j <n ;j++){
            if(v[j]==1)
                c1[j]=c1[j-1]+1;
            else
                c1[j]=c1[j-1];
        }

        int c12 = 0;
        int mins = 0;
        for(int j = n-1-1 ; j >0 ; j--){
            if(v[j]==1 || v[j]==2)
                c12++;
            else
                c12--;

            if(c12>=mins && c1[j-1]>=((j+1)/2) && c1[j-1]>=1){
                cout<<"YES"<<endl;
                flag=false;
                break;
            }

            if(c12<mins)
                mins=c12;
        }

        if(flag)
            cout<<"NO"<<endl;
    }
}