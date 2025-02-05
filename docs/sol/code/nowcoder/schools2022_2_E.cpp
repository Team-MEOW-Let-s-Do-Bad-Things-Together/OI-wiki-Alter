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

int n;

#define ATL_MATH
constexpr ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
constexpr ll lcm(ll a,ll b){return a*b/gcd(a,b);}
template<class T>
T power(T a,size_t b,const T &unit=1){
	if (b==0) return unit;
	if (b&1) return a*power(a*a,b>>1,unit);
	return power(a*a,b>>1,unit);
}
constexpr ll ceildiv(const ll a,const ll b){return a/b+(a%b?1:0);}
tuple<ll,ll,ll> exgcd(ll a,ll b){//a1+b2=gcd(a,b)
	if (b==0) return make_tuple(a,1,0);
	ll g,x,y;
	tie(g,x,y)=exgcd(b,a%b);
	return make_tuple(g,y,x-a/b*y);
}
tuple<ll,ll,ll> Fexgcd(ll a,ll b){//a1+b2=gcd(a,b),ensure 1>0
	auto k=exgcd(a,b);
	if (get<1>(k)<0) {
		get<1>(k)+=b;
		get<2>(k)-=a;
	}
	return k;
}

#ifndef __OP__
#define __OP__
#define def_op(op)\
this_type operator op (const this_type& a)const{this_type k(*this);k op##=a;return k;}
#define def_cmp(op,n2)\
bool operator op (const this_type& a)const{return n2 op a.n2;}
#define def_all_cmp(n2)\
def_cmp(<,n2) def_cmp(>,n2) def_cmp(<=,n2) \
def_cmp(>=,n2) def_cmp(!=,n2) def_cmp(==,n2)
#endif
template<class T,class uT,ll mod>
struct _mint{
	using this_type=_mint;
	T v;
	_mint()=default;
	template<class iT>
	_mint(const iT& a){v=a%mod;v+=v<0?mod:0;}
	_mint& operator+=(const _mint& a){return (v+=a.v)>=mod&&(v-=mod),*this;}
	_mint& operator-=(const _mint& a){return (v-=a.v)<0&&(v+=mod),*this;}
	_mint& operator*=(const _mint& a){return (v=((uT)v*a.v)%mod),*this;}
	def_op(+) def_op(-) def_op(*)
	def_all_cmp(v)
	#ifdef ATL_MATH
	_mint inverse()const{return power(*this,mod-2);}
	_mint& operator/=(const _mint& a){return (*this)*=a.inverse(),*this;}
	def_op(/)
	#endif
};
template<class T,class uT,ll mod>
ostream& operator<<(ostream& os,const _mint<T,uT,mod>& a){return os<<a.v;}
template<class T,class uT,ll mod>
istream& operator>>(istream& os,_mint<T,uT,mod>& a){T k;os>>k;a=_mint<T,uT,mod>(k);return os;}
using mint=_mint<int,long long,998244353>;
using mll=_mint<long long,__int128,998244353>;

template<class T>
struct ntt{
	int size,l,n;
	vector<int> r;
	const int mod{998244353};
	const array<const T,2> P{3,332748118};
	array<vector<T>,2> W;
	int floorintlog2(int i){
		int k=0;
		while (i) i>>=1,k++;
		return k;
	}
	ntt(int size):size(size){
		l=floorintlog2(size);
		n=1<<l;
		r.resize(n,0);
		W.fill(vector<T>(n));
	    for (int i=0;i<n;i++)
	        r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	    for (int type:{0,1})
		    for (int i=0;i<l;i++)
		    	W[type][i]=power(P[type],(mod-1)/(1<<i<<1));
	}
	template<int type,class U>
	valarray<T> _NTT(const U& B)const{
		valarray<T> A(n);
		copy(std::begin(B),std::end(B),begin(A));
	    for (int i=0;i<n;i++) 
	        if(i<r[i]) swap(A[i],A[r[i]]);
	    for (int mid=1,midj=0;mid<n;mid<<=1,midj++){
	        T Wn=W[type][midj];
	        for (int R=mid<<1,j=0;j<n;j+=R){
	            T w=1;
	            for (int k=0;k<mid;k++,w*=Wn){
	                const T x=A[j+k],y=w*A[j+mid+k];
	                A[j+k]=x+y;
	                A[j+mid+k]=x-y;
	            }
	        }
	    }
	    if (type) A*=power(T(n),mod-2);
	    return A;
	}
	template<class U>
	valarray<T> NTT(const U& A)const{return _NTT<0>(A);}
	valarray<T> DNT(const valarray<T>& A)const{return _NTT<1>(A);}
};
mint P[1000000+10];
mint C(int n,int k){
  if (n<0||k>n) return 0;
  return P[n]/P[n-k]/P[k];
}
int main(){
  cin>>n;
  ntt<mint> t(2*n+2);
  vec<mint> a(n+1),b(n+1);
  P[0]=1;
  for (int i=1;i<=1000000;i++) P[i]=P[i-1]*i;
  for (int i=0;i<=n;i++){
    int k=n-i;
    a[i]=C(n-2*k,k)*(n-3*k<0?0:power(mint(26),n-3*k))*P[k];
    //cerr<<C(n-2*k,k)*power(mint(26),n-3*k)*P[k]<<endl;
    b[i]=mint(1)/P[i];
    if (i%2==1) b[i]*=-1;
  }
  auto c=t.DNT(t.NTT(a)*t.NTT(b));
//  print("{{} }\n{{} }\n",a,b);
//  for (int i=0;i<=n;i++) cout<<c[i]<<" ";cout<<endl;
  for (int i=n;i>=0;i--){
    cout << c[i]/P[n-i] << " ";
  }
}