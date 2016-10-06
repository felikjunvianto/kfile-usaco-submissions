{
	PROG: feedtime
	LANG: PASCAL
	ID: felikju1
}

var samping,bawah,x,y,max,temp:longint;
	farm:array[1..750,1..750] of char;
	fin,fout:text;
	
procedure rumput(x,y:longint);
	var ver,hor:longint;
	
	begin
		farm[x,y]:='#';
		inc(temp);
		
		for ver:=-1 to 1 do
			for hor:=-1 to 1 do
				if((ver<>0)or(hor<>0)) then
					if((x+hor>=1)and(x+hor<=samping)and(y+ver>=1)and(y+ver<=bawah)) then
						if farm[x+hor,y+ver]='.' then rumput(x+hor,y+ver);
	end;
	
begin
	assign(fin,'feedtime.in');reset(fin);
	assign(fout,'feedtime.out');rewrite(fout);
	readln(fin,samping,bawah);
	fillchar(farm,sizeof(farm),'*');
	for y:=1 to bawah do
	begin
		for x:=1 to samping do read(fin,farm[x,y]);
		readln(fin);
	end;
	max:=0;
	
	for y:=1 to bawah do
		for x:=1 to samping do if farm[x,y]='.' then
		begin
			temp:=0;
			rumput(x,y);
			if temp>max then max:=temp;
		end;
	writeln(fout,max);
	close(fin);
	close(fout);
end.