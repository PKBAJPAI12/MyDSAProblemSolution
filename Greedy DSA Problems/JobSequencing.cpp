// Question
Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

//Given Test Cases
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60

// TC ->0(nlogn)+0(n*m) SC->o(n);

// Solve Approach

Step-1 Sort the jobs in descending order of profit using comparator. 
Step-2 If the maximum deadline is x, make an array of size x .Make bool Array of size x with false initially as no jobs have been performed yet.
Step-3 For every job check if it can be performed on its last day.
Step-4 If possible mark true to bool array and add the profit to our answer and count. 
Step-5 If not possible, loop through the previous indexes until an empty slot is found.

//Code Solution


static bool comp(Job a,Job b){   
        return a.profit>b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int mx=0;
        for(int i=0; i<n; i++){
           if(arr[i].dead>mx){
               mx=arr[i].dead;
           }
        }
        int maxProfit=0,count=0;
        bool profitArr[mx]={false};
        
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>=1; j--){
                if(profitArr[j]==false){
                 profitArr[j]=true;
            maxProfit+=arr[i].profit;
            count++;
            break;
                }
            }
        }
        vector<int> v;
        v.push_back(count);
        v.push_back(maxProfit);
        return v;
    } 