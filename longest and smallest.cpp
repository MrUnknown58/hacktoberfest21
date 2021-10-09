// CPP Program to find Smallest and
// Largest Word in a String
#include<iostream>
#include<cstring>
using namespace std;
 
void minMaxLengthWords(string input, string &minWord, string &maxWord)
{
    // minWord and maxWord are received by reference
    // and not by value
    // will be used to store and return output
    int len = input.length();
    int si = 0, ei = 0;
   
   
    int min_length = len, min_start_index = 0, max_length = 0, max_start_index = 0;
 
    // Loop while input string is not empty
    while (ei <= len)
    {
        if (ei < len && input[ei] != ' ')
            ei++;
         
        else
        {
            // end of a word
            // find curr word length
            int curr_length = ei - si;
         
            if (curr_length < min_length)
            {
                min_length = curr_length;
                min_start_index = si;
            }
             
            if (curr_length > max_length)
            {
                max_length = curr_length;
                max_start_index = si;
            }
            ei++;
            si = ei;
        }
    }
     
    // store minimum and maximum length words
    minWord = input.substr(min_start_index, min_length);
    maxWord = input.substr(max_start_index, max_length);
}
 

int main()
{
    string a = "GeeksforGeeks A Computer Science portal for Geeks";
    string minWord, maxWord;
    minMaxLengthWords(a, minWord, maxWord);
     
    // to take input in string use getline(cin, a);
    cout << "Minimum length word: "
        << minWord << endl
        << "Maximum length word: "
        << maxWord << endl;
}
