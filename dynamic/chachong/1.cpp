//
// Created by Luxi on 2020/6/15.
//
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#include<string.h>
char s[80];
char c[500][500];
int max(int x,int y)
{
    return x>y?x:y;
}
int LCS(string str1,string str2)  //找最长子序列,递归，消耗时间特别多，尤其当公共子序列所占比例很小时
{
    int LCSlength=0;
    //  cout<<"lasuhduia"<<str1.length()<<endl;
    if(str1.length()==0||str2.length()==0)
    {
        return 0;
    }
    else if(str1.length()>0&&str2.length()>0){
        if(str1[str1.length()-1]==str2[str2.length()-1])
        {
            LCSlength+=LCS(str1.substr(0,str1.length()-1),str2.substr(0,str2.length()-1))+1;
            /// cout<<"LCSlength1111"<<LCSlength<<endl;
        }
        else  if(str1[str1.length()-1]!=str2[str2.length()-1])
        {
            LCSlength+=max(LCS(str1.substr(0,str1.length()-1),str2.substr(0,str2.length())),LCS(str1.substr(0,str1.length()),str2.substr(0,str2.length()-1)));
            // cout<<"LCSlength2222"<<LCSlength<<endl;
        }
    }
    return LCSlength;
}

string remove_surplus_spaces(string& src) //去除多余的空格防止对查重进行影响
{
    string result = "";
    for(int i = 0;src[i] != '\0';i++)
    {
        if(src[i] != ' ' )
            result.append(1,src[i]);
        else if(src[i+1] != ' ')
            result.append(1,src[i]);
    }
    return result;
}


int LCSLOOP(char *x,char *y,int m,int n){//非递归方法，比递归快了不少
    int i, j;

    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i<= m; i++) {
        for(j = 1; j <= n; j++) {
            if(x[i-1] == y[j-1]) {                 //当前所在位置的字符相等
                c[i][j] = c[i-1][j-1] + 1;         //直接加1
            } else if(c[i-1][j] >= c[i][j-1]) { //当不相等的时候就等于较大的那一个，类似于递归实现
                c[i][j] = c[i-1][j];
            } else {
                c[i][j] = c[i][j-1];

            }
        }
    }
    return c[m][n];
}


int min(int a,int b)
{
    return (a<b)?a:b;
}

int ldistance(const string source, const string target)
{
    //step 1
    int i,j;
    int n = source.length();
    int m = target.length();
    if (m == 0) return n;
    if (n == 0) return m;
    //Construct a matrix,using vector in C++ LST,利用LST模板库
    typedef vector< vector<int> >  Tmatrix;
    //类似于LCS中矩阵，相对于LCS中的矩阵这个的实现思想很类似
    Tmatrix matrix(n + 1);
    for (i = 0; i <= n; i++)  matrix[i].resize(m + 1);

    //step 2 Initialize

    for (i = 1; i <= n; i++) matrix[i][0] = i;
    for (i = 1; i <= m; i++) matrix[0][i] = i;

    //step 3
    for (i = 1; i <= n; i++)
    {
        const char si = source[i - 1];
        //step 4
        for (j = 1; j <= m; j++)
        {

            const char dj = target[j - 1];
            //step 5
            int cost;
            if (si == dj){
                cost = 0;
            }
            else{
                cost = 1;
            }
            //step 6
            const int above = matrix[i - 1][j] + 1;
            const int left = matrix[i][j - 1] + 1;
            const int diag = matrix[i - 1][j - 1] + cost;
            matrix[i][j] = min(above, min(left, diag));

        }
    }//step7
    return matrix[n][m];//类似与LCS中返回的矩阵的最后一个元素，计算编辑距离
}


int main()
{
    double **num;
    string a[300],b[300];              //采用 string 类型，存100行的文本，不要用数组
    int i=0,j=0;
    ifstream infile,infile1;
    string file1 = "./实验4测试题/A1.c++.txt";
    string file2 = "./实验4测试题/B1.c++.txt";
    infile.open("./实验4测试题/A1.c++.txt",ios::in);

    while(!infile.eof())            // 若未到文件结束一直循环
    {
        string line;
        getline(infile, a[i], '\n');//读取一行，以换行符结束，存入 a[] 中
        a[i] = remove_surplus_spaces(a[i]);
        cout<<a[i]<<endl;
        i++;                    //下一行
    }
    cout<<i<<endl;
    infile1.open("./实验4测试题/B1.c++.txt",ios::in);
    while(!infile1.eof())
    {
        getline(infile1,b[j],'\n');
        b[j] = remove_surplus_spaces(b[j]);
        cout<<b[j]<<endl;
        j++;
    }
    int ii,jj;
    cout<<i<<j<<endl;
    num=new double*[i];
    for(ii=0;ii<i;ii++)
    {
        num[ii]=new double[j];
    }
    for(ii=0;ii<i;ii++)        // 两个文件对应每行的相同字符个数
    {
        for(jj=0;jj<j;jj++)
        {
            int m = a[ii].length();
            int n = b[jj].length();
            char *s = new char[m+1];
            char *s1 = new char[n+1];
            if(min(a[ii].length(),b[jj].length())==0) break;
            ///   cout<<LCSLOOP(a[ii],b[ii],a[ii].length(),b[jj].length())<<endl;
            strcpy(s,a[ii].c_str());
            strcpy(s1,b[jj].c_str());
            //cout<<min(m,n)<<endl;
            int m1=LCSLOOP(s,s1,a[ii].length(),b[jj].length());
            int n1 =min(m,n);
            num[ii][jj]=(double)m1/n1;
            //delete []s;
            //delete []s1;
        }
    }
    cout<<"haha"<<endl;
    for(ii=0;ii<i;ii++)
    {
        for(jj=0;jj<j;jj++)
        {
            if(num[ii][jj]<0.88) num[ii][jj]=0; //如果超过阈值0.88就设置为相同即为1
            else num[ii][jj]=1;
            printf("%lf ",num[ii][jj]);
        }
        cout<<endl;
    }
    cout<<i<<endl;
    char *line = new char[i+1];
    char *line1 = new char[j+1];
    for(ii=0;ii<i;ii++)
        line[ii]='N';
    for(jj=0;jj<j;jj++)
        line1[jj]='N';
    // cout<<line1<<endl;
    for(ii=0;ii<i;ii++)//如果两个文件的ii行和jj行重复就将对应行数设置为Y，用以找重复了多少行，来找是否是重复的。
    {
        for(jj=0;jj<j;jj++)
        {

            if(line[ii]=='N'||line1[jj]=='N')
            {
                if(num[ii][jj]==1&&a[ii].length()>3&&b[jj].length()>3)
                {
                    line[ii]='Y';
                    line1[jj]='Y';
                }
            }
        }
    }
    cout<<line<<endl;
    cout<<line1<<endl;
    cout<<"hehe"<<endl;
    line[i]='\n';
    line1[j]='\n';
    int length=0;
    for(ii=0;ii<i;ii++)
    {
        if(line[ii]=='Y')
        {
            length++;
        }
    }
    double rate = length/(j*1.0);
    cout<<"未经过优化的查重算法得出的"<<file1<<"对"<<file2<<"的重复率为"<<rate<<endl;
    length=0;
    for(ii=0;ii<j;ii++)
    {
        if(line1[ii]=='Y')
        {
            length++;
        }
    }
    rate = length/(i*1.0);
    cout<<"未经过优化的查重算法得出的"<<file2<<"对"<<file1<<"的重复率为"<<rate<<endl;
    //cout<<min(i,j)<<endl;
    infile.close();
    infile1.close();
    delete []line1;
    delete []line;
    char *line2 = new char[i+1];
    char *line3 = new char[j+1];
    for(ii=0;ii<i;ii++)
        line2[ii]='N';
    for(jj=0;jj<j;jj++)
        line3[jj]='N';
    //进行优化利用字符串编辑距离（Levenshtein距离）算法
    for(ii=0;ii<i;ii++)        // 两个文件对应每行的相同字符个数
    {
        for(jj=0;jj<j;jj++)
        {
            int len = ldistance(a[ii],b[jj]);
            int maxlen = (a[ii].length()>b[jj].length())?a[ii].length():b[jj].length();
            double lowrate = len/(maxlen*1.0);
            if(lowrate<0.30)
            {
                line2[ii]='Y';
                line3[jj]='Y';
            }
        }
    }
    length=0;
    for(ii=0;ii<i;ii++)
    {
        if(line2[ii]=='Y')
        {
            length++;
        }
    }
    rate = length/(j*1.0);
    cout<<"经过优化（编辑距离）的查重算法得出的"<<file1<<"对"<<file2<<"的重复率为"<<rate<<endl;
    length=0;
    for(ii=0;ii<j;ii++)
    {
        if(line3[ii]=='Y')
        {
            length++;
        }
    }
    rate = length/(i*1.0);
    cout<<"经过优化(编辑距离)的查重算法得出的"<<file2<<"对"<<file1<<"的重复率为"<<rate<<endl;
    //cout<<min(i,j)<<endl;
    return 0;
}

