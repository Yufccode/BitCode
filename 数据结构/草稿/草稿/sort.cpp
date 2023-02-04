#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

//ʹ�������ָ�룬��ʹ��vector
void BubbleSort(int* arr, int sz) {
	for (int i = 0; i < sz - 1; i++) {//���ѭ��
	//tips:ֻ��Ҫsz-1�Σ���Ϊ���һ����û�����������Խ�����
		int if_swap = 0;
		for (int j = 0; j < sz - 1 - i; j++) {//�����sz-1-i������ֻҪ��һ����������д�����Ϳ��Ժܺõ����ף����ﲻ׸����
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);//�������ߵ�ֵ��ע��C����ʵ��swap��Ҫ����ַ��
				if_swap = 1;
			}
		}
		//ÿһ������֮�����if_swap==0;ֱ��return
		if (if_swap == 0)
			return;
	}
}

void SelectSort(int* arr, int sz) {
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++) {
		int min = i;
		for (j = i + 1; j < sz; j++) {
			//���±�Ϊarr[i+1]��ʼ��
			//��<sz����Ϊ���һ��Ԫ��ҲҪ�Ƚ�
								  //����<sz-1��ԭ���ǣ�����ѭ��ֻ��Ҫsz-1�Σ����һ�β�������
								  //��ð�ݵ����ѭ��ԭ��һ��
			if (arr[j] < arr[min]) {
				min = j;//����̨
			}
		}
		//�������ѭ��֮�󣬽���min��i��ֵ����i������С�ķŵ�i��λ��
		swap(arr[i], arr[min]);//�������ߵ�ֵ
	}
}



//ʹ��c��cpp���е�����
void InsertSort(int* arr, int sz) {
	int sortNum = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++) {
		sortNum = arr[i];//Ҫ���������
		for (j = i - 1; j >= 0; j--) {//��ΪҪ�Ӵ������Ǹ�����ǰһ������ʼ������Ųһ��
			//�Ӻ���ǰŲ���������÷���ѭ��
			//���жϣ���Ϊֻ��ҪŲ���ȴ��������ִ������
			if (arr[j] < sortNum) {
				break;
			}
			arr[j + 1] = arr[j];//һ����Ų������
		}
		arr[j + 1] = sortNum;//��Ϊ��jָ�������С��sort�ų�ѭ����
		//���Դ�ʱ��jָ���λ��ǰһ��λ�ã�����arr[j+1]=sort;
	}
}



void sort_in_group(int* arr, int sz, int pos, int step) {
	int sortNum = 0;
	int i = 0;
	int j = 0;
	for (i = pos + step; i < sz; i += step) {
		//pos+step���Ǹ����һ��Ԫ�ص�λ��
		//���磺��pos==0��ʱ�򣬸����һ��Ԫ�ؾ����������е�һ��Ԫ��
		//��pos=1��ʱ�򣬸����һ��Ԫ�ؾ����������еڶ���Ԫ��
		sortNum = arr[i];//Ҫ�������
		for (j = i - step; j >= 0; j -= step) {
			//i-step���Ǹ������һ��Ԫ�أ�����������ͼ���Ը��õ����
			if (arr[j] < sortNum) {
				break;
			}
			arr[j + step] = arr[j];//Ų�����ݣ���ͨ������һ��һ��Ų������ǣ���step��Ų��������һ���ģ�������˼�����ܺܺõ���⡣
		}
		arr[j + step] = sortNum;
	}
}
void ShellSort(int* arr, int sz) {
	int i = 0;
	int step = 0;
	//stepΪ������ÿ�μ���Ϊԭ����һ�룬ȡ���������һ�αض�Ϊ1
	for (step = sz / 2; step > 0; step /= 2) {
		//����Ϊstep��������istep���飬��ÿһ�鶼ִ�в�������
		for (i = 0; i < step; i++) {
			//���ÿһ�������groupSort���ǲ���������΢�ı�һ��İ汾
			sort_in_group(arr, sz, i, step);
			//i=0��ʱ�򣬵�����������0���������ͼ��Ҳ���Ǻ�ɫ������в���
			//i=1��ʱ�򣬵�����������1�����ͼ��Ҳ������ɫ������в���
			//�����ͬ��
			//step��ӹ���ɣ��϶���Ҫ����
		}
	}
}


enum {
	LEFT,//��ʾ���±궯
	RIGHT//��ʾ���±궯
};
void QuickSort(int* arr, size_t sz) {
	if (sz < 2)
		return;//�������Ԫ��С�������Ͳ�������
	int pivot = arr[0];//����ѡȡ����ߵ���Ϊ������
	int ileft = 0;//�����±�
	int iright = sz - 1;
	int imoving = RIGHT;//��ǰӦ���ƶ����±꣬LEFT��ʾҪ�ƶ����±꣬RIGHT��ʾ�ƶ����±�
	//��Ϊһ��ʼ�Ȱ�����߿ճ����ˣ������±�һ��ʼ���ұ߿�ʼ��

	while (ileft < iright) {//һ����������ı�־Ϊ�����±��ص�
		if (imoving == RIGHT) {
			if (arr[iright] >= pivot) {//������±�����Ӧ�����Ȼ�׼���󣬱�ʾ���ö�
				iright--;//ֱ���±����
				continue;//���뵽��һ���ƶ��±����
			}
			else if (arr[iright] < pivot) {//������±�����Ӧ�����Ȼ�׼��С����������������
			//�������ƶ����±�
				arr[ileft] = arr[iright];
				ileft++;//���±�++
				imoving = LEFT;//����
				continue;
			}
		}
		//��һ����ͬ�������
		if (imoving == LEFT) {
			if (arr[ileft] <= pivot) {
				ileft++;
				continue;
			}
			else if (arr[ileft] > pivot) {
				arr[iright] = arr[ileft];
				iright--;
				imoving = RIGHT;
				continue;
			}
		}
	}
	arr[ileft] = pivot;//�����˰ѻ�׼ֵ�Ž���
	//���������������һ������
	//��ʱ�Ļ�׼ֵ�������Ŀ�����
	QuickSort(arr, ileft);//��׼ֵ������п���
	QuickSort(arr + ileft + 1, sz - ileft - 1);//��׼ֵ�ұ����п���
}






//arr-������������׵�ַ��arrtmp-�����������ʱ������׵�ַ
//start-���������һ��Ԫ�ص�λ�ã�end-�����������һ��Ԫ�ص�λ��
//ע��
//�����istart1��iend1��istart2��iend2�����±꣬����ָ�룬��Ȼ����ָ��ʵ��Ҳ�ǿ��Ե�
void _mergeSort(int* arr, int* arrtmp, int start, int end) {
	//���start>=end����ʾ�������Ԫ�������������ݹ���ֹ
	if (start >= end) return;

	int mid = start + (end - start) / 2;//�ҵ������м�λ��
	//��һ�������Ϊ��������
	int istart1 = start;
	int iend1 = mid;

	int istart2 = mid + 1;
	int iend2 = end;
	//�����߷ֱ�ݹ�����
	_mergeSort(arr, arrtmp, istart1, iend1);
	_mergeSort(arr, arrtmp, istart2, iend2);

	//��ʼ�ϲ������ֿ�������
	int i = start;
	//�����������������кϲ����Ѿ���������arrtmp��
	while (istart1 <= iend1 && istart2 <= iend2) {
		arrtmp[i] = arr[istart1] < arr[istart2] ? arr[istart1++] : arr[istart2++];
		//�˴�istart1��istart2�����++�ǲ����õ��������ģ���Ϊ�����ĸ��ĸ���Ҫ++������һ���ϴ���ǲ��ö���
		i++;
	}
	while (istart1 <= iend1) {//�������1����ʣ������1�����ȫ������arrtmp[]���漴��
		arrtmp[i] = arr[istart1];
		i++;
		istart1++;
	}
	while (istart2 <= iend2) {
		arrtmp[i] = arr[istart2];
		i++;
		istart2++;
	}
	//����ٰ�arrtmp[]��������ݿ�����ȥ
	memcpy(arr + start, arrtmp + start, sizeof(int) * (end - start + 1));
}
void MergeSort(int* arr, int sz) {
	if (sz < 2)return;//С������Ԫ�ز���Ҫ����
	int* arrtmp = (int*)malloc(sz * sizeof(int));//����һ���������������ͬ��С������
	_mergeSort(arr, arrtmp, 0, sz - 1);
}




void heapify(int* arr, int start, int end) {
	//1.ѭ����
#if 0
	//ȷ�����������ӽ��������±�
	int dad = start;
	int son = dad * 2 + 1;
	//ѭ���������ӽ����±겻Խ��
	while (son <= end) {
		//�ȱȽ������ӽڵ�Ĵ�С��ѡ���
		if ((son + 1 <= end) && (arr[son] < arr[son + 1])) {//ע��������ֹԽ��
		//���ж��Ƿ��ұ����ֵܽڵ���ܱȽ�
			son++;//��һ�����Ǵ�����ת���ҽ��
		}
		//������������ӽ������Ԫ�ز���Ҫ�³������ѵ�����ϣ�ֱ����������
		if (arr[dad] > arr[son])return;
		//���򽻻����ӽڵ������ټ����ӽ�������ıȽ�
		swap(arr[dad], arr[son]);
		//����
		dad = son;//�ӽ�����µĸ��ڵ㣬����ѭ��
		son = dad * 2 + 1;//ͨ���µĸ�����ҵ��µ��ӽ��
	}
#endif
	//2.�ݹ鷨
#if 1
	//ȷ�����������ӽ��������±�
	int dad = start;
	int son = dad * 2 + 1;
	//���������Χ�ˣ�return
	if (son > end) return;//�ݹ��������
	//�ȱȽ������ӽ�㣬ѡ����
	if ((son + 1 <= end) && (arr[son] < arr[son + 1])) {
		son++;//�����ѭ����ͬһ������
	}
	if (arr[dad] > arr[son]) {
		return;//��ʾ����Ҫ�³���
	}
	swap(arr[dad], arr[son]);
	//����
	heapify(arr, son, end);//�ӽ���Ϊ�µĸ��ڵ����ݹ�
#endif
}
void HeapSort(int* arr, int sz) {
	int i = 0;
	//1.�����������������󶥶�
	//��ʼ���ѣ������һ������㿪ʼ����
	for (i = (sz - 1) / 2; i >= 0; i--) {//����һ��Ҫi>=0����Ϊ��ϵ�Ԫ��Ҳ��Ҫ�³���
		//ÿһ��Ԫ�ض����һ���Ƿ���Ҫ�³�
		heapify(arr, i, sz - 1);//heapifyԪ���³�����
	}
	//2.�ѵ�һ��Ԫ�غͶ����һ��Ԫ�ؽ�����Ȼ�����µ�����ֱ���������
	for (i = sz - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		//����֮�����¹����󶥶�
		heapify(arr, 0, i - 1);
	}
}


void BucketSort(int* arr, int sz) {
	int bucket[5][5] = { 0 };//�������Ͱ,��Ϊ��������������������49������5��Ͱ
	//��������������ˣ�����Ͱ�ĸ���ҲҪ��
	int bucket_size[5] = { 0 };//ÿ��Ͱ����Ҫ��������Ϊ����Ҫ֪��������Ͱ�����˶���Ԫ��
	//������arr�����ݷŵ�Ͱ����
	int i = 0;
	for (i = 0; i < sz; i++) {
		//���ַ�����ÿ��Ԫ�س���ʮ��Ҳ����ȡʮλ�ķ������������ģ��������������50�����ϵģ����Ͱ�Ͳ�����
		bucket[arr[i] / 10][bucket_size[arr[i] / 10]++] = arr[i];
		//arr[i]/10��ʾͰ����ţ�
		//����bucket_size[arr[i]/10]++]��ʾ���ӦͰ��ŵļ��������
	}
	//��ÿ��Ͱ���п��ţ�����Ҫ�Լ��������һ������ʽ�������ÿ���������
	for (i = 0; i < 5; i++) {
		QuickSort(bucket[i], bucket_size[i]);
		//bucket_size[i]��ʾÿ��Ͱ�����Ԫ��
	}

	//��ÿ��Ͱ�е�������䵽����arr��
	//Ҳ����һ���򵥵İѶ�ά�����е�Ԫ�طŵ�һ��һά������
	int j = 0;//��iһ����ƶ�ά����
	int k = 0;//����arr
	for (i = 0; i < 5; i++) {
		for (j = 0; j < bucket_size[i]; j++) {
			arr[k++] = bucket[i][j];
		}
	}
}



int arrMax(int* arr, int sz) {
	int max = INT_MIN;
	for (int i = 0; i < sz; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
void _radixSort(int* arr, int sz, int exp) {
	int i = 0;//����ѭ��
	int* ret = (int*)calloc(sz, sizeof(int));//��Ŵ�Ͱ�ռ������ʱ����
	int buckets[10] = { 0 };//ֻ��0-9ʮ�����֣�����10��Ͱ
	/*
	* �����һά����buckets�����������ľ������ڣ�����˼����ʱ���ǰ����ַŵ�Ͱ����
	* ��������ʵ��д�����ʱ����ֻ��Ҫ�����Ϳ����ˡ�
	* ��Ϊ����һ������Ҳ����һ��_radixSort�ǲ��ù�������λ����ʲô��
	*/
	//����arr�������ݳ��ִ����洢��buckets��
	for (i = 0; i < sz; i++) {
		buckets[(arr[i] / exp) % 10]++;
	}
	//����������for���ǱȽ�������
	//����buckets��Ԫ�ص�ֵ���������ֵ����arr��Ԫ����ret�е�λ��
	for (i = 1; i < 10; i++) {
		buckets[i] = buckets[i] + buckets[i - 1];//�����н���
	}
	//��arr�е�Ԫ����䵽result��
	//�������ѭ���ǳ�������ǿ��Թ۲쵽����bucket[]���������ֵ��������֮��ret[]����Ӧ�е���ֵ����һ������Ĺ�ϵ��
	for (i = sz - 1; i >= 0; i--) {
		int iexp = (arr[i] / exp) % 10;//���iexp������Ҫ�ŵ���һλ���Ǹ���������134�������������Ÿ�λ����iexp����4
													   //������ʮλ��iexp����3
		ret[buckets[iexp] - 1] = arr[i];//�����н���
		buckets[iexp]--;//ÿ��һ������ret�����Ӧ�ļ�����Ҫ����
	}
	//������õ�����ret���Ƶ�arr��
	memcpy(arr, ret, sz * sizeof(int));
}
void RadixSort(int* arr, int sz) {
	int imax = arrMax(arr, sz);//��ȡ����arr�е����ֵ,��Ϊ��������������������Ĵ���
	int iexp;//����ָ����iexp=1������λ����iexp=10����ʮλ����.....
	//�Ӹ�λ��ʼ��������arr��ָ��λ��������
	for (iexp = 1; imax / iexp > 0; iexp *= 10) {//ѭ������ǡǡ�Ϳ���ȷ������Ҫѭ���Ĵ���
		//imax/iexp�������ѭ����������iexp�����ʱ��ͻ�ӽ����ѭ������
		_radixSort(arr, sz, iexp);//ÿһ�εĻ�������
		//iexp����_radixSort()�����Ҫ����һλ����������
	}
}