#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/*declaration de structures */

struct frac
{
    long int num;
    long int den;
};
typedef struct frac fraction;

typedef struct point
{
    fraction x;
    fraction y;
} point;

/* declarations de fonctions */
fraction build(long int, long int);
int eq(fraction f, fraction g);

fraction sub(fraction, fraction);
fraction mul(fraction f, fraction g);
fraction reduce(fraction f);
int isInteger(fraction);
long pgcd(long a, long b);
void afficher(fraction);
int eqp(point a, point b);
double dist(point p1, point p2);

// main
int main()
{
    fraction ex_fractions[] = {build(1, 1),
                               build(1, 2),
                               build(2, 4),
                               build(-9, 3),
                               build(8, -20),
                               build(-5, -1),
                               build(1, -3)};

    afficher(reduce(ex_fractions[3]));
    printf("is integer %d\n", isInteger(ex_fractions[0]));
    point a = {.x = ex_fractions[0],
               .y = ex_fractions[0]};
    point b = {.x = ex_fractions[0],
               .y = ex_fractions[1]};

    printf("Distance :%.2f ", dist(a, b));
}
void afficher(fraction f)
{
    printf("%ld / %ld\n", f.num, f.den);
}

fraction build(long int n, long int d)
{
    assert(d != 0);
    fraction f = {.num = n, .den = d};
    return f;
}
int eq(fraction f, fraction g)
{
    if (f.num * g.den == g.num * f.den)
        return 1;
    else
        return 0;
}

int isInteger(fraction f)
{
    return (f.num % f.den == 0);
}

fraction sum(fraction f, fraction g)
{
    return build(f.num * g.den + f.den * g.num, f.den * g.den);
}
fraction sub(fraction f, fraction g)
{
    return build(f.num * g.den - f.den * g.num, f.den * g.den);
}
fraction mul(fraction f, fraction g)
{
    return build(f.num * g.num, f.den * g.den);
}

fraction reduce(fraction f)
{
    long p = pgcd(f.num, f.den);
    if (f.den < 0)
        return build(-f.num / p, -f.den / p);
    else
        return build(f.num / p, f.den / p);
}

long pgcd(long a, long b)
{
    long x = a;
    long y = b;
    long r;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

// points
int eqp(point a, point b)
{
    return eq(a.x, b.x) && eq(a.y, b.y);
}

double dist(point a, point b)
{
    double x1 = a.x.num / a.x.den;
    double y1 = a.y.num / a.y.den;
    double x2 = b.x.num / b.x.den;
    double y2 = b.y.num / b.y.den;

    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}