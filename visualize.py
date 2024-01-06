import sys
import numpy as np
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

data_with_labels = np.loadtxt(sys.argv[1], delimiter=' ')
data = data_with_labels[:, :-1] 
labels = data_with_labels[:, -1]
cluster_centers = np.loadtxt(sys.argv[2], delimiter=' ')[:, :-1]

pca = PCA(n_components=2)
data_reduced = pca.fit_transform(data)
cluster_centers_reduced = pca.transform(cluster_centers)

plt.figure(figsize=(10, 8))
unique_labels = np.unique(labels)

for label in unique_labels:
    plt.scatter(data_reduced[labels == label, 0], data_reduced[labels == label, 1], alpha=0.5, label=f'Cluster {label}')

plt.scatter(cluster_centers_reduced[:, 0], cluster_centers_reduced[:, 1], c='black', marker='X', s=100, label='Centers')

plt.title('KMeans Clustering Visualization with PCA')
plt.xlabel('PCA Component 1')
plt.ylabel('PCA Component 2')
plt.legend()
plt.show()

