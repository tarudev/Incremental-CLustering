#include"projectlib.h"

int main(){
   vector<point> allpoin;
   vector<point> cluster;
   int k;

   cout<<"Enter the number of clusters: ";
   cin>>k;

   string traindata="19 2,21 0,-3 -4,3 5,1 12,-1 -4,4 7,2.2 0.3,-6 3,2 1";
   fetch(traindata,allpoin);
   if(allpoin.size()<k){return 1;}
   cout<<"All points:\n";
   printa(allpoin);
   makeclus(allpoin,cluster,k);
   cout<<"\n";
   cout<<"Initial Cluster centroids\n";
   printw(cluster);
   cout<<"\n";
   int k1=0;
   while(k1==0){
       nearclusallo(allpoin,cluster);
       k1=centroid(allpoin,cluster);
    }
   cluspoint(allpoin,k);
   printw(cluster);
   int x,y;
   cout<<"\nEnter the coordinates of the entry:\n";
   cout<<"x ="; cin>>x;
   cout<<"y ="; cin>>y;
   cout<<"\n";
   addp(x,y,allpoin);
   nearclusalloincre(allpoin[allpoin.size()-1],cluster);
   ccentroid(allpoin[allpoin.size()-1].f,allpoin,cluster);
   cluspoint(allpoin,k);
   cout<<"\n";
   printw(cluster);
}