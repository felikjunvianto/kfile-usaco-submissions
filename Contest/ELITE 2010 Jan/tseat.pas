{
	PROG: tseat
	LANG: PASCAL
	ID: felikju1
}
type prior=record
	 nilai:qword;
	 status:string;
	 baris,kolom:longint;
	 end;
	
var w,r,x,y,z,a:longint;
	atas,samping:qword;
	seat:array[1..101,1..50] of longint;
	baca:array[1..5050] of prior;
	fin,fout:text;
	
procedure quick(terkiri,terkanan:integer);
	var kiri,kanan:integer;
		pivot:qword;
		temp:prior;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=baca[(kiri+kanan) div 2].nilai;
			while kiri<=kanan do
			begin
				while baca[kiri].nilai < pivot do inc(kiri);
				while baca[kanan].nilai > pivot do dec(kanan);
			
				if kiri<=kanan then
				begin
					temp:=baca[kiri];
					baca[kiri]:=baca[kanan];
					baca[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			quick(terkiri,kanan);
			quick(kiri,terkanan);
		end;
	end;
	
procedure sorttempat(terkiri,terkanan:integer);
	var kiri,kanan:integer;
		pivot:qword;
		temp:prior;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=baca[(kiri+kanan) div 2].baris;
			while kiri<=kanan do
			begin
				while baca[kiri].baris < pivot do inc(kiri);
				while baca[kanan].baris > pivot do dec(kanan);
			
				if kiri<=kanan then
				begin
					temp:=baca[kiri];
					baca[kiri]:=baca[kanan];
					baca[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			sorttempat(terkiri,kanan);
			sorttempat(kiri,terkanan);
		end;
	end;	
	
procedure tukarkaki(mulai,selesai:longint);
	var temp:prior;
		x:longint;
		
	begin
		for x:=mulai to selesai-1 do 
			if(baca[x].baris=baca[x+1].baris) then
				if((baca[x].status='kanan') and (baca[x+1].status='kiri')) then
				begin
					temp:=baca[x];
					baca[x]:=baca[x+1];
					baca[x+1]:=temp;
				end;
	end;
	
begin
	assign(fin,'tseat.in');reset(fin);
	assign(fout,'tseat.out');rewrite(fout);
	readln(fin,w,r);
	z:=0;

	for x:=1 to w div 2 do
		for y:=1 to r do 
		begin
				inc(z);
				samping:=(w div 2)+1-x;
				atas:=(y-1);
				baca[z].nilai:=samping*samping+atas*atas;
				baca[z].status:='kiri';
				baca[z].kolom:=x;
				baca[z].baris:=y;
		end;
	
	for x:=(w div 2)+2 to w do
		for y:=1 to r do 
		begin
				inc(z);
				samping:=x-((w div 2)+1);
				atas:=(y-1);
				baca[z].nilai:=samping*samping+atas*atas;
				baca[z].status:='kanan';
				baca[z].kolom:=x;
				baca[z].baris:=y;
		end;
	
	for x:=1 to r do 
	begin
		inc(z);
		baca[z].status:='tengah';
		baca[z].kolom:=(w div 2)+1;
		baca[z].baris:=x;
		baca[z].nilai:=(x-1)*(x-1);
	end;
	
	quick(1,z);
	y:=0;
	repeat
		inc(y);
		a:=y+1;
		if baca[a].nilai=baca[y].nilai then 
		begin
			while ((baca[a].nilai=baca[y].nilai) and (a<=w*r)) do inc(a);
			dec(a);
			sorttempat(y,a);
			tukarkaki(y,a);
		end else dec(a);
		y:=a;
	until y=w*r;
	
	for x:=1 to z do seat[(baca[x].kolom),(baca[x].baris)]:=x;
	
	for y:=r downto 1 do
	begin
		for x:=1 to w-1 do write(fout,seat[x,y],' ');
		writeln(fout,seat[w,y]);
	end;
	close(fin);
	close(fout);
end.