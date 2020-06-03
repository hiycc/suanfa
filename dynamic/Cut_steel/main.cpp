#include <iostream>
using namespace std;
int award[11]={0,1,5,8,10,13,17,18,22,25,30};

int max_award(int length);

int main() {

    int length = 0;
    int total_award = 0;
    cin>>length;
    while(length!=-1){
        total_award = max_award(length);
        cout<<total_award<<endl;
        cin>>length;
    }
    return 0;
}
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
