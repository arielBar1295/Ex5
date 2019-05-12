//
// Created by ariel on 07/05/2019.
//

#ifndef UNTITLED_POWERSET_HPP
#define UNTITLED_POWERSET_HPP

#endif //UNTITLED_POWERSET_HPP

#include <utility>
#include <iostream>
#include <math.h>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;
namespace itertools {

    using namespace std;

    template<typename T>

    class powersetIt {
        T a;
         int sizeA;

    public:
        powersetIt() {

        }

        powersetIt(T &a1) {
            a = a1;
            int sizeType=a.size();
            sizeA=pow(2,sizeType);


        }

        class iterator {
            decltype(a.begin()) tStart;
            decltype(a.end()) tEnd;
            int i;
            int j;
            bool isC;
            unsigned int limit;
            pair < decltype(a.begin()), decltype(a.end())> pair1;

        public:

            iterator(T &a,int c,  int e) {
                tStart = a.begin();
                tEnd = a.end();
                i=c;
                limit=e;
                j= a.size();
                pair1=std::make_pair(a.begin(),a.end());
                isC=false;
            }

            iterator() {

            }


            auto operator*()  {
                string ans="{";

                for(int k=0;k<j;k++){
                    if(i & (1 << k)) {
//                        std::cout << "int is: " << typeid('a').name() << '\n';
//                        const bool isC=std::is_same<decltype( typeid(*tStart).name()),char>::value;
                        //const bool isS=std::is_same<,>::value;
                      //  std::cout <<decltype(ci)>() << '\n';
                      isC=false;
                      if(*tStart>='a' && *tStart<='z')
                          isC=true;
                        if(isC) {

                            ans += *tStart;
                        }
                        else
                        {

                            ans += to_string(*tStart);
                        }
                    }
                    ++tStart;
                }
                ans+="}";
                return ans;
            }


            iterator &operator++() {

                    i++;
                    tStart = pair1.first;

                   return *this;
            }


            bool operator!=(const iterator &other) {
                if(i!=other.i )
                    return true;
                else return false;

            }

        };

        iterator begin() {

          return iterator(a,0,sizeA);
        }

        iterator end() {
            return  iterator(a,sizeA,sizeA);
        }
    };

    template<typename T>powersetIt<T> powerset(T a) {

        return powersetIt<T>(a);
    }




}
