#include<bits/stdc++.h>
using namespace std;
mt19937 rnd;
int dep=0;
unsigned long long seed=0;
unsigned long long gen(){
	rnd.seed(seed);
	seed^=seed>>12;
	seed^=seed<<8;
	seed^=seed>>21;
	seed^=seed<<33;
	seed^=0xf82ba39ab159d892;
	return (seed^=(seed<<2))^(seed<<14);
}
#define FML 95
#define DML 235
#define randChar ([](){seed^=rnd();char x=chr(rnd);if(x=='\''\
)x=33;if(x=='\\')x=126;return x;})()
uniform_int_distribution<char>chr(34,125);
uniform_int_distribution<char>chl(6,15);
uniform_real_distribution<double>expFloat(-FML,FML);
uniform_real_distribution<double>expDouble(-DML,DML);
#define sign ((rnd()%2)*2-1)
auto gByte=[](){cout<<(int)(signed char)(gen()%256ull)<<'b';};
auto gShort=[](){cout<<(short)(gen()%65536ull)<<'s';};
auto gInt=[](){cout<<(int)(gen()%(1ull<<32));};
auto gLL=[](){cout<<(long long)gen()<<'L';};
auto gFloat=[](){cout<<sign*(float)pow(2,expFloat(rnd))<<'f';};
auto gDouble=[](){cout<<sign*(double)pow(10,expDouble(rnd));};
auto gStrBase=[](){int len=chl(rnd);while(len--)(cout<<randChar),gen();};
auto gKey=[](){string c="0987654321poiuytrewqasdfghjklmnbvcxzQAZWERTYUIOPSDFGHJKLMNBVCX__";
int len=chl(rnd);while(len--)cout<<c[rnd()%64];};
auto gString=[](){cout<<"'";gStrBase();cout<<"'";};
void gRand(int);
auto gCompound=[](){cout<<'{';dep++;int len=chl(rnd);while(len--){
gKey();cout<<':';gRand(rnd()%9);if(len!=0)cout<<',';}dep--;cout<<'}';};
auto gList=[](){int tp=rnd()%7+1;cout<<'[';dep++;int len=chl(rnd);while(len--)
{gRand(tp);if(len)cout<<',';}cout<<']';dep--;};
void gRand(int type){
	if(type==0)if(dep<=7)gList();else gRand(rnd()%7+1);
	if(type==1)gInt();
	if(type==8){if(dep<=7)gCompound();else gRand(rnd()%7+1);};
	if(type==3)gFloat();
	if(type==4)gShort();
	if(type==2)gString();
	if(type==6)gByte();
	if(type==7)gLL();
	if(type==5)gDouble();
}
int main(int argc,char**argv){
	seed=/*argc*argv[0][0]+strlen(argv[1])*/chrono::system_clock::now().time_since_epoch().count();
	cout<<"{id:'***',Count:1b,tag:";
	gCompound();
	cout<<"}";
	return 0;
}