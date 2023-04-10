#include <stdio.h>

// �������˲�����
float Q = 0.001;
float R = 0.1;
float x = 0;
float P = 1;
float K;

// ���¿������˲�����
void kalman_filter(float measurement) {
	// Ԥ����һʱ��״̬����
	float x_predict = x;
	float P_predict = P + Q;

	// ���¿���������
	K = P_predict / (P_predict + R);

	// ����״̬������״̬Э����
	x = x_predict + K * (measurement - x_predict);
	P = (1 - K) * P_predict;
}

int main() {
	// ģ���Ƶ����ֵ
	float pulse[] = { 10.0, 12.0, 11.0, 14.0, 10.0, 9.0, 13.0, 11.0, 12.0, 15.0 };

	// ������Ƶ����ֵ�����п������˲�
	for (int i = 0; i < 10; i++) {
		kalman_filter(pulse[i]);
		printf("��Ƶ����ֵ��%f���������˲�ֵ��%f\n", pulse[i], x);
	}
	getchar();
	return 0;
}
