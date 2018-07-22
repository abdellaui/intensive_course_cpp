#pragma once

template <const int n>
class faculty
{
  public:
    static const int val = faculty<n - 1>::val * n;  // n!
};

template <>
class faculty<1>
{
  public:
    static const int val = 1;
};


template <const int n, const int k>
class fallendeFaktorielle
{
  public:
    static const int val = (faculty<n>::val / faculty<n - k>::val); // n! / (n-k)!
};

template <const int n, const int k>
class fallendeFaktorielleKurz
{
  public:
    static const int val = fallendeFaktorielleKurz<n-1, k-1>::val * n;  //  n^_k => n*(n-1)(n-2)...*(n-1-k)  (dekrement k till 0, return 1)
};

template <const int n>
class fallendeFaktorielleKurz<n, 0>
{
public:
    static const int val = 1;
};

