'''
def sum_series(precision):
    total = 0.0
    k = 1
    while True:
        term = 26 / 2**(k - 1) + (-1)**(k - 1) / (2 * 3**(k - 1))
        if abs(term) < precision:
            break
        total += term
        k += 1
    return total
prec = 1e-6
result = sum_series(prec)
print(f"Сумма ряда с точностью до {prec}: {result}")
'''
import math

def series_sum(x, prec):
    total = 0.0
    k = 1
    while True:
        term = (-1)**k / (math.sin(k * x) + 26 + k**2)
        if abs(term) < prec:
            break
        total += term
        k += 1
    return total
x_val = 1.0
precision = 1e-6
result = series_sum(x_val, precision)
print(f"Сумма функционального ряда для x={x_val} с точностью до {precision}: {result}")