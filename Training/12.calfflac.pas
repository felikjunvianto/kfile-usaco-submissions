{
	ID: felikju1
	PROG: calfflac
	LANG: PASCAL
}

var kalimat:array[1..80100] of char;
	x,y,awal,akhir,longest,tes1,tes2,alpha,omega,temp,temp_awal,temp_akhir:longint;
	fin,fout:text;
	
begin
	assign(fin,'calfflac.in');reset(fin);
	assign(fout,'calfflac.out');rewrite(fout);
	x:=0;
	while not(eof(fin)) do
	begin
		inc(x);
		read(fin,kalimat[x]);
	end;

	longest:=0;
	for y:=2 to x-1 do
	begin
		if ((ord(kalimat[y])>=65) and (ord(kalimat[y])<>91) and (ord(kalimat[y])<>123)) then
		begin
			temp:=1;
			awal:=y-1;
			akhir:=y+1;
		
			repeat
			if awal>1 then while((ord(kalimat[awal])<65) or (ord(kalimat[awal])=91) or (ord(kalimat[awal])=92) or (ord(kalimat[awal])=124) or (ord(kalimat[awal])=123) or (ord(kalimat[awal])=93) or (ord(kalimat[awal])=125)) do dec(awal);
			if akhir<x then while((ord(kalimat[akhir])<65) or (ord(kalimat[akhir])=91) or (ord(kalimat[akhir])=92) or (ord(kalimat[akhir])=124) or (ord(kalimat[akhir])=123) or (ord(kalimat[akhir])=93) or (ord(kalimat[akhir])=125)) do inc(akhir);
			if ord(kalimat[awal]) <97 then tes1:=ord(kalimat[awal])+32 else tes1:=ord(kalimat[awal]);
			if ord(kalimat[akhir]) <97 then tes2:=ord(kalimat[akhir])+32 else tes2:=ord(kalimat[akhir]);
			if abs(tes1-tes2)=0 then
			begin
				inc(temp,2);
				temp_awal:=awal;
				temp_akhir:=akhir;
				if awal>1 then dec(awal) else break;
				if akhir<x then inc(akhir) else break;
			end;
			until abs(tes1-tes2)<>0;
		
			if temp>longest then 
			begin
				longest:=temp;
				alpha:=temp_awal;
				omega:=temp_akhir;
			end;
			
			if ((ord(kalimat[y])>=65) and (ord(kalimat[y])<>91) and (ord(kalimat[y])<>123)) then
			begin
				temp:=0;
				awal:=y;
				akhir:=y+1;
				repeat
				if awal>1 then while((ord(kalimat[awal])<65) or (ord(kalimat[awal])=91) or (ord(kalimat[awal])=92) or (ord(kalimat[awal])=124) or (ord(kalimat[awal])=123) or (ord(kalimat[awal])=93) or (ord(kalimat[awal])=125)) do dec(awal);
				if akhir<x then while((ord(kalimat[akhir])<65) or (ord(kalimat[akhir])=91) or (ord(kalimat[akhir])=92) or (ord(kalimat[akhir])=124) or (ord(kalimat[akhir])=123) or (ord(kalimat[akhir])=93) or (ord(kalimat[akhir])=125)) do inc(akhir);
				if ord(kalimat[awal]) <97 then tes1:=ord(kalimat[awal])+32 else tes1:=ord(kalimat[awal]);
				if ord(kalimat[akhir]) <97 then tes2:=ord(kalimat[akhir])+32 else tes2:=ord(kalimat[akhir]);
				if abs(tes1-tes2)=0 then
				begin
					inc(temp,2);
					temp_awal:=awal;
					temp_akhir:=akhir;
					if awal>1 then dec(awal) else break;
					if akhir<x then inc(akhir) else break;
				end;
				until abs(tes1-tes2)<>0;
				
				if temp>longest then 
				begin
					longest:=temp;
					alpha:=temp_awal;
					omega:=temp_akhir;
				end;
				
			end;
		end;
	end;
	writeln(fout,longest);
	for x:=alpha to omega do write(fout,kalimat[x]);
	writeln(fout);
	close(fin);
	close(fout);
end.