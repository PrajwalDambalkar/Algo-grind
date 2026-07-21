class Solution {
// private:
//     //function to get the roman string for units digits
//     string unitsDigitsToRoman(int digit) {
//         switch(digit) {
//             case 0:
//                 return "";
//         }
//     }

//     //function to get the roman string for tens digits
//     string tensDigitsToRoman(int digit) {
        
//     }

//     //function to get the roman string for hundreds digits
//     string hundredsDigitsToRoman(int digit) {
        
//     }

//     //function to get the roman string for thousands digits
//     string thousandsDigitsToRoman(int digit) {
        
//     }

public:
    string intToRoman(int num) {
        
        // char I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        vector<vector<string>> s = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}};

        return s[3][num/1000] + s[2][(num/100)%10] + s[1][(num/10)%10] + s[0][num%10];
    }
};