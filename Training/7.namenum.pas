{
	ID: felikju1
	PROG: namenum
	LANG: PASCAL
}

var t,x,y,z,a:longint;
	number,temp,semen:string;
	data:array[1..5000] of string;
	fin,fout,database:text;
	benar:boolean;
	
begin
	
	assign(fin,'namenum.in');reset(fin);
	assign(fout,'namenum.out');rewrite(fout);

	readln(fin,number);
	close(fin);
	assign(database,'dict.txt');reset(database);
	z:=0;
	for x:=1 to 4617 do
	begin
		readln(database,temp);
		benar:=true;
		for y:=1 to length(temp) do if((temp[y] = 'Q') or (temp[y]='Z')) then
		begin
			benar:=false;
			break;
		end;
		if benar then
			if length(temp)=length(number) then
			begin
				inc(z);
				data[z]:=temp;
			end;
	end;
	t:=0;
	close(database);
	
	while t < length(number) do
	begin
		inc(t);
		case ord(number[t])-48 of
		2 : temp:='ABC';
		3 : temp:='DEF';
		4 : temp:='GHI';
		5 : temp:='JKL';
		6 : temp:='MNO';
		7 : temp:='PRS';
		8 : temp:='TUV';
		9 : temp:='WXY';
		end;
		
		y:=0;
		for x:=1 to z do 
		begin
			a:=pos(data[x,t],temp);
			if a = 0 then continue else 
			begin
				inc(y);
				semen:=data[y];
				data[y]:=data[x];
				data[x]:=semen;
			end;
		end;
		z:=y;
	end;
	if z=0 then writeln(fout,'NONE') else for x:=1 to z do writeln(fout,data[x]);
	close(fout);
end.