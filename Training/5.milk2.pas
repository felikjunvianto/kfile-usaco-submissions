{
	ID: felikju1
	PROG: milk2
	LANG: PASCAL
}
type cow=record
		 time:longint;
		 status:string;
		 end;

var n,x,y,count,max,min:longint;
	kerja:array[1..10000] of cow;
	fin,fout:text;
	
procedure quicksort(terkiri,terkanan:longint);
	var pivot,kiri,kanan:longint;
		temp:cow;
	begin
		if terkiri <terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=kerja[(kiri+kanan) div 2].time;
			
			while kiri<=kanan do
				begin
				while kerja[kiri].time < pivot do inc(kiri);
				while kerja[kanan].time > pivot do dec(kanan);
			
				if kiri<=kanan then
					begin
						temp:=kerja[kiri];
						kerja[kiri]:=kerja[kanan];
						kerja[kanan]:=temp;
						inc(kiri);
						dec(kanan);
					end;
				end;
			quicksort(terkiri,kanan);
			quicksort(kiri,terkanan);
		end;
	end;
	
begin
	assign(fin,'milk2.in');reset(fin);
	assign(fout,'milk2.out');rewrite(fout);
	
	readln(fin,n);
	for x:=1 to n do
	begin
		read(fin,kerja[2*x-1].time);kerja[2*x-1].status:='START';
		readln(fin,kerja[2*x].time);kerja[2*x].status:='STOP';
	end;
	
	quicksort(1,2*n);
	x:=1;
	y:=0;
	count:=0;
	max:=0;
	min:=0;
	while x < 2*n do
	begin
		repeat
			inc(y);
			if kerja[y].status='START' then inc(count) else dec(count);
			if count=0 then
				if kerja[y+1].time = kerja[y].time then 
				begin
					inc(count);
					inc(y);
				end;
		until count=0;
		if kerja[y].time-kerja[x].time > max then max:=kerja[y].time-kerja[x].time;
		x:=y+1;
		if kerja[x].time-kerja[y].time > min then min:=kerja[x].time-kerja[y].time;
	end;
	
	
	writeln(fout,max,' ',min);
	close(fin);
	close(fout);
end.