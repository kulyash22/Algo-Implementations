#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat,int m,vector<int>&lps){
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

int KMPSearch(string pat,string txt){
    int m=pat.size();
    int n=txt.size();
    vector<int>lps(m);
    computeLPSArray(pat,m,lps);
    int ans=-1;
    int i=0;
    int j=0;
    while(i<n){
        if(pat[j]==txt[i]){
            j++;
            i++;
        }
        if(j==m){
            ans=i-j;
            j=lps[j-1];
            break;
        }
        else if(i<n && pat[j]!=txt[i]){
            if(j!=0)j=lps[j-1];
            else i=i+1;
        }
    }
    return ans;
}

int main() {
    string pat="ABABCABAB";
    string txt="ABABDABACDABABCABAB";
    cout << KMPSearch(pat,txt);
	return 0;
}
