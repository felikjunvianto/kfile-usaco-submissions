{
	ID: felikju1
	PROG: sprime
	LANG: PASCAL
}

const awal:array[1..4] of longint =(2,3,5,7);

var n:longint;
	fin,fout:text;
	
procedure ribs(t,bil:longint);
	var x,y:longint;
		temp:longint;
		prime:boolean;
		
	begin
		if t=n+1 then writeln(fout,bil) else
			if t=1 then for y:=1 to 4 do ribs(t+1,awal[y])
				else for y:=1 to 9 do if odd(y) then
				begin
					temp:=(bil*10)+y;
					prime:=TRUE;
					for x:=2 to trunc(sqrt(temp)) do if temp mod x = 0 then
					begin
						prime:=FALSE;
						break;
					end;
					if prime then ribs(t+1,temp);
				end;
	end;
	
begin
	assign(fin,'sprime.in');reset(fin);
	assign(fout,'sprime.out');rewrite(fout);
	readln(fin,n);
	ribs(1,0);
	close(fin);
	close(fout);
end.
