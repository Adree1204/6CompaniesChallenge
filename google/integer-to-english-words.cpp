string suff[] = {"", "Thousand ", "Million ", "Billion "};
    
string tens_with_one[] = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
string tens[] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
string dig[] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "}; 

class Solution {
public:

    string triplet(string num){
        if(num.size() == 1) return dig[num[0] - '0'];
        string prefix = num.size() == 3 && num[0] - '0' ? dig[num[0] - '0'] + "Hundred " : "";

        string last = tens[num[num.size() - 2] - '0'] + dig[num.back() - '0'];
        if(num[num.size() - 2] != '1') return prefix + last;

        return prefix + tens_with_one[num.back() - '0'];
    }

    string num_to_str(string num){
        int it = 0;
        while(it < num.size() && num[it] == '0') it++;
        num = num.substr(it, num.size() - it + 1);

        if(num.size() == 0) return num;

        int d = num.size();
        string suffix = suff[(d - 1)/3];

        int pre_len = d%3 ? d%3 : 3;
        string prefix = triplet(num.substr(0, pre_len));

        // if(prefix == "") suffix = "";

        int rem_sz = num.size() - pre_len;
        return prefix + suffix + num_to_str(num.substr(pre_len, rem_sz));
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string ans = num_to_str(to_string(num));
        ans.pop_back();
        return ans;
    }
};


//   explore and see the basic rules of billion, ..  and understand em well for evevry possible case : Then pseudo code (recc and fnal) and then code is super easy)
// We will notice each number is combn of cluster of triplets from right to left and each triplet(sz <= 3) is written 
// as hundreds (123, 012, ...) and if all 0 : Nothing is written - not even suffix (million, ...), else after this triplet it is wrrten 
// Since we left sapce after every word, we will end up with extra space removing and an edge case of `0 as number passed 
// Only word zero is seen in any ans when ip is itself 0