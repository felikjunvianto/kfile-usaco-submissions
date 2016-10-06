{
	ID: felikju1
	PROG: ride
	LANG: PASCAL
}
const alfa : array[1..26] of char = ('A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z');

var comet,group:string;
    a,b:integer;
	comy,groupy:longint;
	fin,fout:text;

begin
	assign(fin,'ride.in');reset(fin);
	assign(fout,'ride.out');rewrite(fout);
	readln(fin,comet);
	readln(fin,group);
	
	comy:=1;
	groupy:=1;
	
	for a:=1 to length(comet) do
		for b:=1 to 26 do if comet[a] = alfa[b] then
		begin
			comy:=comy*b;
			break;
		end;
	
	for a:=1 to length(group) do
		for b:=1 to 26 do if group[a] = alfa[b] then
		begin
			groupy:=groupy*b;
			break;
		end;
		  
	comy:= comy mod 47;
	groupy:= groupy mod 47;
	
	if groupy = comy then writeln(fout,'GO') else writeln(fout,'STAY');
	close(fout);
	close(fin);
end.