ǳ�������򵥵ĸ�ֵ��������
������ڶ�����������ռ䣬���п�������

Shallow copy: a simple assignment copy operation
Deep copy: requesting space in the heap area and and then do a copy operation in the newly allocated space


����: �������ٵ�������Ҫ����Ա�ֶ�����ͬʱҲ��Ҫ����Ա�ֶ��ͷţ�����һ���ر������� a = new int (b)[pointer], return a *. ����
ͨ�������������϶Ե�ʱ����Ŀռ�����ͷţ�������������Ҫ���ã�
problem:It is a necessary process that the data allocated in the heap area needs to be deleted before the object is destoried.
so the allocated heap memory is freed in deconstructor

