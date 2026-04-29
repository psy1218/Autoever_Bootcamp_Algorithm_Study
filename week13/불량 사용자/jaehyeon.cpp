#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool Check_ban(string b_id, string u_id)
{
    if(b_id.size()!=u_id.size()) return false;
    for(int i=0; i<u_id.size(); i++)
    {
        if(b_id[i]=='*') continue;
        if(b_id[i]!=u_id[i]) return false;
    }
    return true;
}

set<string> s;
set<vector<string>> result;

void dfs(vector<vector<string>>& ban_list, int depth)
{
    if(depth==ban_list.size())
    {
        if(s.size()==depth)
        {
            vector<string> temp(s.begin(), s.end());
            result.insert(temp);
            return;
        }
        return;
    }
    
    for(int i=0; i<ban_list[depth].size(); i++)
    {
        string str = ban_list[depth][i];

        if(s.count(str)) continue;

        s.insert(str);
        dfs(ban_list, depth + 1);
        s.erase(str);
    }
    
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<vector<string>> ban_list(banned_id.size());
    
    for(int i=0; i<banned_id.size(); i++)
    {
        for(int j=0; j<user_id.size(); j++)
        {
            if(Check_ban(banned_id[i], user_id[j])) 
            {
                ban_list[i].push_back(user_id[j]); 
            }
        }
    }
    
    dfs(ban_list, 0);
    
    answer=result.size();
    
    return answer;
}