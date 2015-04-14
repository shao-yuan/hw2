#include"super.h"
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
#include<vector>
#include<string.h>
using namespace std;
enum ORDER{ GET, CLICKED, IMPRESSED, PROFIT, QUIT};
int main(int argc, char* argv[]){
    FILE *fp;
    fp = fopen(argv[1],"r");
    vector<SuperArray> s;
    s.reserve(MAXN);
    Func func;
    func.reserve(MAXU);
    Profit pro;
    pro.reserve(MAXA);
    read(s, func, pro, fp);
    fclose(fp);
    char buffer[20];
    scanf("%s", buffer);
    int order = find_name(buffer);
            int u, a, q, d, p;
            int u1, u2;
            double r;
    while(order != QUIT){
        switch (order){
            case GET:
            scanf("%d%d%d%d%d", &u, &a, &q, &d, &p);
            get(func, u, a, q, d, p);
            break;
            case CLICKED:
            scanf("%d", &u);
            clicked(func, u);
            break;
            case IMPRESSED:
            scanf("%d%d", &u1, &u2);
            impressed(func, u1, u2);
            break;
            case PROFIT:
            scanf("%d%lf", &a, &r);
            profit(pro, a, r);
            break;
        }
        scanf("%s", buffer);
        order = find_name(buffer);
    }
    return 0;
}

