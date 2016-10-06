{
PROG: evenodd  
LANG: PASCAL
ID: felikju1
}

var n,x,y,temp:longint;
	i:array[1..110] of string;
	fin,fout:text;
	
begin
	assign(fin,'evenodd.in');reset(fin);
	assign(fout,'evenodd.out');rewrite(fout);
	readln(fin,n);
	for x:=1 to n do readln(fin,i[x]);
	for x:=1 to n do
	begin
		val(i[x,length(i[x])],temp,y);
		if temp mod 2 = 0 then writeln(fout,'even') else writeln(fout,'odd');
	end;
	close(fin);
	close(fout);
end.