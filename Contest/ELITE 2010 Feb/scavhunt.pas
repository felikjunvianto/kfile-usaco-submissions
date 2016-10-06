{
PROG: scavhunt
LANG: PASCAL
ID: felikju1
}

var x,y,p,q,count_p,count_q:longint;
	factor_p,factor_q:array[1..100] of longint;
	fin,fout:text;
	
begin
	assign(fin,'scavhunt.in');reset(fin);
	assign(fout,'scavhunt.out');rewrite(fout);
	readln(fin,p,q);
	count_p:=0;
	count_q:=0;
	for x:=1 to p do if p mod x=0 then
	begin
		inc(count_p);
		factor_p[count_p]:=x;
	end;
	for x:=1 to q do if q mod x=0 then
	begin
		inc(count_q);
		factor_q[count_q]:=x;
	end;
	
	for x:=1 to count_p do
		for y:=1 to count_q do writeln(fout,factor_p[x],' ',factor_q[y]);
	close(fin);
	close(fout);
end.