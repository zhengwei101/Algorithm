#pragma once

//��arr[l ... mid] �� arr[mid+1 ... r]�����ֽ��й鲢
template <typename T>
void __merge(T arr[], int l, int mid, int r) {
    //�ȶ���һ����arr��ͬ��С�ĸ����ռ�
    T* aux = new T[r - l + 1];

    for (int i = l; i <= r; i++) {
        aux[i - l] = arr[i];
    }

    //��ʼ����iָ����벿�ֵ���ʼ����ֵl��jָ���Ұ벿����ʼ����λ��mid+1
    int i = l;
    int j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i <= mid && j <= r) { //�������δԽ��
            // ��벿����ָԪ�� < �Ұ벿����ָԪ��
            if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            }
            else { // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
                arr[k] = aux[j - l];
                j++;
            }
        }
        else if (i > mid) { // �����벿��Ԫ���Ѿ�ȫ���������
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r) { // ����Ұ벿��Ԫ���Ѿ�ȫ���������
            arr[k] = aux[i - l];
            i++;
        }
    }

    delete[] aux;
}

// �ݹ�ʹ�ù鲢���򣬶�arr[l ... r]�ķ�Χ��������
template <typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + (r - l) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    if(arr[mid] > arr[mid+1]) {
        __merge(arr, l, mid, r);
    }
}

template <typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}
