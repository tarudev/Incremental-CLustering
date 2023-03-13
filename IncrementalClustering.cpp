#include"projectlib.h"

int main(){
   vector<point> all_points;
   vector<point> cluster;
   int k;

   cout<<"Enter the number of clusters: ";
   cin>>k;

   string traindata="19 2,21 0,-3 -4,3 5,1 12,-1 -4,4 7,2.2 0.3,-6 3,2 1";
   fetch(traindata,all_points);
   if(all_points.size()<k){return 1;}
   cout<<"All points:\n";
   print_points(all_points);
   makeclus(all_points,cluster,k);
   cout<<"\n";
   cout<<"Initial Cluster centroids\n";
   print_centroid(cluster);
   cout<<"\n";
   int k1=0;
   while(k1==0){
       near_cluster_alloted(all_points,cluster);
       k1=centroid(allpoin,cluster);
    }
   clusterpoint(allpoin,k);
   print_centroid(cluster);
   int x,y;
   cout<<"\nEnter the coordinates of the entry:\n";
   cout<<"x ="; cin>>x;
   cout<<"y ="; cin>>y;
   cout<<"\n";
   addp(x,y,all_points);
   near_cluster_alloted_incremental(all_points[all_points.size()-1],cluster);
   c_centroid(all_points[all_points.size()-1].f,all_points,cluster);
   clusterpoint(all_points,k);
   cout<<"\n";
   print_centroid(cluster);
}
