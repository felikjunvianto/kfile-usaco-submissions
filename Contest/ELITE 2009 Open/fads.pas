{
PROG: fads
LANG: PASCAL
ID: felikju1
}

var n,l,k:int64;
	x,y,z,temp:longint;
	r:array[1..100000] of longint;
	fin,fout:text;
	
begin
	assign(fin,'fads.in');reset(fin);
	assign(fout,'fads.out');rewrite(fout);
	readln(fin,n,l,k);
	for x:=1 to n do readln(fin,r[x]);
	
	for x:=1 to n do
		for y:=n downto x+1 do 
		begin
			if r[y] < r[y-1] then
			begin
				temp:=r[y];
				r[y]:=r[y-1];
				r[y-1]:=temp;
			end;
		end;
	z:=0;
	
	for x:=1 to n do if r[x] <= l then
	begin
		l:=l+k;
		inc(z);
	end;
	writeln(fout,z);
	close(fin);close(fout);
end.