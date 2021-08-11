
// TESTED ON HACKERRANK 
// FLASHING TLE ON TESTCASE 10 ONLY

#include<bits/stdc++.h>

using namespace std;

const int N = 2e6;
int top = -1;
pair<char, string> Stack[N];
string s, str;

void Delete(int del, string &str);

void Undone()
{
    pair<char, string> x = Stack[top];
    top--;
    if(x.first == 'a')
    {
        int del = x.second.size();
        int g = str.size() - del;
        string::iterator it = str.end();
        it--;
        str.erase(g,del);
    }
    else
    {
        str = str + x.second;
    }
}

void Delete(int del, string &str)
{
    string s;
    string::iterator it = str.end();
    it--;
    while(del--)
    {
        s = s+(*it);
        str.erase(it);
        it--;
    }
    string d;
    int i = s.size()-1;
    while(i)
    {
        d = d+s[i];
        i--;
    }
    d = d + s[0];
    top++;
    Stack[top] = make_pair('d', d);
}

int main()
{
    int queries, del;
    cin >> queries;
    int ch;
    while(queries--)
    {
        cin >> ch;
        switch(ch)
        {
            case 1: cin >> s;
                    str = str + s;
                    top++;
                    Stack[top] = make_pair('a', s);
                    //cout << str << " ->a " << endl;
                    break;
            case 2: cin >> del;
                    Delete(del, str);
                    //cout << str << " ->d " << endl;
                    break;
            case 3: cin >> del;
                    cout << str[del-1] << endl;
                    break;
            case 4: Undone();
                    //cout << str << endl;
                    break;
            default: cout << "Not Applicable\n";
                    break;
        }
    }
    return 0;
}