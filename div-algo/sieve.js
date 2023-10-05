function divlist(num, list) {
	for (var i = 0; i < list.length; i++) {
		if ((num % list[i]) == 0)
			return (0);
	}
	return (1);
}

function eratosthene(n) {
	var list = [2];

	for (var i = 3; i < n; i++) {
		if (divlist(i, list) == 1)
			list.push(i);
	}
	console.log(list.map(e => `if (upseudoprime_pretest(prime, ${e}, bits)) return (0);`).join('\n'))
}

eratosthene(5000);
