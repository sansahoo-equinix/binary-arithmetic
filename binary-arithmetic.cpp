#include <bits/stdc++.h>
using namespace std;
#define LENGTH  32
vector<int> decimal_to_binary(int);
vector<int> add(vector<int>,vector<int>);

vector<int> input_key(){
    int num1,num2;
    cout<<"enter two numbers:"<<endl;
    cin>>num1;
    cin>>num2;
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
int binary_to_decimal(vector<int>num){
    int ans=0;
    for(int i=0;i<LENGTH;i++){
           ans+=num[i]*pow(2, LENGTH - 1 - i);
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

vector<int> sub(vector<int> bin1,vector<int> bin2)
{
      
      bin2=complement_2s(bin2);
      vector<int> ans=add(bin1,bin2);
      return ans;

}

//null
vector<int> mul(vector<int> bin1, vector<int> bin2 ){    
    vector<int> res(LENGTH, 0);
    for(int i=LENGTH-1;i>=0;i--){
        vector<int> temp(LENGTH,0);
        int k = i;
        for(int j=LENGTH-1;j>=0;j--){
            if(k >= 0){
              temp[k]=(bin2[i] & bin1[j]);
              k--;
            }
        } 
        res = add(res, temp);
    }
    
    return res;

}

vector<int> div(vector<int> bin1, vector<int> bin2){
    int count = 0;
    while(binary_to_decimal(bin1) >= binary_to_decimal(bin2)){
        bin1 = sub(bin1, bin2);
        count++;
    }

    return decimal_to_binary(count);
}

vector<int> power(vector<int> bin1,vector<int> bit2){
   vector<int>res = decimal_to_binary(1);
   for(int i=0; i<binary_to_decimal(bit2); i++)
   {
      res=mul(res,bin1);
   }
   return res;
}
vector<int> modulo(vector<int>bin1 ,vector<int> bin2){
   while(binary_to_decimal(bin1)>=binary_to_decimal(bin2)){
    bin1=sub(bin1,bin2);
   }
   return bin1;
}
vector<int> factorial(vector<int> bin){
   vector<int> ans = decimal_to_binary(1);
   for(int i = 2; i<= binary_to_decimal(bin); i++){
       ans = mul(ans, decimal_to_binary(i));
   }
   return ans;
}
void print_the_vector(vector<int>bin)
{
    cout<<binary_to_decimal(bin)<<endl;
    for(int i=0;i<LENGTH-1;i++)
    {
        cout<<bin[i]<<" ";
    }
}
// basic layout of code 
int main()
{
    cout<<"Enter 1: for binary addition"<<endl;
    cout<<"Enter 2: for binary division"<<endl;
    cout<<"Enter 3: for binary multiplication"<<endl;
    cout<<"Enter 4: for binary division"<<endl;

    cout<<"Enter 5: for binary power"<<endl;
    cout<<"Enter 6: for binary modulo"<<endl;
    cout<<"Enter 7: for binary addition"<<endl;
    int n;
    cin>>n;
    vector<int>bin;
    vector<int>ans;
    int num;
    switch(n)
    {
        case 1:
                bin=input_key();
                
                ans=add(decimal_to_binary(bin[0]),decimal_to_binary(bin[1]));
                print_the_vector(ans);
                break;
        case 2:
                bin=input_key();
                
                ans=sub(decimal_to_binary(bin[0]),decimal_to_binary(bin[1]));
                print_the_vector(ans);
                break;
        case 3:
                bin=input_key();
                
                ans=mul(decimal_to_binary(bin[0]),decimal_to_binary(bin[1]));
                print_the_vector(ans);
                break;
        case 4:
                bin=input_key();
                
                ans=div(decimal_to_binary(bin[0]),decimal_to_binary(bin[1]));
                print_the_vector(ans);
                break;
        case 5:
                bin=input_key();
                
                ans=power(decimal_to_binary(bin[0]),decimal_to_binary(bin[1]));
                print_the_vector(ans);
                break;

        case 6:
                bin=input_key();
                
                ans=modulo(decimal_to_binary(bin[0]),decimal_to_binary(bin[1]));
                print_the_vector(ans);
                break;
        case 7:
                cout<<"enter the number";
                cin>>num;
                ans=factorial(decimal_to_binary(num));
                print_the_vector(ans);
                break;
        default:break;
    }
    
    return 0 ;
}
