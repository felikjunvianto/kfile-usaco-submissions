{
	ID: felikju1
	PROG: beads
	LANG: PASCAL
}

var n,x,a,awal,akhir,jumlah,depan,belakang,maju,mundur:longint;
	bead:ansistring;
	ubahdepan,ubahbelakang:boolean;
	fin,fout:text;

begin
	assign(fin,'beads.in');reset(fin);
	assign(fout,'beads.out');rewrite(fout);
	readln(fin,n);
	readln(fin,bead);
	
	jumlah:=0;
	bead:=copy(bead,1,n) + bead + copy(bead,1,n);
	
	for x:=n+1 to 2*n do
	begin
		awal:=x;
		akhir:=x+1;
		depan:=1;
		belakang:=1;
		maju:=awal-1;
		mundur:=akhir+1;
		a:=1;
		ubahdepan:=FALSE;
		ubahbelakang:=FALSE;
		
		while bead[awal] = 'w' do
		begin
			ubahdepan:=TRUE;
			bead[awal]:=bead[awal-a];
			inc(a);	
		end;
		a:=1;
		
		while bead[akhir] = 'w' do
		begin
			ubahbelakang:=TRUE;
			bead[akhir] := bead[akhir-a];
			inc(a);
		end;
	
		while (bead[maju] = bead[awal]) xor (bead[maju] = 'w') do
		begin
			inc(depan);
			dec(maju);
		end;
	
		while (bead[mundur] = bead[akhir]) xor (bead[mundur] = 'w') do
		begin
			inc(belakang);
			inc(mundur);
		end;
		
		if depan+belakang>jumlah then jumlah := depan+belakang;
		if ubahdepan then bead[awal] := 'w';
		if ubahbelakang then bead[akhir] := 'w';
	end;
	
	if jumlah > n then jumlah := n;
	writeln(fout,jumlah);
	close(fin);
	close(fout);
end.