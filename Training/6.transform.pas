{
	ID: felikju1
	PROG: transform
	LANG: PASCAL
}

var n,x,y,z,transform:longint;
	awal,temp,akhir:array[1..10,1..10] of char;
	semen:char;
	fin,fout:text;
	benar:boolean;

begin
	assign(fin,'transform.in');reset(fin);
	assign(fout,'transform.out');rewrite(fout);
	readln(fin,n);
	for y:=1 to n do 
	begin
		for x:=1 to n-1 do read(fin,awal[x,y]);
		readln(fin,awal[n,y]);
	end;
	
	for y:=1 to n do 
	begin
		for x:=1 to n-1 do read(fin,akhir[x,y]);
		readln(fin,akhir[n,y]);
	end;

	transform:=7;
	benar:=TRUE;
	
	for x:=1 to n do
	begin
		for y:=1 to n do if awal[x,y] <> akhir[x,y] then
		begin
			benar:=FALSE;
			break;
		end;
		if not(benar) then break;
	end;
	
	if benar then transform:=6;
	
	for z:=1 to 3 do
	begin
		for x:=1 to n do
			for y:=1 to n do temp[n+1-y,x]:=awal[x,y];
			
		for x:=1 to n do
			for y:=1 to n do awal[x,y]:=temp[x,y];
		
		benar:=TRUE;
		for x:=1 to n do
		begin
			for y:=1 to n do if awal[x,y] <> akhir[x,y] then
			begin
				benar:=FALSE;
				break;
			end;
			if not(benar) then break;
		end;
		
		if benar then
		begin
			transform:=z;
			break;
		end;
	end;
	
	if transform >= 6 then
	begin
		for x:=1 to n do
			for y:=1 to n do temp[n+1-y,x]:=awal[x,y];
			
		for x:=1 to n do
			for y:=1 to n do awal[x,y]:=temp[x,y];
		
		for y:=1 to n do
			for x:=1 to n div 2 do
			begin
				semen:=awal[x,y];
				awal[x,y]:=awal[n+1-x,y];
				awal[n+1-x,y]:=semen;
			end;
		
		benar:=TRUE;
		for x:=1 to n do
		begin
			for y:=1 to n do if awal[x,y] <> akhir[x,y] then
			begin
				benar:=FALSE;
				break;
			end;
			if not(benar) then break;
		end;
	
		if benar then transform:=4;
	end;
	
	if transform >=6 then
	begin
		for z:=1 to 3 do
		begin
			for x:=1 to n do
				for y:=1 to n do temp[n+1-y,x]:=awal[x,y];
			
			for x:=1 to n do
				for y:=1 to n do awal[x,y]:=temp[x,y];
			
			benar:=TRUE;
			for x:=1 to n do
			begin
				for y:=1 to n do if awal[x,y] <> akhir[x,y] then
				begin
					benar:=FALSE;
					break;
				end;
				if not(benar) then break;
			end;
		
			if benar then
			begin
				transform:=5;
				break;
			end;
		end;
	end;
	
	writeln(fout,transform);
	close(fin);
	close(fout);
end.