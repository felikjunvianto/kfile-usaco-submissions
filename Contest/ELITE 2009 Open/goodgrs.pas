{
PROG: goodgrs
LANG: PASCAL
ID: felikju1
}
var nr,nc,x,y,baris,kolom:integer;
	grid:array[1..100,1..100] of integer;
	temp,perm:longint;
	fin,fout:text;

begin
	assign(fin,'goodgrs.in');reset(fin);
	assign(fout,'goodgrs.out');rewrite(fout);
	readln(fin,nr,nc);
	for y:=1 to nr do
	begin
		for x:=1 to nc-1 do read(fin,grid[x,y]);
		readln(fin,grid[nc,y]);
	end;
	
	perm:=0;
	
	for y:=1 to nr-2 do
		for x:=1 to nc-2 do
		begin
			temp:=grid[x,y]+grid[x+1,y]+grid[x+2,y]+grid[x,y+1]+grid[x+1,y+1]+grid[x+2,y+1]+grid[x,y+2]+grid[x+1,y+2]+grid[x+2,y+2];
			if perm < temp then
			begin
				perm:=temp;
				baris:=y;
				kolom:=x;
			end;
		end;
	
	writeln(fout,perm);
	writeln(fout,baris,' ',kolom);
	close(fin);close(fout);
end.