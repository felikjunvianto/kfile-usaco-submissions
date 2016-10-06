{
PROG: kcow
LANG: PASCAL
ID: felikju1
}

var x,y,a,b,coba,count,sumbux,sumbuy:longint;
	peta:array[1..510,1..510] of char;
	fin,fout:text;

procedure jalan(axis,ordinat:longint);
	begin
		if((axis<=0)or(axis>x)or(ordinat<=0)or(ordinat>y)or(peta[axis,ordinat]='*'))then dec(coba) else
		begin
			if peta[axis,ordinat] ='H' then count:=coba else
			begin
				peta[axis,ordinat]:='*';
				inc(coba);
				jalan(axis+2,ordinat+1);
				inc(coba);
				jalan(axis+2,ordinat-1);
				inc(coba);
				jalan(axis+1,ordinat-2);
				inc(coba);
				jalan(axis-1,ordinat-2);
				inc(coba);
				jalan(axis-2,ordinat-1);
				inc(coba);
				jalan(axis-2,ordinat+1);
				inc(coba);
				jalan(axis-1,ordinat+2);
				inc(coba);
				jalan(axis+1,ordinat+2);
			end;
		end;
	end;
	
begin
	assign(fin,'kcow.in');reset(fin);
	assign(fout,'kcow.out');rewrite(fout);
	readln(fin,x,y);
	for a:=1 to y do
	begin
		for b:=1 to x-1 do 
		begin
			read(fin,peta[b,a]);
			if peta[b,a]='K' then 
			begin
				sumbux:=b;
				sumbuy:=a;
			end;
		end;
		
		readln(fin,peta[x,a]);
		if peta[x,a]='K' then 
		begin
			sumbux:=x;
			sumbuy:=a;
		end;
	end;
	coba:=0;
	jalan(sumbux,sumbuy);
	writeln(fout,count);
	close(fin);
	close(fout);
end.	