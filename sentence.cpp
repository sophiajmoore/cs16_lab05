// Sentence.cpp
// By: Sophia Moore
// Created on: 11/06/20

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// MISSING FUNCTION DECLARATIONS HERE (you can remove these comments)

void sort_string(string &the_string, int string_size);
// Pre-condition: needs a string and its size
// Post-condition: will take out non-alphabetical characters, 
// sort letters by ascii, then outputs final string

void print_freq(string the_string, int string_size);
// Pre-condition: needs a string and its size
// Post-condition: will find the frequency of each letter and 
// will print each letter and its corresponding frequency

int main()
{
    string sentence;
    // MISSING (short) CODE HERE TO GET SENTENCE FROM USER (you can remove these comments)

    cout << "Enter sentence: ";
    getline(cin, sentence);

    sort_string(sentence, sentence.size());
    print_freq(sentence, sentence.size());

	return 0;
}

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)

void sort_string(string &the_string, int string_size)
{
    // instead of deleting from the_string, i'm adding letters to alpha_string
    string alpha_string; 

    for (int i = 0; i < string_size; i++)
    {
        if (isalpha(the_string[i]) != 0)
        {
            alpha_string += the_string[i];
        }
    }

    // temp to help letters switch places
    int temp;

    // bubble sorting by ascii
    for (int i = alpha_string.size()-1; i >=0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (alpha_string[j-1] > alpha_string[j])
            {
                temp = alpha_string[j-1];
                alpha_string[j-1] = alpha_string[j];
                alpha_string[j] = temp;
            }
        }
    }
    
    the_string = alpha_string;
    cout << "Sorted and cleaned-up sentence:" << the_string << endl;

    return;
}

void print_freq(string the_string, int string_size)
{
    for (int i = 0; i < string_size; i++)
    {
        if (the_string[i] != ' ')
        {
            int i_count = 1; // if it's not a space, it's automatically 1
            for (int j = i+1; j < string_size; j++)
            {
                if (the_string[i] == the_string[j])
                {
                    i_count++;
                    the_string[j] = ' '; // after it's counted, I set it to space
                    
                }
            }
            cout << the_string[i] << ": " << i_count << endl;
            the_string[i] = ' ';
        }
    }
    
    return;
}

