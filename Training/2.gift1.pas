{
	ID: felikju1
	PROG: gift1
	LANG: PASCAL
}
type person = record
				name:string[14];
				give:integer;
				acce:integer;
				acep:array[1..10] of string;
			  end;

var m,x,y,z,sum:integer;
	namo:array[1..10] of string[14];
	money:array[1..10] of longint;
	act:array[1..10] of person;
	fin,fout:text;

begin
	assign(fin,'gift1.in');reset(fin);
	assign(fout,'gift1.out');rewrite(fout);
	readln(fin,sum);
	for x:=1 to sum do readln(fin,namo[x]);
	for x:=1 to sum do
	begin
		with act[x] do
		begin
			readln(fin,name);
			readln(fin,give,acce);
			for y:=1 to acce do readln(fin,acep[y]);
		end;
	end;
	for x:=1 to sum do money[x] := 0;
	
	for x:=1 to sum do
	begin
		with act[x] do
		begin
			for y:=1 to sum do if name = namo[y] then
			begin				
				for z:=1 to acce do
					for m:=1 to sum do if acep[z] = namo[m] then
					begin
						if acce <> 0 then  money[m] := money[m] + (give div acce);	 
						break;
					end;

				if acce <> 0 then money[y] := money[y] + (give mod acce) - give;
			end;
		end;
	end;
	
	for x:=1 to sum do
	begin
		write(fout,namo[x],' ',money[x]);
		writeln(fout);
	end;
	close(fin);
	close(fout);
end.