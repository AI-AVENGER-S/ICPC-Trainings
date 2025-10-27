from collections import defaultdict

s1 = input()
s2 = input()
s3 = input()

lst_lenght = list(map(len, [s1, s2, s3]))
n1, n2, n3 = lst_lenght


def get_most_common(s):
    freq = defaultdict(int)
    for char in s:
        freq[char] += 1
        if freq[char] == 2:
            return int(char) - 1


i, j, k = 0, 0, 0
mapping = {
    0: i,
    1: j,
    2: k,
}
answer = ["0"] * 10**5 * 5
index = 0
while i < n1 and j < n2 and k < n3:
    most_common = get_most_common(s1[i] + s2[j] + s3[k])
    answer[index] = str(most_common + 1)
    mapping[0] += 1
    mapping[1] += 1
    mapping[2] += 1
    mapping[most_common] -= 1
    i = mapping[0]
    j = mapping[1]
    k = mapping[2]
    index += 1

while (i < n1 and j < n2) or (i < n1 and k < n3) or (j < n2 and k < n3):
    if i >= n1:
        most_common = get_most_common(s2[j] + s3[k])
        answer[index] = str(most_common + 1)
        j += 1
        k += 1
        if most_common == 1:
            j -= 1
        elif most_common == 2:
            k -= 1

    elif j >= n2:
        most_common = get_most_common(s1[i] + s3[k])
        answer[index] = str(most_common + 1)
        i += 1
        k += 1
        if most_common == 0:
            i -= 1
        elif most_common == 2:
            k -= 1

    elif k >= n3:
        most_common = get_most_common(s1[i] + s2[j])
        answer[index] = str(most_common + 1)
        i += 1
        j += 1
        if most_common == 0:
            i -= 1
        elif most_common == 1:
            j -= 1
    index += 1

answer = answer[:index]
answer = "".join(answer)
print(answer)
