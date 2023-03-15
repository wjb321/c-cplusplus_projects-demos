/*
f(x, y) =(6. 452(x+0. 125y) (cosx-cos2y) (cosx-cos2y)) /(�|(0. 8+(x-4. 2) (x-4. 2) +2(y-7) (y-7))) +3. 226y
�������ֵ  x������[ 0, 10), y������[0, 10)
x  y��Ϊ��λС����Ⱦɫ�����Ϊxxxxyyyy
��ʼȾɫ��   42303407 44670717 41877579
09054353 57997839 11976719
64139420 89513808 52092913
73909290*/
//д���Ҷ���ͷͺ��  ��ѧ��
//�������Ӵ�����10�����壬���Ӵ����ɺ���һ�����������Ӵ���洢�������У����ǣ�

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>

#define Seed  srand((unsigned)time(0));//���������
#define BIAN  0.15   //�������
#define DAISHU 500 //��������


int XuanZeShu[10];//����ѡ���Ⱦɫ����±�
double ZuiYouZhi[20] = { 0 };//��������ֵ����������
double TureZuiYou[10] = { 0 };//�������д���������ֵ

//���������
//����xΪѡ���ĸ�������sumΪѡ���㷨�е���Ӧ��֮��
double Rand(int x, int sum) {
	// rand����% ��b - a + 1���ķ�Χ��[0��b - a+1]

	if (x == 1){//���ڳ�ʼ��Ⱦɫ��

		return rand() % 10;//����0��9�������

	}
	else if (x == 0) {//�ж��Ƿ���Ҫ����(bian����100)<=0.15������

		double bian;
		bian = (rand() % 100);//����0��100�������

		return bian / 100;

	}
	else if (x == 2){//����ѡ����������������ѡ����һ��Ⱦɫ�� 10��

		return rand() % (sum + 1);

	}
	else if (x == 3){//���ؽ���������һλ����

		return rand() % 8;

	}
	else if (x == 4){//���ر�����ٸ�

		return rand() % 5 + 1;
	}

}

//��Ӧ�Ⱥ���(��������) ������Ӧ��
double ShiYing(double ranseti[][10], int i){
	double x, y;
	//����x,y;
	x = ranseti[i][0] + ranseti[i][1] * 0.1 + ranseti[i][2] * 0.01 + ranseti[i][3] * 0.001;
	y = ranseti[i][4] + ranseti[i][5] * 0.1 + ranseti[i][6] * 0.01 + ranseti[i][7] * 0.001;

	double FenZi = 6.452*(x + 0.125*y)*pow((cos(x) - cos(2 * y)), 2);
	double FenMu = sqrt(0.8 + pow((x - 4.2), 2) * 2 * pow((y - 7), 2));

	return (FenZi / FenMu) + 3.266*y;
}


//ѡ���㷨�����̶�ѡ��:��������ʽ���֣�����Ӧ�ȷ�Ϊ�ֳ�10������
void XuanZe(double ranseti[][10]){

	//�˴�Ϊ��Ⱦɫ����������ռ����Ϊ�˷������ʡ����С����
	double sum[10] = { 0 };
	sum[0] = ranseti[0][8];
	for (int i = 1; i<10; i++){
		sum[i] = sum[i - 1] + ranseti[i][8];
	}

	//ѡ���ĸ�Ⱦɫ�壬�����±괢����XuanZeShu[]������
	int NaGe = 10;
	for (int j = 0; j<10; j++){
		int XuanRan = Rand(2, (int)sum[9]);
		//��ͬ�����Ӧ��ͬ��Ⱦɫ��
		if (XuanRan >= 0 && XuanRan<(int)sum[0]){ XuanZeShu[j] = 0; }
		else if (XuanRan >= (int)sum[0] && XuanRan<(int)sum[1]){ XuanZeShu[j] = 1; }
		else if (XuanRan >= (int)sum[1] && XuanRan<(int)sum[2]){ XuanZeShu[j] = 2; }
		else if (XuanRan >= (int)sum[2] && XuanRan<(int)sum[3]){ XuanZeShu[j] = 3; }
		else if (XuanRan >= (int)sum[3] && XuanRan<(int)sum[4]){ XuanZeShu[j] = 4; }
		else if (XuanRan >= (int)sum[4] && XuanRan<(int)sum[5]){ XuanZeShu[j] = 5; }
		else if (XuanRan >= (int)sum[5] && XuanRan<(int)sum[6]){ XuanZeShu[j] = 6; }
		else if (XuanRan >= (int)sum[6] && XuanRan<(int)sum[7]){ XuanZeShu[j] = 7; }
		else if (XuanRan >= (int)sum[7] && XuanRan<(int)sum[8]){ XuanZeShu[j] = 8; }
		else if (XuanRan >= (int)sum[8] && XuanRan <= (int)sum[9]){ XuanZeShu[j] = 9; }

	}

}

//�����㷨
void BianYi(double RanSeTi[][10]){
	for (int i = 0; i<10; i++){//ѭ��ÿ��Ⱦɫ���Ƿ���Ҫ����
		double IsBian = Rand(0, 0);//����Ƚ�ֵ
		int NaWei[7] = { 11 };//������Щ�����±��ʾ
		if (IsBian <= BIAN){//����ʽ�����������   
			NaWei[6] = Rand(4, 0);//������5λ   
			for (int j = 0; j <= NaWei[6];){//���������±�
				int SHU = Rand(3, 0);//�����±�
				int flag = 0;//���趼���ظ�
				for (int k = 0; k <= j; k++){
					if (NaWei[k] == SHU){ flag = 1; break; }//�ж�
				}
				if (flag == 0){
					int Huan;
				XuanHuan:
					Huan = Rand(1, 0);
					NaWei[j] = SHU;
					if (RanSeTi[i][SHU] != Huan){
						RanSeTi[i][SHU] = Huan;
					}
					else{ goto XuanHuan; }
					j++;
				}//��ֵ
				if (j == NaWei[6]){ break; }//�˳�ѭ��
			}

		}

	}



}

//�����㷨  ֻ�����������һ��
//���жϸ�����ĸ���Ƿ���ȣ������������һ����������
//Ȼ�󸲸�
void JiaoCha(double RanSeTiFu[][10], double RanSeTi[][10]){

	int NaWei[5][10] = { -1 };//������λȾɫ����н����滻��
	for (int i = 0; i<5; i++){//ѭ��������
		int count = 0;//�Ƿ�ѡ��һ��Ľ���λ��

		while (1){//���ڻ�Ҫ����������Ƿ��ظ�������while

			int flag = 0;//���趼���ظ�
			int ZHI = Rand(3, 0);//�Ƿ��ظ�
			for (int j = 0; j <= count; j++){
				if (ZHI == NaWei[i][j]){//�ж�
					flag = 1;
					break;
				}
			}
			//��ֵ ��ͬ�������
			if (flag == 0){ NaWei[i][count] = ZHI; count++; }
			if (count == 4){ break; }//Ϊ4ʱ��һ��ѡ�����
		}

	}

	//��ʼ��������
	for (int i = 1; i <= 5; i++){
		for (int j = 0; j<8; j++){
			if (j == NaWei[i - 1][0] || j == NaWei[i - 1][1] || j == NaWei[i - 1][2] || j == NaWei[i - 1][3]){
				RanSeTi[i * 2 - 2][j] = RanSeTiFu[i * 2 - 1][j];
				RanSeTi[i * 2 - 1][j] = RanSeTiFu[i * 2 - 2][j];
			}
			else{
				RanSeTi[i * 2 - 1][j] = RanSeTiFu[i * 2 - 1][j];
				RanSeTi[i * 2 - 2][j] = RanSeTiFu[i * 2 - 2][j];
			}

		}

	}

}


//�Ƚ�����ֵ����
//�����ÿһ������Ⱦɫ�弰��ֵ
void BiJiao(double RanSeTi[][10], int ZiDai){
	ZuiYouZhi[8] = 0;
	//ÿ������
	for (int i = 0; i<10; i++){
		if (RanSeTi[i][8]>ZuiYouZhi[8])
		{
			ZuiYouZhi[8] = RanSeTi[i][8];
			ZuiYouZhi[9] = i;
		}
	}
	//ȫ������
	for (int i = 0; i<10; i++){
		if (TureZuiYou[8]<RanSeTi[i][8])
		{//���ŲŸ�ֵ
			TureZuiYou[8] = RanSeTi[i][8];
			TureZuiYou[9] = (double)ZiDai;
			//�����
			for (int j = 0; j<8; j++){
				TureZuiYou[j] = RanSeTi[i][j];
			}
		}

	}


	double x, y;
	int ii = ZuiYouZhi[9];
	//����x,y;
	x = RanSeTi[ii][0] + RanSeTi[ii][1] * 0.1 + RanSeTi[ii][2] * 0.01 + RanSeTi[ii][3] * 0.001;
	y = RanSeTi[ii][4] + RanSeTi[ii][5] * 0.1 + RanSeTi[ii][6] * 0.01 + RanSeTi[ii][7] * 0.001;

	printf("��%d������ֵΪ\n", ZiDai);
	printf("x = %.3lf, y = %.3lf\n", x, y);
	printf("����ֵ%lf\n", ZuiYouZhi[8]);
	printf("\n");


}


//������
int main(){
	double RanSeTi[10][10], RanSeTiFu[10][10];
	Seed//��
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j<8; j++) {

			//��ʼ������Ⱦɫ��
			RanSeTi[i][j] = (int)Rand(1, 0);

		}
		//������Ӧ��
		RanSeTi[i][8] = ShiYing(RanSeTi, i);
	}

	//��ʼ����ֵ
	BiJiao(RanSeTi, 0);


	//ѭ������
	for (int ZiDai = 1; ZiDai <= DAISHU; ZiDai++){
		//ѡ�����
		XuanZe(RanSeTi);

		//��ѡ�����Ⱦɫ��洢��Ϊ��һ��������׼��
		for (int i = 0; i<10; i++){
			for (int j = 0; j<8; j++){
				RanSeTiFu[i][j] = RanSeTi[XuanZeShu[i]][j];
			}
		}

		//�������
		JiaoCha(&RanSeTiFu[0], &RanSeTi[0]);

		//�������
		BianYi(RanSeTi);

		//������Ӧ��
		for (int Shi = 0; Shi<10; Shi++){
			RanSeTi[Shi][8] = ShiYing(RanSeTi, Shi);
		}

		//�Ƚ�����ô�����ֵ
		BiJiao(RanSeTi, ZiDai);

	}

	//���Ž�
	double tx, ty;
	//����tx,ty;
	tx = TureZuiYou[0] + TureZuiYou[1] * 0.1 + TureZuiYou[2] * 0.01 + TureZuiYou[3] * 0.001;
	ty = TureZuiYou[4] + TureZuiYou[5] * 0.1 + TureZuiYou[6] * 0.01 + TureZuiYou[7] * 0.001;
	printf("��������ֵΪ\n");
	printf("x = %.3lf, y = %.3lf\n", tx, ty);
	printf("����ֵ%lf\n", TureZuiYou[8]);
	printf("�����ڵ�%.0lf��\n", TureZuiYou[9]);
	printf("\n");




	return 0;
}

//int main()
//{
//	float a = 456.78926;
//	int b = 0;
//	float c = 0;
//    int temp = 0;
//	int d = 0;
//	// C = A �C B * (A / B).
//	temp = (int)((a - (int)a)*10000);
//	printf("b = %d\n", int(a)); 
//	printf("c= %d\n",(temp)/100);
//	d = (temp) / 100;
//	printf("d= %d\n", (temp ) % 100);
//	//printf("d1= %d\n", temp -100 *(temp / 100)); 
//	printf("d1= %d\n", temp - 100 * d);
//	return 0;
//}
//float intermediate = 0;
//float Decelerate = 50.0;
//#define Radian  0.523
//#define Radius  0.045
//#define PI 3.14159
//#include <math.h>
//
//float vol0 = 90.0;
//float tempval = 0.0;
//float vol1 = 85.3;
//int main(void)
//{
//	intermediate = Decelerate * Radian * Radius;
//	tempval = ((vol0 + sqrt(vol0 * vol0 - 4 * intermediate)) / 2.0);
//	if (vol1 + 3 < ((vol0 + sqrt(vol0 * vol0 - 4 * intermediate)) / 2.0) && vol1 < vol0 - 3)
//	{
//		                  printf("vol1  is %f \r\n", vol1 );
//		                  printf("vol0 is %f \r\n", vol0);
//		                  printf("cal is %f \r\n", (vol0 + sqrt(vol0 * vol0 - 4* intermediate))/ 2.0 );
//		MES4_DATA0 = 1;
//
//		printf("block\n");
//		 printf("ECU_IDs it is blocked %#x\r\n", ECU_IDs);
//	}
//	printf("tempval %.5f\n", tempval);
//	printf("differ %.5f\n", vol0 - tempval);
//}