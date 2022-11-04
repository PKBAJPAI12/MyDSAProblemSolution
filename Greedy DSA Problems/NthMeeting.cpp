// Question
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

// Constraints

Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)

// Given Test Case
    N = 6 start[] = {1, 3, 0, 5, 8, 5} end[] = {2, 4, 6, 7, 9, 9}

// Solving Approach

Step-1: First We need to create vector pair (Extra Space 0(n))
Step-2: Iterate a Array of start and end from 0 to N-1 
        Insert end time and start time of meeting in Array with every iteration
Steo-3: Sort Array on behalf of end time of Meeting
Step-4: Interate a Array from 1 to Nth-1 Meetings
        compare start time of meeting > end time of previous meeting
        then increment number of meeting
        and set end time of meeting=curr end time of meeting 
Step-5 Print (Answer Number of Meeting)

// TC=0(n(log n)) and SC=0(n)

// Pschedocode

vector<pair<int, int>>
    v;
i = 0;
for
    i to N - 1
    {
        v.push_back({end[i], start[i]});
    }
sort vectorArray
    m = v[0].first;
c = 1;
for
    i to N
    {
        if v[i].second > m
            {
                c++ m = v[i].first;
            }
    }
return c

    
// Code Solution

    vector<pair<int, int>>
        v;
for (int i = 0; i < n; i++)
{

    v.push_back({end[i], start[i]});
}
sort(v.begin(), v.end());
int m = v[0].first;
int c = 1;
for (int i = 1; i < n; i++)
{
    if (v[i].second > m)
    {
        c++;
        m = v[i].first;
    }
}
return c;


