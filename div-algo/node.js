function div_ntime(nbr0, nbr1, pbase, cbase) {
	var v = nbr1 * cbase;
	if (nbr0 >= v && (nbr0-v) <= nbr1)
		return (cbase);
	if (nbr0 > v)
		return (div_ntime(nbr0, nbr1, cbase, cbase << 1));
	if (nbr0 < v)
		return (div_ntime(nbr0, nbr1, pbase, Math.floor((cbase + pbase) >> 1)));
}

//console.log(0xff/0xf);

function random0() {
	return Math.floor(Math.random() * 100000);
}

function random1() {
	return Math.floor(Math.random() * 100);
}

function div() {
	var d = random0();
	var d2 = random1() + 1;
	console.log(d, d2);
	console.log(div_ntime(d, d2, 0, 100000));
}

while (1) div();
