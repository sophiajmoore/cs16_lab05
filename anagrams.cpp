// Anagrams.cpp
// By: Sophia Moore
// Created on: 11/06/20

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string only_letters(string &the_string, int string_size);
// Pre-condition: a string and its size
// Post-condition: returns a string with only letters

string lowercase_string(string &the_string, int string_size);
// Pre-condition: a string and its size
// Post-condition: returns a string with only lowercase letters

string alphabetical_order(string &the_string);
// Pre-condition: a string
// Post-condition: returns a string in alphabetical order

int letter_frequency(int letter, string &the_string, int string_size);
// Pre-condition: a number corresponding to a character of a string, a string, and its size
// Post-condition: returns the frequency of the specified character

void anagram_checker(string &a_string, string &another_string);
// Pre-condition: two strings
// Post-condition: determines if they are anagrams

int main()
{
    string first_string, second_string;

    cout << "Enter first string:\n";
    getline(cin, first_string);
    cout << "Enter second string:\n";
    getline(cin, second_string);

	// Clean strings: lowercase letters in alphabetical order
    only_letters(first_string, first_string.size());
    only_letters(second_string, second_string.size());
    lowercase_string(first_string, first_string.size());
    lowercase_string(second_string, second_string.size());
    alphabetical_order(first_string);
    alphabetical_order(second_string);


	// Check to see if they are anagrams
	// Report if they are or not anagrams
    anagram_checker(first_string, second_string);

    return 0;
}

string only_letters(string &the_string, int string_size)
{
    string alpha_string;
    for (int i = 0; i < string_size; i++)
    {
        if (isalpha(the_string[i]) != 0)
        {
            alpha_string += the_string[i]; // adds all letters to a new string
        }
    }
    the_string = alpha_string; // rename it to the original name
    return the_string;
}

string lowercase_string(string &the_string, int string_size)
{
    for (int i = 0; i < string_size; i++)
    {
        if ( (the_string[i] >= 65) && (the_string[i] <= 90) )
        {
            the_string[i] += 32; // lowercase letters are 32 away from their corresponding uppercase letters in ascii
        }
    }
    return the_string;
}

int letter_frequency(int letter, string &the_string, int string_size)
{
    int i_count = 1;
    for (int i = letter+1; i < string_size; i++)
    {
        if (the_string[letter] == the_string[i])
        {
            i_count++;
        }
    }
    return i_count;    
}

string alphabetical_order(string &the_string)
{
    // temp to help letters switch places
    int temp;

    // bubble sorting by ascii
    for (int i = the_string.size()-1; i >=0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (the_string[j-1] > the_string[j])
            {
                temp = the_string[j-1];
                the_string[j-1] = the_string[j];
                the_string[j] = temp;
            }
        }
    }
    return the_string;
}

void anagram_checker(string &a_string, string &another_string)
{
    // creating new strings which will hold the frequencies
    string a_string_freq, another_string_freq;

    for (int i = 0; i < a_string.size(); i++)
    {
        a_string_freq += to_string(letter_frequency(i, a_string, a_string.size()));

    }

    for (int i = 0; i < a_string.size(); i++)
    {
        another_string_freq += to_string(letter_frequency(i, another_string, another_string.size()));

    }

    if (a_string_freq == another_string_freq) // comparing the strings
    {
        cout << "The strings are anagrams.\n";
    }

    else
    {
        cout << "The strings are not anagrams.\n";
    }

    return;
}

