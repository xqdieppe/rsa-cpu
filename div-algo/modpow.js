function modPow(b, e, m) {
	if (m == 1)
		return 0;
	var r = 1;
	b = b % m;
	while (e > 0) {
		if (e % 2 == 1) {
			r = (r*b) % m;
		}
		b = (b*b) % m;
		e = e >> 1;
	}
	return r;
}

const result = modPow(567890,4567890,75678)
console.log(result);
