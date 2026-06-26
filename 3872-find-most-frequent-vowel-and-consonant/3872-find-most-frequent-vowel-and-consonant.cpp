class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map <char, int> vow;
        unordered_map <char, int> cons;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') 
            {
                if (vow.contains(s[i]))
                {
                    vow[s[i]] += 1;
                }
                else
                {
                    vow[s[i]] = 1;
                }
                
            }
            else
            {
                if (cons.contains(s[i]))
                {
                    cons[s[i]] += 1;
                }
                else
                {
                    cons[s[i]] = 1;
                }
            }
        }

        int vow_fre = 0;
        for (auto vow_val = vow.begin(); vow_val != vow.end(); vow_val++)
        {
            if (vow_val->second > vow_fre)
            {
                vow_fre = vow_val->second;
            }
        }
        int cons_fre = 0;
        for (auto con_val = cons.begin(); con_val != cons.end(); con_val++)
        {
            if (con_val->second > cons_fre)
            {
                cons_fre = con_val->second;
            }
        }
        return cons_fre + vow_fre;
    }
};