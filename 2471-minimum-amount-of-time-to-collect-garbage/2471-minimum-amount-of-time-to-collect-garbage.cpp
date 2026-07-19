class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int g_max_index = -1;
        int m_max_index = -1;
        int p_max_index = -1;
        int counter = 0;
        int sum = 0;

        int tr_n = travel.size();
        int gr_n = garbage.size();
        vector<int> prefix(tr_n);
        prefix[0] = travel[0];

        for (int i = 1; i < tr_n; i++) {
            prefix[i] = prefix[i - 1] + travel[i];
        }

        for (int i = 0; i < gr_n; i++) {
            for (int j = 0; j < garbage[i].size(); j++) {
                if (garbage[i][j] == 'G') {
                    g_max_index = i;
                    counter++;
                }

                else if (garbage[i][j] == 'P') {
                    p_max_index = i;
                    counter++;
                }

                else if (garbage[i][j] == 'M') {
                    m_max_index = i;
                    counter++;
                }
            }
        }

        if (g_max_index > 0) {
            sum += prefix[g_max_index - 1];
        }

        if (p_max_index > 0) {
            sum += prefix[p_max_index - 1];
        }

        if (m_max_index > 0) {
            sum += prefix[m_max_index - 1];
        }

        return sum + counter;
    }
};