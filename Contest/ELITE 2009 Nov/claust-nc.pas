{
PROG: claust
LANG: PASCAL
ID: felikju1
}
type koordinat = record
	 sumbux:longint;
	 sumbuy:longint;
	 end;

var n,x,y,sapi1,sapi2:longint;
	cow:array[1..2010] of koordinat;
	terpendek,temp:longint;
	fin,fout:text;

function kuadrat(x:longint):longint;
	begin
		kuadrat:=x*x;
	end;
	
begin
	assign(fin,'claust.in');reset(fin);
	assign(fout,'claust.out');rewrite(fout);
	readln(fin,n);
	for x:=1 to n do readln(fin,cow[x].sumbux,cow[x].sumbuy);
	
	terpendek:=(kuadrat(cow[1].sumbux-cow[2].sumbux)+kuadrat(cow[1].sumbuy-cow[2].sumbuy));
	sapi1:=1;
	sapi2:=2;
	
	for x:=1 to n do
		for y:=x+1 to n do
		begin
			temp:=(kuadrat(cow[x].sumbux-cow[y].sumbux)+kuadrat(cow[x].sumbuy-cow[y].sumbuy));
			if temp < terpendek then
			begin
				terpendek:=temp;
				sapi1:=x;
				sapi2:=y;
			end;
		end;
		
	writeln(fout,sapi1,' ',sapi2);
	close(fin);
	close(fout);
end.