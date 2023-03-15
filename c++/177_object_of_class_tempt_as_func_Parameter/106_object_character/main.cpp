#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SUM 20            //�ܹ���Ⱦɫ������
#define MAXloop 1200       //���ѭ������
#define error 0.01        //����������ֵ֮��С�ڴ�������Ϊ���û�иı�
#define crossp 0.7        //�������
#define mp 0.04           //�������

//������⺯��y=x^6-10x^5-26x^4+344x^3+193x^2-1846x-1680�ڣ�-8��8��֮�����Сֵ 

struct gen                //����Ⱦɫ��ṹ
{
	int info;        		//Ⱦɫ��ṹ����һ�������ĺ�14λ��ΪȾɫ����� 
	float suitability;		//��Ⱦɫ������Ӧ����Ӧ�Ⱥ���ֵ���ڱ�����Ϊ���ʽ��ֵ 
};
struct gen gen_group[SUM];//����һ������20��Ⱦɫ�����
struct gen gen_new[SUM];

struct gen gen_result;    //��¼���ŵ�Ⱦɫ��
int result_unchange_time; //��¼��errorǰ��������ֵΪ�ı��ѭ������

struct log                //�γ�������¼ÿ��ѭ�������������ŵ���Ӧ��
{
	float suitability;
	struct log *next;
}llog, *head, *end;
int log_num;              //������

/**************��������******************/
void initiate();          	//��ʼ����������Ҫ���������ʼ����Ⱥ 
void evaluation(int flag);	//������Ⱥ�и�Ⱦɫ�����Ӧ�ȣ����ݴ˽������� 
void cross();				//���溯�� 
void selection();			//ѡ���� 
int  record();				//��¼ÿ��ѭ�����������ŽⲢ�ж��Ƿ���ֹѭ�� 
void mutation();			//���캯�� 
void showresult(int);		//��ʾ��� 
//-----------------------���Ϻ�����������ֱ�ӵ��� 
int   randsign(float p);	//���ո���p���������0��1����ֵΪ1�ĸ���Ϊp 
int   randbit(int i, int j);	//����һ����i��j������֮���������� 
int   randnum();			//�������һ����14��������ɵ�Ⱦɫ�� 
int   convertionD2B(float x);//����ʵ��ռ�Ŀ��ܽ�x���ж����Ʊ��루Ⱦɫ����ʽ�� 
float convertionB2D(int x);	//�������Ʊ���xת��Ϊ��ʵ��ռ��ֵ 
int   createmask(int a);	//���ڽ������ 

void main()
{
	int i, flag;
	flag = 0;
	initiate();				//������ʼ����Ⱥ 
	evaluation(0);		//�Գ�ʼ����Ⱥ�������������� 
	for (i = 0; i < MAXloop; i++)
	{
		cross();			//���н������ 
		evaluation(1);	//������Ⱥ�������������� 
		selection();		//�Ը�����Ⱥ��ѡ�����ŵ�NUM����Ϊ�µĸ���Ⱥ 
		if (record() == 1)	//������ֹ����1����flag=1��ֹͣѭ�� 
		{
			flag = 1;
			break;
		}
		mutation();			//������� 
	}
	showresult(flag);		//����flag��ʾѰ�Ž�� 
}

void initiate()
{
	int i, stime;
	long ltime;
	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);
	for (i = 0; i < SUM; i++)
	{
		gen_group[i].info = randnum();		//����randnum()����������ʼ��Ⱥ	 
	}
	gen_result.suitability = 1000;
	result_unchange_time = 0;
	head = end = (struct log *)malloc(sizeof(llog));//��ʼ������ 
	if (head == NULL)
	{
		printf("\n�ڴ治����\n");
		exit(0);
	}
	end->next = NULL;
	log_num = 1;
}

void evaluation(int flag)
{
	int i, j;
	struct gen *genp;
	int gentinfo;
	float gentsuitability;
	float x;
	if (flag == 0)			// flag=0��ʱ��Ը���Ⱥ���в��� 
		genp = gen_group;
	else genp = gen_new;
	for (i = 0; i < SUM; i++)//�����Ⱦɫ���Ӧ�ı��ʽֵ
	{
		x = convertionB2D(genp[i].info);
		genp[i].suitability = x*(x*(x*(x*(x*(x - 10) - 26) + 344) + 193) - 1846) - 1680;    //��ȡ����ʽ��ԭʽ���� 
	}
	for (i = 0; i < SUM - 1; i++)//�����ʽ��ֵ��������
	{
		for (j = i + 1; j < SUM; j++)
		{
			if (genp[i].suitability > genp[j].suitability)
			{
				gentinfo = genp[i].info;
				genp[i].info = genp[j].info;
				genp[j].info = gentinfo;

				gentsuitability = genp[i].suitability;
				genp[i].suitability = genp[j].suitability;
				genp[j].suitability = gentsuitability;
			}
		}
	}
}

void cross()
{
	int i, j, k;
	int mask1, mask2;
	int a[SUM];
	for (i = 0; i < SUM; i++)  a[i] = 0;
	k = 0;
	for (i = 0; i < SUM; i++)
	{
		if (a[i] == 0)
		{
			for (;;)//����ҵ�һ��δ���й������Ⱦɫ����a[i]����
			{
				j = randbit(i + 1, SUM - 1);
				if (a[j] == 0)	break;
			}
			if (randsign(crossp) == 1)		//����crossp�ĸ��ʶ�ѡ���Ⱦɫ����н������ 
			{
				mask1 = createmask(randbit(0, 14));		//��ranbitѡ�񽻲�λ 
				mask2 = ~mask1;				//�γ�һ������ 111000 000111֮��Ķ���������� 
				gen_new[k].info = (gen_group[i].info) & mask1 + (gen_group[j].info) & mask2;
				gen_new[k + 1].info = (gen_group[i].info) & mask2 + (gen_group[j].info) & mask1;
				k = k + 2;
			}
			else 		//�����н��� 
			{
				gen_new[k].info = gen_group[i].info;
				gen_new[k + 1].info = gen_group[j].info;
				k = k + 2;
			}
			a[i] = a[j] = 1;
		}
	}
}

void selection()
{
	int i, j, k;
	j = 0;
	i = SUM / 2 - 1;
	if (gen_group[i].suitability < gen_new[i].suitability)
	{
		for (j = 1; j < SUM / 2; j++)
		{
			if (gen_group[i + j].suitability > gen_new[i - j].suitability)
				break;
		}
	}
	else
	if (gen_group[i].suitability>gen_new[i].suitability)
	{
		for (j = -1; j>-SUM / 2; j--)
		{
			if (gen_group[i + j].suitability <= gen_new[i - j].suitability)
				break;
		}
	}
	for (k = j; k<SUM / 2 + 1; k++)
	{
		gen_group[i + k].info = gen_new[i - k].info;
		gen_group[i + k].suitability = gen_new[i - k].suitability;
	}
}

int record()	//��¼���Ž���ж��Ƿ��������� 
{
	float x;
	struct log *r;
	r = (struct log *)malloc(sizeof(llog));
	if (r == NULL)
	{
		printf("\n�ڴ治����\n");
		exit(0);
	}
	r->next = NULL;
	end->suitability = gen_group[0].suitability;
	end->next = r;
	end = r;
	log_num++;

	x = gen_result.suitability - gen_group[0].suitability;
	if (x < 0)x = -x;
	if (x < error)
	{
		result_unchange_time++;
		if (result_unchange_time >= 20)return 1;
	}
	else
	{
		gen_result.info = gen_group[0].info;
		gen_result.suitability = gen_group[0].suitability;
		result_unchange_time = 0;
	}
	return 0;
}

void mutation()
{
	int i, j, m;
	float x;
	float gmp;
	int gentinfo;
	float gentsuitability;
	gmp = 1 - pow(1 - mp, 11);//�ڻ���������Ϊmpʱ����Ⱦɫ��ı������
	for (i = 0; i < SUM; i++)
	{
		if (randsign(gmp) == 1)
		{
			j = randbit(0, 14);
			m = 1 << j;
			gen_group[i].info = gen_group[i].info^m;
			x = convertionB2D(gen_group[i].info);
			gen_group[i].suitability = x*(x*(x*(x*(x*(x - 10) - 26) + 344) + 193) - 1846) - 1680;
		}
	}
	for (i = 0; i < SUM - 1; i++)
	{
		for (j = i + 1; j < SUM; j++)
		{
			if (gen_group[i].suitability > gen_group[j].suitability)
			{
				gentinfo = gen_group[i].info;
				gen_group[i].info = gen_group[j].info;
				gen_group[j].info = gentinfo;

				gentsuitability = gen_group[i].suitability;
				gen_group[i].suitability = gen_group[j].suitability;
				gen_group[j].suitability = gentsuitability;
			}
		}
	}
	/*
	*Ϊ�����ִ���ٶȣ��ڽ��б��������ʱ��û��ֱ��ȷ����Ҫ���б����λ
	*��������cmp����ȷ����Ҫ���������Ⱦɫ�壬�ٴ�Ⱦɫ�������ѡ��һ��������б���
	*���ڽ���ѡ��ͱ���󸸴���Ⱥ�Ĵ����ѱ����ң���ˣ��ڱ���ǰ�����Ⱥ����һ������
	*/
}

void showresult(int flag)//��ʾ����������ͷ��ڴ�
{
	int i, j;
	struct log *logprint, *logfree;
	FILE *logf;
	if (flag == 0)
		printf("�ѵ������������������ʧ�ܣ�");
	else
	{
		printf("��ȡֵ%fʱ���ʽ�ﵽ��СֵΪ%f\n", convertionB2D(gen_result.info), gen_result.suitability);
		printf("�������̼�¼���ļ�log.txt");
		if ((logf = fopen("log.txt", "w+")) == NULL)
		{
			printf("Cannot create/open file");
			exit(1);
		}
		logprint = head;
		for (i = 0; i < log_num; i = i + 5)//���������̽�����ʾ
		{
			for (j = 0; (j < 5) & ((i + j) < log_num - 1); j++)
			{
				fprintf(logf, "%20f", logprint->suitability);
				logprint = logprint->next;
			}
			fprintf(logf, "\n\n");
		}
	}
	for (i = 0; i< log_num; i++)//�ͷ��ڴ�
	{
		logfree = head;
		head = head->next;
		free(logfree);
		fclose(logf);
	}
	getchar();
}

int randsign(float p)//������p����1
{
	if (rand() > (p * 32768))
		return 0;
	else return 1;
}
int randbit(int i, int j)//������i��j֮���һ�������
{
	int a, l;
	l = j - i + 1;
	a = i + rand() * l / 32768;
	return a;
}
int randnum()
{
	int x;
	x = rand() / 2;
	return x;
}
float convertionB2D(int x)
{
	float y;
	y = x;
	y = (y - 8192) / 1000;
	return y;

}
int convertionD2B(float x)
{
	int g;
	g = (x * 1000) + 8192;
	return g;
}
int createmask(int a)
{
	int mask;
	mask = (1 << (a + 1)) - 1;
	return mask;
}