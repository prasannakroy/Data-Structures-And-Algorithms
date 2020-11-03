auto extendedEuclid(int a, int b) {
	int x(1), x1(0), y(0), y1(1);
	while (b) {
        tie(x, x1) = make_tuple(x1, x - (a / b) * x1);
        tie(y, y1) = make_tuple(y1, y - (a / b) * y1);
        tie(a, b) = make_tuple(b, a % b);
    }
    return make_tuple(a, x, y);
}