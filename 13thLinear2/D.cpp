#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    deque<int> dq;
    vector<int> result;
    
    // Обрабатываем первые k элементов
    for (int i = 0; i < n; i++) {
        // Удаляем элементы, выходящие за границы окна
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Удаляем элементы из конца дека, которые больше текущего
        while (!dq.empty() && arr[dq.back()] > arr[i]) {
            dq.pop_back();
        }
        
        // Добавляем текущий индекс в дек
        dq.push_back(i);
        
        // Начиная с (k-1)-го элемента, добавляем минимумы в результат
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    // Выводим результат
    for (int min_val : result) {
        cout << min_val << "\n";
    }
    
    return 0;
}