#include <bits/stdc++.h>
using namespace std;
void job_squence(vector<pair<int, int>> &job)
{
    int profit = 0;
    profit =job[0].second;
    int safe_deadline = 2;
    //greedy method applies here
    sort(job.begin(),job.end(), [](pair<int, int> a, pair<int, int> b)
         { return b.second < a.second; });
    for (int i = 1; i <job.size(); i++)
    {
        if(job[i].first>=safe_deadline){
            profit+=job[i].second;
            safe_deadline++;
        }
    }
    cout<<"Maximum Profit is : "<<profit;
}
int main()
{
    vector<pair<int, int>> job = {{1, 40}, {1, 15}, {4, 20}, {1, 30}};
    job_squence(job);
    return 0;
}
