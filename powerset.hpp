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
#include <utility> 
#include <bits/stdc++.h>
using namespace std;
namespace itertools {

    using namespace std;

    template<typename T>

    class powerset {
         const T a;
        const  int sizeA;

    public:
        powerset() {

        }

        powerset(const T& a1):a(a1),sizeA(pow(2,a.size())){}







        class iterator {
            decltype(a.begin()) tStart;
            decltype(a.end()) tEnd;
            int i;  //for the number of set
            int j;  //for the size of the typename.
            bool isC;
            pair < decltype(a.begin()), decltype(a.end())> pair1;

        public:
         //constructor
            iterator(const T& a,int c,  int e) {
                tStart = a.begin();
                tEnd = a.end();
                i=c;
                j= a.size();
                pair1=std::make_pair(tStart,tEnd);
                isC=false;
            }

            iterator() {

            }


            auto operator*()  {
                string ans="{";
                 bool isIn=false;
                  bool isP=false;
                   string h=typeid(*tStart).name() ;
                for(int k=0;k<j;k++){
                    if(i & (1 << k)) {

                      isC=false;
//                         if(h=="St4pairIiiE"){ 
//                            bool isC2=false;
//                              if(*tStart.first>='a' && *tStart.first<='z') {
//                                    isC = true;

//                       }
//                         if(isC) {
//                             isIn=true;
//                             ans += *tStart.first;
//                         }
//                         else
//                         {
//                             isIn=true;
//                             ans += to_string(*tStart.first);
//                         }
//                            if(*tStart.second>='a' && *tStart.second<='z') {
//                                    isC2 = true;

//                       }
//                         if(isC2) {
//                             isIn=true;
//                             ans += *tStart.second;
//                         }
//                         else
//                         {
//                             isIn=true;
//                             ans += to_string(*tStart.second);
//                         }  
//                        ans+=",";
//                         }
//                        else{
                      if(*tStart>='a' && *tStart<='z') {
                          isC = true;

                      }
                        if(isC) {
                            isIn=true;
                            ans += *tStart;
                        }
                        else
                        {
                            isIn=true;
                            ans += to_string(*tStart);
                        }
                       ans+=",";
                       }
                    //}

                    ++tStart;
                }
                if(isIn) {
                    string ans1 = ans.substr(0, ans.size()-1);
                     ans=ans1;

                }
                ans+="}";
                return ans;
            }


            iterator operator++() {

                    i++;
                    tStart = pair1.first;

             return *this;
            }


            bool operator!=(const iterator other) {
                if(i!=other.i )
                    return true;
                else return false;

            }

        };

        iterator begin() const {

          return iterator(a,0,sizeA);
        }

        iterator end() const {
            return  iterator(a,sizeA,sizeA);
        }
    };

   // template<typename T>powersetIt<T> powerset(T a) {

     //   return powersetIt<T>(a);
  //  }




}
