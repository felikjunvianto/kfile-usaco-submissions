{
	ID: felikju1
	PROG: sort3
	LANG: PASCAL
}

var n,x,y,exchange,temp:longint;
	awal,akhir:longint;
	deret:array[1..1000] of longint;
	count:array[1..3] of longint;
	dapat:boolean;
	fin,fout:text;

begin
	assign(fin,'sort3.in');reset(fin);
	assign(fout,'sort3.out');rewrite(fout);
	fillchar(count,sizeof(count),0);
	readln(fin,n);
	for x:=1 to n do
	begin
		readln(fin,deret[x]);
		inc(count[deret[x]]);
	end;
	exchange:=0;
	
	for x:=1 to count[1] do if deret[x]<>1 then //samakan deret angka 1
	begin
		inc(exchange);
		dapat:=FALSE;
		
		if deret[x]=3 then
		begin
			awal:= count[1]+count[2]+1;
			akhir:= count[1]+count[2]+count[3];
			for y:= akhir downto awal do if(deret[y]=1) then //cek deret 3, ada 1 ga
			begin
				temp:=deret[x];
				deret[x]:=deret[y];
				deret[y]:=temp;
				dapat:=TRUE;
				break;
			end;
			
			if not dapat then
			begin
				awal:=count[1]+1;
				akhir:=count[1]+count[2];
				for y:=akhir downto awal do if (deret[y]=1) then //cek deret 2, ada 1 ga
				begin
					temp:=deret[x];
					deret[x]:=deret[y];
					deret[y]:=temp;
					dapat:=TRUE;
					break;
				end;
			end;
		end else //deret[x]=2
		
		begin
			awal:=count[1]+1;
			akhir:=count[1]+count[2];
			for y:=akhir downto awal do if (deret[y]=1) then //cek deret 2, ada 1 ga
			begin
				temp:=deret[x];
				deret[x]:=deret[y];
				deret[y]:=temp;
				dapat:=TRUE;
				break;
			end;
			
			if not dapat then
			begin
				awal:= count[1]+count[2]+1;
				akhir:= count[1]+count[2]+count[3];
				for y:= akhir downto awal do if(deret[y]=1) then //cek deret 3, ada 1 ga
				begin
					temp:=deret[x];
					deret[x]:=deret[y];
					deret[y]:=temp;
					dapat:=TRUE;
					break;
				end;
			end;
		end;
	end;
	
	for x:=count[1]+1 to count[1]+count[2] do if deret[x]<>2 then //samakan deret angka 2
	begin
		inc(exchange);

		awal:= count[1]+count[2]+1;
		akhir:= count[1]+count[2]+count[3];
		for y:= akhir downto awal do if(deret[y]=2) then //cek deret 3, ada 2 ga
		begin
			temp:=deret[x];
			deret[x]:=deret[y];
			deret[y]:=temp;
			break;
		end;
	end;
	
	writeln(fout,exchange);
	close(fin);
	close(fout);
end.