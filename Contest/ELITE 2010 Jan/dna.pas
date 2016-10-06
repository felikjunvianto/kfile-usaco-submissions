{
	PROG: dna
	LANG: PASCAL
	ID: felikju1
}
var a,m,f,x,y,z,count:longint;
	sapi:array[1..40] of string[25];
	fin,fout:text;

begin
	assign(fin,'dna.in');reset(fin);
	assign(fout,'dna.out');rewrite(fout);
	readln(fin,m,f);
	for x:=1 to m+f do readln(fin,sapi[x]);
	
	for x:=1 to m do
	begin
		for y:=m+1 to m+f do
		begin
			count:=0;
			
			for a:=1 to m+f do 
			begin
				if ((a<>x)and(a<>y))then
				begin
					for z:=1 to 25 do if ((sapi[a,z]<>sapi[x,z])and(sapi[a,z]<>sapi[y,z])) then break;

				if z=25 then 
					if ((sapi[a,z]=sapi[x,z])and(sapi[a,z]=sapi[y,z])) then inc(count);
					
				end;
			end;
			if y<m+f then write(fout,count,' ') else write(fout,count);
		end;
		writeln(fout);
	end;
	close(fin);
	close(fout);
end.