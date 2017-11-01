def get_max_profit(prices):
    min_price = prices[0]
    max_profit = prices[1] - prices[0]
    
    for price in prices[1:]:
        profit = price - min_price
        if profit > max_profit:
            max_profit = profit
        if price < min_price:
            min_price = price
    return max_profit

print get_max_profit([10, 7, 5, 8, 11, 9])
print get_max_profit([10, 9, 8, 7, 6])
