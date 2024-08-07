class Solution {
public:
    unordered_map<int, string> name = {
        {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
        {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
        {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
        {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
        {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"},
        {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"},
        {90, "Ninety"}
    };

    unordered_map<int, string> mp = {
        {2, "Thousand"}, {3, "Million"}, {4, "Billion"}
    };

    string sol(int num) {
        string ans = "";
        if (num / 100) {
            ans += name[num / 100] + " Hundred";
        }
        int remainder = num % 100;
        if (remainder) {
            if (remainder < 20) {
                if (ans.length() > 0) ans += " ";
                ans += name[remainder];
            } else {
                if (ans.length() > 0) ans += " ";
                ans += name[remainder - remainder % 10];
                if (remainder % 10) {
                    ans += " " + name[remainder % 10];
                }
            }
        }
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = "";
        int count = 1;
        while (num > 0) {
            if (num % 1000 != 0) {
                string segment = sol(num % 1000);
                if (count > 1 && mp.find(count) != mp.end()) {
                    segment += " " + mp[count];
                }
                if (res.length() > 0) {
                    res = segment + " " + res;
                } else {
                    res = segment;
                }
            }
            num /= 1000;
            count++;
        }
        return res;
    }
};
