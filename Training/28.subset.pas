{
	ID: felikju1
	PROG: subset
	LANG: PASCAL
}

var n,sum,x,y:longint;
	dp:array[0..750] of longword;
	fin,fout:text;
	
begin
	assign(fin,'subset.in');reset(fin);
	assign(fout,'subset.out');rewrite(fout);
	readln(fin,n);
	sum:=n*(n+1) div 2;
	fillchar(dp,sizeof(dp),0);
	dp[0]:=1;
	if odd(sum) then writeln(fout,'0') else
	begin
		for x:=1 to n do
			for y:=sum div 2 downto x do dp[y]:=dp[y]+dp[y-x];
		writeln(fout,dp[sum div 2] div 2);
	end;
	close(fin);
	close(fout);
end.