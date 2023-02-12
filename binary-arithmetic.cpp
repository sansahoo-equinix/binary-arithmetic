#include <bits/stdc++.h>
using namespace std;
#define LENGTH  32
vector<int> decimal_to_binary(int);
vector<int> add(vector<int>,vector<int>);

vector<int> input_key(){
    int num1,num2;
    cout<<"enter two numbers:"<<endl;
    cin>>num1>>num2;
    vector<int> num;
    num.push_back(num1);
    num.push_back(num2);
    return num;
}
vector<int> complement_2s(vector<int> bin){
  for(int i=LENGTH-1; i>=0; i--){
      bin[i]=1-bin[i];
  }
   bin = add(bin, decimal_to_binary(1));
   return bin;
}
int binary_to_decimal(vector<int>num)
{
    int ans=0;
    for(int i=0;i<LENGTH;i++)
    {
           ans+=num[i]*pow(2,LENGTH-1);
    }
    return ans;
}
vector<int> decimal_to_binary(int num){
    bool is_negative = false;
    if(num < 0){
        is_negative = true;
        num = num * (-1);
    }

    vector<int> bin(LENGTH, 0);
    for(int i = LENGTH - 1; i>=0; i--){
        bin[i] = num%2;
        num = num/2;
    }

    if(is_negative){
        bin = complement_2s(bin);
    }
    return bin;
}

vector<int> add(vector<int> bin1,vector<int> bin2){
    vector<int> ans(LENGTH, 0);
    int carry = 0, i = LENGTH - 1;

    while(i >= 0){
        int sum = bin1[i];
        sum += bin2[i];
        sum += carry;
        
        ans[i] = sum % 2;
        carry = sum / 2;
        i--;
    }
    return ans;
}

void sub(int a,int b)
{

}

//null
void mul(int a, int b)
{

}
void pow(int a,int b)
{

}
void modulo(int a,int b)
{

}
void factorial(int a)
{

}
// basic layout of code 
int main()
{
    vector<int> a = decimal_to_binary(3);
    vector<int> b = decimal_to_binary(4);

    vector<int> ans = add(a, b);
    for(int i = 0; i<LENGTH; i++){
        cout<<ans[i]<<" ";
    }
    return 0 ;
}
