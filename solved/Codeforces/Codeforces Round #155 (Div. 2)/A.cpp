// http://codeforces.com/contest/254/problem/A

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

struct point{
    double x,y;
    point() {}
    point(double X, double Y) : x(X), y(Y) {}
    point sub(point a){
        return point(x - a.x,y - a.y);
    }
    point add(point a){
        return point(x + a.x,y + a.y);
    }
    double cross(point a){
        return x*a.y - y*a.x;
    }
    point multbyscalar(double ua) {
        return point(ua*x,ua*y);
    }
};



int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin>>n;
    vector<int> pos[n<<1];
    map<int,int> cod;
    int index = 0;
    int tmp;
    For(i,n<<1){
        cin>>tmp;
        if(cod.count(tmp)== 0)
            cod[tmp]=index++;
        pos[cod[tmp]].push_back(i+1);
    }
    For(i,n<<1){
        if(pos[i].size()%2){
            cout<<-1<<endl;
            return 0;
        }
    }
    For(i,n<<1){
        if(pos[i].size()){
            for(int j=0;j<pos[i].size()-1;j+=2){
                cout<<pos[i][j]<<" "<<pos[i][j+1]<<endl;
            }
        }
    }
    return 0;
}