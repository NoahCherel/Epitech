#!/usr/bin/python3

import sys
from math import sqrt

time_series = []
ratio = []
bollinger = [0.0, 0.0]
weirdest = [0.0, 0.0, 0.0, 0.0, 0.0]
nb_switch = 0
lastEvol = 0.0
period = int(sys.argv[1])

def calculate_average_increase():
    try:
        avg = sum(time_series[-n] - time_series[-(n + 1)] for n in range(1, period + 1) if time_series[-n] > time_series[-(n + 1)])
        tia = avg / period
        print(f"g={tia:.2f}", end="")
    except Exception:
        print("g=nan", end="")

def calculate_relative_evolution():
    try:
        start = next((time_series[idx] for idx in range(-(period + 1), 0) if time_series[idx] != 0), 0.0)
        relative_change = round(100 * ((time_series[-1] - start) / abs(start)))
        print(f"\t\tr={relative_change}%", end="")
        is_change_direction = relative_change * calculate_relative_evolution.last_relative < 0
        calculate_relative_evolution.last_relative = relative_change if relative_change != 0 else calculate_relative_evolution.last_relative
        return is_change_direction
    except Exception:
        print("\t\tr=nan%", end="")
        return False
calculate_relative_evolution.last_relative = 0

def calculate_standard_deviation():
    global bollinger
    try:
        average = sum(time_series[-n] for n in range(1, period + 1)) / period
        variance = sum((time_series[-n] - average) ** 2 for n in range(1, period + 1)) / period
        standard_deviation = sqrt(variance)
        print(f"\t\ts={standard_deviation:.2f}", end="")
        bollinger = [average + (2 * standard_deviation), average - (2 * standard_deviation)]
    except Exception:
        print("\t\ts=nan", end="")
        return

def weirdness_ratio():
    if len(time_series) <= period + 1:
        odd_diff = 9999999.0
    else:
        last_val = time_series[-2]
        closest_bollinger = min(bollinger, key=lambda x: abs(x - last_val))
        odd_diff = abs(closest_bollinger - last_val)
    ratio.append(odd_diff)

def outliers(n=5):
    weirdest = []
    for i in range(n):
        min_ratio_idx = min(range(len(ratio)), key=ratio.__getitem__)
        weirdest.append(time_series[min_ratio_idx - 1])
        ratio.pop(min_ratio_idx)
        time_series.pop(min_ratio_idx - 1)
    return weirdest

def main():
    if (len(sys.argv) != 2):
        exit(84)
    try:
        period = int(sys.argv[1])
    except ValueError:
        exit(84)
    global nb_switch, ratio
    switch = False
    cpt = 0
    while (True):
            if (cpt >= 1000):
                exit(84)
            cpt += 1
            try:
                tmp = input()
            except EOFError:
                exit(84)
            if (tmp == "STOP"):
                break
            try: 
                tmp = float(tmp)
            except ValueError:
                exit(84)
            time_series.append(float(tmp))
            print(tmp, end='\n')
            weirdness_ratio()
            calculate_average_increase()
            switch = calculate_relative_evolution()
            calculate_standard_deviation()
            if (switch):
                print("\t\ta switch occurs", end='')
                nb_switch += 1
            print()
    if (len(time_series) < period):
        exit(84)
    print("Global tendency switched %d times" % nb_switch)
    print("5 weirdest values are", outliers())

if __name__ == "__main__":
    main()