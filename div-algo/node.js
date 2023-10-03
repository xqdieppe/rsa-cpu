function div_ntime(nbr0, nbr1, pbase, cbase) {
	console.log(cbase);
	var v = nbr1 * cbase;
	if (nbr0 >= v && (nbr0-v) < nbr1)
		return (cbase);
	if (nbr0 > v)
		return (div_ntime(nbr0, nbr1, cbase, cbase * 2));
	if (nbr0 < v)
		return (div_ntime(nbr0, nbr1, pbase, Math.floor((cbase + pbase) >> 1)));
}

//console.log(0xff/0xf);
console.log(div_ntime(0xffffff,0xea,0,0xffffff));
