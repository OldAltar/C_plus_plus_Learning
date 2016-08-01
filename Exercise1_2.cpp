#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int i;
    int a,b,c,d,e,f;
/*
    first way to print binary number of 0-63
*/
    for(i=0;i<64;i++)
    {
        cout<< bitset<6>(i) <<endl;
    }

    cout<<endl;
/*
    another way to print binary number of 0-63
*/
    for(a=0;a<=1;a++)
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
                for(d=0;d<=1;d++)
                    for(e=0;e<=1;e++)
                        for(f=0;f<=1;f++)
                            cout<<a<<b<<c<<d<<e<<f<<endl;

    return 0;
}
