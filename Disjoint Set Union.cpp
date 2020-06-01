int dsu[MX], SIZE[MX]; // MX is macro for maximum SIZE of array.

// dsu array stores the number of parent node of element.
// Initially each node is parent of itself.
// SIZE array stores the SIZE of the connnected component.
// Initially SIZE of each connected commponents is one.

// 'init' function initializes required arrays 'dsu' and 'SIZE' with initial values.
void init(int n) {
    // n is total number of nodes.
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        SIZE[i] = 1;
    }
}

// 'root' function finds root of the disjoint set.
int root(int a) {
    // a is node whose root we are finding.
    return dsu[a] == a? a: dsu[a] = root(dsu[a]);
}

// join function connects two given nodes joining two different connnected commponents.
void join(int a, int b) {
    // a and b are nodes to be connnected.
    a = root(a);
    b = root(b);
    if (a == b) return; // a and b are already part of same connected component.
    if (SIZE[a] < SIZE[b]) {
        dsu[a] = b;
        SIZE[b] += SIZE[a];
    }
    else {
        dsu[b] = a;
        SIZE[a] += SIZE[b];
    }
}