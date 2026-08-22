class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int wordlen = words[0].size();
        int wordCount = words.size();
        int totallen = wordlen * wordCount;

        if (n < totallen)
            return ans;

        unordered_map<string, int> target;

        for (const string& word : words) {
            target[word]++;
        }

        for (int offset = 0; offset < wordlen; offset++) {
            int left = offset;
            int count = 0;

            unordered_map<string, int> window;
            for (int right = offset;
                 right + wordlen <= n;
                 right += wordlen) {
                string word = s.substr(right, wordlen);
                if (!target.count(word)) {
                    window.clear();
                    count = 0;
                    left = right + wordlen;
                    continue;
                }

                window[word]++;
                count++;
                while (window[word] > target[word]) {
                    string leftWord = s.substr(left, wordlen);

                    window[leftWord]--;
                    left += wordlen;
                    count--;
                }
                if (count == wordCount) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordlen);
                    window[leftWord]--;
                    left += wordlen;
                    count--;
                }
            }
        }

        return ans;
    }
};