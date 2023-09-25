class Solution {
public:
char findTheDifference(string s, string t)
{
    vector<int> count1 (26, 0); 
    vector<int> count2 (26, 0); 
    char ans;

    for (int i = 0; i < s.length(); i++)
    {
        count1[s[i]-'a'] += 1;
    }

    for (int i = 0; i < t.length(); i++)
    {
        count2[t[i]-'a'] += 1;
    }

    for (int i = 0; i < count1.size(); i++)
    {

        count2[i] -= count1[i];

    }
    for (int i = 0; i < count2.size(); i++)
    {

        if (count2[i]!=0)
        {
            ans = (i + 'a');
        }
        

    }

    return ans;
    
    
}
};