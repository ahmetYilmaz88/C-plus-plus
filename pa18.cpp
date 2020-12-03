/// @file pa18.cpp
/// @author Ahmet Yilmaz <ahmet.yilmaz@student.csn.edu>
/// @date 2020-08-02
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief This is the interface for the Stacks and Queues.
/// @note Stacks and Queues
/// DO NOT ALTER THIS INTERFACE

#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

string nested(string str)
{
    int pos=0; // variable to store the position
    stack<char> st;// stack ch st
    int i;
     
    char topChar;
    for ( i=0; i < str.length(); i++,pos++)
    {
        if (str[i]=='('||str[i]=='['||str[i]=='{'||str[i]=='<')
        {
            //current char ith char is '(' and the next coming char is '*'
            if(str[i]=='('&& str[i+1]=='*')
            {
                //push both characters ith and (i+1)th character
                st.push(str[i]);
                st.push(str[i+1]);
                //increment i
                i++;
                //decrement the pos 1 time so it can count (* once
                pos--;
            }
            else
            {
                //otherwise
                //push it one time
                st.push(str[i]);
                //continue the loop
                continue;
            }
        }
        if (st.empty())
        {
                return "NO "+to_string(pos);
                break;
        }
            
        //if str[i] is ')'
        if(str[i]==')')
        {
            //if previous character is *
            if(str[i-1]=='*')
            {
                // extract the top character and store it in topChar
                char topChar = st.top();

                //pop two times so that both * and ) come out from the stack
                st.pop();
                st.pop();
                //decrement position
                pos--;
                //check for other symbols
                if (topChar=='{' || topChar=='[' || topChar=='<')
                {
                    //if other start symbol is there then return No with position.
                    return "NO "+to_string(pos);
                }
                //otherwise continue the loop
                continue;
            }
        else //if *) is not there
        {
            // extract the top character and store it in topChar
            topChar = st.top();
            //pop once
            st.pop();
            if (topChar=='{' || topChar=='[' || topChar=='<')
            {
                //if other start symbol then return NO with position
                return "NO "+to_string(pos);
            }
            //continue the loop
            continue;
        }
        }
        //similar process for the other symbols
        //so ill skip the documentation part
        if(str[i]=='}')
        {
            topChar = st.top();
            st.pop();
            if (topChar=='(' || topChar=='[' || topChar=='<' )
            {
                return "NO "+to_string(pos);
            }
            continue;
        }
        if(str[i]==']')
        {
            topChar = st.top();
            st.pop();
            if (topChar=='(' || topChar=='{' || topChar=='<')
            {
                return "NO "+to_string(pos);
            }
            continue;
        }
        
        if(str[i]=='>')
        {
            topChar = st.top();
            st.pop();
            if (topChar=='(' || topChar=='{' || topChar=='<')
            {
                return "NO "+to_string(pos);
            }
            continue;
        }
    }
    if(st.empty())
    {
        return "YES";
    }
    
    return "NO "+to_string(pos);
    
}

// main function demonstrates/ tests the above code
int main()
{
    string str=" ";//variable to store input
    cout<<"Enter a string"<<endl;
    cin>>str;//get input
    cout<<"String " << str << " " << nested(str)<<endl;//display output
    return 0;
}
 
