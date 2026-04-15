int min(int a, int b){
    if(a >= b){
        return b;
    }
    else{
        return a;
    }
}

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];
    dp[0] = 0;
    int MAX = amount + 1;
    for(int i = 1; i < amount + 1; i++){
        dp[i] = MAX;
    }
    for(int i = 1; i < amount + 1; i++){
        for(int j = 0; j < coinsSize; j++){
            if(coins[j] <= i){
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}