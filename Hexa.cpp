 #include <bits/stdc++.h>
typedef long long int l;
using namespace std ;


string hexxavalue (string &h)
{
    if (h == "0000") return "0";
    if (h == "0001") return "1";
    if (h == "0010") return "2";
    if (h == "0011") return "3";
    if (h == "0100") return "4";
    if (h == "0101") return "5";
    if (h == "0110") return "6";
    if (h == "0111") return "7";
    if (h == "1000") return "8";
    if (h == "1001") return "9";
    if (h == "1010") return "A";
    if (h == "1011") return "B";
    if (h == "1100") return "C";
    if (h == "1101") return "D";
    if (h == "1110") return "E";
    if (h == "1111") return "F";

}
string hexa (string &s1)
{

    //cerr <<"program in " << endl;

    string s2 , s3, s4,s5,s;
    int j = 0;
    int k = 4;
    int l = 8;
    int m = 12;

    for (int i =0; i < 4; i++)
    {
        s2.push_back(s1[j]);
        s3.push_back(s1[k]);
        s4.push_back(s1[l]);
        s5.push_back(s1[m]);
        j++;
        k++;
        l++;
        m++;
        //cerr <<"program in 2 " << endl;


    }

    s= hexxavalue(s2)+hexxavalue(s3)+hexxavalue(s4)+hexxavalue(s5);

    //cerr << s << endl;

    return s;

}

int main()
{
    freopen("output.txt","r",stdin);
    freopen("hexa.txt","w",stdout);

    string s;
    //cin >> s;
    while (getline(cin , s))
    {
        //cerr << s <<endl;
        cout << hexa(s)<<endl;
        cerr << hexa(s) << endl;
    }
}
