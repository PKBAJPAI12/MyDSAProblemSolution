// Question
Given arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. 
Arrival and departure time can never be the same for a train but we can have arrival time of one 
train equal to departure time of the other. At any given instance of time, same platform can not be
 used for both departure of a train and arrival of another train. 
In such cases, we need different platforms.

// Constraints

Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)


// Given Test Case
Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3

// Solving Approach
We Know that Minimum platform reqired=maximum train at platform at a same time

Step-1: First We need to sort arrival time of train and departure time of train
Step-2: we know 1 platform is always available for single train and maximum(mx) platform is also 1
Steo-3: Iterate a array from 1 to n-1 train
        if arrival time of train >min departure time from sorted departure time array 
           it means one 'plaform is decrement' before arrive of train and 
           now 'departure time array index increment' becuase prev departure time is already over
        else 'arrive train need one platform' and other platform is also occupied then 'increment platform'
              and set maximum train at a time= max(platform,mx);
Step-4: print maximum train at a time=minium platform


// Algorithm Flow                                                                         
                                                                         //comment                  
    (set min dept time dept[2]=11:30(from dep sort Array))              __________________ 
    (this train arrive after min dept time=11:20 that's' why it stay at same platform)    |               (set min dept time dept[2]=11:30(from dep sort Array))   
                                                                                          |    (train 6) (this train arrive after min dept time=11:30 that's' why it stay at same platform) 
Platform=3            (train 4)       11:00--->11:30                                      |   18:00 ---->20:00
                                      ^   |                                               |
                                      |  (because platform 1 & 2 both is occupied during  |this train arrival time)
                                      |(train arrives before min dept time=11:20 that's'__| why platform++)
Platform=2            (train 3) 9:50---->11:20                    15:00-------->18:00---| (train 5)
                                ^   | (because platform 1 is occupied during this train arrival time)
                                |  (train arrives before min dept time=11:20 that's' why platform++)
            (train 1)             | 
Platform=1  9:00-->9:10   9:40--------------------->12:00 (train 2)       
            |              | (set min dept time dept[1]=11:20(from dep sort Array))
            |              (this train arrive after min dept time=9:10 that's' why it stay at same platform)
            Here min dept= dept[0]=9:10 platform =1 and mx=1  (max train at time)



// TC=0(n(log n)) and SC=0(1)


// Why ?
Why we Sort Arrival Time
'We Sort Arrival Time of Train because one by one increment train at the plaform at station '

Why we Sort Departure Time
'We Sort Departure Time of Train because I don't 'care about departure time of respected arrival time train'.

'I care about if any train arrive/comes on platform that need platform for staying so if any platform is available
for arrive/coming train then train occupy empty platform otherwise we need extra other platform'
'for checcking platform availability for arriving train we need to sort deparure time if any train
 is departed before upcoming train then respected platform is empty and upcoming train stay on this available platform'   


// Code Solution

   
 sort(arr,arr+n);
sort(dep,dep+n);
int mx=1;
int j=0,i=1;
int platform=1;
while(i<n)
{
    if (arr[i]>dep[j])
    {
        j++;
        platform--;
    }
    else{
        i++;
        platform++;
        mx=max(mx,platform);
    }
}
return mx;

