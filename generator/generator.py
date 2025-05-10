import os
import random
import argparse


def generate_test_sequence(N, M, merge_prob, pop_prob):

    counts = [0] * (N + 1)
    lines = [f"{N} {M}"]
    for _ in range(M):
        r = random.random()
        # merge operation
        if r < merge_prob:
            a = random.randint(1, N)
            b = random.randint(1, N)
            if b == a:
                b = b % N + 1
            # update counts
            counts[a] += counts[b]
            counts[b] = 0
            lines.append(f"3 {a} {b}")
        # pop operation, only if there's a non-empty set
        elif r < merge_prob + pop_prob:
            non_empty = [i for i in range(1, N+1) if counts[i] > 0]
            if not non_empty:
                # fallback to insert
                m = random.randint(1, N)
                x = random.randint(1, 10**9)
                counts[m] += 1
                lines.append(f"1 {m} {x}")
            else:
                m = random.choice(non_empty)
                counts[m] -= 1
                lines.append(f"2 {m}")
        # insert operation
        else:
            m = random.randint(1, N)
            x = random.randint(1, 10**9)
            counts[m] += 1
            lines.append(f"1 {m} {x}")
    return lines

def main():
    parser = argparse.ArgumentParser(
        description="Generate test files to benchmark heap implementations"
    )
    parser.add_argument('--out-dir', '-o', type=str, default='tests',
                        help='Output directory for test files')
    parser.add_argument('--sets', type=int, nargs='+', default=[1000, 5000, 10000],
                        help='List of N values (number of sets)')
    parser.add_argument('--ops', type=int, nargs='+', default=[10000, 50000, 100000],
                        help='List of M values (number of operations)')
    args = parser.parse_args()

    # define workload scenarios
    scenarios = {
        'insert_heavy':  {'merge': 0.05, 'pop': 0.10},
        'pop_heavy':     {'merge': 0.05, 'pop': 0.40},
        'merge_heavy':   {'merge': 0.40, 'pop': 0.10},
        'mixed':         {'merge': 0.20, 'pop': 0.20},
    }

    # create output directory
    os.makedirs(args.out_dir, exist_ok=True)

    for scenario, probs in scenarios.items():
        mp = probs['merge']
        pp = probs['pop']
        for N in args.sets:
            for M in args.ops:
                filename = f"{scenario}_N{N}_M{M}.txt"
                path = os.path.join(args.out_dir, filename)
                lines = generate_test_sequence(N, M, mp, pp)
                with open(path, 'w') as f:
                    f.write("\n".join(lines))
                print(f"Generated {path}")

if __name__ == '__main__':
    main()
