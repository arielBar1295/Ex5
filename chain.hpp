////
//// Created by ariel on 06/05/2019.
////
//
#ifndef UNTITLED_RANGE_HPP
#define UNTITLED_RANGE_HPP

#endif //UNTITLED_RANGE_HPP

#include <iostream>
//#include "range.hpp"
#include <bits/stdc++.h>
using namespace std;
namespace itertools {

    using namespace std;

    // 2 different typename.
    template<typename T, typename U>
    class chain {
        const T a;
        const U b;
    public:
        //constructor
        chain(const T& a1,const U& b1):a(a1),b(b1){}

        chain(){

        }

        class iterator {
            //variables for the start and begin for each typename.
            decltype(a.begin()) tStart;
            decltype(a.end()) tEnd;
            decltype(b.begin()) uStart;
            decltype(b.end()) uEnd;

        public:
            iterator(const T& a,const U& b) {
                tStart = a.begin();
                tEnd = a.end();
                uStart = b.begin();
                uEnd = b.end();
            }
            //constructor for end function
            iterator(const T &a,const U &b,bool f) {
                tStart = a.end();
                tEnd = a.end();
                uStart = b.end();
                uEnd = b.end();
            }
            iterator(){

            }

            auto operator*()  {
                if(tStart!=tEnd)
                    return *tStart;
                else
                    return *uStart;
            }

            iterator& operator++() {
                if (tEnd != tStart)
                    ++tStart;
                else
                    ++uStart;
                return *this;
            }

            bool operator!=(const iterator &other)  {
                if (tStart != other.tStart) {
                    return true;
                }
                if (uStart != other.uStart) {
                    return true;
                }
                return false;
            }

//            }
        };

        iterator begin() const{
            return iterator(a, b);
        }

        iterator end()const {
            return iterator(a, b, false);
        }
        //return the size of the chain.
        int size (){
            decltype(a.begin()) start1=a.begin();
            decltype(a.end()) end1=a.end();
            decltype(b.begin()) start2=b.begin();
            decltype(b.end()) end2=b.end();
            int s=0;
            int s1=0;
            while(start1!=end1) {
                ++start1;
                s++;
            }
            while(start2!=end2) {
                ++ start2;
                s1++;
            }
            return (s+s1);
        }
    };
//return the class
  //  template<typename T, typename U>chainIt<T,U> chain(T a, U b) {
      //  return chainIt<T,U>(a, b);

  //  }
}
