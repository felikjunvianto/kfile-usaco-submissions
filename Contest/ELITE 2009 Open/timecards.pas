{
PROG: timecards
LANG: PASCAL
ID: felikju1
}

var n,nbaris,x,y,z:longint;
	stri:string;
	command,key:array[1..1458] of string;
	cow,hour,minute:array[1..1458] of longint;
	timeh,timem,temp:array[1..145] of longint;
	fin,fout:text;

begin
	assign(fin,'timecards.in');reset(fin);
	assign(fout,'timecards.out');rewrite(fout);
	readln(fin,n,nbaris);
	for x:=1 to nbaris do readln(fin,command[x]);
	for x:=1 to nbaris do
	begin
		z:=pos(' ',command[x]);
		stri:=copy(command[x],1,z-1);
		val(stri,cow[x],y);
		delete(command[x],1,z);
		
		z:=pos(' ',command[x]);
		key[x]:=copy(command[x],1,z-1);
		delete(command[x],1,z);
		
		z:=pos(' ',command[x]);
		delete(stri,1,length(stri));
		stri:=copy(command[x],1,z-1);
		val(stri,hour[x],y);
		delete(command[x],1,z);
		val(command[x],minute[x],y);
		delete(stri,1,length(stri));
	end;
	
	for x:=1 to n do temp[x] := 0;
	
	for x:=1 to nbaris do if key[x] = 'START' then
	begin
		for y:=x to nbaris do if (cow[y] = cow[x]) and (key[y] = 'STOP') then
		begin
			temp[cow[x]]:= temp[cow[x]] + ((hour[y]*60 + minute[y]) - (hour[x]*60 + minute[x]));
			break;
		end;
	end;
	
	for x:=1 to n do
	begin
		timeh[x]:=temp[x] div 60;
		timem[x]:=temp[x] mod 60;
		writeln(fout,timeh[x],' ',timem[x]);
	end;
	close(fin);close(fout);
end.