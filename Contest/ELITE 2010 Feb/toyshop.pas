{
	PROG: toyshop
	LANG: PASCAL
	ID: felikju1
}
type mainan=record
	 price,joy:int64;
	 order:longint;
	 end;
	 
var n,x:longint;
	toy:array[1..25000] of mainan;
	fin,fout:text;
	
procedure sort(terkiri,terkanan:longint);
	var kiri,kanan:longint;
		pivot:int64;
		temp:mainan;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=toy[(kiri+kanan) div 2].joy;
			
			while kiri<=kanan do
			begin
				while toy[kiri].joy>pivot do inc(kiri);
				while toy[kanan].joy<pivot do dec(kanan);
				
				if kiri<=kanan then
				begin
					temp:=toy[kiri];
					toy[kiri]:=toy[kanan];
					toy[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			sort(terkiri,kanan);
			sort(kiri,terkanan);
		end;
	end;
	
begin
	assign(fin,'toyshop.in');reset(fin);
	assign(fout,'toyshop.out');rewrite(fout);
	readln(fin,n);
	for x:=1 to n do
	begin
		readln(fin,toy[x].joy,toy[x].price);
		toy[x].order:=x;
		toy[x].joy:=trunc((toy[x].joy/toy[x].price)*100000000);
	end;
	sort(1,n);
	writeln(fout,(toy[1].price+toy[2].price+toy[3].price));
	writeln(fout,toy[1].order);
	writeln(fout,toy[2].order);
	writeln(fout,toy[3].order);
	
	close(fin);
	close(fout);
end.
