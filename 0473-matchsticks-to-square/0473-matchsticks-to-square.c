#include <stdbool.h>
#include <string.h>

int used[20];
int target = 0;

bool Try(int k, int current_sum, int start_index, int* matchsticks, int matchsticksSize) {
    if (k == 3) {
        return true; 
    }
    if (current_sum == target) {
        return Try(k + 1, 0, 0, matchsticks, matchsticksSize); 
    }

    for (int i = start_index; i < matchsticksSize; i++) {
        if (used[i] == 0 && current_sum + matchsticks[i] <= target) {
            used[i] = 1;     
            if (Try(k, current_sum + matchsticks[i], i + 1, matchsticks, matchsticksSize)) {
                return true;
            }
            
            used[i] = 0;
        }
    }
    
    return false;
}

bool makesquare(int* matchsticks, int matchsticksSize) {
    int sum = 0;
    for (int i = 0; i < matchsticksSize; i++) {
        sum += matchsticks[i];
    }
    if (sum % 4 != 0 || matchsticksSize < 4) {
        return false;
    }
    target = sum / 4;
    
    // Reset mảng toàn cục cho mỗi test case trên LeetCode
    memset(used, 0, sizeof(used)); 

    // Bắt đầu ghép: 0 cạnh đã xong, tổng hiện tại = 0, bắt đầu từ que diêm thứ 0
    return Try(0, 0, 0, matchsticks, matchsticksSize);
}