{
	ID: felikju1
	PROG: numtri
	LANG: PASCAL
}

var n,x,y:longint;
	tri:array[1..1000,1..1000] of longint;
	fin,fout:text;
	
function max(a,b:longint):longint;
	begin
		max:=a;
		if max<b then max:=b;
	end;
	
begin
	assign(fin,'numtri.in');reset(fin);
	assign(fout,'numtri.out');rewrite(fout);
	readln(fin,n);
	for y:=1 to n do
	begin
		for x:=1 to y do read(fin,tri[x,y]);
		readln(fin);
	end;
	
	for y:=n downto 2 do
		for x:=1 to y-1 do tri[x,y-1]:=tri[x,y-1]+max(tri[x,y],tri[x+1,y]);

	writeln(fout,tri[1,1]);
	close(fin);
	close(fout);
end.