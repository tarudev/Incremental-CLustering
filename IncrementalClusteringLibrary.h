#ifndef projectlib_H
#define projectlib_H

#include<bits/stdc++.h>
using namespace std;
#define ff first.first 
#define fs first.second 
#define sf second.first 
#define ss second.second 
#define f first
#define se second

typedef pair<double,double> co;
typedef pair<int,co> point;

double dist(point x,point y){
   double s=sqrt(pow(x.sf-y.sf,2)+pow(x.ss-y.ss,2));
   return s;
}
//procure data from string into defined data structure 
void fetch(string &d,vector<point> &a){
    point a2;
    stringstream train(d);
    string line;
    while(getline(train,line,',')){
        stringstream s(line);
        a2.f=0;
        double i1,i2;
        s>>a2.sf;s>>a2.ss;
        a.push_back(a2);
    } 
}
//initialise clusters
void makeclus(vector<point> &a,vector<point> &c,int h){
    point allpoin;
    int q=a.size();
    for(int i=0;i<h;i++){
        allpoin=a[rand()%q];
        allpoin.f=i;
        c.push_back(allpoin);
    }
}

void print(point &a){cout<<"["<<a.sf<<","<<a.ss<<"]";}

void printa(vector<point> &a){
    for(int i1=0;i1<a.size();i1++){cout<<"["<<a[i1].sf<<","<<a[i1].ss<<"]"; cout<<"\n";}
}

void printw(vector<point> &a){
    for(int i1=0;i1<a.size();i1++){cout<<"Centroid "<<i1+1<<" ["<<a[i1].sf<<","<<a[i1].ss<<"]"; cout<<"\n";}
}
//function to update centroids and return a check value
int centroid(vector<point> &a,vector<point> &c){
    #pragma omp parallel shared(a,c) private(i,j,1,s2,q)
  {
	  #pragma omp for
    for(int j=0;j<c.size();j++){
        double s1=0,s2=0;
        int q=0;
        for(int i=0;i<a.size();i++){
            if(a[i].f==j){s1+=a[i].sf;s2+=a[i].ss;q++;}
        }
        s1=s1/q;  s2=s2/q;
	    #pragma omp critical
        if(c[j].sf==s1 && c[j].ss==s2){return 1;}
        else{c[j].sf=s1; c[j].ss=s2;}
    }
    return 0;
}
}

void addp(double x,double y,vector<point> &ap){
    point w;
    w.f=-1; w.sf=x; w.ss=y;
    ap.push_back(w);
}
//allocate data to the respective nearest centroids 
void nearclusallo(vector<point> &a,vector<point> &c){
    #pragma omp parallel shared(a,c) private(i,j,s,q)
  {
	  #pragma omp for
    for(int i=0;i<a.size();i++){
        double s=INT_MAX;
        for(int j=0;j<c.size();j++){
            double q=dist(a[i],c[j]);
            if(q<s){s=q; a[i].f=c[j].f; }
        }
    }
}
}
// incremental part update centroid
void ccentroid(int j,vector<point> &ap,vector<point> &c){
    double s1=0,s2=0;
    int q=0;
    for(int i=0;i<ap.size();i++){
        if(ap[i].f==j){s1+=ap[i].sf;s2+=ap[i].ss;q++;}
    }
    s1=s1/q;  s2=s2/q;
    c[j].sf=s1; c[j].ss=s2;
}
//incremental cluster allocation
void nearclusalloincre(point &a,vector<point> &c){
    double s=INT_MAX;
    for(int j=0;j<c.size();j++){
        double q=dist(a,c[j]);
        if(q<s){s=q; a.f=c[j].f; }
    }
}
//printing the clusters
void cluspoint(vector<point> &a,int k){
    for(int i=0;i<k;i++){
        cout<<"Cluster "<<i+1<<" ";
        for(int j=0;j<a.size();j++){if(a[j].f==i)print(a[j]);}
        cout<<"\n";
    }
}

#endif
