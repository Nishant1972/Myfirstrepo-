# include <bits/stdc++.h>
# include <iostream>
using namespace std;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
int main(){
    int num,den;
    float no;
    int mult_den = 1,mult_num = 1;
    for (num = 10; num < 100 ; ++num){
        for (den = 10; den < 100 ;++den){
            int new_num = num;
            int new_den = den;
            no = (float)num/den;
          //  cout << no << " ";
            if (num >= den)
                continue;
            if (num%10==0 || den%10 == 0){
                continue;
            }
           int num1 = num%10;
           int num2 = num/10;
           int den1 = den%10;
           int den2 = den/10;
           //cout << num1 << " " << num2 << " " << den1  << " " << den2 << "\n"; 
           if (num1 == den1)
                num1 = den1 = -1;
           else if (num1 == den2)
                num1= den2 = -1;
           else if(num2 == den1)
                num2 = den1 = -1;
           else if (num2 == den2)
                num2 = den2 = -1; 
           // cout << num1 << " " << num2 << " " << den1  << " " << den2 << "\n";    
           if (num1 == -1){
               new_num = num2;
           }
           if (num2 == -1)
                new_num = num1;
           if (den1 == -1)
                new_den = den2;
           if (den2 == -1)
                new_den = den1;  
            //cout << new_num << " " << new_den << " ";
           if (new_num != num || new_den!= den)
           {
               int div = gcd(new_num,new_den);
               //cout << div << " " << new_den<<" ";
               new_den = new_den/div;
               new_num = new_num/div;
               //cout << new_den << new_num;
               
               if ((float) new_num / new_den == no)
                {    
                    cout << num << " " << den <<"\n";
                    mult_den *= new_den; 
                    mult_num *= new_num;
                }
                
                   // cout << "YEs "<<num <<" "<< den; 
           }

        }
    }
    int div= gcd(mult_den,mult_num);
    cout << mult_den/div;
}