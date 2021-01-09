int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h)
{
    long long total = (long long)w *h;

    // �Էµ� �� ���� ���� ��� ���� �ش��ϴ� ������ ���� �ȴ�.
    if (w == h) 
    {
        return total - w;
    }

    // �߸� �簢���� ������ �� + ���� - (���� ������ �ִ� �����)�̴�.
    return total - (w + h - gcd(w, h));
}
