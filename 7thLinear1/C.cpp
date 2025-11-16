#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int su = 0;
    // считаем сумму первых k элементов
    for (int i = 0; i < k; i++)
        su += nums[i];

    // проверяем первый отрезок
    if (su == m) {
        cout << k;
        return 0;
    }

    // скользящее окно
    for (int i = k; i < n; i++) {
        su += nums[i];        // добавляем новый элемент
        su -= nums[i - k];    // убираем старый
        if (su == m) {
            cout << i + 1;    // индекс последнего элемента окна
            return 0;
        }
    }

    cout << 0;
    return 0;
}
