# ユークリッド互除法証明

## 前提となる式

$a=bq+r$

## 証明したいこと

$gcd(a,b)=gcd(a-bq,b)$

## [1]$gcd(a,b)|gcd(a-bq,b)$について

$d=gcd(a,b)$ とする

個人的にわかりやすくするため下記のようにする

$x=\frac{d}{a}$

$y=\frac{d}{b}$

前提となる式を変形

$r=a-bq$

$r=dx-dyq$

$r=d(x-dy)$

よって$d|r$、つまり$d|a-bq$が分かる

$d|a-bq$, $d|b$ より下記が分かる

$d|gcd(a-bq,b)$

これはつまり $gcd(a,b)|gcd(a-bq,b)$ ということである・・・①

## [2]$gcd(a-bq,b)|gcd(a,b)$について

前提として $a'=a-bq$ とする(1)

また $d'=gcd(a',b)$ とする

同様に下記のように整理する

$x'=\frac{d'}{a'}$

$y'=\frac{d'}{b}$

前提を式変形すると下記になる

$a=bq+a'$ (2)

整理した$x'$,$y'$を用いると下記のようになる

$a=d'y'q+d'x'$

$a=d'(y'q+x')$

よって下記が分かる

$d'|a$

前提の式変形を用いて下記になる

$d'|bq+a'$

$d'|bq+a'$, $d'|b$ より下記が分かる

$d'|gcd(bq+a',b)$

これはつまり $gcd(a',b)|gcd(bq+a',b)$ということである

(1), (2)より下記になる

$gcd(a-bq,b)|gcd(a,b)$

## [1], [2] より、$gcd(a,b)=gcd(a-bq,b)$ が分かる

前提

* [1] $gcd(a,b)|gcd(a-bq,b)$
* [2] $gcd(a-bq,b)|gcd(a,b)$

互いが互いの倍数であるということは等しいということなので下記が分かる

$gcd(a,b)=gcd(a-bq,b)$
