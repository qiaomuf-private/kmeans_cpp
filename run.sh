make clean && make -j
./kmeans ./glove.10k centers 3 20
python3 visualize.py centers.data centers
