char ch[] = {'A', 'C', 'G', 'T'};

class Solution {
public:

    string stringify(int no){
        string ans;
        for(int i = 0; i < 10; i++){
            int ind = no & 3;
            ans.push_back(ch[ind]);
            no >>= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        int subs = 0;
        unordered_map<int, int> cnt;
        unordered_map<char, int> hash;

        hash['A'] = 0;
        hash['C'] = 1;
        hash['G'] = 2;
        hash['T'] = 3;


        if(s.size() < 11) return {};
        
        for(int i = 0; i < 10; i++){
            subs = ((subs << 14) >> 12) |  hash[s[i]];
        }
        cnt[subs] = 1;
        
        for(int i = 10; i < s.size(); i++){
            subs = ((subs << 14) >> 12) |  hash[s[i]];
            cnt[subs] ++;
        }

        vector<string> ans;

        for(auto &[str, f] : cnt){
            if(f == 1) continue;
            ans.push_back(stringify(str));
        }

        return ans;
    }
};

// New approch learnt :-
// instead of maintaining set for every string and use (10) iterations for every string for matching string character by character

// Since no of character are just 4 and also 10 characters in 1 string BUT 
// We can match number in O(1) time but not string, lets encode sting into number :
//     We can either make 10 digit no where each digit represent 1 of the chaarcter : bt out of bound chances ->
//                 either use long but instead 
//                 if we observe, every no is 32 bits where 30 bits are empty : So instead of storing full nhumber, lets just use 2 bits to represent characetr to save space 
//                 Will see that 10 char -> 2 bits each (00, 01, 10, 11 - represeting the no only can be used)
//                 Total 20 bits of int var will be used and either use bitset for optimization or simpley use int 
//                         NOW time of O(10) to match the string is compressed to O(1)
