# for i in range(100):
#     print(f"cargo run -r --bin tester python ../sample_submission.py < in/{str(i).zfill(4)}.txt > out/{str(i).zfill(4)}out")

import random
import statistics

def simulate_project_cospa(L, num_samples=100):
    cospas = []
    for _ in range(num_samples):
        b = random.uniform(2.0, 8.0)
        h = round(2 * b) * (2 ** L)
        v = round(2 * clamp(gauss(b, 0.5), 0.0, 10.0)) * (2 ** L)
        if h > 0:
            cospas.append(v / h)
    return cospas

def clamp(x, l, r):
    return max(l, min(r, x))

def gauss(mu, sigma):
    return random.gauss(mu, sigma)

def calculate_avg_std(cospas):
    avg_cospa = statistics.mean(cospas)
    std_deviation = statistics.stdev(cospas)
    return avg_cospa, std_deviation

cospa_by_L = []
for L in range(21):
    cospas = simulate_project_cospa(L)
    cospa_by_L.append(calculate_avg_std(cospas))
    print(cospa_by_L[-1])

print()
print(cospa_by_L)
