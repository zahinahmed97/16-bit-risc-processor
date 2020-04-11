 #include <bits/stdc++.h>
typedef long long int l;
using namespace std ;

string  opcode(const string & s)
{
    if (s == "add") return "0011";
    else if (s == "lw") return "0000";
    else if (s == "sw") return "0001";
    else if (s == "la") return "0010";
    else if (s == "sub") return "0100";
    else if (s == "and") return "0101";
    else if (s == "or") return "0110";
    else if (s == "not") return "0111";
    else if (s == "sl")  return "1000";
    else if (s == "sr")  return "1001";
    else if (s == "ori") return "1010";
    else if (s == "addi") return "1011";
    else if (s == "beq") return "1100";
    else if (s == "slt") return "1101";

}
string reg(const string & r)
{
    if(r == "$0") return "000";
    else if(r == "$1") return "001";
    else if(r == "$2") return "010";
    else if(r == "$3") return "011";
    else if(r == "$4") return "100";
    else if(r == "$5") return "101";
    else if(r == "$6") return "110";
    else if(r == "$7") return "111";
    else if(r == "$zero") return "000";
    else
        return "null";

}

string binaryGenerator (int &n)
{
    int num = n ;

    int flag = 0;
    if (num < 0)
        flag= 1;

    stack <int> st;
    int reminder;
    int result;
    string s;

    while(num != 0)
    {
        if (num == 1)
        {
            break;
        }
        reminder = num % 2;
        st.push(reminder);
        num = num/2;
        //cout << num << endl;
    }
    st.push(num);



    for (int i = 1; i <= (6 -st.size());i++ )
    {
        if(flag== 0)
        {
             s.push_back('0');
        }
        else
        {
            s.push_back('1');
        }
    }

    while (!st.empty())
    {

        if(st.top()== 0)
        {
             s.push_back('0');
        }
        else
        {
            s.push_back('1');
        }
        st.pop();
    }


   return s;
}

string binaryGenerator2 (int &n , int &f)
{
    int num = n ;

    int flag = f ;
    if (num < 0)
        flag= 1;

    stack <int> st;
    int reminder;
    int result;
    string s;

    while(num != 0)
    {
        if (num == 1)
        {
            break;
        }
        reminder = num % 2;
        st.push(reminder);
        num = num/2;
        //cout << num << endl;
    }
    st.push(num);



    for (int i = 1; i <= (6 -st.size());i++ )
    {

             s.push_back('0');

    }

    while (!st.empty())
    {

        if(st.top()== 0)
        {
             s.push_back('0');
        }
        else
        {
            s.push_back('1');
        }
        st.pop();
    }

    //cout << s << endl;

    int ind = (s.length()-1);

    //cout  << "ind 1   " << ind  << endl;
    if (flag == 1)
    {
        while (s[ind] != '1')
        {
            ind --;
        }

        ind --;

        //cout <<" ind" <<ind  << endl;

        for (int i = ind; i >=0; i-- )
        {
            if (s[i] == '1')
                s[i]= '0';
            else
                s[i]= '1';
        }

    }

    return s;
}



void  R_format(const string  &s, const string &r1, const string &r2, const string &r3 ,const string &shm )
{
        string  o ,sh, rs2 , rs1 ,rt, ra, rb, rc;
        string zero= "$zero";
        if (s== "sub")
        {
            string  a = "sub";
            o = opcode(a);

        }

        else
        {
            string a = s;
            o = opcode(a);
        }


       if ( s == "add" || s == "sub" || s == "and" || s == "or" || s == "not" || s == "slt")
        {   sh = shm;
        }
        else
        {
            if ( shm == "0")
            {
                string s= "000";
                sh = s;
            }
            else if ( shm == "1")
            {
                string s= "001";
                sh = s;
            }
            else if ( shm == "2")
            {
                string s= "010";
                sh = s;
            }
            else if ( shm == "3")
            {
                string s= "011";
                sh = s;
            }
            else if ( shm == "4")
            {
                string s= "100";
                sh = s;
            }
            else if ( shm == "5")
            {
                string s= "101";
                sh = s;
            }
            else if ( shm == "6")
            {
                string s= "110";
                sh = s;
            }
            else if ( shm == "7")
            {
                string s= "111";
                sh = s;
            }
        }
        ra = r1;
        rb= r2;
        rc = r3;

        rt = reg(ra);
        rs1 = reg(rb);
        rs2 = reg(rc);

        cerr << o << rs1  << rs2 << rt<< sh << endl;
        cout << o << rs1  << rs2 << rt<< sh << endl;
}

void i_format1(const string  &s, const string &r1, const string &immi)
{
    string o = opcode(s);
    string r = r1;
    string r2 = "$";
    string rt,rs ;
    string im = immi;
    string sub ;
    int num;

    int i = 0;
    while (immi[i] != '(')
    {
        sub.push_back(immi[i]);
        i++;
    }
    while(immi[i] != '$' )
    {
        i++;
    }

        if(immi[i+1] == '0')  r2.push_back('0');
        else if(immi[i+1] == '1')  r2.push_back('1');
        else if(immi[i+1] == '2')  r2.push_back('2');
        else if(immi[i+1] == '3')  r2.push_back('3');
        else if(immi[i+1] == '4')  r2.push_back('4');
        else if(immi[i+1] == '5')  r2.push_back('5');
        else if(immi[i+1] == '6')  r2.push_back('6');
        else if(immi[i+1] == '7')  r2.push_back('7');

    stringstream iss(sub);
    iss >> num;

    //cerr << r2 <<" "<<"bal"<<immi[i+1] <<endl;
    rs = reg(r2);
    rt = reg(r);
    im = binaryGenerator(num);

        cout << o<< rs << rt << im << endl;
        cerr << o<<rs << rt << im << endl;

}

void i_format2(const string  &s, const string &r1, const string &r2, const string &immi)
{
        string  o , rs1 ,rt, sub, im;
        int flag = 0;
        if (immi[0]== '-')
        {
            sub = immi[1];
            flag = 1;
        }
        else
        sub= immi;

        int num;

        stringstream iss(sub);
        iss >> num;
        im = binaryGenerator2(num, flag );

        if (s == "addi")
        {
            string  a = "addi";
            o = opcode(a);
        }
        else if (s == "ori")
        {
            string  a = "ori";
            o = opcode(a);
        }
         else if (s == "beq")
        {
            string  a = "beq";
            o = opcode(a);
        }

        else if (s == "la")
        {
            string  a = "la";
            o = opcode(a);
        }

        string ra = r1;
        string rb= r2;

        rt = reg(ra);
        rs1 = reg(rb);

        cerr << o << rs1 << rt<< im << endl;
        cout << o << rs1 << rt<< im << endl;
}

/*string hexxavalue (string &h)
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
        i++;
        k++;
        l++;
        m++;
    }

    s= hexxavalue(s2)+hexxavalue(s3)+hexxavalue(s4)+hexxavalue(s5);

    return s;

} */



int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;
    string r1 , r2 , r3, immidiet;
    string shm = "000";
    while (cin >> s)
    {
        cerr << s << endl;
        if (s == "add" || s == "sub" || s == "and" ||s == "or" ||s == "not" || s == "sr" || s == "sl" || s== "slt")
        {
            cin >> r1 >> r2 >> r3;
            if (s == "sr" || s == "sl")
            {
                cin >>  shm;
            }
            R_format(s, r1 , r2, r3 , shm);
        }

        else if ( s == "lw" || s == "sw" )
        {
            cin >> r1 >>immidiet;
            i_format1(s,r1,immidiet);
        }
        else if (s == "addi"|| s== "beq"|| s == "ori" || s == "la")
        {
            cin>> r1 >> r2 >> immidiet;
            i_format2(s, r1, r2, immidiet);
        }


    }




    return 0;
}



