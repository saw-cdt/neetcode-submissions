class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> records;
        int score = 0;

        // fill records
        for (auto i: operations) {
            if (i == "+") {
                auto size = records.size();
                int sum = records[size-1] + records[size-2];
                records.push_back(sum);
            } else if (i == "C") {
                records.pop_back();        
            } else if (i == "D") {
                auto size = records.size();
                int sum = records[size-1] * 2;
                records.push_back(sum);
            } else {
                records.push_back(stoi(i));
            }
        }

        // sum score
        for (auto i: records) {
            score += i;
        }

        return score;
    }
};