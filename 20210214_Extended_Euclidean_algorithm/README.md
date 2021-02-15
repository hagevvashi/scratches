# Extended Euclidean algorithm

一時不定方程式 $ax+by=c$ が整数解を持つことについての証明

e.g. $6x+8y=10$ の整数解を求めよ

まずは下記内容を掘り下げる

> $a,b,c$ を $0$ 以外の整数とする。一時不定方程式 $ax+by=c$ が整数解をもつための必要十分条件は $c$ が $gcd(a,b)$ で割り切れることである。

まず下記が明らかになる。


"一時不定方程式 $ax+by=c$ が整数解をもつならば $gcd(a,b)|c$ である"

それは下記内容から分かる。

"$d=gcd(a,b)$ とおいたとき、$d|a$, $d|b$。よって、$d|ax+by$ である"

$gcd(a,b)|c$ のとき、$ax+by=c$ が整数解をもつことを示す。

具体的に整数解を構成する方針で進めていく。

$gcd(a,b)|c$ なので、$c=c'gcd(a,b)$ とおくと、$ax+by=c'gcd(a,b)$ となる。

$ax+by=gcd(a,b)$ を満たす整数 $x,y$ が存在することは明らか

両辺を $c'$ 倍すると下記になる

$a(c'x)+b(c'y)=c$

よって、$(c'x,c'y)$ が $ax+by=c$ の整数解になっている

# 例: $111x+30y=12$

まずは $11x+30y=gcd(111,30)$ を求める

$gcd(111,30)=3$

ということで $11x+30y=3$ を満たす $x,y$ を考える

$gcd(111,30)$ のユークリッド互除法を用いた解導出までの経路を詳細に起こすと下記のようになる

1. $111÷30=3…21$
2. $30÷21=1…9$
3. $21÷9=2…3$
4. $9÷3=3$

それぞれかけ算で表現すると下記のようになる

1. $111=3×30+21$
2. $30=1×21+9$
3. $21=2×9+3$
4. $9=3×3+0$

それぞれをさらに式変形してあまりに焦点を当てるために下記のような形にする

1. $21=111-3×30$
2. $9=30-1×21$
3. $3=21-2×9$
4. $0=9-3×3$

ここで逆にたどっていく

$3$
$=21-2×9$
$=21-2×(30-1×21) (9を置き換えた)$
$=-2×30+2×21+21$
$=-2×30+21×(2+1)$
$=-2×30+3×21$
$=-2×30+3×(111-3×30) (21を置き換えた)$
$=-2×30+3×111-3×3×30$
$=3×111-2×30-3×3×30$
$=3×111-11×30$

最終的な式から以下のことが分かる

$(x,y)=(3,-11)$ が $111x+30y=3$ を満たす

$x,y$ を $4$ 倍する(求めるべき一次不等式は $111x+30y=12$ なので)

よって $(x,y)=(12,-44)$ が $111x+30y=12$ を満たす