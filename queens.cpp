class Solution {
    public:
    vector<bool> rs;
    vector<bool> cs;
    unordered_map<int, bool> diags;
    unordered_map<int, bool> antidiags;
    vector<string> build;
    int buildSol(int r) {
        if (r == rs.size()) {
            return 1;
        }
        rs[r] = true;
        int sum = 0;
        for (int c = 0; c < cs.size(); c++) {
           
            
            if (!cs[c] && !diags[r-c] && !antidiags[r + c]) {
                build[r][c] = 'Q';
                cs[c] = true;
                diags[r-c] = true;
                antidiags[r + c] = true;
                // diags and antidiags are true
                sum += buildSol(r + 1);
                build[r][c] = '.';
                diags[r-c] = false;
                cs[c] = false;
                antidiags[r+c] = false;
                // diags and antidiags are false

            }
        }
        rs[r] = false;
        return sum;
    }
    int totalNQueens(int n) {
        rs.resize(n);
        cs.resize(n);
        string b;
        b.resize(n, '.');

        build.resize(n, b);
        return buildSol(0);
    }


};
