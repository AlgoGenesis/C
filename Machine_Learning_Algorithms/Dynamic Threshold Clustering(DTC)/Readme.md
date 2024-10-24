# Dynamic Threshold Clustering (DTC)

Dynamic Threshold Clustering (DTC) is an innovative unsupervised learning algorithm designed for grouping similar data points based on local density. This algorithm dynamically adjusts its clustering threshold, making it particularly effective for a variety of datasets and applications. 

## Overview

DTC is a density-based clustering algorithm that:
- Identifies clusters in a dataset by assessing the local density of points.
- Dynamically adjusts the threshold for cluster formation based on the distribution of data.
- Effectively identifies noise and outlier points that do not belong to any cluster.

## Features

- **Dynamic Thresholding**: Adapts to varying densities in the data, allowing for more flexible clustering.
- **Noise Handling**: Robustly identifies and manages outlier data points.
- **Scalable**: Efficiently processes large datasets using spatial partitioning techniques.
- **Customizable Distance Metrics**: Supports various distance calculations to suit different types of data.

## How It Works

1. **Local Density Calculation**: For each point, the algorithm calculates the local density based on the number of neighbors within a specified radius.
2. **Dynamic Threshold Adjustment**: The clustering threshold is adjusted dynamically according to the average local density of the data.
3. **Cluster Formation**: Points exceeding the dynamic threshold are grouped into clusters, while those below it are marked as noise.
4. **Cluster Merging**: Clusters that are close to each other may be merged based on their centroids.


## Usage

Once compiled, you can run the DTC algorithm on your dataset. Modify the `data` array in the `main` function to include your points.

```c
Point data[MAX_POINTS] = {
    {1.0, 2.0}, {1.1, 2.1}, {10.0, 10.0}, {10.5, 10.5}, {5.0, 5.0}
};
```

## Example

After compiling and running the program, the output will display the clustering results:

```
Clusters:
Point (1.0, 2.0) -> Cluster 0
Point (1.1, 2.1) -> Cluster 0
Point (10.0, 10.0) -> Cluster 1
Point (10.5, 10.5) -> Cluster 1
Point (5.0, 5.0) is noise
```

## Applications

- **Market Segmentation**: Grouping customers based on purchasing behavior.
- **Image Segmentation**: Identifying regions in images based on color and texture.
- **Anomaly Detection**: Detecting outliers in high-dimensional datasets.
- **Bioinformatics**: Clustering gene expression data.

