#include <bits/stdc++.h>
using namespace std;

class HugeInteger{
   private:
      string num;
   public:
   	  HugeInteger(){
   	  	num="0";
		 }
      HugeInteger(int n){
         num=to_string(n);
      }
      HugeInteger(string n){
         num=n;
      }
      string deal(string a,string b);
      HugeInteger operator+(const HugeInteger& x){
        	HugeInteger hi;
        	hi.num=this->deal(this->num,x.num);
      		return hi;
	  }		
	  HugeInteger operator+(string x){
        	HugeInteger hi;
        	hi.num=this->deal(this->num,x);
      		return hi;
	  }	
	  friend ostream &operator<<( ostream &output, const HugeInteger &hi )
      { 
         output << hi.num;
         return output;            
      }
};

string HugeInteger::deal (string a, string b){
   int la=a.size()-1,lb=b.size()-1,carry=0;
   string ans="";
   while(la>=0 || lb>=0 || carry!=0){
      int x= la>=0? a[la]-'0' : 0;
      int y= lb>=0? b[lb]-'0' : 0;
      int result = x+y+carry;
      ans.push_back('0'+result%10);
      carry=result/10;
      la--;
      lb--;
   }
   reverse(ans.begin(),ans.end());
   return ans;
}
int main()
{
   HugeInteger n1( 7654321 );
   HugeInteger n2( 7891234 );
   HugeInteger n3( "99999999999999999999999999999" );
   HugeInteger n4( "1" );
   HugeInteger n5;
   cout << "n1 is " << n1 << "\nn2 is " << n2
      << "\nn3 is " << n3 << "\nn4 is " << n4
      << "\nn5 is " << n5 << "\n\n";
   n5 = n1 + n2;
   cout << n1 << " + " << n2 << " = " << n5 << "\n\n";
   cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";
   n5 = n1 + 9;
   cout << n1 << " + " << 9 << " = " << n5 << "\n\n";
   n5 = n2 + "10000";
   cout << n2 << " + " << "10000" << " = " << n5 << endl;

    return 0;
}
