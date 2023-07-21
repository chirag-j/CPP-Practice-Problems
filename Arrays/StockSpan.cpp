// Given stock prices on each, return stock span of each day
// i.e number of days going backwards, for which the stock price was less than or equal to today
// Example
// INPUT : [100,80,60,70,60,75,85]
// OUTPUT : [1,1,1,2,1,4,6]

// Easy Monotonic stack problem
class StockSpanner {
public:
    vector<int> prices;
    int n = 0;
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        n++;
        int res;
        while(!stk.empty() && stk.top().first <= price){stk.pop();}
        res = (stk.empty())? n:n-stk.top().second;
        stk.push({price,n});
        return res;
    }
};