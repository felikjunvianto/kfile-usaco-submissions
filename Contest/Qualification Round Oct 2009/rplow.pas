{
PROG: rplow 
LANG: PASCAL
ID: felikju1
}

type coor=record
		  xi,yi,xf,yf:longint;
		  end;
		  
var x,y,i,a,b,c,counter:longint;
	task:array[1..210] of coor;
	ladang:array[1..250,1..250] of char;
	fin,fout:text;
	
begin
	assign(fin,'rplow.in');reset(fin);
	assign(fout,'rplow.out');rewrite(fout);
	readln(fin,x,y,i);
	for a:=1 to i do readln(fin,task[a].xi,task[a].yi,task[a].xf,task[a].yf);
	
	for a:=1 to x do
		for b:=1 to y do ladang[a,b]:='.';
		
	for a:=1 to i do
	begin
		for b:=task[a].yi to task[a].yf do 
			for c:=task[a].xi to task[a].xf do ladang[c,b]:='#';
	end;
	counter:=0;
	for a:=1 to y do
		for b:=1 to x do if ladang[b,a] ='#' then inc(counter);
	
	writeln(fout,counter);
	close(fin);
	close(fout);
end.