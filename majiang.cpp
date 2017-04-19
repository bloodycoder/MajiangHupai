#include <iostream>
#include <stdlib.h>
using namespace std;
class Card{
public:
    int value;//1 to 9
    Card(int num1){
        value = num1;
        /*
         1 2 3 4 5 6 7 8 9 
        101112131415161718            18
        192021222324252627 ~            27
         * */
        }
    void cardPrint(){
        cout<<"("<<value<<")"<<" ";
        }
    //
    };
int comp(const void*a,const void *b){
    Card *p1 = (Card *)a;
    Card *p2 = (Card *)b;
    if(p1->value > p2->value){
        return -1;
        }
    else if(p1->value < p2->value){
        return 1;
        }
    else{
        return 0;
        }
    }
class Hand{
public:
    Card *hand[14];
    bool Qing;
    Hand(int *card){
        for(int i=0;i<14;i++){
            hand[i] = new Card(card[i]);
            }
        return;
        }
    int handPrint(){
        for(int i=0;i<14;i++){
            hand[i]->cardPrint();
            }
        cout<<endl;
        }
    void handSort(){
        int tmp;
        for(int j=12;j>=0;j--){
            for(int i=0;i<=j;i++){
                if(hand[i]->value>hand[i+1]->value){
                    tmp = hand[i]->value;
                    hand[i]->value = hand[i+1]->value;
                    hand[i+1]->value = tmp;
                    }
                }
            }
        //this->handPrint();
        }
    bool judgeHu(int n,int*array,int *paicnt){
        if(n>=28){
            if((array[3]+array[5]==4)&&array[2]==1&&array[3]!=4){
                cout<<"Ping Hu"<<endl;
                }
            else if(array[3]==4){
                if(this->Qing==1){
                    cout<<"Qing Da dui zi"<<endl;
                    }
                else{
                    cout<<"Da dui zi"<<endl;
                    }
                }
            else if(array[2]==7){
                if(this->Qing==1){
                    cout<<"Qing Qi dui"<<endl;
                    }
                else{
                    cout<<"Qi Dui"<<endl;
                    }
                }
            else if(array[2]==5 && array[4]==1){
                if(this->Qing==1){
                    cout<<"Qing Long Bei"<<endl;
                    }
                else{
                    cout<<"Long Qi Dui"<<endl;
                    }
                }
            else if(this->Qing==1){
                cout<<"Qing Yi Se"<<endl;
                }
            else{
                return 0;
                }
            for(int i=1;i<=5;i++){
                cout<<array[i]<<" ";
                }
            cout<<endl;
            return 1;
            }
        if(paicnt[n]==0){
            judgeHu(n+1,array,paicnt);
            }
        else{
            if(paicnt[n+1]>0 && paicnt[n+2]>0){
                paicnt[n+1]-=1;paicnt[n+2]-=1;paicnt[n]-=1;array[5]+=1;
                judgeHu(n,array,paicnt);
                paicnt[n+1]+=1;paicnt[n+2]+=1;paicnt[n]+=1;array[5]-=1;
                }
            if(paicnt[n]==4){
                paicnt[n]-=4;array[4]+=1;
                judgeHu(n+1,array,paicnt);
                paicnt[n]+=4;array[4]-=1;
                }
            if(paicnt[n]>=3){
                paicnt[n]-=3;array[3]+=1;
                judgeHu(n,array,paicnt);
                paicnt[n]+=3;array[3]-=1;
                }
            if(paicnt[n]>=2){
                paicnt[n]-=2;array[2]+=1;
                judgeHu(n,array,paicnt);
                paicnt[n]+=2;array[2]-=1;
                }
            if(paicnt[n]==1){
                paicnt[n]-=1;array[1]+=1;
                judgeHu(n+1,array,paicnt);
                paicnt[n]+=1;array[1]-=1;
                }
            }
    }
    bool judgeQing(){
        int list[3]={1,10,19},posi;
        bool flag = 1;
        if(hand[0]->value<10){
            posi=0;
            }
        else if(hand[0]->value<19){
            posi=1;
            }
        else{
            posi=2;
            }
        for(int i=0;i<14;i++){
            if((hand[i]->value<list[posi])||(hand[i]->value>list[posi]+8)){
                flag = 0;
                }
            }
        return flag;
        }
    int findHu(){
        //
        this->Qing = judgeQing();
        cout<<"qing is "<<this->Qing<<endl;
        int n=1,array[10]={0,0,0,0,0,0},paicnt[35];
        for(int i=1;i<=27;i++){
            paicnt[i]=0;
            }
        for(int i=0;i<14;i++){
            paicnt[hand[i]->value]++;
            }
        for(int i=1;i<=27;i++){
            cout<<paicnt[i]<<" ";
            }
            cout<<endl;
        judgeHu(n,array,paicnt);
        }
    ~Hand(){
        delete[]this->hand;
        }
    };
int main(){
    //int array[14]= {2,6,2,2,6,6,14,14,14,22,22,22,25,25};
    //int array[14]= {2,6,3,4,6,6,14,14,14,22,22,22,25,25};//pinghu
    int array[14]= {2,2,2,6,6,6,14,14,14,22,22,22,25,25};//大对子
    //int array[14]= {3,3,5,8,8,13,13,16,16,20,20,23,23,5};//7对
    //int array[14]= {1,1,4,4,8,8,12,12,14,14,24,24,24,24};//龙7对
    //int array[14]= {1,1,1,2,3,4,5,6,7,8,9,9,9,2};//清一色
    //int array[14]= {10,10,12,12,12,14,14,14,16,16,16,18,18,18};//清大对
    //int array[14]= {19,19,20,20,21,21,22,22,23,24,24,25,25,23};//清7对
    //int array[14]= {2,2,3,3,5,5,5,6,6,7,7,8,8,5};//清龙背
    //int array[14]= {1,1,1,1,2,2,2,2,3,3,3,3,4,4};//清龙背
    //int array[14]= {2,6,3,4,6,6,7,7,7,5,3,2,1,2};
    Hand *h = new Hand(array);
    h->handPrint();
    h->handSort();
    h->handPrint();
    //cout<<h->judgeThree(0)<<h->judgeLian(1)<<h->judgeLian(2)<<h->judgeLian(0);
    h->findHu();
    //delete h;
    }
    /*
     * 首先想的是，不用递归，直接排序，然后数4和3的个数。
     * 后来发现有时候4可能会拆成3和1来用。然后用了递归。
     * 递归版本1，是优先考虑把牌当成3张，而不是拆成连子。
     * 递归版本2.把连子 和3张同时考虑，只要没有环，就没有问题。
     * */