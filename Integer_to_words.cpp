// Time Complexity: O(log n), where n is the input number.
// Space Complexity: O(1), as we are using a constant amount of space for the variables.
// Did this code run successfully on LeetCode? Yes

// Approach: 
// 1. We define three vectors to store the words for numbers below 20, tens, and thousands.
// 2. We create a function `numberToWords` that takes an integer as input and returns its English words representation.
// 3. Inside the function, we check if the number is zero and return "Zero".
// 4. We use a while loop to process the number in chunks of 1000, appending the corresponding words to the result.
// 5. We call a helper function to convert numbers less than 1000 into words.
// 6. The helper function handles numbers less than 20, tens, and hundreds.
// 7. Finally, we return the constructed string after trimming any leading or trailing spaces.

class Solution {
    vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen","Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> hundreds = {"","","Twenty","Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        string word = "";
        int i = 0; 
        while(num > 0){
            if(num % 1000 != 0){
                word = helper(num % 1000) + thousands[i] + (word.empty() ? "" : " ") + word;
            }
            num = num / 1000;
            i++;
        }
        word.erase(0, word.find_first_not_of(' '));
        word.erase(word.find_last_not_of(' ') + 1);
        return word;
    }
private: 
    string helper(int num){
        if(num < 20){
            return below_20[num % 20] + " ";
        }
        else if(num < 100){
            return hundreds[num / 10] + (num % 10 ? " " + helper(num % 10) : " ");
        }
        else{
            return below_20[num / 100] + " Hundred" + (num % 100 ? " " + helper(num % 100) : " ");
        }
    }
};