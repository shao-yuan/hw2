#include"super.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
bool cmp(SuperArray *a, SuperArray *b){
    if(a->adid < b->adid)
        return true;
	if(a->adid > b->adid)
		return false;
    if(a->que < b->que)
        return true;
	if(a->que > b->que)
		return false;
    if(a->depos < b->depos)
        return true;
    if(a->depos > b->depos)
        return false;
	return false;
}
bool cmp2(SuperArray* a, SuperArray* b){
     if(a->adid < b->adid)
         return true;
     if(a->adid > b->adid)
         return false;
     if(a->que < b->que)
         return true;
     if(a->que > b->que)
         return false;
	return false;
}
bool cmp3(SuperArray* a, SuperArray* b){
     if(a->adid < b->adid)
         return true;
	return false;
}
bool cmp5(SuperArray* a, SuperArray* b){
     if(a->adid < b->adid)
         return true;
     if(a->adid > b->adid)
         return false;
     if(a->url < b->url)
         return true;
     if(a->url > b->url)
         return false;
     if(a->key < b->key)
         return true;
     if(a->key > b->key)
         return false;
     if(a->tit < b->tit)
         return true;
     if(a->tit > b->tit)
         return false;
     if(a->des < b->des)
         return true;
     if(a->des > b->des)
         return false;
	return false;
}
bool cmp4(SuperArray* a, SuperArray* b){
     if(a->user < b->user)
         return true;
	return false;
}
void read(vector<SuperArray> &sp, Func &func, Profit &profit, FILE *fp){
    SuperArray s;
    int dep;
#ifdef DEBUG
    int i = 0;
#endif
    while(fscanf(fp,"%d%d%llu%d%d%d%d%d%d%d%d%d\n",
                &s.cli, &s.imp, &s.url, &s.adid, &s.adzer, 
                &dep, &s.depos, &s.que, &s.key, &s.tit, &s.des, &s.user) != EOF){
#ifdef DEBUG
       	if(i == 1000)
            puts("1000!");
        if(i % 100000 == 0)
            printf("%d!!\n", i); 
        i++;
#endif       
        s.depos += 3 * dep;
        sp.push_back(s); 
        func[s.user].push_back(&(sp.back()));
        profit[s.adid].push_back(&(sp.back()));
    }
}
void get(Func &func, int u, int a, int q, int d, int p){
    sort(func[u].begin(), func[u].end(), cmp);
#ifdef DEBUG2
    for(auto i = func[u].begin(); i < func[u].end(); i++)
        printf("i%d %d\n", (*i)->adid, (*i)->que);
#endif
	SuperArray tmp;
    tmp.adid = a;
    tmp.que = q;
    tmp.depos = d * 3 + p;
    SuperArray *pt = &tmp;
    Pair bound = equal_range(func[u].begin(), func[u].end(), pt, cmp);
    CI ans = {0,0};
    for(auto i = bound.first; i < bound.second; i++){
        ans.click += (*i)->cli;
        ans.impression += (*i)->imp;
    }
    puts("********************");
    printf("%d %d\n", ans.click, ans.impression);
    puts("********************");
}
void clicked(Func &func, int u){
    int ad = -1, q = -1;
    sort(func[u].begin(), func[u].end(), cmp2);
    puts("********************");
    for(auto i = func[u].begin(); i < func[u].end(); i++){
        if((*i)->cli == 0)
            continue;
        if(ad == (*i)->adid && q == (*i)->que)
            continue;
        ad = (*i)->adid;
        q = (*i)->que;
        printf("%d %d\n", ad, q);
    }
    puts("********************");
}
void impressed(Func &func, int u1, int u2){
    puts("********************");
    sort(func[u1].begin(), func[u1].end(), cmp3);
#ifdef DEBUG2
    for(auto i = func[u1].begin(); i < func[u1].end(); i++)
        printf("ad:%d \n", (*i)->adid);
#endif
    sort(func[u2].begin(), func[u2].end(), cmp3);
#ifdef DEBUG2
    for(auto i = func[u2].begin(); i < func[u2].end(); i++)
        printf("ad:%d \n", (*i)->adid);
#endif
    vector<SuperArray*>::iterator i = func[u1].begin();
    vector<SuperArray*>::iterator j = func[u2].begin();
    while(i != func[u1].end() && j != func[u2].end()){
        if((*i)->adid < (*j)->adid)
            i++;
        else if((*i)->adid > (*j)->adid)
            j++;
        else{
            vector<SuperArray*> print;
            int adid = (*i)->adid;
            printf("%d\n", adid);
            while(i != func[u1].end() && (*i)->adid == adid){
            print.push_back(*i);
            i++;
            }while(j != func[u2].end() && (*j)->adid == adid){
            print.push_back(*j);
            j++;
            }
            sort(print.begin(), print.end(), cmp5);
            vector<SuperArray*>::iterator p = print.begin();
            while(p != print.end()){ 
                printf("\t%llu %d %d %d %d\n", (*p)->url, (*p)->adzer, (*p)->key, (*p)->tit, (*p)->des);
                p = upper_bound(print.begin(), print.end(), (*p), cmp5);
            }
         }
    }
    puts("********************");
}
void profit(Profit &pro, int a, double r){
    puts("********************");
    sort(pro[a].begin(), pro[a].end(), cmp4);
    vector<SuperArray*>::iterator i = pro[a].begin();
    int u = -1;
    int sum_cli = 0;
    int sum_imp = 0;
	double myr;
    for(auto i = pro[a].begin(); i < pro[a].end(); i++){
		if((*i)->user == u){
			sum_cli += (*i)->cli;
			sum_imp += (*i)->imp;
		}else{
			myr =  double(sum_cli) / double(sum_imp);
        	if(myr >= r)
            	printf("%d\n", u);
			sum_cli = (*i)->cli;
			sum_imp = (*i)->imp;
			u = (*i)->user;
    	}
	}
		myr =  double(sum_cli) / double(sum_imp);
        if(myr >= r)
          	printf("%d\n", u);
    puts("********************");
}

int find_name(char *buffer){
    char name[5][20] = {"get", "clicked", "impressed", "profit", "quit"};
    for(int i = 0; i < 5; ++i){
        if(strcmp(buffer, name[i]) == 0)
            return i;
    }
    return 4;
}
