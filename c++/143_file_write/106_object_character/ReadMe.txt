�ı��ļ���ȡ
ofstream д����
ifstream ������
fstream  ��д����

basic steps:

1.include file 
2.create object like ofstream:  ofstream ofs;
3.open file ofs.open(path, open_method)
4.ofs << "write data"
5.ofs.close();

ios::in       read file
iso::out      write file
ios::ate      start from file tail
ios::app      add to the file
ios::trunc    delete the exist file then create new
ios::binary   binary mode