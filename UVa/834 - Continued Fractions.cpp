#include <iostream>
#include <vector>

using namespace std;

struct fraction{
    int n,d;
    fraction( int a, int b ): n(a), d(b){};
    fraction(){}
};

vector<int> ans;
void g( fraction f )
{
    if( f.d == 1 )
	{ 
	  	ans.push_back( f.n ); 
 		return; 
    }
	ans.push_back( f.n/f.d );
    g( fraction( f.d, (f.n%f.d) ) );
}

int main()
{
   int a, b;
   while( cin >> a >> b )
   {
       g( fraction( a, b ) );
       cout << "[" << ans[0] << ";";
       for( int i=1; i<ans.size(); i++ )
	   {
           cout << ans[i];
           if( i < ans.size()-1 ) cout << ",";
           else cout <<"]" << endl;
       }
       ans.clear();
   }
}
