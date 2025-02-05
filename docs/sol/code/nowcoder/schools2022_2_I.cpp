#include <bits/stdc++.h>
using namespace std;
struct FAST_IO{
	FAST_IO(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	}
}__fast_io;
#if __cplusplus < 201402L
template<class T, class U=T>
T exchange(T& obj, U&& new_value){
    T old_value=move(obj);
    obj=forward<U>(new_value);
    return old_value;
}
#endif
#define cons(a,...) a=typename decay<decltype(a)>::type(__VA_ARGS__)
using INT=int;
#define DEF_NUM(num) \
using i##num=int##num##_t;using u##num=uint##num##_t;
DEF_NUM(8)DEF_NUM(16)DEF_NUM(32)DEF_NUM(64)
using i128=__int128;using u128=unsigned __int128;
using usize=uintptr_t;using isize=intptr_t;
using f32=float;using f64=double;using f128=long double;
#define x first
#define y second
//#define int long long
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
auto &_=std::ignore;
using ll=long long;
template<class T>
using vec=vector<T>;
template<bool B,class T=void>
using enableif_t=typename enable_if<B,T>::type;

#define DEF_COULD(name,exp) \
template<class U> \
struct name{\
	template<class T>\
	constexpr static auto is(int i)->decltype(exp,true){return true;}\
	template<class T>\
	constexpr static bool is(...){return false;}\
	static const bool value=is<U>(1);\
};
#define DEF_CAN(name,exp) DEF_COULD(can##name,exp)
#define ENABLE(T,name) enableif_t<can##name<T>::value>(1)
#define ENABLEN(T,name) enableif_t<!can##name<T>::value>(1)
#define FOR_TUPLE enableif_t<i!=tuple_size<T>::value>(1)
#define END_TUPLE enableif_t<i==tuple_size<T>::value>(1)
#define FOR_TUPLET(T) enableif_t<i!=tuple_size<T>::value>(1)
#define END_TUPLET(T) enableif_t<i==tuple_size<T>::value>(1)

#define DEF_INF(name,exp)\
constexpr struct{\
	template<class T>\
	constexpr operator T()const {return numeric_limits<T>::exp();}\
} name;

DEF_CAN(Out,(cout<<*(T*)(0))) DEF_CAN(For,begin(*(T*)(0)))
DEF_INF(INF,max) DEF_INF(MINF,min)
DEF_CAN(Array,declval<T>()[0])

template<size_t i,class T>
auto operator>>(istream& is,T &r)->decltype(END_TUPLE,is){
	return is;
}
template<size_t i=0,class T>
auto operator>>(istream& is,T &r)->decltype(FOR_TUPLE,is){
	is>>get<i>(r);
	return operator>> <i+1>(is,r);
}

template<size_t i,class ...Args>
auto operator>>(istream& is,const tuple<Args&...> &r)->decltype(END_TUPLET(tuple<Args&...>),is){
	return is;
}
template<size_t i=0,class ...Args>
auto operator>>(istream& is,const tuple<Args&...> &r)->decltype(FOR_TUPLET(tuple<Args&...>),is){
	is>>get<i>(r);
	return operator>> <i+1>(is,r);
}

template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLE(T,Out),c+1);
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),END_TUPLE,c+1);
template<size_t i=0,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),FOR_TUPLE,c+1);
template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,Out),ENABLE(T,For),c+1);


template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLE(T,Out),c+1){
	os << cv;
	while (*c!='}') c++;
	return c+1;
}
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),END_TUPLE,c+1){
	return c;
}
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),FOR_TUPLE,c+1){
	while (*c!='{') os << *c++;
	c=__format(os,c,get<i>(cv));
	return __format<i+1>(os,c,cv);
}
template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,Out),ENABLE(T,For),c+1){
	const char *ct=c+1;
	if (cv.size()==0){
		int b=1;
		while (1){
			if (*ct=='}') b--;
			if (*ct=='{') b++;
			if (!b) break;
			ct++;
		}
	}else{
		for (auto &i:cv){
			const char *cc=c+1;
			while (*cc!='{') os << *cc++;
			cc=__format(os,cc,i);
			while (*cc!='}') os << *cc++;
			ct=cc;
		}
	}
	return ct+1;
}
void _format(ostream &os,const char *c){
	while (*c!='{'&&*c!='\0') os<< *c++;
}
template<class T,class ...Args>
void _format(ostream &os,const char *c,const T &a,const Args& ...rest){
	while (*c!='{'&&*c!='\0') os<< *c++;
	if (*c=='{') c=__format(os,c,a);
	_format(os,c,rest...);
}
template<class ...Args>
string format(const char *c,const Args& ...rest){
	ostringstream os;
	_format(os,c,rest...);
	return os.str();
}
template<class ...Args>
ostream& print(const char *c,const Args& ...rest){return _format(cout,c,rest...),cout;}
template<class ...Args>
ostream& println(const char *c,const Args& ...rest){return print(c,rest...)<<endl;}

#ifndef ONLINE_JUDGE
#define debug(...) cerr<<format(__VA_ARGS__)
#define debugln(...) cerr<<format(__VA_ARGS__)<<endl
#else
#define debug(...) cerr
#define debugln(...) cerr
#endif

template<class T>
uintptr_t flat(T* b){
	return reinterpret_cast<uintptr_t>(b);
}
template<class T>
auto index(const T a[],uintptr_t p)->decltype(ENABLEN(T,Array),tuple<int>()){
	return (p-flat(&a[0]))/sizeof(T);
}
template<class T>
auto index(const T a[],uintptr_t p)->decltype(ENABLE(T,Array),
	tuple_cat(tuple<int>(),index(a[0],p))){
	int i=(p-flat(a))/sizeof(a[0]);
	p-=i*sizeof(a[0]);
	return tuple_cat(tuple<int>(i),index(a[0],p));
}

template<class T,class ...Args>
struct Rtar{
	T& a;tuple<Args...> n;
	Rtar(T& a,tuple<Args...> n):a(a),n(n){}
};
template<class T,class ...Args>
Rtar<T,Args&...> rtar(T &a,Args&... rest){
	return Rtar<T,Args&...>(a,tie(rest...));
}
template<size_t i,class U,class ...Args,class T=tuple<Args&...>>
auto operator>>(istream& is,Rtar<U,Args&...> r)->decltype(END_TUPLE,is){
	return is>>r.a;
}
template<size_t i=0,class U,class ...Args,class T=tuple<Args&...>>
auto operator>>(istream& is,Rtar<U,Args&...> r)->decltype(FOR_TUPLE,is){
	r.a=typename decay<U>::type(get<i>(r.n));
	for (auto &w:r.a)
		operator>> <i+1>(is,Rtar<decltype(w),Args&...>(w,r.n));
	return is;
}
template<class T1,class T2>
bool cmin(T1 &a,const T2 b){return a>b?a=b,1:0;}
template<class T1,class T2>
bool cmax(T1 &a,const T2 b){return a<b?a=b,1:0;}
template<class T1,class T2,class ...T3>
bool cmin(T1 &a,const T2 b,const T3 ...rest){return cmin(a,b)|cmin(a,rest...);}
template<class T1,class T2,class ...T3>
bool cmax(T1 &a,const T2 b,const T3 ...rest){return cmax(a,b)|cmax(a,rest...);}

bool MULTIDATA=true;


#define for_n(i,n,exp) for (int i=0;i<n;i++) exp;
template<class T>
struct dmat:public vector<T>{
	int n,m;
	dmat(int n,int m):n(n),m(m),vector<T>(n*m,0){}
	dmat(int n,int m,initializer_list<T> a):n(n),m(m),vector<T>(a){}
	T* operator[](int i){return &vector<T>::operator[](i*m);}
	const T* operator[](int i)const{return &vector<T>::operator[](i*m);}
	dmat operator*(const dmat<T> &b)const{
		auto& a=(*this);
		dmat<T> x(a.n,b.m);
		for (int i=0;i<a.n;i++)
			for (int j=0;j<b.m;j++)
				for (int k=0;k<a.m;k++)
					x[i][j]+=a[i][k]*b[k][j];
		return x;
	}
	dmat operator*=(const dmat<T> &b){return (*this)=(*this)*b;}
	static dmat<T> unit(int n,int m){
		dmat<T> x(n,m);
		for (int i=0;i<n;i++) x[i][i]=1;
		return x;
	}
};
double q2(double x){return x*x;}
int main(){
  int n,k,d;
  cin>>n>>k>>d;
  dmat<double> X(n,k),Y(n,d),XT(k,n);
  for (int i=0;i<n;i++){
    double x=0;
    for (int j=0;j<k;j++){
      cin>>X[i][j];
      x+=q2(X[i][j]);
    }
    x=sqrt(x);
    for (int j=0;j<k;j++){
      XT[j][i]=X[i][j]/=x;
    }
  }
  
  for (int i=0;i<n;i++)
    for (int j=0;j<d;j++)
      cin>>Y[i][j];
  auto a=X*(XT*Y);
  cout<<fixed<<setprecision(8);
  for (int i=0;i<n;i++){
    for (int j=0;j<d;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
}