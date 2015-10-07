
mdir = pwd;
fid = fopen('list.txt');

tline = fgetl(fid);
while ischar(tline)
	fprintf('%sに対する処理を実行\n',tline);
	[pathstr,name,ext] = fileparts(tline);
	cd(pathstr);
	datafile = ['data_' name '.m'];
	if exist(datafile) ~= 0
		run(datafile);
	end
	rtwbuild(name);
	export_decoration_file(name,'','','','','','','-w');
	tline = fgetl(fid);
	fprintf('\n');
end

exit;