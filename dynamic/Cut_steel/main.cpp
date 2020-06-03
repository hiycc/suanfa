#include <iostream>
#include <algorithm>
using namespace std;
int award[11]={0,1,5,8,10,13,17,18,22,25,30};
int value[11]={0,1,5,8,9,10,17,17,20,24,30};

int CUT_ROD(int *p,int n);//自顶向下递归实现
int MEMOIZED_CUT_ROD(int *p,int n);//带备忘录的自顶向下
int MEMOIZED_CUT_ROD_AUX(int *p,int n,int *r);
int BOTTOM_UP_CUT_ROD(int *p,int n);//自底向上

int max_award(int length);

int main() {

    int length = 0;
    int total_award = 0;
    cin>>length;
    while(length!=-1){
        total_award = max_award(length);
        cout<<total_award<<endl;
        total_award = CUT_ROD(value,length);
        cout<<total_award<<endl;
        total_award = MEMOIZED_CUT_ROD(value,length);
        cout<<total_award<<endl;
        total_award = BOTTOM_UP_CUT_ROD(value,length);
        cout<<total_award<<endl;
        cin>>length;
    }
//    int *r;
//    r = new int[1];
//    r[0] = -1;
//    cout<<r[0];
    return 0;
}

//自己通过求出子问题最优解，再求原问题的解
int max_award(int length)
{
    int total_award = 0;
    while(length>0){
        for(int i=10;i>0;i--){
            if(length>=i){
                length-=i;
                total_award+=award[i];
                break;
            }
        }
    }
    return total_award;
}

//自顶向下递归实现
int CUT_ROD(int *p,int n)   //p为价格数组,n为钢条长度
{
    if(n==0)
        return 0;
    int q = -1;
    for(int i=1;i<=n;i++){
        q = max(q,p[i]+CUT_ROD(p,n-i));
    }
    return q;
}

//带备忘录的自顶向下
int MEMOIZED_CUT_ROD(int *p,int n)     //p为价格数组,n为钢条长度
{
    int *r;
    r = new int[n+1];
    for(int i=0;i<=n;i++){
        r[i] = -999;
    }
    return MEMOIZED_CUT_ROD_AUX(p,n,r);
}
int MEMOIZED_CUT_ROD_AUX(int *p,int n,int *r)
{
    int q = 0;
    if(r[n]>=0)
        return r[n];
    if(n==0)
        q = 0;
    else{
        q = -999;
        for(int i=1;i<=n;i++){
            q = max(q,p[i]+MEMOIZED_CUT_ROD_AUX(p,n-i,r));
        }
    }
    r[n] = q;
    return q;
}

//自底向上
int BOTTOM_UP_CUT_ROD(int *p,int n)
{
    int *r;
    int q;
    r = new int [n+1];
    r[0] = 0;
    for(int j=1;j<=n;j++){
        q = -999;
        for(int i=1;i<=j;i++){
            q = max(q,p[i]+r[j-i]);
        }
        r[j] = q;
    }
    return r[n];
}
