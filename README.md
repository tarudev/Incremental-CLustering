# Incremental-Clustering
Implemented the Unsupervised Machine Learning Algorithm of K-Means Clustering incrementally, improving resource utilization in terms of speed and space. Used OpenMP Library to design a parallelized, multithreaded model in a MISD Parallel Computing System further increasing the speed of execution.

WHAT IS CLUSTERING?

Clustering is the classification of objects into different groups or more precisely portioning of data into subsets(clusters) so that the data in each subset ideally share some trait common-often according to some defined distance measure. It is one of the most popular unsupervised learning algorithms.

WHAT IS K-MEANS CLUSTERING?

Its a type of clustering algorithm. It labels the data by assessing the distance (Euclidean or Manhattan) among the data. Clusters are formed for data having proximity to each other.

Algorithm:

1) Choose the number of clusters
2) Select at random k-points which are to be the centroids of each cluster.
3) Assign the data points to the closest centroid
4) Calculate the new centroid
5) Repeat the above step till the centroid is fixed

We can also deploy elbow method to determine the optimum number of clusters or the value of K by checking for the value of K at which the bent is prominent.

For example:

Initially 3 centroids are assigned randomly.
Used Euclidian distance to find out which centroid is closest to each data point and the data point and are assigned to the corresponding centroids.
We formed 3-clusters by assigning points to it’s closest centroid of each clusters centroid of each cluster. The recomputing is done based on the points that have been assigned to that cluster centroid.

Reposition of centroids for optimization

This process is iteratively repeated until our centroids become static. This process goes on until a point where no centroid shifts the position. We call that case as the problem has been converged.
 
In the C++ program, I developed a data structure to store the data as co-ordinates and an additional part is allocated as cluster ID to store its association with a certain cluster. The data is provided as a string. The data from the string is streamed into the defined data structures. Then, the algorithm designed takes over and produces clusters and allocates the data to respective clusters and updates the centroids iteratively. The dynamic data entry is inputted after the initial implementation of the clustering algorithm. The entry is allocated the respective cluster incrementally by utilizing the previous allocations saving us resources in terms of space and time.

The algorithm used here is implemented under Parallel Computing Paradigm of MISD (Multiple Instruction Single Data), shared memory Parallel Computing System. The OpenMP directives of:

1) #pragma omp parallel: It instructs the compiler to parallelize the enclosed block of code. Here, we are also assigning shared data, to be shared across all the parallel threads, and private data, to declare the data which is limited to the scope of the individual thread only.

2) #pragma omp for: It instructs the compiler to distribute loop iterations within the team of threads that encounter the enclosed instructions.

Above directives are used to provide for parallel computing which boost the performance of the code.

To get a breifing of Parallel Computing: https://hpc.llnl.gov/training/tutorials/introduction-parallel-computing-tutorial

Similar models are heavily used in spam filtering application, and broadly, for making sense of any unlabeled data.
