/**
 * A demo program for bull-pgia.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;



#include <bits/stdc++.h>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
//#include "powerset.hpp"
using namespace itertools;
#include "badkan.hpp"
#define COMMA ,




int main() {

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
//range tests
auto r1=range<int>(4,9);
auto r2=range<int>(4,11);
auto r3=range<double>(5.7,11.7);
auto r4=range<double> (2.3,6.3);
auto r5=range<char>('a','f');
auto r6=range<char>('l','z');
auto r7=range<int>(4,4);
//for the begin iterator for each range.
auto Itr1=r1.begin();
auto Itr2=r1.begin();
auto Itr3=r3.begin();
auto Itr4=r4.begin();
auto Itr5=r5.begin();
auto Itr6=r6.begin();
auto Itr7=r7.begin();
//for saving the answers.
string answer="";
string answer1="";
string answer2="";
string answer3="";
string answer4="";
string answer5="";
string answer7="";
for(int i: r1) {
    answer += to_string(i);
}

for(int i: r2) {
    answer1 += to_string(i);
}
for(double i: r3) {
    answer2 += to_string(i);
}
for(double i: r4) {
    answer3 += to_string(i);
}
for(char i: r5) {
    answer4 +=i;
}
for(char i: r6) {
    answer5 +=i;
}
for(int i: r7) {
    answer7 += to_string(i);
}

testcase.setname("range result ")
.CHECK_EQUAL ( answer=="45678", true)
.CHECK_EQUAL ( answer1=="45678910", true)
.CHECK_EQUAL ( answer7=="", true)
.CHECK_EQUAL ( answer2=="5.7000006.7000007.7000008.7000009.70000010.700000", true)
.CHECK_EQUAL ( answer3=="2.3000003.3000004.3000005.300000", true)
.CHECK_EQUAL ( answer4=="abcde", true)
.CHECK_EQUAL ( answer5=="lmnopqrstuvwxy", true)
;

//chain test
auto c1= chain(range('a','f'), string("cppEX5"));
auto c2= chain(string("arieluni"),string("vercity"));
auto c3= chain(range('a','f'), range('f','l'));
auto c4= chain(range(12,20), range(30,40));
auto c5= chain(range(4.4,8.4), range(7.3,10.3));
//iterator for each variable.
auto Itc1=c1.begin();
auto Itc2=c2.begin();
auto Itc3=c3.begin();
auto Itc4=c4.begin();
auto Itc5=c5.begin();
//saving the answers
string answerC1="";
string answerC2="";
string answerC3="";
string answerC4="";
string answerC5="";

for(char i : c1){
    answerC1+=i;
}
for(char i : c2){
    answerC2+=i;
}
for(char i : c3){
    answerC3+=i;
}
for(int i : c4){
    answerC4+=to_string(i);
}
for(double i : c5){
    answerC5+=to_string(i);
}

        testcase.setname("chain results  ")
           .CHECK_EQUAL ( answerC1=="abcdecppEX5", true )
           .CHECK_EQUAL ( answerC2=="arielunivercity", true )
           .CHECK_EQUAL ( answerC3=="abcdefghijk", true )
           .CHECK_EQUAL ( answerC4=="121314151617181930313233343536373839", true )
           .CHECK_EQUAL ( answerC5== "4.4000005.4000006.4000007.4000007.3000008.3000009.300000", true )
                ;
//zip test
auto z1=zip(range(1,6), string("hello"));
auto z2=zip(range('a','g'), string("heyyou"));
auto z3=zip(chain(range(1,4), range(4,8)), string("arielba"));
auto z4=zip(range(1,6), range(1,6));
auto z5=zip(range(14,18),string("abcd"));
auto z6=zip(range(10,14), string("abcd"));
auto z7= zip(z6,z5);
auto z8=zip(range(5.1,7.1), range('a','c'));
auto z9=zip(range(1,3), range('c','e'));
auto z10=zip(z8,z9);

auto Itz1=z1.begin();
auto Itz2=z2.begin();
auto Itz3=z3.begin();
auto Itz4=z4.begin();
auto Itz5=z5.begin();
auto Itz6=z6.begin();
auto Itz7=z7.begin();
auto Itz8=z8.begin();
auto Itz9=z9.begin();
auto Itz10=z10.begin();
//for saving and compare the answers.
string answerZ1="";
string answerZ2="";
string answerZ3="";
string answerZ4="";
string answerZ5="";
string answerZ6="";
string answerZ7="";
string answerZ8="";
string answerZ9="";
string answerZ10="";

        for(auto pair  : z1){
            answerZ1=answerZ1+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : z2){
            answerZ2=answerZ2+pair.first+pair.second+" ";
        }
        for(auto pair  : z3){
            answerZ3=answerZ3+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : z4){
            answerZ4=answerZ4+to_string(pair.first)+to_string(pair.second)+" ";
        }
        for(auto pair  : z5){
            answerZ5=answerZ5+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : z6){
            answerZ6=answerZ6+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : z7){
            answerZ7=answerZ7+to_string(pair.first.first)+pair.first.second+to_string(pair.second.first)+pair.second.second+" ";
        }
        for(auto pair  : z8){
            answerZ8=answerZ8+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : z9){
            answerZ9=answerZ9+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : z10){
            answerZ10=answerZ10+to_string(pair.first.first)+pair.first.second+to_string(pair.second.first)+pair.second.second+" ";
        }
        testcase.setname("zip results  ")
                .CHECK_EQUAL ( answerZ1=="1h 2e 3l 4l 5o ", true )
                .CHECK_EQUAL ( answerZ2=="ah be cy dy eo fu ", true )
                .CHECK_EQUAL ( answerZ3=="1a 2r 3i 4e 5l 6b 7a ", true )
                .CHECK_EQUAL ( answerZ4=="11 22 33 44 55 ", true )
                .CHECK_EQUAL ( answerZ6=="10a 11b 12c 13d ", true )
                .CHECK_EQUAL ( answerZ5=="14a 15b 16c 17d ", true )
                .CHECK_EQUAL ( answerZ7==  "10a14a 11b15b 12c16c 13d17d ", true )
                .CHECK_EQUAL ( answerZ8=="5.100000a 6.100000b ", true )
                .CHECK_EQUAL ( answerZ9=="1c 2d ", true )
                .CHECK_EQUAL ( answerZ10=="5.100000a1c 6.100000b2d ", true )
                ;
//product test
auto p1= product(range(1,2), string("hello"));
auto p2= product(range(1,5), string("h"));
auto p3= product(string("abcd"), string("h"));
auto p4= product(string("ab"), range(2.1,4.1));
auto p5= product(chain(range(1,4),range(10,12)),range('a','c'));
auto p6= product(range(5,5), range(2,2));
auto p7= product(range('a','d'), range('d','f'));

auto Itp1=p1.begin();
auto Itp2=p2.begin();
auto Itp3=p3.begin();
auto Itp4=p4.begin();
auto Itp5=p5.begin();
auto Itp6=p6.begin();
auto Itp7=p7.begin();

string answerP1="";
string answerP2="";
string answerP3="";
string answerP4="";
string answerP5="";
string answerP6="";
string answerP7="";
        for(auto pair  : p1){
            answerP1=answerP1+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : p2){
            answerP2=answerP2+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : p3){
            answerP3=answerP3+pair.first+pair.second+" ";
        }
        for(auto pair  : p4){
            answerP4=answerP4+pair.first+to_string(pair.second)+" ";
        }
        for(auto pair  : p5){
            answerP5=answerP5+to_string(pair.first)+pair.second+" ";
        }
        for(auto pair  : p6){
            answerP6=answerP6+to_string(pair.first)+to_string(pair.second)+" ";
        }
        for(auto pair  : p7){
            answerP7=answerP7+pair.first+pair.second+" ";
        }
        testcase.setname("product results  ")
                .CHECK_EQUAL ( answerP1=="1h 1e 1l 1l 1o ", true )
                .CHECK_EQUAL ( answerP2=="1h 2h 3h 4h ", true )
                .CHECK_EQUAL ( answerP3=="ah bh ch dh ", true )
                .CHECK_EQUAL ( answerP4=="a2.100000 a3.100000 b2.100000 b3.100000 ", true )
                .CHECK_EQUAL ( answerP5=="1a 1b 2a 2b 3a 3b 10a 10b 11a 11b ", true )
                .CHECK_EQUAL ( answerP6=="", true )
                .CHECK_EQUAL ( answerP7=="ad ae bd be cd ce ", true )
                ;

//powerset tests.

        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    return 0;
}
