{
	PROG: wmorph
	LANG: PASCAL
	ID: felikju1
}

var x,count:longint;
	awal,akhir:string[20];
	fin,fout:text;
	
begin
	assign(fin,'wmorph.in');reset(fin);
	assign(fout,'wmorph.out');rewrite(fout);

	readln(fin,awal);
	readln(fin,akhir);
	count:=0;
	for x:=1 to length(awal) do if awal[x]<>akhir[x] then inc(count);
	writeln(fout,count);
	close(fin);
	close(fout);
end.