{
PROG: pachinko 
LANG: PASCAL
ID: felikju1
}

var r,x,y:longint;
	pac:array[1..30,1..30] of longint;
	fin,fout:text;
	
begin
	assign(fin,'pachinko.in');reset(fin);
	assign(fout,'pachinko.out');rewrite(fout);
	readln(fin,r);
	for x:=1 to r do
	begin
		for y:=1 to x-1 do read(fin,pac[x,y]);
		readln(fin,pac[x,x]);
	end;
	
	for x:=r downto 2 do
		for y:=1 to x-1 do if pac[x,y] > pac[x,y+1] then
			pac[x-1,y]:=pac[x-1,y]+pac[x,y] else pac[x-1,y]:=pac[x-1,y]+pac[x,y+1];
			
	writeln(fout,pac[1,1]);
	close(fin);
	close(fout);
end.