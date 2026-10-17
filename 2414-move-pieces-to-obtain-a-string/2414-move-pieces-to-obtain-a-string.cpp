class Solution {
public:
    bool canChange(string start, string target) {
        int st_ind = 0;
        int trg_ind = 0;
        int m = start.size();
        int n = target.size();

        while (st_ind < m && trg_ind < n) {

            st_ind = non_dash(st_ind, start);
            trg_ind = non_dash(trg_ind, target);

            if (trg_ind < st_ind && start[st_ind] == 'R') {
                return false;
            }

            else if (trg_ind > st_ind && start[st_ind] == 'L') {
                return false;
            }

            if (target[trg_ind] != start[st_ind]) {
                return false;
            }

            st_ind++;
            trg_ind++;
        }

        if (st_ind == m && trg_ind < n) {
            if (non_dash(trg_ind, target) < n) {
                return false;
            }
        }

        if (trg_ind == n && st_ind < m) {
            if (non_dash(st_ind, start) < m) {
                return false;
            }
        }

        return true;
    }

    int non_dash(int ind, string& s) {
        int n = s.size();
        while (ind < n && s[ind] == '_') {
            ind++;
        }

        return ind;
    }
};