class DSU {
private: vector<int> parent, rank, size;
    
public:
    DSU() {}
    DSU(int n){
        parent.assign(n + 1, 0);
        rank.assign(n + 1, 0);
        size.assign(n + 1, 1);
        iota(all(parent), 0);
    }
    
    inline int find(int a) {
        return parent[a] = (a == parent[a] ? a : find(parent[a]));
    }
    
    inline bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a == b) {
            return false;
        }
        
        if (rank[a] > rank[b]) {
            parent[b] = a;
            size[a] += size[b];
        } else {
            parent[a] = b;
            size[b] += size[a];
            
            if (rank[a] == rank[b]) {
                rank[b]++;
            }
        }
        
        return true;
    }
    
    inline int get_size(int a) {
        return size[find(a)];
    }
};
