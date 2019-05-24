//
// Created by ariel on 08/05/2019.
//

#ifndef UNTITLED_PRODUCT_HPP
#define UNTITLED_PRODUCT_HPP

#endif //UNTITLED_PRODUCT_HPP

#include <utility>
#include <iostream>
//#include "range.hpp"
#include <bits/stdc++.h>
namespace itertools {

    using namespace std;
    template<typename T, typename U>

    class product {
        const T a;
        const  U b;

    public:
        product() {

        }

        product(const T& a1,const U& b1):a(a1),b(b1){}

        class iterator {
         //variables for the begin and end for each typename.
            decltype(a.begin()) tStart;
            decltype(a.end()) tEnd;
            decltype(b.begin()) uStart;
            decltype(b.end()) uEnd;
            pair < decltype(b.begin()), decltype(b.end())> pair1;
        public:

            iterator(const T &a, const U &b) {

                tStart = a.begin();
                tEnd = a.end();
                uStart = b.begin();
                uEnd = b.end();
                pair1=std::make_pair(b.begin(),b.end());
            }

            iterator(const T &a, const U &b, bool f) {

                tStart = a.end();
                tEnd = a.end();
                uStart = b.end();
                uEnd = b.end();
               pair1=std::make_pair(b.begin(),b.end());
            }
            iterator() {

            }


            auto operator*() const {
                return make_pair(*tStart,*uStart);
            }


            iterator &operator++() {

                    ++uStart;
                    if (!(uStart != pair1.second)) {
                      ++tStart;
                      uStart = pair1.first;
                    }

                 return *this;
               }




            bool operator!=(const iterator &other) {
                if (tStart != other.tStart && uStart != other.uStart)
                    return true;
             else return false;

            }
        };

        iterator begin() const {
            return iterator(a, b);
        }

        iterator end() const {
            return iterator(a, b, false);
        }


    };

//function returns the class.
//    template<typename T, typename U>productIt<T, U> product(T a, U b) {
  //      return productIt<T, U>(a, b);
   // }


}
