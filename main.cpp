/*
___mennat khoday ra azz o va jall ke taatash mojebe ghorbat ast o be shokr andarash mazide nemat.
___har nafasi ke foro miravad momedde hayatast o chon bar miayad mofarrahe zat.
___pas dar har nafasi 2 nemat mojod ast o bar har nematy shokry vajeb.

___az dast o zabane ke barayad ?
___kaz ohdeye shokrash be dar ayad !


___man be to dami gharar natvanam kard
___va ehsane to ra shomar natvanam kard
####################
___gar bar tane man zaban shavad har moyee
___yek shokre to az hezar natvanam kard

*/

#include <bits/stdc++.h>


#define pb push_back
#define SALI main
#define left(x) ((x)*2)
#define right(x) (((x)*2)+1)
#define fuck(x) cout << #x << " : " << x << "  "
#define findLowVec(v,x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define findUpVec(v,x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define findLowArr(a,n,x) (lower_bound(a, a+n, x) - a)
#define findUpArr(a,n,x) (upper_bound(a, a+n, x) - a)
#define int long long

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,char> pic;
typedef long double ld;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p)
{return out << "(" << p.first << ", " << p.second << ")";}

template<class A> ostream& operator <<(ostream& out, const vector<A> &v)
{out << "[";for(int i = 0; i < v.size(); i++) {if(i) out << ", ";out << v[i];}return out << "]";}

template<class A,class B> ostream& operator <<(ostream& out, const set<A,B> &s)
{out << "[";for(auto i = s.begin(); i != s.end(); i++) {out << ", ";out << *i;}return out << "]";}

template<class A> ostream& operator <<(ostream& out, const set<A> &s)
{out << "[";for(auto i = s.begin(); i != s.end(); i++) {out << ", ";out << *i;}return out << "]";}

struct process
{
    string name;
    char type;
    int time;
    int rmd; // remained
    string state;
    int CPU_used;
    void input()
    {
        cin >> name >> type >> time;
        CPU_used = 0;
        state = "ready";
        rmd = time;
    }

};
/*
template<class A> ostream& operator <<(ostream& out, const process &a)
{out << "(name = " << a.name << ", type = " << a.type << ", time" << ", rmd = "
<< a.rmd << ", state = " << a.state << ", CPU_used = " << a.CPU_used << ")";}
*/
int A,B,C,n;
vector<process> ready;
vector<process> waiting;
vector<process> running;


// X : A B
// Y : B C
// Z : A C
void scheduler()
{

}
void input()
{
    cin >> A >> B >> C >> n;
    for(int i = 0; i < n; i++){
        process t;
        t.input();
        ready.pb(t);
    }

}
int32_t SALI()
{
    input();
}

/**< WRITEN BY ALI ADELKHAH */
