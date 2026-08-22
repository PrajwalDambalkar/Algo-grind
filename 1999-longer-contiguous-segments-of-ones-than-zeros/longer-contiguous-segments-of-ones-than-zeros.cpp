class Solution {
public:
    bool checkZeroOnes(string s) {
        int zero = 0, one = 0, maxi0 = 0, maxi1 = 0, res = 0;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '1') {
                one++;
                zero = 0;
                maxi1 = max(maxi1, one);
            }
            else if (s[i] == '0'){
                zero++;
                one = 0;
                maxi0 = max(maxi0, zero);
            }
        }
        // cout<<maxi1<<"\n";
        // cout<<maxi0;
        if (maxi1 > maxi0) return true;
        return false;
    }
};