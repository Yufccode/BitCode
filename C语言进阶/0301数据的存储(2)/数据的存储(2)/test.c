#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>



//整型在内存中的存储
//浮点型在内存中的存储

//练习
#if 0
int main() {
	char a = 128;
	//00000000000000000000000010000000
	//11111111111111111111111110000000--看成正数--原反补相同
	//截断
	//10000000
	//整型提升
	//按照符号位提升
	//11111111111111111111111110000000
	//打印无符号
	//4,294,967,168
	printf("%u\n", a);
	return 0;
}
#endif


#if 0
int main() {
	int i = -20;
	//100000000000000000000000010100
	//111111111111111111111111101011
	//111111111111111111111111101100
	unsigned int j = 10;
	//000000000000000000000000001010
	//相加
	//111111111111111111111111110110-补
	//111111111111111111111111110101
	//100000000000000000000000001010~-10
	printf("%d\n", i + j);
	return 0;
}
#endif



#include<Windows.h>
#if 0
int main() {
	unsigned int i;
	for (i = 9; i >= 0; i--) {
		printf("%u\n", i);
		Sleep(100);
	}
	//i=-1时
	//10000000000000000000000000000001
	//11111111111111111111111111111111
	//4,294,967,295
	return 0;
}
#endif


#if 0
int main() {
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++) {
		a[i] = -1 - i;
	}
	//-1,-2,-3.....-128,127,126.....0
	//100000~是不能算的-直接解析成-128
	printf("%d", strlen(a));
	return 0;
}
#endif 


#if 0
unsigned char i = 10;
int main() {
	//11111111~255
	//00000000~256截断了
	//死循环
	for (i = 0; i <= 255; i++) {
		printf("hello world\n");
	}
	return 0;
}
#endif



//浮点型数据的存储
//3.14159
//1E10
//float long double...
//float.h 定义了浮点数的取值范围
//limits.h 定义了整型的取值范围
#include<limits.h>
#include<float.h>

//引入
#if 0
int main() {
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为:%d\n", n);
	printf("*pFloat的值为:%f\n", *pFloat);
	*pFloat = 9.0;
	printf("n的值为:%d\n", n);
	printf("*pFloat的值为:%f\n", *pFloat);
	return 0;
}
#endif
//说明了整型和浮点型的存储规则是不一样的
//什么形式放进去就要用什么形式拿出来，因为放和拿的规则有差异


//根据国际标准IEEE（电气和电子工程协会）754，任意一个二进制浮点数V可以表示成下面的形式
//(-1)^S*M*2^E
//(-1)^S表示符号位，当S=0时，V为正数；当S=1时，V为负数
//M表示有效数字，大于1小于2
//2^E表示指数位


//十进制的5.0，写成二进制就是101.0，相当与1.01x2^2
//          此时 S=0,M=1.01,E=2



//十进制的5.5
//101.1是它的二进制表示形式，最右边的1表示2的-1次方
//1.011*2^2，向左移了两位


//十进制的9.0
//1001.0
//(-1)^0*1.001*2^3


//3.14这种数是很难保存的
//可能小数点后面要跟很多二进制序列，才能不断逼近3.14，所以，才会有精度限制


//所以我们存的时候，存S M E三个数就可以了



//32个bit位
//最高位是符号位
//然后紧接着8个留给E
//剩下的23个位留给M

//64个bit位
//最高是符号位
//然后紧接着11个留给E
//剩下52个留给M



//我们存M的时候，M肯定可以写成1.xxxxxxx的形式
//所以1是不用存的，存xxxxxxx就行了



//E比较复杂
//E是一个无符号正数
//如果是8个位置，就是0~255，如果是11个位置，就是0~2047
//但是E有可能是负数的，比如我们要存十进制的0.5的时候，时1.0*2^-1
//所以规定
//存入内存的时候，真实值必须再加上一个中间数，对于8位的，中间数时127，11位的中间数时1023
//比如2^10的E是10，所以保存成32位浮点数的时候，必须保存成10+127=137


#if 1
int main() {
	float f = 5.5;
	//101.1---1011*2^2
	//S=0;		
	//E=2;----129
	//M=1.011
	//存储到内存
	//01000000101100000000000000000000
	//存进去就是这样的，我们可以验证一下
	//0100 0000 1011 0000 0000 0000 0000 0000
	//  4    0   b    0    0    0    0    0
	//0x40b00000
	//打开内存就可以了

	float f2 = 0.5;
	//0.1
	//(-1)^0*1.0*2*2^-1
	//S=0
	//E=126  0111 1110
	//M=0
	//0011 1111 0000 0000 0000 0000 0000 0000
	//  3    f   0    0...
	//0x3f000000
	return 0;
}
#endif


//整数才有原反补，浮点数没有


//怎么取
//取的时候分为3种情况，
//1.E不全为0或不全为1(怎么放怎么拿出来)
//   E减去127或1023 得到真实值，再将有效数字M前面加上第一位的1
//2.E为全0
//   指数E直接等于1-127或1-1023即为真实值
//   有效数字M前面不再加上1，而是还原为0.xxxxxxx的小数，这样做为了表示±0表示接近0的很小的数字
//3.E为全1
//   表示±无穷大


//现在，我们再来看之前的引入的例子
#if 0
int main() {
	int n = 9;
	//00000000000000000000000000001001--原反补
	float* pFloat = (float*)&n;
	//00000000000000000000000000001001~被解析成浮点数
	//0 00000000 00000000000000000001001
	//E为全0，表示一个很小的数字--->所以打印的是0.00000....
	printf("n的值为:%d\n", n);
	printf("*pFloat的值为:%f\n", *pFloat);
	*pFloat = 9.0;
	//9.0
	//1001.0
	//(-1)^0 * 1.001 * 2^3
	//S=0
	//M=1.001
	//E=3  +127  =130~10000010
	//0 10000010 00100000000000000000000 ~9.0
	//01000001000100000000000000000000~被解析成整数~1,091,567,616
	printf("n的值为:%d\n", n);
	printf("*pFloat的值为:%f\n", *pFloat);
	return 0;
}
#endif

//浮点数是不能直接用==来相等的
#if 0
int main() {
	float f = 0.00000000001;
	if (f == 0.0) {//err
		//不能直接这样比的，一般使用的时候是要做差，看看是否是在所允许的误差范围之内
		printf("true\n");
	}
	return 0;
}
#endif
//这就是内功的修炼