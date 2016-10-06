{
	ID: felikju1
	PROG: milk3
	LANG: PASCAL
}
var x,count:longint;
	sisa:array[0..20] of boolean;
	kondisi:array[1..1000] of string[9];
	gelasA,gelasB,gelasC:longint;
	fin,fout:text;

function min(a,b:longint):longint;
	begin
		min:=a;
		if min>b then min:=b;
	end;
	
procedure cari(isiA,isiB,isiC,n:longint);
	var temp,x:longint;
		temp1,temp2,temp3,cek:string;
		sudah:boolean;
		
	begin
		str(isiA,temp1);
		str(isiB,temp2);
		str(isiC,temp3);
		cek:=temp1+' '+temp2+' '+temp3;
		sudah:=FALSE;
		for x:=1 to count do if cek=kondisi[x] then
		begin
			sudah:=TRUE;
			break;
		end;
				
		if not(sudah) then
		begin
			inc(count);
			kondisi[count]:=cek;
			if ((isiA=0) and (sisa[isiC]=FALSE)) then sisa[isiC]:=TRUE;
			
			//C tuang ke A
			if ((isiA<gelasA)and(isiC>0)) then 
			begin
				temp:=min(isiA+isiC,gelasA);
				cari(temp,isiB,isiC-(temp-isiA),n+1);
			end;
			
			//C tuang ke B
			if ((isiB<gelasB)and(isiC>0)) then 
			begin
				temp:=min(isiB+isiC,gelasB);
				cari(isiA,temp,isiC-(temp-isiB),n+1);
			end;
			
			//B tuang ke A
			if ((isiA<gelasA)and(isiB>0)) then 
			begin
				temp:=min(isiA+isiB,gelasA);
				cari(temp,isiB-(temp-isiA),isiC,n+1);
			end;
			
			//B tuang ke C
			if ((isiC<gelasC)and(isiB>0)) then 
			begin
				temp:=min(isiC+isiB,gelasC);
				cari(isiA,isiB-(temp-isiC),temp,n+1);
			end;
			
			//A tuang ke B
			if ((isiB<gelasB)and(isiA>0)) then 
			begin
				temp:=min(isiB+isiA,gelasB);
				cari(isiA-(temp-isiB),temp,isiC,n+1);
			end;
			
			//A tuang ke C
			if ((isiC<gelasC)and(isiA>0)) then 
			begin
				temp:=min(isiC+isiA,gelasC);
				cari(isiA-(temp-isiC),isiB,temp,n+1);
			end;
		end;
	end;
	
begin
	assign(fin,'milk3.in');reset(fin);
	assign(fout,'milk3.out');rewrite(fout);
	readln(fin,gelasA,gelasB,gelasC);
	
	fillchar(sisa,sizeof(sisa),FALSE);
	count:=0;
	cari(0,0,gelasC,0);
	
	for x:=0 to gelasC do if sisa[x] then
	begin
		write(fout,x);
		if x<gelasC then write(fout,' ');
	end;
	writeln(fout);
	
	close(fin);
	close(fout);
end.