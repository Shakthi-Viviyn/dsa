class Solution {
public:
    string minWindow(string s, string t) {

        std::unordered_map<char, int> map;
        std::unordered_map<char, int> window;

        for (int i = 0; i < t.length(); i++){
            map[t[i]] += 1;
        }

        int minLeft = 0;
        int minRight = s.length() - 1;
        int left = 0;
        int right = 0;

        while (left < s.length() && right < s.length()){
            while(right < s.length()){
                if (map.find(s[right]) != map.end()){
                    window[s[right]] += 1;
                    for (const auto& pair : map) {
                        std::cout << "{" << pair.first << " " << pair.second << "} , ";
                    }
                    std::cout << std::endl;
                    for (const auto& pair : window) {
                        std::cout << "{" << pair.first << " " << pair.second << "} , ";
                    }
                    std::cout << std::endl;
                }
                if (window == map){
                    break;
                }
                right++;
                std::cout << "l: " << left << "  r: " << right << std::endl;
            }

            while(left < s.length()){
                if (map.find(s[left]) != map.end() && window[s[left]] == map[s[left]]){
                    break;
                }
                if (window.find(s[left]) != window.end()){
                    window[s[left]] -= 1;
                    for (const auto& pair : map) {
                        std::cout << "{" << pair.first << " " << pair.second << "} , ";
                    }
                    std::cout << std::endl;
                    for (const auto& pair : window) {
                        std::cout << "{" << pair.first << " " << pair.second << "} , ";
                    }
                    std::cout << std::endl;
                }
                std::cout << "l: " << left << "  r: " << right << std::endl;
                left++;
            }
            
            if ((right - left) < (minRight - minLeft) && left < s.length() && right < s.length()){
                minLeft = left;
                minRight = right;
            }

            if (right == s.length() - 1){
                break;
            }
            window[s[left]] -= 1;
            left++;
        }

        window.clear();
        for (int i = minLeft; i <= minRight; i++){
            if (map.find(s[i]) != map.end()){
                window[s[i]] += 1;
            }
        }

        if (window == map){
            return s.substr(minLeft, minRight - minLeft + 1);   
        }
        return "";
         
    }
};