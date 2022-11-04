// Prefix Sum Technique Approach
/*  
Suppose Given Array 
Index           i to N ->  {1 2 3 4 5 6}
Array           arr[]  ->  {3,6,2,8,9,2}
Prefix Sum Array pf[]  ->  {3,9,11,19,28,30}
Here If We  need Sum of between any 2 indexes
Suppose we need sum of 2 to 4 index Now
assume l=2 and r=4
Now pr[r]-pr[l-1];
Here We can Compute Sum of indexes between l and r 
sum of till r index substract to index before l;
*/



/* Prefix Sum is a Pre Computaion Technique for Reduce Complexity 
*/


/*
Constraints:
1<=N<=10^5
1<=a[i]<=10^9
1<=Q<=10^5
1<=L, R<=N


 Calculate sum of Array from L to R index given in Query using Brute Force Approach 
*/

# include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
int n; cin>>n;
for(int i=1; i<=n; i++){            // TC: O(N)
    cin>>a[i];
}
int q; cin>>q;
while(q--){                         // TC: O(Q)
    int l,r;
    cin>>l>>r;
    long long sum=0;
for(int i=l; i<=r; i++){           // TC: O(N) because in worst case Scenario l=1 and r= N in given Constraints
sum+=a[i];
}
cout<<sum<<endl;
}
}
/*
Time Complexity Scenario

In this Approach Time Complexity of Program is with given Constraints
O(N)+O(Q)*O(N)=O(N)+O(N)*O(N)=O(N^2) in terms of N;
here N=10^5 now 10^5 *10^5=10^10 this program take more than 1 second so thats why its not work if TC is O(N)
 */


/* This Program Done using Prefix Sum Technique we can Optimised this Complexity */

# include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int pr[N];                       // Prefix Sum Array 
int main(){
int n; cin>>n;
for(int i=1; i<=n; i++){            // TC: O(N)  Use 1 base Indexing for Prefix sum
    cin>>a[i];
    pr[i]=pr[i-1]+a[i];         // Calculate Prefix Sum
}
int q; cin>>q;
while(q--){                         // TC: O(Q)
    int l,r;
    cin>>l>>r;

cout<<pr[r]-pr[l-1]<<endl;
}
}

/*Time Complexity Scenario in Prefix Sum

In this Approach Time Complexity of Program is with given Constraints
O(N)+O(Q)=O(N)+O(N)=O(2N)=O(N) in terms of N;
here N=10^5 now 10^5 
 */

