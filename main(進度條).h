#ifndef LAB107_HOMEWORK_20180326_MAIN_H_INCLUDED
#define LAB107_HOMEWORK_20180326_MAIN_H_INCLUDED

/**
 *  �������@�~�M�׬[�c�G
 *  + hw20180326/      <--------- �إ�hw20180326��Ƨ�
 *    + main.c         <--------- �D�{���ɦW�� main.c �]��@�n�D�b�U���^
 *    + main.h         <--------- ���ɮ� main.h �����Q main.c �ޤJ�]#include "main.h"�^
 *    + README.xxx     <--------- ���i��l�ɮ� ���ɦW�����]�p .md .docx .doc�^
 *    + README.pdf     <--------- ���ipdf�ɮ�
 *  �����ᥴ�]���M�׸�Ƨ��� hw20180326-<�m�W>.zip ��
 *  <�m�W>�Ч令�ۤv���W�r�A�äW�Ǧܸs�դ�
 *  �����@�U�A�Х�C�y����@�����@�~
 * �]�p�G��C++�sĶ���ܷ|�o�ͦ��쪺�Ʊ��^
 */

typedef int boolean;
enum { false, true };

/**
 *  �禡 gcd_using_factorization
 *  �]�l���Ѫk�D�̤j���]��
 *  ���ե��T��^�D0�ȡA���ե��Ѫ�^0 "
 *  �ǤJ���Ѽƥ����Ҭ�����ơA��ƪ�^�̤j���]��
 *  �Y�ǤJ���ѼƬ��D����ơA�h��^0
 *  ��ƥ����b10�����槹���ê�^�ƭ�
 */
int gcd_using_factorization(int,int);

/**
 * �禡 gcd_using_euclidean_algorithm
 * ����۰��k�D�̤j���]��
 * ���ե��T��^�D0�ȡA���ե��Ѫ�^0
 * �ǤJ���Ѽƥ����Ҭ�����ơA��ƪ�^�̤j���]��
 * �Y�ǤJ���ѼƬ��D����ơA�h��^0
 * ��ƥ����b10�����槹���ê�^�ƭ�
 */
int gcd_using_euclidean_algorithm(int,int);

/**
 * �禡 test_gcd_using_factorization
 * �]�l���Ѫk�D�̤j���]�ƴ���
 * ���ե��T��^ true�A���ե��Ѫ�^ false
 */
boolean test_gcd_using_factorization(int *n);

/**
 * �禡 test_gcd_using_euclidean_algorithm
 * ����۰��k�D�̤j���]�ƴ���
 * ���ե��T��^ true�A���ե��Ѫ�^ false
 */
boolean test_gcd_using_euclidean_algorithm(int *n);

/**
 * �D�禡 main
 * ������������W��2�Ӵ��ը��
 * �ñN���դ����G�C�L�� stderr 
 * �]���ܡAgoogle "stderr" �M "fprintf" ���Ϊk�^
 * �Y�G�Ӵ��լҥ��T�L�~�A��^0�A�_�h��^1
 */

void test_gcd_using_factorization_thread(long *clk_end,boolean *TGUF); 

void test_gcd_using_euclidean_algorithm_thread(long *clk_end,boolean *TGUEA); 

void displayProgress(int);

int main();

#endif // LAB107_HOMEWORK_20180326_MAIN_H_INCLUDED
