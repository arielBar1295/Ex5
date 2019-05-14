///**
// * A demo program for bull-pgia.
// *
// * @author Erel Segal-Halevi
// * @since  2019-04
// */
//

#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace itertools;
#include "badkan.hpp"
#define COMMA ,

 //returns a string
template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
    ostringstream ostr;
    for (decltype(*iterable.begin()) i: iterable)
        ostr << i << ",";
     string s=ostr.str();
     s=s.substr(0,s.size()-1);
     return s;
}

int main() {

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
////range tests
auto r1=range<int>(4,9);
auto r2=range<int>(4,11);
auto r3=range<double>(5.7,11.7);
auto r4=range<double> (2.3,6.3);
auto r5=range<char>('a','f');
auto r6=range<char>('l','z');
auto r7=range<int>(4,4);   //a range between a number to itself should return an empty range.

string answer=iterable_to_string(r1);
string answer1=iterable_to_string(r2);
string answer2=iterable_to_string(r3);
string answer3=iterable_to_string(r4);
string answer4=iterable_to_string(r5);
string answer5=iterable_to_string(r6);
string answer7=iterable_to_string(r7);

testcase.setname("range result ")
.CHECK_EQUAL ( answer=="4,5,6,7,8", true)
.CHECK_EQUAL ( answer1=="4,5,6,7,8,9,10", true)
.CHECK_EQUAL ( answer7=="", true)
.CHECK_EQUAL ( answer2=="5.7,6.7,7.7,8.7,9.7,10.7", true)
.CHECK_EQUAL ( answer3=="2.3,3.3,4.3,5.3", true)
.CHECK_EQUAL ( answer4=="a,b,c,d,e", true)
.CHECK_EQUAL ( answer5=="l,m,n,o,p,q,r,s,t,u,v,w,x,y", true)
;
//
////chain test
auto c1= chain(range('a','f'), string("cppEX5"));
auto c2= chain(string("arieluni"),string("vercity"));
auto c3= chain(range('a','f'), range('f','l'));
auto c4= chain(range(12,20), range(30,40));
auto c5= chain(range(4.4,8.4), range(7.3,10.3));
string answerC1=iterable_to_string((c1));
string answerC2=iterable_to_string((c2));
string answerC3=iterable_to_string((c3));
string answerC4=iterable_to_string((c4));
string answerC5=iterable_to_string((c5));

        testcase.setname("chain results  ")
           .CHECK_EQUAL ( answerC1=="a,b,c,d,e,c,p,p,E,X,5", true )
           .CHECK_EQUAL ( answerC2=="a,r,i,e,l,u,n,i,v,e,r,c,i,t,y", true )
           .CHECK_EQUAL ( answerC3=="a,b,c,d,e,f,g,h,i,j,k", true )
           .CHECK_EQUAL ( answerC4=="12,13,14,15,16,17,18,19,30,31,32,33,34,35,36,37,38,39", true )
           .CHECK_EQUAL ( answerC5== "4.4,5.4,6.4,7.4,7.3,8.3,9.3", true )
                ;
////zip test
auto z1=zip(range(1,6), string("hello"));
auto z2=zip(range('a','g'), string("heyyou"));
auto z3=zip(chain(range(1,4), range(4,8)), string("arielba")); //zip which accepts chain.
auto z4=zip(range(1,6), range(1,6));
auto z5=zip(range(14,18),string("abcd"));
auto z6=zip(range(10,14), string("abcd"));
auto z7= zip(z6,z5);  //zip which accepts 2 zips.
auto z8=zip(range(5.1,7.1), range('a','c'));
auto z9=zip(range(1,3), range('c','e'));
auto z10=zip(z8,z9);
string answerZ1=iterable_to_string(z1);
string answerZ2=iterable_to_string(z2);
string answerZ3=iterable_to_string(z3);
string answerZ4=iterable_to_string(z4);
string answerZ5=iterable_to_string(z5);
string answerZ6=iterable_to_string(z6);
string answerZ7=iterable_to_string(z7);
string answerZ8=iterable_to_string(z8);
string answerZ9=iterable_to_string(z9);
string answerZ10=iterable_to_string(z10);

        testcase.setname("zip results  ")
                .CHECK_EQUAL ( answerZ1=="1,h ,2,e ,3,l ,4,l ,5,o ", true )
                .CHECK_EQUAL ( answerZ2=="a,h ,b,e ,c,y ,d,y ,e,o ,f,u ", true )
                .CHECK_EQUAL ( answerZ3=="1,a ,2,r ,3,i ,4,e ,5,l ,6,b ,7,a ", true )
                .CHECK_EQUAL ( answerZ4=="1,1 ,2,2 ,3,3 ,4,4 ,5,5 ", true )
                .CHECK_EQUAL ( answerZ5=="14,a ,15,b ,16,c ,17,d ", true )
                .CHECK_EQUAL ( answerZ6=="10,a ,11,b ,12,c ,13,d ", true )
                .CHECK_EQUAL ( answerZ7==  "10,a ,14,a  ,11,b ,15,b  ,12,c ,16,c  ,13,d ,17,d  ", true )
                .CHECK_EQUAL ( answerZ8=="5.1,a ,6.1,b ", true )
                .CHECK_EQUAL ( answerZ9=="1,c ,2,d ", true )
                .CHECK_EQUAL ( answerZ10=="5.1,a ,1,c  ,6.1,b ,2,d  ", true )
                ;
////product test
auto p1= product(range(1,2), string("hello"));
auto p2= product(range(1,5), string("h"));
auto p3= product(string("abcd"), string("h"));
auto p4= product(string("ab"), range(2.1,4.1));
auto p5= product(chain(range(1,4),range(10,12)),range('a','c')); //product with chain and range
auto p6= product(range(5,5), range(2,2));
auto p7= product(range('a','d'), range('d','f'));
string answerP1=iterable_to_string(p1);
string answerP2=iterable_to_string(p2);
string answerP3=iterable_to_string(p3);
string answerP4=iterable_to_string(p4);
string answerP5=iterable_to_string(p5);
string answerP6=iterable_to_string(p6);
string answerP7=iterable_to_string(p7);
   testcase.setname("product results  ")
                .CHECK_EQUAL ( answerP1=="1,h ,1,e ,1,l ,1,l ,1,o ", true )
                .CHECK_EQUAL ( answerP2=="1,h ,2,h ,3,h ,4,h ", true )
               .CHECK_EQUAL ( answerP3=="a,h ,b,h ,c,h ,d,h ", true )
                .CHECK_EQUAL ( answerP4=="a,2.1 ,a,3.1 ,b,2.1 ,b,3.1 ", true )
                .CHECK_EQUAL ( answerP5=="1,a ,1,b ,2,a ,2,b ,3,a ,3,b ,10,a ,10,b ,11,a ,11,b ", true )
                .CHECK_EQUAL ( answerP6=="", true )
                .CHECK_EQUAL ( answerP7=="a,d ,a,e ,b,d ,b,e ,c,d ,c,e ", true )
               ;

////powerset tests.
auto ps= powerset(string("he"));
auto ps1= powerset(range(2.2,5.2));
auto ps2= powerset(range('e','i'));
auto ps3= powerset(range(10,14));
auto ps4= powerset(chain(range(1,3),range(5,7)));  //powerset that accepts chain with 2 ranges of int.
auto ps5= powerset(string("ariel"));
string answerPs=iterable_to_string(ps);
string answerPs1=iterable_to_string(ps1);
string answerPs2=iterable_to_string(ps2);
string answerPs3=iterable_to_string(ps3);
string answerPs4=iterable_to_string(ps4);
string answerPs5=iterable_to_string(ps5);

        testcase.setname("powerset results  ")
              .CHECK_EQUAL ( answerPs=="{},{h},{e},{h,e}", true )
               .CHECK_EQUAL ( answerPs1=="{},{2.200000},{3.200000},{2.200000,3.200000},{4.200000},{2.200000,4.200000},{3.200000,4.200000},{2.200000,3.200000,4.200000}", true )
               .CHECK_EQUAL ( answerPs2=="{},{e},{f},{e,f},{g},{e,g},{f,g},{e,f,g},{h},{e,h},{f,h},{e,f,h},{g,h},{e,g,h},{f,g,h},{e,f,g,h}", true )
               .CHECK_EQUAL ( answerPs3=="{},{10},{11},{10,11},{12},{10,12},{11,12},{10,11,12},{13},{10,13},{11,13},{10,11,13},{12,13},{10,12,13},{11,12,13},{10,11,12,13}", true )
                .CHECK_EQUAL ( answerPs4=="{},{1},{2},{1,2},{5},{1,5},{2,5},{1,2,5},{6},{1,6},{2,6},{1,2,6},{5,6},{1,5,6},{2,5,6},{1,2,5,6}", true )
               .CHECK_EQUAL ( answerPs5=="{},{a},{r},{a,r},{i},{a,i},{r,i},{a,r,i},{e},{a,e},{r,e},{a,r,e},{i,e},{a,i,e},{r,i,e},{a,r,i,e},{l},{a,l},{r,l},{a,r,l},{i,l},{a,i,l},{r,i,l},{a,r,i,l},{e,l},{a,e,l},{r,e,l},{a,r,e,l},{i,e,l},{a,i,e,l},{r,i,e,l},{a,r,i,e,l}", true )
                ;

        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    return 0;
}


