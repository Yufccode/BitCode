#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

//��¼���ŵݹ����
int callCount = 0;

void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
//ֱ�Ӳ�������
void InsertSort(int* a, int n) {
	//[0,end]���򣬰�end+1λ�õ�ֵ���룬��������
	for (int i = 0; i < n - 1; i++) {//�߽���n-2
		int end = i;
		int tmp = a[end + 1];//����end����λ����n-2
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				--end;
			}
			else {
				break;//��break�ٸ�ֵ
			}
		}
		a[end + 1] = tmp;
	}
}
//ϣ������
void ShellSort(int* a, int n) {
	//Ԥ����+��������
	//gap

	//�����ǵ���ѭ��
#if 0
	for (int j = 0; j < gap; j++) {
		for (int i = 0; i < n - gap; i += gap) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}
	}
#endif
	//����������ѭ���ķ�ʽ���Խ�����Ƚ������������������ַ����Ǽ򻯺��д��
	int gap = n;
	while (gap > 1) {
		gap /= 2;
		for (int i = 0; i < n - gap; ++i) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (tmp < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}
	}
}
//�������ʱ��gapԽ�󣬴�����ֿ��Ը���ĵ����棬С�������Ը��쵽ǰ��
//����Խ���ӽ�����
//gapԽС���½ӽ����򣬵�gap==1��ʱ�򣬾���ֱ�Ӳ�������



//������
//����-С��
//����-���
void _AdjustDown(int* a, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		//ѡ��С���Ǹ����ӽڵ�
		if (child + 1 < size && a[child + 1] > a[child]) {
			++child;
		}
		if (a[child] > a[parent]) {
			//���µ���
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			//�������
			break;
		}
	}
}
void HeapSort(int* a, int n) {
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {//n-1�����һ��Ҷ�ӣ�n-1-1/2���ǵ�һ����Ҷ�ӽڵ�,�����һ���ж��ӵĽ�㿪ʼ�³�
		_AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0) {
		swap(a[0], a[end]);
		_AdjustDown(a, end, 0);
		--end;
	}
}


//ֱ��ѡ������O(n^2)
//��������û���ѡ������ã�
//������ã������������߽ӽ����򣬶��ǲ����
void SelectSort(int* a, int n) {
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (a[i] < a[mini]) {
				mini = i;//�����±�
			}
			if (a[i] > a[maxi]) {
				maxi = i;//�����±�
			}
		}
		//��С��ֵ������ߣ������ֵ�����ұ�
		swap(a[begin], a[mini]);
		//���Իᷢ����������ģ����begin��maxi�ص��˵Ļ�
		//��һ���������ᵼ��maxi�����ֱ����ߣ���������
		//����
		if (begin == maxi)maxi = mini;
		swap(a[end], a[maxi]);
		//������һ�˵ģ����������Ϳ�����
		begin++;
		end--;
		//end��begin ����n��������ż��n����
	}
}


//ð������
void BubbleSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int exchange = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				exchange = 1;
			}
		}
		if (!exchange)break;
	}
}


//����--------ÿһ��partsort-----�ҳ��ӵ�λ��
// 
// 
// 
//�Ż�-����ȡ��
int GetMidIndex(int* a, int begin, int end) {
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid]) {
		if (a[mid] < a[end]) {
			return mid;
		}
		else if (a[begin] < a[end]) {
			return end;
		}
		else {
			return begin;
		}
	}
	else {//a[begin]>a[mid]
		if (a[mid] > a[end]) {
			return mid;
		}
		else if (a[begin] < a[end]) {
			return begin;
		}
		else {
			return end;
		}
	}
}
//hoare�汾        O(nlogn)
//1.ѡ��һ��key��һ��������߻������ұߵ�ֵ
//2.��������֮��Ҫ����߱�keyС���ұ߱�key��
//���key���ұ�����
//�ұ�key���������
//ÿ������һ�ˣ�key��λ�õ�ֵ����׼ȷ���ˣ����ö���
int PartSort1(int* a, int begin, int end) {//hoare
	int left = begin;
	int right = end;
	int keyi = left;//�����±꣬Ҳ����ָ�������ŵ�
//�����ǵ���
	while (left < right) {//������ͣ����
		//�ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])--right;//whileһ��Ҫ���Ⱥţ��������ѭ��
		                                               //����Ҫ����һ�����ڣ������п��ܻ�Խ��
		//������ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])++left;
		//����
		swap(a[left], a[right]);
	}
	//����key������λ�û�
	swap(a[keyi], a[right]);
//Ϊʲô�����key��Ҫ���ұ����ߣ�
//��ΪҪ��֤������λ�õ�ֵ��keyС

	keyi = left;
	//[begin,keyi-1]��[keyi+1,end]���򼴿�
	return keyi;
}
//�ڿӷ�
//��hoare��ͬ�ĵط�����-���굥��-����key��߱�keyС���ұ߱�key��
int PartSort2(int* a, int begin, int end) {
	int key = a[begin];
	int piti = begin;//begin�ǵ�һ����
	int left = begin;
	int right = end;
	while (left < right) {
		//�ұ���С�����ߵĿ�
		while (left < right && a[right] >= key) {
			right--;
		}
		a[piti] = a[right];
		piti = right;//�Լ���ɿ�
		while (left < right && a[left] <= key){
			left++;
		}
		a[piti] = a[left];
		piti = left;
	}
	//һ�������ڿӵ�λ��
	a[piti] = key;
	return piti;
}
//ǰ��ָ���
int PartSort3(int* a, int begin, int end) {
	//����֮��prev֮ǰ�ı�prevС��prev��ı�prev��
	int prev = begin;
	int cur = begin + 1;//һ��ʼcur��prevҪ��
	int keyi = begin;

	//��������ȡ�е��Ż�
	int midi = GetMidIndex(a, begin, end);
	swap(a[keyi], a[midi]);//������һ�£�key�ͱ��GetMidIndex()������ȡֵ��-����Ĵ��붼������

	while (cur <= end) {
		//���cur��ֵС��keyi��ֵ
		if (a[cur] < a[keyi] && ++prev != cur) {//ֻ���������Ҫ����һ��
			swap(a[prev], a[cur]);
		}
		++cur;
	}
	swap(a[prev], a[keyi]);
	keyi = prev;
	return keyi;
}
void _QuickSort(int* a, int begin, int end) {
	//��¼�ݹ����
	callCount++;
	//���䲻���ڻ���ֻ����һ��ֵ����Ҫ�ٴ���
	//���ţ�ÿ�ΰ�keyŪ�ã��ݹ���key���ߵ���
	if (begin >= end)return;
	//С�����Ż�
	if (end - begin > 10) {
		int keyi = PartSort3(a, begin, end);//ÿһ��partsort�����ҵ�key
		_QuickSort(a, begin, keyi - 1);
		_QuickSort(a, keyi + 1, end);
	}
	else {
		InsertSort(a + begin, end - begin + 1);//ע��+1��a+begin
	}
}
//��������������key�ķ���������������������ʱ��Ч�ʾͻ�ܵ�
//Ч�ʱ��
//n+n-1+n-2+n-3.....
//O(n^2)
//������Ϊ�ݹ飬�������������΢��һЩ���ͻ����ջ���
//���ǿ�����TestOP������
//����ÿ������������ʱ����debug�汾С�Ϳ��ܻᱬ
//����Ч�ʻ��÷ǳ���

//����Ҫ�Ż�
//1.���ѡkey
//2.����ȡ��--��һ�����м䣬���һ�� ѡ�м��Ǹ�
//3.С�����Ż�--������Ƚ�С��ʱ�򣬾Ͳ��ٵݹ黮��ȥ�������С���䡣���Կ�����������
//  ֱ���ò�������
//������callCount�Ϳ��ԺܺõĿ������ݹ������ʵ�����˷ǳ���

//����뿴�ݹ������ô��
//��һ��callCount����
//���������ͻ����һЩ����
//�������.h�ļ����棬��sort.c,test.c���涼��չ��
//����������ض��������(��������)
//������Ǽ�һ��static����ôsort.c��sort.h��test.c�����callCount�ͻ���Ӱ�죬Ҳ���У���֪�����Ĵ�ӡ��


// �������� �ǵݹ�ʵ��
//�ݹ�ķǵݹ�
//�ݹ��ǿ϶�����һ��ȱ�ݵ�
//����ݹ����̫��ͻ����stackoverflow
#include<stack>
void QuickSortNonR(int* a, int begin, int end) {
	//1.ֱ�Ӹ�ѭ��
	//2.�����ݽṹջģ��ݹ����
	stack<int>st;
	st.push(end);
	st.push(begin);
	//ջ����û�������ˣ��ͽ�����
	while (!st.empty()) {
		int left = st.top();
		st.pop();

		int right = st.top();
		st.pop();

		int keyi = PartSort3(a, left, right);
		//[left,keyi-1]keyi[keyi+1,right]
		
		//��ô����
		//������������

		//ջ��������䶼���ó�������������ָ����������ջ
		if (left < keyi - 1) {
			st.push(keyi - 1);
			st.push(left);
		}
		if (keyi + 1 < right) {
			st.push(right);//ͬ����������������
			st.push(keyi + 1);
		}
	}
}
//
void QuickSort(int* a, int n) {
	int begin = 0;
	int end = n - 1;
	_QuickSort(a, begin, end);
}
//��ʵ����ö�����ʵ��
//��ʵ����dfs��bfs������
//��ջ��ʵ�ֵĻ�������ģ��dfs
//����ö��о���bfs
//�Ͷ������ı�����һ����ͬ�ĵط�


//�鲢����
//�����Ƿ���
void _MergeSort(int* a, int begin, int end, int* tmp) {
	//���䲻���ڣ���������ֻ��һ��ֵ��������>=
	if (begin >= end)return;
	int mid = (begin + end) / 2;
	//[begin,mid][mid+1,end]
	//���εݹ飬������������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	//�����Ѿ��������������ˣ�����Ҫ��ʼ�鲢�ˣ�
	//��ʵ����һ������Ĺ���
	//������ǰ�����������鲢һ��	[begin,mid][mid+1,end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;//ע�⣬���ǿ�����tmp���ʼ��λ�ã�����begin1��λ��
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else {
			tmp[i++] = a[begin2++];
		}
	}
	//ʣ�µĻ�û����
	while (begin1 <= end1) {
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = a[begin2++];
	}
	// �ѹ鲢�����ݿ�����ԭ��������
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));//ע�������a+begin��tmp+begin
}
void MergeSort(int* a, int n) {
	//Ҫ�ȿ�һ�����������鲢
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == nullptr) {
		perror("malloc:");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}


//�ǵݹ���ջ�ʺ�ǰ���ʺϺ���
//�ǵݹ��˼·��ֱ�ӷֳ�һ��һ����Ȼ������������Ȼ���ĸ��ĸ��ϲ�...
//���Կ���һ��gap
//һ��ʼgap��1
//Ȼ��gap��2...
void MergeSortNonR(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == nullptr) {
		perror("malloc:");
		exit(-1);
	}
	//
	int gap = 1;
	while (gap < n) {
		for (int i = 0; i < n; i += 2 * gap) {//Ϊʲô��i+=2*gap,��Ϊ��������鲢������һ����������gap
			//[i,i+gap-1][i+gap,i+2*gap-1]....�����䣬�ֱ�鲢
			//�鲢�Ĵ��������ݹ鷨����
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//�����߽�-���Խ������
			if (end1 >= n) {
				//���end1Խ��
				end1 = n - 1;//ֱ������end1
				//���end1Խ���ˣ���ôbegin2��end2��ô��
				//����Ϊ�����ڵ�����
				//[begin2,end2]Ҫ�ǲ����ڵ�����
				begin2 = n;
				end2 = n - 1;
				//�����ǲ���ֱ��break�ģ���Ϊ�����ᵼ�¶���������ݲ�������ȥ����Ϊ�����ں���
			}
			else if (begin2 >= n) {
				//��begin2����Ϊһ�������ڵ�����
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n) {//������else����ΪûԽ��Ĳ���ȥ����
				end2 = n - 1;//˭Խ���˾�����˭
			}
			//��Ϊ�����������������鿽����ȥ�ģ����Բ���ֱ��break
			//���breakֱ�Ӳ��飬��ô��mainÿһ��ѭ��������Ҫ����һ��
			//���Ի���Ҫ�飬����Ĵ�˼·���������߽�

			//��������������䲻���ڣ������ѭ���Ͳ����ȥ


			int j = begin1;//ע�⣬���ǿ�����tmp���ʼ��λ�ã�����begin1��λ��
			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] < a[begin2]) {
					tmp[j++] = a[begin1++];
				}
				else {
					tmp[j++] = a[begin2++];
				}
			}
			//ʣ�µĻ�û����
			while (begin1 <= end1) {
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2) {
				tmp[j++] = a[begin2++];
			}
		}
		memcpy(a, tmp, sizeof(int) * n);//ȫ������������һ���Կ�����ȥ
		//������gap=1��ʱ��Ŀ��ƣ���������һ��ѭ������gap����
		gap *= 2;//����gap
	}
	free(tmp);
}
//�������ǵݹ飬�����κα߽紦���ǿ϶���Խ��ģ���Ϊ��gap��ʱ��iֱ�Ӱ��±�����ȥ�ˣ���Ϊֱ�Ӽ���������gap
//��ʵֻ��һ��ֵ����Խ�磬ֻ��begin1����Խ�磬��������Խ��


//�ǱȽ�����
//Ͱ����
//��������
//��������



//��������
//�ʺϷ�Χ���У������ظ���
//ʱ�临�Ӷ�O(max(range,N))
//�ռ临�Ӷ�O(range)
void CountSort(int* a, int n) {
	//Ҫ������Сֵ�����ֵ
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
		if (a[i] > max) {
			max = a[i];
		}
	}
	//
	int range = max - min + 1;//ע��+1
	int* hash = (int*)malloc(sizeof(int) * range);
	if (hash == nullptr) {
		perror("malloc");
		exit(-1);
	}
	memset(hash, 0, sizeof(int) * range);

	for (int i = 0; i < n; i++) {
		++hash[a[i] - min];
	}
	//�����ó���
	//����
	int j = 0;
	for (int i = 0; i < range; i++) {
		//���ּ���д����
		while (hash[i]--) {
			a[j++] = i + min;
		}
	}
}


//ֱ�Ӳ��������ȶ�
//ϣ�����򣺲��ȶ�  ��Ԥ�ŵ�ʱ����ͬ�����ݿ��ܻᱻ�ֵ���ͬ������ȥ�ˣ�
//ѡ�����򣺲��ȶ�  ��������Щ���Ϻ��鼮˵�����ȶ��ģ����ǲ���ȷ�ģ�
//�����򣺲��ȶ�
//ð�������ȶ�
//�������򣺲��ȶ�
//�鲢�����ȶ�