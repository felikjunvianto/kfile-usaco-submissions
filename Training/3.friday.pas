{
	ID: felikju1
	PROG: friday
	LANG: PASCAL
}

type day = (monday,tuesday,wednesday,thursday,friday,saturday,sunday);
var a,x,y:longint;
	hari: day;
	count:array[1..7] of longint;
	month:longint;
	kabisat:boolean;
	fin,fout:text;

begin
	assign(fin,'friday.in');reset(fin);
	assign(fout,'friday.out');rewrite(fout);
	readln(fin,a);
	for x:=1 to 7 do count[x] := 0;
	hari:=monday;
	
	for x:= 1900 to 1900 + a - 1 do
	begin
		kabisat:=FALSE;
		if x mod 100 = 0 then 
			if x mod 400 = 0 then kabisat:=TRUE else kabisat := FALSE
		else if x mod 4 = 0 then kabisat:= TRUE;
	
		for month:=1 to 12 do
		begin
			for y:=1 to 2 do
			begin
				if hari = monday then hari:=sunday else dec(hari);
			end;	
			case hari of
			saturday : inc(count[1]);
			sunday   : inc(count[2]);
			monday   : inc(count[3]);
			tuesday  : inc(count[4]);
			wednesday: inc(count[5]);
			thursday : inc(count[6]);
			friday   : inc(count[7]);
			end;
			
			for y:=1 to 2 do
			begin
				if hari = sunday then hari:=monday else inc(hari);
			end;
			
			case month of
			1,3,5,7,8,10,12   : begin									
									for y:=1 to 3 do
									begin
										if hari = sunday then hari:=monday else inc(hari);
									end;
								end;
			
			4,6,9,11		:	begin
									for y:= 1 to 2 do
									begin
										if hari = sunday then hari:=monday else inc(hari);
									end;
								end;
			2				:	begin
									if kabisat then 
										if hari = sunday then hari:=monday else inc(hari);
								end;
			end;
		end;
	end;
	
	for x:=1 to 6 do write(fout,count[x],' ');
	write(fout,count[7]);
	writeln(fout);
	close(fin);
	close(fout);
end.
	