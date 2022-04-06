#include <string>
#include <vector>
using namespace std;

string multi(string a, string b)
{
    int len1 = a.size();    
    int len2 = b.size();    

    if(len1 == 0 || len2 == 0)
    return "0";

    vector<int> ans(len1+len2, 0);

    int i_a = 0;
    int i_b = 0;

    for(int i = len1-1; i>=0 ; i--)
    {
        int carry = 0;
        int n1 = a[i] - '0';
        i_b = 0;

        for(int j = len2-1; j >= 0; j--)
        {
            int n2 = b[j] - '0';

            int sum = n1*n2 + ans[i_a + i_b] + carry;

            carry = sum/10;

            ans[i_a+i_b] = sum % 10;

            i_b++;

        }

        if(carry >0)
        ans[i_a + i_b] += carry;

        i_a++;
    }

    int i = ans.size() - 1;
    while (i>=0 && ans[i] == 0)
    i--;
 
   
    if (i == -1)
    return "0";
 
    
    string s = "";
     
    while (i >= 0)
        s += to_string(ans[i--]);
 
    return s;
    
}


string factorial(int factorial){
  vector<string> answer(factorial + 1,"1");

  

  for(int i = 2; i <= factorial; i++)
  {
      answer[i] = multi(to_string(i), answer[i-1]);
  }

  return answer[factorial];


}