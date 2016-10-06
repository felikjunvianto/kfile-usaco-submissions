{
PROG: papaya
LANG: PASCAL
ID: felikju1
}
var x,y,a,b,koorx,koory,counter:longint;
	kebun:array[1..50,1..50] of longint;
	fin,fout:text;

begin
	assign(fin,'papaya.in');reset(fin);
	assign(fout,'papaya.out');rewrite(fout);
	readln(fin,y,x);
	for a:=1 to y do
	begin
		for b:=1 to x-1 do read(fin,kebun[b,a]);
		readln(fin,kebun[b,x]);
	end;
	
	koorx:=1;
	koory:=1;
	counter:=0;
	while ((koorx <>x)and(koory<>y)) do
	begin
		if((koorx=1)and(koory=1)) then
		begin
			if (kebun[koorx+1,koory] > kebun[koorx,koory+1]) then
			begin
				counter:=counter+kebun[koorx+1,koory];
				koorx:=koorx+1;
			end
			else
			begin	
				counter:=counter+kebun[koorx,koory+1];
				koory:=koory+1;
			end;
		end
		
		else if(koorx=1) then
		begin
			if ((kebun[koorx,koory-1] > kebun[koorx+1,koory]) and (kebun[koorx,koory-1] > kebun[koorx,koory+1])) then
			begin
				counter:=counter+kebun[koorx,koory-1];
				koory:=koory-1;
			end
			else if((kebun[koorx+1,koory] > kebun[koorx,koory-1])and(kebun[koorx+1,koory] > kebun[koorx,koory+1])) then
			begin
				counter:=counter+kebun[koorx+1,koory];
				koorx:=koorx+1;
			end
			else
			begin
				counter:=counter+kebun[koorx,koory+1];
				koory:=koory+1;
			end;
		end
		
		else if ((koorx=1) and (koory=y)) then
		begin
			if((kebun[koorx,koory-1]) > (kebun[koorx+1,koory])) then
			begin
				counter:=counter+kebun[koorx,koory-1];
				koory:=koory-1;
			end
			else
			begin
				counter:=counter+kebun[koorx+1,koory];
				koorx:=koorx+1;
			end;
		end
		
		else if(koory=1) then
		begin
			if((kebun[koorx-1,koory] > kebun[koorx,koory+1])and(kebun[koorx-1,koory] > kebun[koorx+1,koory])) then
			begin
				counter:=counter+kebun[koorx-1,koory];
				koorx:=koorx-1;
			end
			else if((kebun[koorx,koory+1] > kebun[koorx-1,koory]) and (kebun[koorx,koory+1] > kebun[koorx+1,koory])) then
			begin
				counter:=counter+kebun[koorx,koory+1];
				koory:=koory+1;
			end
			else
			begin
				counter:=counter+kebun[koorx+1,koory];
				koorx:=koorx+1;
			end;
		end
		
		else if(koory=y) then
		begin
			if((kebun[koorx-1,koory] > kebun[koorx,koory-1])and(kebun[koorx-1,koory] > kebun[koorx+1,koory])) then
			begin
				counter:=counter+kebun[koorx-1,koory];
				koorx:=koorx-1;
			end
			else if((kebun[koorx,koory-1] > kebun[koorx-1,koory])and(kebun[koorx,koory-1] > kebun[koorx+1,koory])) then
			begin
				counter:=counter+kebun[koorx,koory-1];
				koory:=koory-1;
			end
			else
			begin
				counter:=counter+kebun[koorx+1,koory];
				koorx:=koorx+1;
			end;
		end
		
		else if((koorx=x)and(koory=1))then
		begin
			if(kebun[koorx-1,koory] > kebun[koorx,koory+1]) then
			begin
				counter:=counter+kebun[koorx-1,koory];
				koorx:=koorx-1;
			end
			else
			begin
				counter:=counter+kebun[koorx,koory+1];
				koory:=koory+1;
			end;
		end
		
		else if(koorx=x) then
		begin
			if((kebun[koorx,koory-1]>kebun[koorx-1,koory])and(kebun[koorx,koory-1]>kebun[koorx,koory+1])) then
			begin
				counter:=counter+kebun[koorx,koory-1];
				koory:=koory-1;
			end
			else if((kebun[koorx-1,koory]>kebun[koorx,koory-1])and(kebun[koorx-1,koory]>kebun[koorx,koory+1]))then
			begin
				counter:=counter+kebun[koorx-1,koory];
				koorx:=koorx-1;
			end
			else
			begin
				counter:=counter+kebun[koorx,koory+1];
				koory:=koory+1;
			end;
		end
		
		else if((koorx=x)and(koory=y)) then
		begin
			if(kebun[koorx,koory-1] > kebun[koorx-1,koory]) then
			begin
				counter:=counter+kebun[koorx,koory-1];
				koory:=koory-1;
			end
			else
			begin
				counter:=counter+kebun[koorx-1,koory];
				koorx:=koorx-1;
			end;
		end
		
		else
		begin
			if((kebun[koorx,koory-1]>kebun[koorx+1,koory])and(kebun[koorx,koory-1]>kebun[koorx,koory+1])and(kebun[koorx,koory-1]>kebun[koorx-1,koory]))then
			begin
				counter:=counter+kebun[koorx,koory-1];
				koory:=koory-1;
			end
			else if ((kebun[koorx+1,koory]>kebun[koorx,koory-1])and(kebun[koorx+1,koory]>kebun[koorx-1,koory])and(kebun[koorx+1,koory]>kebun[koorx,koory+1])) then
			begin
				counter:=counter+kebun[koorx+1,koory];
				koorx:=koorx+1;
			end
			else if((kebun[koorx,koory+1]>kebun[koorx,koory-1])and(kebun[koorx,koory+1]>kebun[koorx+1,koory])and(kebun[koorx,koory+1]>kebun[koorx-1,koory])) then
			begin
				counter:=counter+kebun[koorx,koory+1];
				koory:=koory+1;
			end
			else
			begin
				counter:=counter+kebun[koorx-1,koory];
				koorx:=koorx-1;
			end;
		end;
		kebun[koorx,koory]:=0;
	end;
	writeln(fout,counter);
	close(fin);
	close(fout);
end.