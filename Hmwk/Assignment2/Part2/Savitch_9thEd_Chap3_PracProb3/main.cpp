/* 
 * File:   main.cpp
 * Author: Tati
 *
 * Created on January 14, 2015, 9:51 PM
 * 
 * Homework:
 * Write an astrology program. 
 * 1. The user types in a birthday, and the program 
 *    responds with the sign and horoscope for that birthday. 
 *    - The month may be entered as a number from 1 to 12. 
 * 
 * 2. Then enhance your program so that if the birthday is only one or two days 
 *    away from an adjacent sign, the program announces that 
 *    - the birthday is on a “cusp” and 
 *    - outputs the horoscope for that nearest adjacent sign. 
 * This program will have a long multiway branch. Make up a horoscope for 
 * each sign. 
 * 
 * Your program should include a 
 * loop that lets the user repeat this calculation until the user says she 
 * or he is done.
 */

#include <iostream>
using namespace std;

short month, // the month entered by user
      day;   // the day entered by user

void getMonth()
{
    // continues until input is correct
    while (true)
    {
        // Get month from user
        cout << "Month of Birth: ";
        cin  >> month;
        
        // check if month exists
        if (month < 1 || month > 12)
        {
            cout << "Month does not exist" << endl;
            continue;
        }
        else
            break;
    }
}

void getDay()
{
    
        
    while (true)
    {
        // Get day from user
        cout << "Day of Birth: ";
        cin  >> day;
    
        // Check for correct day per month
        switch (month)
        {
            case 1: 
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else
                    break;
            }
            case 2:
            {
                if (day < 1 || day > 29)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 3:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 4:
            {
                if (day < 1 || day > 30)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 5:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 6:
            {
                if (day < 1 || day > 30)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 7:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 8:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 9:
            {
                if (day < 1 || day > 30)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 10:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 11:
            {
                if (day < 1 || day > 30)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            case 12:
            {
                if (day < 1 || day > 31)
                {
                    cout << "Day does not exist" << endl;
                    continue;
                }
                else 
                    break;
            }
            default:
                break;
        }
        break;
    }
}

void getBirthday()
{
    getMonth();
    getDay();
}

void getSign()
{
    short adj; // check if day of birth is only 
               // one or two days away from an adjacent sign
    
    // Get user's horoscope sign
    switch (month)
    {
        case 1:
        {
            if (day <= 19)
            {
                cout << "You are a(n) Capricorn" << endl;
                adj = 19 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Capricorn: You will be lucky today."  << endl;     
                }
            }
            if (day >= 20)
            {
                cout << "You are a(n) Aquarius" << endl;
                adj = 20 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Aquarius: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 2:
        {
            if (day <= 18)
            {
                cout << "You are a(n) Aquarius" << endl;
                adj = 18 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Aquarius: You will be lucky today."  << endl;     
                }
            }
            if (day >= 19)
            {
                cout << "You are a(n) Pisces" << endl;
                adj = 19 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Pisces: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 3:
        {
            if (day <= 20)
            {
                cout << "You are a(n) Aries" << endl;
                adj = 20 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Aries: You will be lucky today."  << endl;     
                }
            }
            if (day >= 21)
            {
                cout << "You are a(n) Pisces" << endl;
                adj = 21 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Pisces: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 4:
        {
            if (day <= 19)
            {
                cout << "You are a(n) Aries" << endl;
                adj = 19 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Aries: You will be lucky today."  << endl;     
                }
            }
            if (day >= 20)
            {
                cout << "You are a(n) Taurus" << endl;
                adj = 20 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Taurus: You will be lucky today." << endl;     
                }
            }
            break;
        }
        case 5:
        {
            if (day <= 20)
            {
                cout << "You are a(n) Taurus" << endl;
                adj = 20 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Taurus: You will be lucky today."  << endl;     
                }
            }
            if (day >= 21)
            {
                cout << "You are a(n) Gemini" << endl;
                adj = 21 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Gemini: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 6:
        {
            if (day <= 21)
            {
                cout << "You are a(n) Gemini" << endl;
                adj = 21 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Gemini: You will be lucky today."  << endl;     
                }
            }
            if (day >= 22)
            {
                cout << "You are a(n) Cancer" << endl;
                adj = 22 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Cancer: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 7:
        {
            if (day <= 22)
            {
                cout << "You are a(n) Cancer" << endl;
                adj = 22 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Cancer: You will be lucky today."  << endl;     
                }
            }
            if (day >= 23)
            {
                cout << "You are a(n) Leo" << endl;
                adj = 23 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Leo: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 8:
        {
            if (day <= 22)
            {
                cout << "You are a(n) Leo" << endl;
                adj = 22 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Leo: You will be lucky today."  << endl;     
                }
            }
            if (day >= 23)
            {
                cout << "You are a(n) Virgo" << endl;
                adj = 23 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Virgo: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 9:
        {
            if (day <= 22)
            {
                cout << "You are a(n) Virgo" << endl;
                adj = 22 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Virgo: You will be lucky today."  << endl;     
                }
            }
            if (day >= 23)
            {
                cout << "You are a(n) Libra" << endl;
                adj = 23 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Libra: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 10:
        {
            if (day <= 22)
            {
                cout << "You are a(n) Libra" << endl;
                adj = 22 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Libra: You will be lucky today."  << endl;     
                }
            }
            if (day >= 23)
            {
                cout << "You are a(n) Scorpio" << endl;
                adj = 23 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Scorpio: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 11:
        {
            if (day <= 21)
            {
                cout << "You are a(n) Scorpio" << endl;
                adj = 21 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Scorpio: You will be lucky today."  << endl;     
                }
            }
            if (day >= 22)
            {
                cout << "You are a(n) Sagittarius" << endl;
                adj = 22 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Sagittarius: You will be lucky today."  << endl;     
                }
            }
            break;
        }
        case 12:
        {
            if (day <= 21)
            {
                cout << "You are a(n) Sagittarius" << endl;
                adj = 21 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Sagittarius: You will be lucky today." << endl;     
                }
            }
            if (day >= 22)
            {
                cout << "You are a(n) Capricorn" << endl;
                adj = 22 - day;
                if (adj == 2 || adj == 1)
                {
                    cout << "Your birthday is on a cusp!" << endl;
                    cout << "Capricorn: You will be lucky today."  << endl;     
                }
            }
            break;
        }
    }
}

bool repeat()
{
    string input;  // user input
    
    // Ask user if repeat is wanted
    cout << "Repeat Calculation? ";
    cin  >> input;
    
    while (true)
    {
        // Check if input is valid
        if (input == "yes")
            return true;
        else if (input == "no")
            return false;
        else
        {
            cout << "What was that? yes or no? ";
            cin  >> input;
        } 
    }  
}

int main(int argc, char** argv) 
{
    while (true)
    {
        // gets the user's birth day and 
        // checks if month and day are correct
        getBirthday();
        
        // Get user's sign and horoscope
        getSign();
  
        // Ask user if repeat is wanted and repeat if yes
        if (repeat())
            continue;
        else
            break; 
    }
  
    return 0;
}

