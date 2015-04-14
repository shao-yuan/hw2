#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<map>
#include<utility>
#include<algorithm>
#define MAXN 149639105
#define MAXU 23907635
#define MAXA 22238278
using namespace std;

typedef struct superArray{
    int cli;
    int imp;
    unsigned long long url;
    int adid;
    int adzer;
    int depos;
    int que;
    int key;
    int tit;
    int des;
    int user;
} SuperArray;

typedef struct ci{
    int click;
    int impression;
}CI;

typedef struct data{
    unordered_map<int, unordered_map < double, CI> > Get;
    vector<SuperArray*> Click;
    map<int, vector<SuperArray*> > Impre;
}Data;
typedef unordered_map<int, vector<SuperArray*> > Func;
typedef unordered_map< int, vector<SuperArray*> >Profit;

typedef pair<vector<SuperArray*>::iterator, vector<SuperArray*>::iterator> Pair;

void read(vector<SuperArray> &sp, Func &func, Profit &profit, FILE *fp);
void get(Func &func, int u, int a, int q, int d, int p);
void clicked(Func &func, int u);
void impressed(Func &func, int u1, int u2);
void profit(Profit &pro, int a, double r);
int find_name(char *buffer);
