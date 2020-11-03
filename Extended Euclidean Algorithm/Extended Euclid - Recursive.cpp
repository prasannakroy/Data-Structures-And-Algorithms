auto extendedEuclid(int a, int b) {
	if (!b) 
		return make_tuple(a, 1, 0);
	auto [d, x, y] = extendedEuclid(b, a % b);
	return make_tuple(d, y, x - (a / b) * y);
}