vc<int> dsu, sz;

void init(int n) {
    dsu.resize(n, 0);
    iota(span(dsu), 0);
    sz.assign(n + 1, 1);
}

int root(int a) {
    return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) 
        return;

    if (sz[a] < sz[b]) 
        swap(a, b);

    dsu[b] = a;
    sz[a] += sz[b];
}